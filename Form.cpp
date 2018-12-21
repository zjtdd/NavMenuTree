#include "Form.h"
#include "ui_Form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    init();
}

Form::~Form()
{
    delete ui;
}

void Form::init()
{
    m_customTreeWidget = new CustomTreeWidget(this);
    ui->verticalLayout->addWidget(m_customTreeWidget);
    m_customTreeWidget->addItem(QStringLiteral("主界面"));
    m_customTreeWidget->setItemInfo(QStringLiteral("信息管理"), QStringLiteral("权限"));
    m_customTreeWidget->addItem(QStringLiteral("系统设置"));
    m_customTreeWidget->addItem(QStringLiteral("系统设置"), QStringLiteral("防区信息"));
    m_customTreeWidget->addItem(QStringLiteral("系统设置"), QStringLiteral("位置调整"));
    m_customTreeWidget->addItem(QStringLiteral("系统设置"), QStringLiteral("地图编辑"));
    m_customTreeWidget->addItem(QStringLiteral("警情查询"));
    m_customTreeWidget->addItem(QStringLiteral("警情查询"), QStringLiteral("记录查询"));
    m_customTreeWidget->addItem(QStringLiteral("警情查询"), QStringLiteral("图像查询"));
    m_customTreeWidget->addItem(QStringLiteral("警情查询"), QStringLiteral("视频查询"));
    m_customTreeWidget->addItem(QStringLiteral("警情查询"), QStringLiteral("数据回放"));
    m_customTreeWidget->addItem(QStringLiteral("信息管理"));
    m_customTreeWidget->addItem(QStringLiteral("信息管理"), QStringLiteral("学生管理"));
    m_customTreeWidget->addItem(QStringLiteral("信息管理"), QStringLiteral("教师管理"));
    m_customTreeWidget->addItem(QStringLiteral("信息管理"), QStringLiteral("成绩管理"));
    m_customTreeWidget->addItem(QStringLiteral("帮助文档"));
}
