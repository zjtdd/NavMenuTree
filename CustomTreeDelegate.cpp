#include "CustomTreeDelegate.h"

CustomTreeDelegate::CustomTreeDelegate(CustomTreeWidget *view, QObject *parent)
    :QStyledItemDelegate(parent)
{
    m_view = view;
    m_model = static_cast<QStandardItemModel *>(view->model());
}

void CustomTreeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setRenderHint(QPainter::Antialiasing);

    //绘制背景
    QColor colorBg;
    if (option.state & QStyle::State_Selected) {
        colorBg = m_view->checkedBgColor();
    } else if (option.state & QStyle::State_MouseOver) {
        colorBg = m_view->hoverBgColor();
    } else {
        colorBg = m_view->bgColor();
    }
    QRect bgRect(m_view->geometry().left(), option.rect.top(), m_view->width(), option.rect.height()); // 直接用option.rect，二级树左边有空白
    painter->fillRect(bgRect, colorBg);

    //绘制+-伸缩图片
    if (m_model->itemFromIndex(index)->hasChildren())
    {
        QPixmap pix(18, 16);
        pix.fill(Qt::transparent);
        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);
        int penWidth = 2;
        //根据采用的背景色判断
        QColor icoColorSelected;
        QColor icoColorNormal;
        QColor icoColorHover;
        icoColorSelected = m_view->checkedTextColor();
        icoColorNormal = m_view->textColor();
        icoColorHover = m_view->hoverTextColor();

        p.setBrush(Qt::NoBrush);
        if (option.state & QStyle::State_Selected) {
            p.setPen(QPen(icoColorSelected, penWidth));
        } else if (option.state & QStyle::State_MouseOver) {
            p.setPen(QPen(icoColorHover, penWidth));
        } else {
            p.setPen(QPen(icoColorNormal, penWidth));
        }
        // 绘制+-线条图片
        if (!m_view->isExpanded(index)) {
            p.drawLine(QPointF(8, 8), QPointF(18, 8));
            p.drawLine(QPointF(12, 4), QPointF(12, 12));
        } else {
            p.drawLine(QPointF(8, 8), QPointF(18, 8));
        }

        QPixmap img(pix);
        QRect targetRect = option.rect;
        targetRect.setWidth(16);
        targetRect.setHeight(16);
        QPoint c = option.rect.center();
        c.setX(8 + option.rect.x());
        targetRect.moveCenter(c);
        painter->drawPixmap(targetRect, img, img.rect());
    }

    // 绘制条目文字
    QColor colorText;
    if (option.state & QStyle::State_Selected) {
        colorText = m_view->checkedTextColor();
    } else if (option.state & QStyle::State_MouseOver) {
        colorText = m_view->hoverTextColor();
    } else {
        colorText = m_view->textColor();
    }
    painter->setPen(QPen(colorText));

    //绘制文字离左边的距离
    int margin = 25;
    QRect rect = option.rect;
    rect.setWidth(rect.width() - margin);
    rect.setX(rect.x() + margin);
    QFont normalFont("Microsoft Yahei", 9);
    painter->setFont(normalFont);
    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());

    //绘制提示信息
    QString recordInfo = m_view->infoStr(index);
    //如果不需要显示提示信息或者提示信息为空则返回
    if (recordInfo.isNull() || recordInfo.isEmpty() || !recordInfo.length())
    {
        return;
    }
    QPen decorationPen(option.state & QStyle::State_Selected ? m_view->checkedBgColor() : m_view->checkedTextColor());
    QBrush decorationBrush(option.state & QStyle::State_Selected ? m_view->checkedTextColor() : m_view->checkedBgColor());
    QFont decorationFont("Microsoft Yahei", 8);
    painter->setFont(decorationFont);

    //绘制提示信息背景
    QRect decoration = option.rect;
    decoration.setHeight(15);
    decoration.moveCenter(option.rect.center());
    decoration.setLeft(option.rect.right() - 45);
    decoration.setRight(option.rect.right() - 5);
    painter->setPen(decorationPen);
    QPainterPath path;
    path.addRoundedRect(decoration, 7, 7);
    painter->fillPath(path, decorationBrush);

    //如果是数字则将超过999的数字显示成 999+
    if (recordInfo.toInt() > 999) {
        recordInfo = "999+";
    }

    //如果显示的提示信息长度超过4则将多余显示成省略号..
    if (recordInfo.length() > 4) {
        recordInfo = recordInfo.mid(0, 4) + "..";
    }

    painter->drawText(decoration, Qt::AlignCenter, recordInfo);
}




















