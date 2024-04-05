// datelineeditdelegate.h
#ifndef DATELINEEDITDELEGATE_H
#define DATELINEEDITDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QAbstractItemModel>

class DateLineEditDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QLineEdit* editor = new QLineEdit(parent);
        QRegularExpressionValidator* validator = new QRegularExpressionValidator(QRegularExpression("\\d{2}-\\d{2}-\\d{4}"), editor);
        editor->setValidator(validator);
        return editor;
    }

    void setEditorData(QWidget* editor, const QModelIndex& index) const override {
        QString value = index.model()->data(index, Qt::EditRole).toString();
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        lineEdit->setText(value);
    }

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override {
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        QString value = lineEdit->text();
        model->setData(index, value, Qt::EditRole);
    }
};

#endif // DATELINEEDITDELEGATE_H