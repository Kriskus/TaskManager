#ifndef TASKTABLEWIDGET_H
#define TASKTABLEWIDGET_H

#include <QTableWidget>

class TaskTableWidget : public QTableWidget
{
public:
    TaskTableWidget();

public slots:
    void hideSubTask();
    void showSubTask();

    bool checkTask();
    bool checkSubTask();
    bool checkPriority();
    bool checkStatus();
    bool checkType();

private slots:

};

#endif // TASKTABLEWIDGET_H
