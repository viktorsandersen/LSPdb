#include "mainwindow.h"
#include "database_functions.h"
#include <QCompleter>
#include <QLineEdit>
#include "datelineeditdelegate.h"

int main(int argc, char *argv[]) {
    //pqxx::connection conn("dbname=dvdrental user=postgres password=1101");
    pqxx::connection conn("dbname=lsp user=postgres password=lsp");
    if (!conn.is_open()) {
        std::cerr << "Can't open database" << std::endl;
        return 1;
    }

    QApplication app(argc, argv);

    Ui::Dialog ui;
    QDialog mainWindow;
    ui.setupUi(&mainWindow);
    mainWindow.show();

    QTextEdit *textEdit = mainWindow.findChild<QTextEdit*>("textEdit");
    QPushButton *search = mainWindow.findChild<QPushButton*>("pushButton");
    QPushButton *resetButton = mainWindow.findChild<QPushButton*>("pushButton_2");
    QPushButton *addButton = mainWindow.findChild<QPushButton*>("pushButton_3");
    QPushButton *joinButton = mainWindow.findChild<QPushButton*>("pushButton_4");
    QPushButton *deleteButton = mainWindow.findChild<QPushButton*>("delete_2");
    QLineEdit *lineEdit = mainWindow.findChild<QLineEdit*>("lineEdit_3");
    QSpinBox *spinBox = mainWindow.findChild<QSpinBox*>("spinBox");
    QComboBox *comboBox = mainWindow.findChild<QComboBox*>("comboBox");
    QComboBox *comboBox2 = mainWindow.findChild<QComboBox*>("comboBox_2");
    QLabel *label = mainWindow.findChild<QLabel*>("label_5");
    QTreeView *treeView = mainWindow.findChild<QTreeView*>("treeView");
    //QTreeView *departments = mainWindow.findChild<QTreeView*>("treeView_2");
    QTableView *departments = mainWindow.findChild<QTableView*>("tableView");

    QStringList tableNames = populateTreeView(treeView, conn);
    populateTableView(departments, conn);// Populate the tree view and get table names
    //QLineEdit *date = mainWindow.findChild<QLineEdit*>("lineEdit");
    QLineEdit *dateLineEdit = mainWindow.findChild<QLineEdit*>("lineEdit");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("\\d{2}-\\d{2}-\\d{4}"), dateLineEdit);
    dateLineEdit->setValidator(validator);

    QCompleter *completer = new QCompleter(tableNames, &mainWindow); //Autocomplete for the line edit based on tableNames
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    lineEdit->setCompleter(completer);

    TableItemDelegate *delegate = new TableItemDelegate(treeView);
    treeView->setItemDelegate(delegate);

    spinBox->setValue(10);
    populateComboBoxWithTableNames(comboBox, conn);
    populateComboBox(comboBox2, conn, "contacts");
    populateTreeView(treeView, conn); // Populate the tree view initially

    QObject::connect(resetButton, &QPushButton::clicked, [&]() {
        populateTreeView(treeView, conn); // Refresh the tree view
        on_resetButton_clicked(comboBox, conn, textEdit);
        label->setText("Table names");
    });

    QObject::connect(search, &QPushButton::clicked, [&]() {
        on_pushButton_clicked(textEdit, conn, lineEdit, spinBox, comboBox, label);
    });

    QObject::connect(deleteButton, &QPushButton::clicked, [&]() {
        deleteLatestCompany(conn);
    });

    QObject::connect(departments, &QTreeView::clicked, [&]() {
        on_treeView_clicked(treeView, departments, textEdit, conn, spinBox);
    });

    QObject::connect(treeView, &QTreeView::clicked, [&]() {
        on_treeView_clicked(treeView, departments, textEdit, conn, spinBox);
    });

    QObject::connect(addButton, &QPushButton::clicked, [&]() {
        insertCompanyData(conn, "John", "Göteborg", "Sverige");
        std::cout << "Data inserted" << std::endl;
    });

    //joinButton->setText("Joint country and city");

    //QObject::connect(joinButton, &QPushButton::clicked, [&]() {
    //    performJoin(conn, "country", "city", textEdit, spinBox);
    //    std::cout << "Data joined" << std::endl;
    //});

    return app.exec();
}
