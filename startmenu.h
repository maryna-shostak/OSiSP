#ifndef STARTMENU_H
#define STARTMENU_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class StartMenu : public QWidget
{
    Q_OBJECT  
public:
    StartMenu();
    QLabel *win_text;
    QLabel *lose_text;
    QGridLayout *grid;
public slots:
    void StartEvent();
    void ExitEvent();
    void WinEvent();
    void LoseEvent();
};

#endif // STARTMENU_H
