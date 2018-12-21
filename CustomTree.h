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

    QColor bgColor() const {return m_bgColor;}
    void setBgColor(const QColor &bgColor) {m_bgColor = bgColor;}

    QColor hoverBgColor() const {return m_hoverBgColor;}
    void setHoverBgColor(const QColor &hoverBgColor) {m_hoverBgColor = hoverBgColor;}

    QColor checkedBgColor() const {return m_checkedBgColor;}
    void setCheckedBgColor(const QColor &checkedBgColor) {m_checkedBgColor = checkedBgColor;}

    QColor textColor() const {return m_textColor;}
    void setTextColor(const QColor &textColor) {m_textColor = textColor;}

    QColor hoverTextColor() const {return m_hoverTextColor;}
    void setHoverTextColor(const QColor &hoverTextColor) {m_hoverTextColor = hoverTextColor;}

    QColor checkedTextColor() const {return m_checkedTextColor;}
    void setcheckedTextColor(const QColor &checkedTextColor) {m_checkedTextColor = checkedTextColor;}

    QString infoStr(const QModelIndex &index);
    QColor lineColor() const {return m_lineColor;}
    void setLineColor(const QColor &lineColor) {m_lineColor = lineColor;}


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
