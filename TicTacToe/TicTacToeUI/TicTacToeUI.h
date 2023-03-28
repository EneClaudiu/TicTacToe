#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TicTacToeUI.h"
#include "ITicTacToe.h"

class TicTacToeUI : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToeUI(QWidget *parent = nullptr);
    ~TicTacToeUI();

private:
    Ui::TicTacToeUIClass ui;
    QString player1;
    QString player2;

    ITicTacToePtr game = ITicTacToe::Produce(ETicTacToeGameType::Impl1);

    void ResetGame();
    void GameButtonClicked();
private slots:
    void on_pushButton_player_clicked();
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
