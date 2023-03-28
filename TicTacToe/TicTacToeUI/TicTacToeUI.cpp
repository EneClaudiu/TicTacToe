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
    
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}

void TicTacToeUI::on_pushButton_1_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_2_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_3_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_4_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_5_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_6_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_7_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_8_clicked() {
    GameButtonClicked();
}
void TicTacToeUI::on_pushButton_9_clicked() {
    GameButtonClicked();
}

void TicTacToeUI::ResetGame() {
    game->ResetGame();

    ui.pushButton_1->setText("");
    ui.pushButton_2->setText("");
    ui.pushButton_3->setText("");
    ui.pushButton_4->setText("");
    ui.pushButton_5->setText("");
    ui.pushButton_6->setText("");
    ui.pushButton_7->setText("");
    ui.pushButton_8->setText("");
    ui.pushButton_9->setText("");

    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}

void  TicTacToeUI::GameButtonClicked(){
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        int buttonNumber = button->objectName().right(1).toInt();
        int buttonRow = (buttonNumber - 1) / 3;
        int buttonColumn = (buttonNumber - 1) % 3;

        if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
            button->setText("O");
        else
            button->setText("X");

        game->NextMove({ buttonRow,buttonColumn });

        if (game->IsWin({ buttonRow,buttonColumn }))
        {
            QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
            ResetGame();
        }
        else if (game->IsDraw({ buttonRow,buttonColumn }))
        {
            QMessageBox::information(this, "TicTacToe", "Draw!");
            ResetGame();
        }
        ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
    }
}