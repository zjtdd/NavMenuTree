#ifndef CUSTOMTREEDELEGATE_H
#define CUSTOMTREEDELEGATE_H

#include "CustomTreeWidget.h"

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QTreeView>

class CustomTreeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomTreeDelegate(CustomTreeWidget *view, QObject *parent );

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    CustomTreeWidget *m_view;
    QStandardItemModel *m_model;

};

#endif // CUSTOMTREEDELEGATE_H
