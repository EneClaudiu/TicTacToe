#include "UIGame.h"

UIGame::UIGame(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

UIGame::~UIGame()
{}

void UIGame::on_pushButton_1_clicked() {
    if (currentPlayer)
        ui.pushButton_1->setText("X");
    else
        ui.pushButton_1->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_2_clicked() {
    if (currentPlayer)
        ui.pushButton_2->setText("X");
    else
        ui.pushButton_2->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_3_clicked() {
    if (currentPlayer)
        ui.pushButton_3->setText("X");
    else
        ui.pushButton_3->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_4_clicked() {
    if (currentPlayer)
        ui.pushButton_4->setText("X");
    else
        ui.pushButton_4->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_5_clicked() {
    if (currentPlayer)
        ui.pushButton_5->setText("X");
    else
        ui.pushButton_5->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_6_clicked() {
    if (currentPlayer)
        ui.pushButton_6->setText("X");
    else
        ui.pushButton_6->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_7_clicked() {
    if (currentPlayer)
        ui.pushButton_7->setText("X");
    else
        ui.pushButton_7->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_8_clicked() {
    if (currentPlayer)
        ui.pushButton_8->setText("X");
    else
        ui.pushButton_8->setText("O");
    currentPlayer = !currentPlayer;
}
void UIGame::on_pushButton_9_clicked() {
    if (currentPlayer)
        ui.pushButton_9->setText("X");
    else
        ui.pushButton_9->setText("O");
    currentPlayer = !currentPlayer;
}