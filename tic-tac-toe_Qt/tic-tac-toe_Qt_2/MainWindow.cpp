#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    main_layout = new QGridLayout(this);

    // make game board [ROWSxCOLUMNS]
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            Game_cells[i][j] = new GameCells();

            connect(Game_cells[i][j], SIGNAL(gameCellClicked()), this, SLOT(getWinner()));
            main_layout->addWidget(Game_cells[i][j], i, j);
            }
        }

    Game_cells[0][0]->setMaxMoveNumber(max_move);

    this->setLayout(main_layout);
    this->setWindowTitle("tic-tac-toe");
}
unsigned short MainWindow::max_move = ROWS * COLUMNS;

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

        if(countX == ROWS)
            gameResult("Win X");
        else if(countO == ROWS)
            gameResult("Win 0");
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

        if(countX == ROWS)
            gameResult("Win X");
        else if(countO == ROWS)
            gameResult("Win 0");
        }

    // check diagonal
    int countX = 0, countO = 0;
    for(int i = 0, j = 0; i < ROWS; i++, j++){
        if(Game_cells[j][i]->getState() == 1) // X?
            countX++;
        else if(Game_cells[j][i]->getState() == 2) // 0?
            countO++;

        if(countX == ROWS)
            gameResult("Win X");
        else if(countO == ROWS)
            gameResult("Win 0");
    }

    // draw?
    int cur = Game_cells[0][0]->getCurrentMoveNumber();
    if(cur >= max_move)
        gameResult("Draw");
}

void MainWindow::gameResult(const QString winner){
    int r = QMessageBox::information(this, "Result", winner + "\nDo you want play again?",
                                     QMessageBox::Yes | QMessageBox::No);
    if(r == QMessageBox::Yes){
        for(int i = 0; i < ROWS; i++)
            for(int j = 0; j < COLUMNS; j++)
                Game_cells[i][j]->setState(0);

        Game_cells[0][0]->setCurrentMoveNumber(0);
        }
    else
        qApp->exit(0);
}
