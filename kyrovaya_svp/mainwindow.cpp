#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(0,1,this);
    ui->tableView->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, "Предыдущие данные");
    ui->lineEdit->setValidator(new QIntValidator(0, 100, this) );
    ui->lineEdit_3->setValidator(new QIntValidator(0, 100, this) );
    ui->lineEdit_2->setValidator(new QIntValidator(0, 100, this) );
    ui->label_8->setText("               ");
    ui->label_9->setText("               ");
    ui->label_10->setText("               ");
    QPixmap pix(":/new/prefix1/form/formul1.jpg");
    ui->label->setPixmap(pix.scaled(250, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ind!=0 && qstr!="nan"){
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(ind-1,0);
        model->setData(index, qstr);
    }
bool ret = false;
    double wc = 0;
    wc = ui->lineEdit->text().toDouble()/100;
    if (wc == 0){
        ui->label_10->setText("Введите данные!");
    ret=true;
    }
    else{
        ui->label_10->setText("               ");
    }

    double h = 0;
    h = ui->lineEdit_3->text().toDouble()/100;
    if (h == 0){
        ui->label_8->setText("Введите данные!");
    ret=true;
    }
    else{
        ui->label_8->setText("               ");
    }
    double mass = 0;
    mass = ui->lineEdit_2->text().toDouble();
    if (mass == 0){
        ui->label_9->setText("Введите данные!");
    ret=true;
    }
    else{
        ui->label_9->setText("               ");
    }
    if (ret == true){
        qstr = "nan";
        ui->label_11->setText("Индекс формы тела: ");
        return;
    }
    double bmi=0;
    bmi = mass/(pow(h,2));
    double absi = (wc/(pow(bmi, 0.666)*pow(h, 0.5))) ;
    std::string strabsi = std::to_string(absi) ;
    qstr = QString::fromStdString(strabsi);
    qDebug()<<absi<<"-absi "<< bmi<<"-bmi "<< h<<"-h "<< wc<<"-wc "<< mass<<"-mass ";
    qDebug()<<pow(bmi, 0.666)/100<<pow(h, 0.5)/100;
    ui->label_11->setText("Индекс формы тела: " + qstr);
    ind++;
}

