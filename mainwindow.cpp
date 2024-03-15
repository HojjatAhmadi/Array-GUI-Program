#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->helpBtn , SIGNAL(clicked()) , this , SLOT(show_help_page()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitArray_clicked()
{
    QStringList arraytext = ui->input_array->text().split(" ");
    foreach (QString item, arraytext) {
        array[lengthArray++] = item.toInt();
    }
    ui->console->append("آرایه با موفقیت اضافه شد!");
}

// split 1 2 3 -5 -4 6 7 8 -12 -7 -6 -5
void MainWindow::on_splitBtn_clicked()
{
    QString Posetive = "عناصر مثبت آرایه = [ " , Negative = "عناصر منفی آرایه = [ ";
    int posetiveArray[lengthArray] , negativeArray[lengthArray];
    int p=0 , n=0;
    for(int i=0 ; i<lengthArray ; i++){
        if(array[i]>=0){
            posetiveArray[p++]=array[i];
        }
        else{
            negativeArray[n++]=array[i];
        }
    }

    for(int i=0 ; i<p ; i++){
        Posetive += QString::number(posetiveArray[i]);
        if(i != p-1){
            Posetive += " , ";
        }
    }

    for(int i=0 ; i<n ; i++){
        Negative += QString::number(negativeArray[i]);
        if(i != n-1){
            Negative += " , ";
        }
    }

    Posetive += " ]";
    Negative += " ]";

    ui->console->append(Posetive);
    ui->console->append(Negative);
}

// Reverse
void MainWindow::on_reverseBtn_clicked()
{
    for(int i=0 ; i<lengthArray/2 ; i++){
        int temp;
        temp = array[i];
        array[i] = array[lengthArray-i-1];
        array[lengthArray-i-1] = temp;
    }

    QString text = "آرایه ی معکوس شده = [ ";
    for(int i=0 ; i<lengthArray ; i++){
        text += QString::number(array[i]);
        if(i != lengthArray-1){
            text += " , ";
        }
    }

    text += " ]";

    ui->console->append(text);
}



void MainWindow::on_sortBtn_clicked()
{
    QString text = "آرایه ی مرتب شده = [ ";
    // int sort_array[length] , maxvalue , index;
    for(int i=0 ; i<lengthArray ; i++){
        int min = array[i] , index=i , temp;
        for(int j=i ; j<lengthArray ; j++){
            if(array[j]<min){
                min=array[j];
                index=j;
            }
        }
        temp = array[i];
        array[i]=min;
        array[index]=temp;
    }

    for(int i=0 ; i<lengthArray ; i++){
        text += QString::number(array[i]);
        if(i != lengthArray-1){
            text += " , ";
        }
    }
    text += " ]";
    ui->console->append(text);
}


void MainWindow::on_deleteBtn_clicked()
{
    ui->console->append("لطفا عدد مورد نظر را داخل اینپوت بالا وارد کنید (لازم نیست دکمه ای را کلیک کنید)");
    ui->input_array->clear();
    connect(ui->input_array , SIGNAL(editingFinished()) , this , SLOT(deleteNumber()));
}

bool MainWindow:: deleteNumber(){
    int number = ui->input_array->text().toInt();
    bool condition = false;

    for(int i=0 ; i<lengthArray ; i++){
        if(array[i]==number){
            for(int j=i ; j<lengthArray-1 ; j++){
                array[j] = array[j+1];
                condition = true;
            }
        }
    }
    if(condition){
        lengthArray--;
        ui->console->append("عملیات حذف با موفقیت انجام شد!");
        return true;
    }
}

//max
void MainWindow::on_maxBtn_clicked()
{
    QString text = "بزرگترین عدد در آرایه = [ ";
    int max = array[0];

    for(int i=0 ; i<lengthArray ; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    text += QString::number(max);
    text += " ]";
    ui->console->append(text);
}

// min
void MainWindow::on_minBtn_clicked()
{
    QString text = "کوچکترین عدد در آرایه = [ ";
    int min = array[0];

    for(int i=0 ; i<lengthArray ; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    text += QString::number(min);
    text += " ]";
    ui->console->append(text);
}

// additem
void MainWindow::on_addBtn_clicked()
{
    ui->console->append("لطفا عدد مورد نظر را داخل اینپوت بالا وارد کنید (لازم نیست دکمه ای را کلیک کنید)");
    ui->input_array->clear();
    connect(ui->input_array , SIGNAL(editingFinished()) , this , SLOT(addNumber()));
}

int MainWindow:: addNumber(){
    int number = ui->input_array->text().toInt();
    array[lengthArray] = number;
    lengthArray++;
    ui->console->append("عملیات اضافه کردن با موفقیت انجام شد!");
    return true;
}

void MainWindow::on_printArray_clicked()
{
    QString text = "آرایه ی مورد نظر شما = [ ";
    for(int i=0 ; i<lengthArray ; i++){
        text += QString::number(array[i]);
        if(i != lengthArray-1){
            text += " , ";
        }
    }
    text += " ]";
    ui->console->append(text);
}


void MainWindow::on_clearBtn_clicked()
{
    ui->console->clear();
    ui->console->append("خروجی با موفقیت پاکسازی شد.");
}

