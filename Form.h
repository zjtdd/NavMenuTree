#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "CustomTreeWidget.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    /**
     * @brief init - 初始化界面
     */
    void init();

private:
    Ui::Form *ui;

    CustomTreeWidget *m_customTreeWidget;
};

#endif // FORM_H
