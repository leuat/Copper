#ifndef COPPERBROWSER_H
#define COPPERBROWSER_H

#include <QTextBrowser>
#include <QKeyEvent>

class CopperBrowser : public QTextBrowser
{
public:
    CopperBrowser();
    CopperBrowser(QWidget* w):QTextBrowser(w) {
    }

    //void keyPressEvent(QKeyEvent *e) override {
//    }

};

#endif // COPPERBROWSER_H
