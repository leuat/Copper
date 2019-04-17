#ifndef FORMCOPPERDATAVIEWER_H
#define FORMCOPPERDATAVIEWER_H

#include <QWidget>
#include "source/base/copperdatafactory.h"

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

private:
    CopperData* pattern;
    Ui::FormCopperDataViewer *ui;
};

#endif // FORMCOPPERDATAVIEWER_H
