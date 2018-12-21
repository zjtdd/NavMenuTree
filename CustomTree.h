#ifndef CUSTOMTREE_H
#define CUSTOMTREE_H

#include <QObject>
#include <QStandardItem>
#include <QTreeView>

class CustomTree : public QTreeView
{
    Q_OBJECT
public:
    CustomTree(QWidget *parent);

    void addItem(const QString &text, QStandardItem *parent = NULL);
    void addItem(const QString &parentText, const QString &text);
    void setItemInfo(const QString &ItemText, const QString &info);

    QColor bgColor() const;
    void setBgColor(const QColor &bgColor);

    QColor hoverBgColor() const;
    void setHoverBgColor(const QColor &hoverBgColor);

    QColor checkedBgColor() const;
    void setCheckedBgColor(const QColor &checkedBgColor);

    QColor textColor() const;
    void setTextColor(const QColor &textColor);

    QColor hoverTextColor() const;
    void setHoverTextColor(const QColor &hoverTextColor);

    QColor checkedTextColor() const;
    void setcheckedTextColor(const QColor &checkedTextColor);

    QString infoStr(const QModelIndex &index);
    QColor lineColor() const;
    void setLineColor(const QColor &lineColor);


private:
    QStandardItemModel *m_model;
    QColor m_bgColor;
    QColor m_hoverBgColor;
    QColor m_checkedBgColor;
    QColor m_textColor;
    QColor m_hoverTextColor;
    QColor m_checkedTextColor;
    QColor m_lineColor;

    QMap<QString, QString> m_infoMap;
};

#endif // CUSTOMTREE_H
