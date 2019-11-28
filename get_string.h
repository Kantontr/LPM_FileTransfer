#ifndef GET_STRING_H
#define GET_STRING_H

#include <QDialog>

inline std::string get_message_value="";

namespace Ui {
class Get_String;
}

class Get_String : public QDialog
{
    Q_OBJECT

public:
    explicit Get_String(QWidget *parent = nullptr);
    ~Get_String();

private Q_SLOTS :
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Get_String *ui;
};

#endif // GET_STRING_H
