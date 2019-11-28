#ifndef EDIT_CONFIG_H
#define EDIT_CONFIG_H

#include <QDialog>

namespace Ui {
class Edit_Config;
}



class Edit_Config : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Config(QWidget *parent = nullptr);
    ~Edit_Config();

private Q_SLOTS :
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Edit_Config *ui;
};

#endif // EDIT_CONFIG_H
