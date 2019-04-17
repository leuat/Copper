#include "formcopperdataviewer.h"
#include "ui_formcopperdataviewer.h"
#include <QDebug>
FormCopperDataViewer::FormCopperDataViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCopperDataViewer)
{
    ui->setupUi(this);

}


void FormCopperDataViewer::Init(int voices, int data, int rows)
{
   pattern = CopperDataFactory::CreatePattern(voices,rows,data);
   QString text;
   pattern->getText(text);
   ui->txtData->setText(text);
}

FormCopperDataViewer::~FormCopperDataViewer()
{
    delete ui;
}
