#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "role.h"
#include<QPainter>
#include<qrect.h>
#include<qtimer.h>
#include<QKeyEvent>
#include<QDebug>
#include<QFont>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mrole = new Role();
    connect(mrole,&Role::role_up,[this](){
        update_role(1);
    } );
    connect(mrole,&Role::role_down,[this](){
        update_role(2);
    } );
    connect(mrole,&Role::role_right,[this](){
        update_role(3);
    } );
    connect(mrole,&Role::role_left,[this](){
        update_role(4);
    } );
    QRect rect(50,50,50,50);
    role = rect;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //InitRole();
    //绘制地图边框
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(50,50,900,700);

    //绘制玩家
    painter.setBrush(Qt::white);
    painter.drawRect(role);
    //绘制格子
    for(int i = 1; i <= 18;i++){
        painter.drawLine(i*50,50,i*50,750);
    }
    for(int i = 1; i <= 14;i++){
         painter.drawLine(50,i*50,950,i*50);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_W:{
        role_up_broadcast();
        break;
    }
    case Qt::Key_A:{
        role_left_broadcast();
        break;
    }
    case Qt::Key_D:{
        role_right_broadcast();
        break;
    }
    case Qt::Key_S:{
        role_down_broadcast();
        break;
    }
    case Qt::Key_Up:{

        break;
    }
    case Qt::Key_Down:{

        break;
    }
    case Qt::Key_Right:{

        break;
    }
    case Qt::Key_Left:{

        break;
    }
    }
    update();
}


void MainWindow::keyReleaseEvent(QKeyEvent *event){

}

void MainWindow::mousePressEvent(QMouseEvent *event){

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){

}

void MainWindow::mouseMoveEvent(QMouseEvent *event){

}


void MainWindow::InitRole(){
    QRect rect(50,50,50,50);
    role = rect;
    connect(mrole,&Role::role_up,[this](){
        update_role(1);
    } );
    connect(mrole,&Role::role_down,[this](){
        update_role(2);
    } );
    connect(mrole,&Role::role_right,[this](){
        update_role(3);
    } );
    connect(mrole,&Role::role_left,[this](){
        update_role(4);
    } );
}


void MainWindow::update_role(int Direction){
    switch(Direction){
    case 1:{
        if(role.top()==50){break;}
        role.setBottom(role.bottom()-50);
        role.setTop(role.top()-50);
        break;
    }
    case 2:{
        if(role.top()==700){break;}
        role.setBottom(role.bottom()+50);
        role.setTop(role.top()+50);
        break;
    }
    case 3:{
        if(role.left()==900){break;}
        role.setLeft(role.left()+50);
        role.setRight(role.right()+50);
        break;
    }
    case 4:{
        if(role.left()==50){break;}
        role.setLeft(role.left()-50);
        role.setRight(role.right()-50);
        break;
    }
    default:;
}
    update();
}
void MainWindow::role_up_broadcast(){
    emit mrole->role_up();
}
void MainWindow::role_down_broadcast(){
    emit mrole->role_down();
}
void MainWindow::role_right_broadcast(){
    emit mrole ->role_right();
}
void MainWindow::role_left_broadcast(){
    emit mrole ->role_left();
}
