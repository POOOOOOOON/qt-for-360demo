#include "widget.h"
#include "ui_widget.h"
#include <QMenu>
#include <QAction>
#include <QButtonGroup>
#include <QStackedWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/image/360.ico"));

    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/image/frame.png").scaled(// 缩放背景图.
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    this->setPalette(palette);                      // 给widget加上背景图

    connect(ui->close,SIGNAL(clicked()),this,SLOT(close()));
    //connect(ui->max,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->min,SIGNAL(clicked()),this,SLOT(showMinimized()));
    //connect(ui->set,SIGNAL(clicked()),this,SLOT(showSetMenu()));

    QMenu *setMenu = new QMenu();
    QAction *setAct = new QAction(setMenu);
    QAction *newAct = new QAction(setMenu);
    QAction *updateAct = new QAction(setMenu);
    QAction *helpAct = new QAction(setMenu);
    QAction *aboutAct = new QAction(setMenu);

    setMenu->addAction(setAct);
    setMenu->addAction(newAct);
    setMenu->addAction(updateAct);
    setMenu->addSeparator();
    setMenu->addAction(helpAct);
    setMenu->addAction(aboutAct);

    ui->set->setMenu(setMenu);

    setAct->setText(QString::fromLocal8Bit("设置"));
    newAct->setText(QString::fromLocal8Bit("新版特性"));
    updateAct->setText(QString::fromLocal8Bit("检查更新"));
    helpAct->setText(QString::fromLocal8Bit("在线帮助"));
    aboutAct->setText(QString::fromLocal8Bit("关于我们"));

    QButtonGroup *buttonGroup = new QButtonGroup;
    buttonGroup->addButton(ui->check,0);
    buttonGroup->addButton(ui->find,1);
    buttonGroup->addButton(ui->bug,2);
    buttonGroup->addButton(ui->system,3);
    buttonGroup->addButton(ui->clear,4);
    buttonGroup->addButton(ui->speed,5);
    buttonGroup->addButton(ui->diag,6);
    buttonGroup->addButton(ui->butler,7);
    buttonGroup->addButton(ui->function,8);
    //connect(buttonGroup,SIGNAL(buttonClicked(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(switchPage(int)));

    ui->check->setStyleSheet("QPushButton{border-image: url(:/image/11.png);}");
    ui->stackedWidget->setCurrentIndex(0);

    preId = 0;
    curId = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::switchPage(int id)
{
    ui->stackedWidget->setCurrentIndex(id);

    curId = id;
    switch(curId)
    {
        case 0:
            ui->check->setStyleSheet("QPushButton{border-image: url(:/image/11.png);}");
            break;
        case 1:
            ui->find->setStyleSheet("QPushButton{border-image: url(:/image/22.png);}");
            break;
        case 2:
            ui->bug->setStyleSheet("QPushButton{border-image: url(:/image/33.png);}");
            break;
        case 3:
            ui->system->setStyleSheet("QPushButton{border-image: url(:/image/44.png);}");
            break;
        case 4:
            ui->clear->setStyleSheet("QPushButton{border-image: url(:/image/55.png);}");
            break;
        case 5:
            ui->speed->setStyleSheet("QPushButton{border-image: url(:/image/66.png);}");
            break;
        case 6:
            ui->diag->setStyleSheet("QPushButton{border-image: url(:/image/77.png);}");
            break;
        case 7:
            ui->butler->setStyleSheet("QPushButton{border-image: url(:/image/88.png);}");
            break;
        case 8:
            ui->function->setStyleSheet("QPushButton{border-image: url(:/image/99.png);}");
            break;
    }

    switch(preId)
    {
        case 0:
            ui->check->setStyleSheet("QPushButton{border-image: url(:/image/1.png);}"
                                    "QPushButton:hover{border-image: url(:/image/11.png);}");
            break;
        case 1:
            ui->find->setStyleSheet("QPushButton{border-image: url(:/image/2.png);}"
                                    "QPushButton:hover{border-image: url(:/image/22.png);}");
            break;
        case 2:
            ui->bug->setStyleSheet("QPushButton{border-image: url(:/image/3.png);}"
                                   "QPushButton:hover{border-image: url(:/image/33.png);}");
            break;
        case 3:
            ui->system->setStyleSheet("QPushButton{border-image: url(:/image/4.png);}"
                                      "QPushButton:hover{border-image: url(:/image/44.png);}");
            break;
        case 4:
            ui->clear->setStyleSheet("QPushButton{border-image: url(:/image/5.png);}"
                                     "QPushButton:hover{border-image: url(:/image/55.png);}");
            break;
        case 5:
            ui->speed->setStyleSheet("QPushButton{border-image: url(:/image/6.png);}"
                                     "QPushButton:hover{border-image: url(:/image/66.png);}");
            break;
        case 6:
            ui->diag->setStyleSheet("QPushButton{border-image: url(:/image/7.png);}"
                                    "QPushButton:hover{border-image: url(:/image/77.png);}");
            break;
        case 7:
            ui->butler->setStyleSheet("QPushButton{border-image: url(:/image/8.png);}"
                                      "QPushButton:hover{border-image: url(:/image/88.png);}");
            break;
        case 8:
            ui->function->setStyleSheet("QPushButton{border-image: url(:/image/9.png);}"
                                        "QPushButton:hover{border-image: url(:/image/99.png);}");
            break;
    }

    preId = curId;
}

void Widget::on_check_clicked()
{

}

void Widget::on_find_clicked()
{

}

void Widget::on_bug_clicked()
{

}

void Widget::on_system_clicked()
{

}

void Widget::on_clear_clicked()
{

}

void Widget::on_speed_clicked()
{

}

void Widget::on_diag_clicked()
{

}

void Widget::on_butler_clicked()
{

}

void Widget::on_function_clicked()
{

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    //当鼠标左键点击时.
    if (event->button() == Qt::LeftButton)
    {
        m_move = true;
        //记录鼠标的世界坐标.
        m_startPoint = event->globalPos();
        //记录窗体的世界坐标.
        m_windowPoint = this->frameGeometry().topLeft();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置.
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可.
        this->move(m_windowPoint + relativePos );
    }
}
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态.
        m_move = false;
    }
}
