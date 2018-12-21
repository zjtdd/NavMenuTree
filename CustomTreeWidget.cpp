#include "CustomTreeWidget.h"

#include "CustomTreeDelegate.h"

#include <QDebug>

CustomTreeWidget::CustomTreeWidget(QWidget *parent)
    :QTreeView(parent)
{
    m_model = new QStandardItemModel(this);
    this->setModel(m_model);

    this->setHeaderHidden(true);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setRootIsDecorated(false); // 设置根节点的小箭头隐藏
    this->setStyleSheet("QTreeView::branch {image:none;}"); // 设置子项的小箭头隐藏
    this->setItemDelegate(new CustomTreeDelegate(this, this));

    m_bgColor = QColor("#31495A");
    m_hoverBgColor = QColor("#77D8C4");
    m_checkedBgColor = QColor("#18BD9B");
    m_textColor = QColor("#F0F0F0");
    m_hoverTextColor = QColor("#000000");
    m_checkedTextColor = QColor("#F0F0F0");
    m_lineColor = QColor("#404244");

}

void CustomTreeWidget::addItem(const QString &text, QStandardItem *parent)
{
    if (NULL == parent) {
        m_model->appendRow(new QStandardItem(text));
    } else {
        parent->appendRow(new QStandardItem(text));
    }
}

void CustomTreeWidget::addItem(const QString &parentText, const QString &text)
{
    QList<QStandardItem *> ls = m_model->findItems(parentText, Qt::MatchRecursive);
    if (!ls.isEmpty()) {
        foreach (QStandardItem *item, ls) { // 找到的都加上
            addItem(text, item);
        }
    }
}

void CustomTreeWidget::setItemInfo(const QString &ItemText, const QString &info)
{
    if (m_infoMap.contains(ItemText)) {
        qDebug() << "contains";
        m_infoMap.remove(ItemText);
        m_infoMap.insert(ItemText, info);
        return;
    }

    m_infoMap.insert(ItemText, info);
    qDebug() << "none";
}

QString CustomTreeWidget::infoStr(const QModelIndex &index)
{
    QString itemText = m_model->itemFromIndex(index)->data(Qt::DisplayRole).toString();

    if (m_infoMap.contains(itemText)) {
        return m_infoMap.value(itemText);
    }

    return QString();
}
