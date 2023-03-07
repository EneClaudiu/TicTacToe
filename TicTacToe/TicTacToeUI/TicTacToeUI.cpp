#include "TicTacToeUI.h"
#include "QMessageBox"

TicTacToeUI::TicTacToeUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->setFixedSize(QSize(600, 400));
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    
    ui.stackedWidget->setCurrentIndex(0);

    player1 = "Player1";
    player2 = "Player2";

}

TicTacToeUI::~TicTacToeUI()
{}

void TicTacToeUI::on_pushButton_player_clicked() {
    if (ui.lineEdit_player1->text() != "")
        player1 = ui.lineEdit_player1->text();
    if(ui.lineEdit_player2->text()!="")
        player2 = ui.lineEdit_player2->text();
    game->SetPlayerNames(player1.toStdString(), player2.toStdString());
    ui.stackedWidget->setCurrentIndex(1);
    
    ui.label->setText("Here will be some info text.");
}

void TicTacToeUI::on_pushButton_1_clicked() {
    QMessageBox::information(this, "Clicked",QString::fromStdString(game->GetCurrentPlayer()));
}
void TicTacToeUI::on_pushButton_2_clicked() {

}
void TicTacToeUI::on_pushButton_3_clicked() {
    
}
void TicTacToeUI::on_pushButton_4_clicked() {

}
void TicTacToeUI::on_pushButton_5_clicked() {
    
}
void TicTacToeUI::on_pushButton_6_clicked() {
    
}
void TicTacToeUI::on_pushButton_7_clicked() {

}
void TicTacToeUI::on_pushButton_8_clicked() {

}
void TicTacToeUI::on_pushButton_9_clicked() {

}


