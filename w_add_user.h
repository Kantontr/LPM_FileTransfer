#ifndef W_ADD_USER_H
#define W_ADD_USER_H

#include <QDialog>

namespace Ui {
class W_Add_User;
}

class W_Add_User : public QDialog
{
    Q_OBJECT

public:
    explicit W_Add_User(QWidget *parent = nullptr);
    ~W_Add_User();

private Q_SLOTS :
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::W_Add_User *ui;
};

#endif // W_ADD_USER_H
