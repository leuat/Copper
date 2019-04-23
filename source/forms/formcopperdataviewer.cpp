#include "formcopperdataviewer.h"
#include "ui_formcopperdataviewer.h"
#include <math.h>
#include <QElapsedTimer>

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
   Redraw();
}

FormCopperDataViewer::~FormCopperDataViewer()
{
    delete ui;
}

void FormCopperDataViewer::keyPressEvent(QKeyEvent *e)
{
    QElapsedTimer timer;
    timer.start();
    if (e->key()==Qt::Key_D) {
        m_curPos.setX(m_curPos.x()+1);
    }
    if (e->key()==Qt::Key_A) {
        m_curPos.setX(m_curPos.x()-1);
    }

    if (e->key()==Qt::Key_W) {
        m_curPos.setY(m_curPos.y()-1);
    }
    if (e->key()==Qt::Key_S) {
        m_curPos.setY(m_curPos.y()+1);
    }

    if (m_curPos.x()<0) m_curPos.setX(0);
    if (m_curPos.y()<0) m_curPos.setY(0);
    if (m_curPos.x()>=pattern->getTotalWidth()) m_curPos.setX(pattern->getTotalWidth()-1);
    if (m_curPos.y()>=pattern->getTotalHeight()) m_curPos.setY(pattern->getTotalHeight()-1);


    if (m_curPos.y()>=m_height+m_curOffset.y()-1) {
        m_curOffset.setY( m_curOffset.y() + 1);
    }
    if (m_curPos.y()<m_curOffset.y()) {
        m_curOffset.setY( m_curOffset.y() - 1);
    }


    Redraw();
    qDebug() << timer.elapsed()<< "ms";
}

void FormCopperDataViewer::Redraw()
{
    m_height = window()->height()/36;
    QString text;
    pattern->getText(text,m_curPos,QPoint(0,0));
    QStringList lst = text.split("<tr>");

    QString res = "";
//    qDebug() << std::min(3,lst.count()) << lst;
    for (int i=0;i<std::min(m_height,lst.count());i++) {
        int j = m_curOffset.y() + i;
        if (j<lst.count())
            res+=lst[j]+"<tr>";
    }
    ui->txtData->setText(res);

}
