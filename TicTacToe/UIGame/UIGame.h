#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UIGame.h"

class UIGame : public QMainWindow
{
    Q_OBJECT

public:
    UIGame(QWidget *parent = nullptr);
    ~UIGame();

private:
    Ui::UIGameClass ui;
    bool currentPlayer = false;
private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
};
