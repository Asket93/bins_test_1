#ifndef WINDOW_H
#define WINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QTimer>


namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

public slots:
    void timer_overflow(); //функция, которая будет выполняться по таймеру

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void rotate_fly(int angle, QPixmap img, int tipe);

    void on_dial_valueChanged(int value);

    void read_pitch();
    void read_yaw();
    void read_roll();

    void on_horizontalSlider_valueChanged(int value);

private:
    //QPushButton *pushButton;
    Ui::Window *ui;

    QTimer *timer; //переменная таймера
};
#endif // WINDOW_H
