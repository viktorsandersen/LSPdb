#ifndef DATABASE_FUNCTIONS_H_
#define DATABASE_FUNCTIONS_H_

#include "database_functions.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QRegularExpressionValidator>


TableItemDelegate::TableItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent) {}

void TableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    QStyledItemDelegate::paint(painter, opt, index);
    //painter->fillRect(option.rect, QColor(173, 216, 230));
}

void on_resetButton_clicked(QComboBox *comboBox, pqxx::connection &conn, QTextEdit *textEdit) {
    pqxx::work txn(conn);
    pqxx::result result;
    if (!conn.is_open()) {
        return;
    }
    try {
        result = txn.exec("SELECT table_name FROM information_schema.tables WHERE table_schema = 'public'");
        setText(textEdit, txn, result);
    } catch (const pqxx::sql_error &e) {
        return;
    }
}

void on_treeView_clicked(QTreeView *treeView, QTextEdit *textEdit, pqxx::connection &conn, QSpinBox *spinBox) {
    int limit = spinBox->value();
    QModelIndex index = treeView->currentIndex();
    QString tableName = index.data().toString();
    std::cout << tableName.toStdString() << std::endl;
    //SELECT first_name, last_name FROM contacts WHERE department='R&D';


    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT c.first_name, c.last_name FROM contacts c INNER JOIN department d ON c.department = d.name INNER JOIN companies co ON d.department_id = co.company_id WHERE co.name = '" + tableName.toStdString() + "' LIMIT " + std::to_string(limit));
    setText(textEdit, txn, result);
}

QStringList populateTreeView(QTreeView *treeView, pqxx::connection &conn) {
    QStringList tableNames;
    pqxx::work txn(conn);
    // Shows all the different table names
    //pqxx::result result = txn.exec("select tablename from pg_catalog.pg_tables where schemaname='public'");
    pqxx::result result = txn.exec("select name from companies");
    QStandardItemModel *model = new QStandardItemModel(treeView);
    for (int i = 0; i < result.size(); i++) {
        QStandardItem *item = new QStandardItem(result[i][0].c_str());
        tableNames.append(result[i][0].c_str()); // Add table name to the list
        model->appendRow(item);
    }
    treeView->setModel(model);
    treeView->expandAll();
    return tableNames;
}

void setText(QTextEdit *textEdit, pqxx::work &txn, pqxx::result result) {
    textEdit->clear();
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            textEdit->insertPlainText(result[i][j].c_str());
            textEdit->insertPlainText("\t");
        }
        textEdit->insertPlainText("\n");
    }
}

void populateComboBoxWithTableNames(QComboBox *comboBox, pqxx::connection &conn) {
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT table_name FROM information_schema.tables WHERE table_schema = 'public'");
    for (int i = 0; i < result.size(); i++) {
        comboBox->addItem(result[i][0].c_str());
    }
}

void populateComboBox(QComboBox *comboBox, pqxx::connection &conn, const std::string &tableName) {
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT first_name FROM " + tableName);
    //std::cout << result[1][1] << std::endl;

    for (int i = 0; i < (int) result.size(); i++) {
        comboBox->addItem(result[i][1].c_str());
    }
}

void on_pushButton_clicked(QTextEdit *textEdit, pqxx::connection &conn, QLineEdit *lineEdit, QSpinBox *spinBox, QComboBox *comboBox, QLabel *label) {
    pqxx::work txn(conn);
    pqxx::result result;
    if (!conn.is_open()) {
        std::cout << "!conn_is_open()" << std::endl;
        return;
    }
    try {
        result = txn.exec("SELECT * FROM " + comboBox->currentText().toStdString() + " LIMIT " + std::to_string(spinBox->value()));
        setText(textEdit, txn, result);
        label->setText(comboBox->currentText());
        std::cout << "try" << std::endl;
    } catch (const pqxx::sql_error &e) {
        std::cout << "catch" << std::endl;
        return;
    }
}

void insertData(pqxx::connection &conn, const QString &tableName, const QString &data) {
    pqxx::work txn(conn);
    txn.exec("INSERT INTO " + tableName.toStdString() + " VALUES (" + data.toStdString() + ")");
    txn.commit();
}

int getNextId(pqxx::work &txn, const std::string &tableName) {
    pqxx::result result = txn.exec("SELECT MAX(company_id) FROM " + tableName);
    return result[0][0].as<int>() + 1;
}

void insertCompanyData(pqxx::connection &conn, const std::string &name, const std::string &city, const std::string &country) {
    pqxx::work txn(conn);
    int company_id = getNextId(txn, "companies");
    txn.exec("INSERT INTO companies VALUES ('" +  name + "', '" + city + "', '" + country + "', '" + std::to_string(company_id) + "')");
    txn.commit();
}

void performJoin(pqxx::connection &conn, const QString &table1, const QString &table2, QTextEdit *textEdit, QSpinBox *spinBox) {
    pqxx::work txn(conn);
    pqxx::result result = txn.exec("SELECT * FROM " + table1.toStdString() + " INNER JOIN " + table2.toStdString() + " ON " + table1.toStdString() + ".country_id = " + table2.toStdString() + ".country_id LIMIT " + std::to_string(spinBox->value()));
    //pqxx::result result = txn.exec("SELECT * FROM city INNER JOIN country ON city.country_id = country.country_id");
    setText(textEdit, txn, result);
}


#endif // DATABASE_FUNCTIONS_H_
