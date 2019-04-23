#ifndef FORMCOPPERDATAVIEWER_H
#define FORMCOPPERDATAVIEWER_H

#include <QWidget>
#include "source/base/copperdatafactory.h"
#include <QPoint>
#include <QKeyEvent>
namespace Ui {
class FormCopperDataViewer;
}

class FormCopperDataViewer : public QWidget
{
    Q_OBJECT

public:
    explicit FormCopperDataViewer(QWidget *parent = nullptr);
    void Init(int voices, int data, int rows);
    ~FormCopperDataViewer();

    void keyPressEvent(QKeyEvent *e) override;

    void Redraw();

private:
    QPoint m_curPos;
    QPoint m_curOffset = QPoint(0,0);
    int m_height;
    CopperData* pattern;
    Ui::FormCopperDataViewer *ui;
};

#endif // FORMCOPPERDATAVIEWER_H
