#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    main_layout = new QGridLayout(this);

    // make game board [ROWS x COLUMNS]
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            Game_cells[i][j] = new GameCells();
            //Game_cells[i][j]->setObjectName("pos_" + QString("%1").arg(i) + "_" + QString("%1").arg(j));

            connect(Game_cells[i][j], SIGNAL(gameCellsClicked()), this, SLOT(getWinner()));
            main_layout->addWidget(Game_cells[i][j], i, j);
            }
        }

    Game_cells[0][0]->setMaxMoveNumber(max_moves);

    this->setLayout(main_layout);
    this->setWindowTitle("tic-tac-toe_2");
}
unsigned short MainWindow::max_moves = ROWS * COLUMNS;
bool MainWindow::game_over = false;

MainWindow::~MainWindow(){ }

void MainWindow::getWinner(){
    // check horizontal
    for(int i = 0; i < ROWS; i++){
        int countX = 0, countO = 0;
        for(int j = 0; j < COLUMNS; j++){
            if(Game_cells[i][j]->getState() == 1) // X?
                countX++;
            else if(Game_cells[i][j]->getState() == 2) // 0?
                countO++;
            }

        if(countX == ROWS){
            QMessageBox::information(this, "Result", "Win X", QMessageBox::Ok);
            game_over = true;
            }
        else if(countO == ROWS){
            QMessageBox::information(this, "Result", "Win 0", QMessageBox::Ok);
            game_over = true;
            }
        }

    // check vertical
    for(int i = 0; i < ROWS; i++){
        int countX = 0, countO = 0;
        for(int j = 0; j < COLUMNS; j++){
            if(Game_cells[j][i]->getState() == 1) // X?
                countX++;
            else if(Game_cells[j][i]->getState() == 2) // 0?
                countO++;
            }

        if(countX == ROWS){
            QMessageBox::information(this, "Result", "Win X", QMessageBox::Ok);
            game_over = true;
            }
        else if(countO == ROWS){
            QMessageBox::information(this, "Result", "Win 0", QMessageBox::Ok);
            game_over = true;
            }
        }

    // check diagonal
    int countX = 0, countO = 0;
    for(int i = 0, j = 0; i < ROWS; i++, j++){
        if(Game_cells[j][i]->getState() == 1) // X?
            countX++;
        else if(Game_cells[j][i]->getState() == 2) // 0?
            countO++;

    if(countX == ROWS){
        QMessageBox::information(this, "Result", "Win X", QMessageBox::Ok);
        game_over = true;
        }
    else if(countO == ROWS){
        QMessageBox::information(this, "Result", "Win 0", QMessageBox::Ok);
        game_over = true;
        }
    }

    // draw?
    int cur = Game_cells[0][0]->getCurrentMoveNumber();
    if(cur >= max_moves){
        QMessageBox::information(this, "Result", "Draw", QMessageBox::Ok);
        game_over = true;
        }

    // if game over, block board
    blockBoard(game_over);
}

void MainWindow::blockBoard(const bool block){
    if(block){
        for(int i = 0; i < ROWS; i++)
            for(int j = 0; j < COLUMNS; j++){
                Game_cells[i][j]->blockSignals(block);
                }
        }
}
