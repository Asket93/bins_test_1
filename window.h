#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>


namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void rotate_fly(int angle, QPixmap img, int tipe);

    void on_dial_valueChanged(int value);

    void read_pitch();
    void read_yaw();
    void read_roll();

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
