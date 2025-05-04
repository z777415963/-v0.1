#ifndef ROLE_H
#define ROLE_H

#include <QWidget>

class Role : public QWidget
{
    Q_OBJECT
public:
    explicit Role(QWidget *parent = nullptr);

signals:
    void role_up();
    void role_down();
    void role_right();
    void role_left();

public slots:

};

#endif // ROLE_H
