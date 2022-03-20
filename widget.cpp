#include "widget.h"
#include "ui_widget.h"
#include "QCryptographicHash"
#include "QTime"
#include "QDate"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
  connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(hashfunction()));

}


Widget::~Widget()
{
    delete ui;
}



void Widget::hashfunction(){
  QCryptographicHash hashed(QCryptographicHash::Keccak_256);
  auto newText = ui->textEdit->toPlainText();
  const char* f= newText.toStdString().c_str();
  hashed.addData(f);
  ui->lineEdit->setText(hashed.result().toBase64());
  ui->label_2->setText("New Password Created At "+QDate::currentDate().toString()+" "+QTime::currentTime().toString());

}
