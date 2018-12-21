#include "CustomTreeDelegate.h"

CustomTreeDelegate::CustomTreeDelegate(CustomTree *view, QObject *parent)
    :QStyledItemDelegate(parent)
{
    m_view = view;
    m_model = static_cast<QStandardItemModel *>(view->model());
}
