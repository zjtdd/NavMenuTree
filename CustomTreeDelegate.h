#ifndef CUSTOMTREEDELEGATE_H
#define CUSTOMTREEDELEGATE_H

#include "CustomTree.h"

#include <QObject>
#include <QStyledItemDelegate>

class CustomTreeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomTreeDelegate(CustomTree *view, QObject *parent );

private:
    CustomTree *m_view;
    QStandardItemModel *m_model;

};

#endif // CUSTOMTREEDELEGATE_H
