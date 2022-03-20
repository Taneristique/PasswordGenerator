#include "widget.h"
#include "ui_widget.h"
#include "QCryptographicHash"

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
  const char * f= newText.toStdString().c_str();
  hashed.addData(f);
  ui->label_2->setText(hashed.result().toBase64());
}
