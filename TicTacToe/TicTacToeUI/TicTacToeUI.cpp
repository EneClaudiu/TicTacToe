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
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_1->setText("O");
    else
        ui.pushButton_1->setText("X");
    game->NextMove({ 0,0 });
    if (game->IsWin({ 0,0 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 0,0 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_2_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_2->setText("O");
    else
        ui.pushButton_2->setText("X");
    game->NextMove({ 0,1 });
    if (game->IsWin({ 0,1 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 0,1 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_3_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_3->setText("O");
    else
        ui.pushButton_3->setText("X");
    game->NextMove({ 0,2 });
    if (game->IsWin({ 0,2 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 0,2 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_4_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_4->setText("O");
    else
        ui.pushButton_4->setText("X");
    game->NextMove({ 1,0 });
    if (game->IsWin({ 1,0 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 1,0 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_5_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_5->setText("O");
    else
        ui.pushButton_5->setText("X");
    game->NextMove({ 1,1 });
    if (game->IsWin({ 1,1 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 1,1 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_6_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_6->setText("O");
    else
        ui.pushButton_6->setText("X");
    game->NextMove({ 1,2 });
    if (game->IsWin({ 1,2 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 1,2 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_7_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_7->setText("O");
    else
        ui.pushButton_7->setText("X");
    game->NextMove({ 2,0 });
    if (game->IsWin({ 2,0 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 2,0 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_8_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_8->setText("O");
    else
        ui.pushButton_8->setText("X");
    game->NextMove({ 2,1 });
    if (game->IsWin({ 2,1 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 2,1 })) {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
}
void TicTacToeUI::on_pushButton_9_clicked() {
    if (QString::fromStdString(game->GetCurrentPlayer()) == player1)
        ui.pushButton_9->setText("O");
    else
        ui.pushButton_9->setText("X");
    game->NextMove({ 2,2 });
    if (game->IsWin({ 2,2 }))
    {
        QMessageBox::information(this, "TicTacToe", QString::fromStdString(game->GetCurrentPlayer()) + " won!");
        ResetGame();
    }
    else if (game->IsDraw({ 2,2 }))
    {
        QMessageBox::information(this, "TicTacToe", "Draw!");
        ResetGame();
    }
    ui.label->setText(QString::fromStdString(game->GetCurrentPlayer()) + "'s turn.");
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
    //QMessageBox::information(this, "Reset", QString::fromStdString(game->GetCurrentPlayer()));

}
