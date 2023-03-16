#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>

#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addNewTask();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewTask()
{
    QGridLayout *layout = new QGridLayout();
    layout->setSpacing(0);
    bool tableShow = true;

    QPushButton *taskButton = new QPushButton("-");
    taskButton->setMaximumHeight(36);
    taskButton->setMaximumWidth(36);

    QTableWidget *taskTable = new QTableWidget(2, 5);
    connect(taskButton, &QPushButton::clicked, [this, taskTable, &tableShow, taskButton] () {
        tableShow = !tableShow;
        if(tableShow) {
            taskButton->setText("+");
            for (int row = 1; row < taskTable->rowCount(); ++row) {
                taskTable->hideRow(row);
            }
        } else {
            taskButton->setText("-");
            for (int row = 1; row < taskTable->rowCount(); ++row) {
                taskTable->showRow(row);
            }
        }
    });
    layout->addWidget(taskButton, 0, 0, 1, 1);
    layout->addWidget(taskTable, 0, 1, 2, 1);
    ui->verticalLayout->addLayout(layout);
}

