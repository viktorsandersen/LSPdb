#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H
#include <iostream>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QComboBox>
#include <QTextEdit>
#include <QSpinBox>
#include <QTreeView>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <pqxx/pqxx>
#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QTableView>
#include <QHBoxLayout>
#include <QHeaderView>

class TableItemDelegate : public QStyledItemDelegate {
public:
    TableItemDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};


void handleDatabaseError(const QSqlError &error);
void populateComboBoxWithTableNames(QComboBox *comboBox, pqxx::connection &conn);
void populateComboBox(QComboBox *comboBox, pqxx::connection &conn, const std::string &tableName);
void setText(QTextEdit *textEdit, pqxx::work &txn, pqxx::result result);
void insertData(pqxx::connection &conn, const QString &tableName, const QString &data);
void deleteLatestCompany(pqxx::connection &conn);
int getNextId(pqxx::work &txn, const std::string &tableName);
void insertCompanyData(pqxx::connection &conn, const std::string &name, const std::string &city, const std::string &country);
void performJoin(pqxx::connection &conn, const QString &table1, const QString &table2, QTextEdit *textEdit, QSpinBox *spinBox);
void on_pushButton_clicked(QTextEdit *textEdit, pqxx::connection &conn, QLineEdit *lineEdit, QSpinBox *spinBox, QComboBox *comboBox, QLabel *label);
void on_resetButton_clicked(QComboBox *comboBox, pqxx::connection &conn, QTextEdit *textEdit);
void on_treeView_clicked(QTreeView *treeView, QTableView *tableView, QTextEdit *textEdit, pqxx::connection &conn, QSpinBox *spinBox);
QStringList populateTreeView(QTreeView *treeView, pqxx::connection &conn);
void populateTableView(QTableView *tableview, pqxx::connection &conn);

#endif // DATABASE_FUNCTIONS_H
