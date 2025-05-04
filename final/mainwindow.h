#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"role.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Role* mrole;
    int Direction;

private:
    Ui::MainWindow *ui;
    QRect role;
    QPainter* painter;


public slots:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    //绘制
    void InitRole();
    void paintEvent(QPaintEvent *event);
    //更新
    void update_role(int Direction);
    void role_up_broadcast();
    void role_down_broadcast();
    void role_right_broadcast();
    void role_left_broadcast();
};
#endif // MAINWINDOW_H
