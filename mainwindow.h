#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QScreen>
#include <QGuiApplication>
#include <QLineEdit>
#include <QObject>
#include <QtMath>


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
    int lengthArray=0;
    int array[100];

private slots:

    int show_help_page(){
        QList<QScreen*> screens = QGuiApplication::screens();
        int widthScreen=0 , heightScreen=0;
        foreach(QScreen *screen, screens) {
            widthScreen = screen->geometry().width();
            heightScreen = screen->geometry().height();
        }

        QDialog helpDialog;
        helpDialog.setWindowTitle("راهنمای استفاده از برنامه");
        helpDialog.setGeometry(widthScreen/2 , heightScreen/2 , 400, 300);


        QTextEdit *helpText = new QTextEdit(&helpDialog);
        helpText->setReadOnly(true);


        QString helpContent = "برنامه ی آرایه ، دقت بفرمایید که هر تغییر روی آرایه در آرایه ی وارد شده تاثیر گذاشته و آن را عوض میکند\n"
                              "عناصر آرایه در حالت پیش فرض صفر میباشد\n"
                              "Split-> برای جدا کردن عناصر مثبت ارایه از عناصر منفی\n"
                              "Reverse -> برای برعکس کردن عناصر آرایه\n"
                              "Sort -> برای مرتب کردن عناصر آرایه\n"
                              "Delete -> برای حذف کردن یک عنصر دلخواه از آرایه\n"
                              "Max -> نمایش دادن عنصر ماکزیمم\n"
                              "Min -> نمایش دادن عنصر مینیمم\n"
                              "Add Item -> برای اضافه کردن یک عنصر به آخر آرایه\n"
                              "";


        helpText->setPlainText(helpContent);


        QVBoxLayout *layout = new QVBoxLayout(&helpDialog);
        layout->addWidget(helpText);


        return helpDialog.exec();
    }

    void on_submitArray_clicked();

    void on_splitBtn_clicked();

    void on_reverseBtn_clicked();


    void on_sortBtn_clicked();

    void on_deleteBtn_clicked();
    bool deleteNumber();

    void on_maxBtn_clicked();

    void on_minBtn_clicked();

    void on_addBtn_clicked();
    int addNumber();

    void on_printArray_clicked();

    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
