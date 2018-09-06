#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_check_clicked();

    void on_find_clicked();

    void on_bug_clicked();

    void on_system_clicked();

    void on_clear_clicked();

    void on_speed_clicked();

    void on_diag_clicked();

    void on_butler_clicked();

    void on_function_clicked();

    void switchPage(int id);

private:
    Ui::Widget *ui;

    bool m_move;
    QPoint m_startPoint;
    QPoint m_windowPoint;

    int preId;
    int curId;
};

#endif // WIDGET_H
