#include "CustomTree.h"


CustomTree::CustomTree(QWidget *parent)
    :QTreeView(parent)
{
    m_model = new QStandardItemModel(this);
    this->setModel(m_model);

    this->setHeaderHidden(true);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setRootIsDecorated(false); // 设置根节点的小箭头隐藏
    this->setStyleSheet("QTreeView::branch {image:none;}"); // 设置子项的小箭头隐藏
//    this->setItemDelegate(new CustomTreeDelegate(this, this));

    m_bgColor = QColor("#31495A");
    m_hoverBgColor = QColor("#77d8c4");
    m_checkedBgColor = QColor("#18bd9b");
    m_textColor = QColor("#f0f0f0");
    m_hoverTextColor = QColor("#000000");
    m_checkedTextColor = QColor("f0f0f0");
    m_lineColor = QColor("#404244");


}

void CustomTree::addItem(const QString &text, QStandardItem *parent)
{
    if (NULL == parent) {
        m_model->appendRow(new QStandardItem(text));
    } else {
        parent->appendRow(new QStandardItem(text));
    }
}

void CustomTree::addItem(const QString &parentText, const QString &text)
{
    QList<QStandardItem *> ls = m_model->findItems(parentText, Qt::MatchRecursive);

    if (!ls.isEmpty()) {
        foreach (QStandardItem *item, ls) {
            addItem(text, item); // 找到的都添加上
        }
    }
}

void CustomTree::setItemInfo(const QString &ItemText, const QString &info)
{
    if (m_infoMap.contains(ItemText)) {
        m_infoMap.remove(ItemText);
        m_infoMap.insert(ItemText, info);
        return;
    }

    m_infoMap.insert(ItemText, info);
}

QString CustomTree::infoStr(const QModelIndex &index)
{
    QString itemText = m_model->itemFromIndex(index)->data(Qt::DisplayRole).toString();

    if (m_infoMap.contains(itemText)) {
        return m_infoMap.value(itemText);
    }

    return QString();
}
