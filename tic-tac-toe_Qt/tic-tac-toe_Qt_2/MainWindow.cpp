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

/*
i:j
_________________
|0:0 | 0:1 | 0:2|
|1:0 | 1:1 | 1:2|
|2:0 | 2:1 | 2:2|

*/


/*
void MainWindow::getWinner(){
    //int cur = Game_cells[0][0]->getCurrentMoveNumber();

    int wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},
                       {0,3,6},{1,4,7},{2,5,8},
                       {0,4,8},{2,4,6}         };

    for(int i = 0; i < 8; i++){
        int countX = 0, countO = 0;
        for(int j = 0; j < 3; j++){
            if(Game_cells[wins[i][j]]->getState() == 1) // X?
                countX++;
            else if(Game_cells[wins[i][j]]->getState() == 2) // 0?
                countO++;
            }

        if(countX == 3){
            QMessageBox::information(this, "Result", "Win X", QMessageBox::Ok);
            }
        else if(countO == 3){
            QMessageBox::information(this, "Result", "Win 0", QMessageBox::Ok);
            }
        }

    int cur = Game_cells[0]->getCurrentMoveNumber();
    if(cur >= max_moves){
        QMessageBox::information(this, "Result", "Draw", QMessageBox::Ok);
        }
}
*/
/*
    GAME BOARD (1):
  _________________
  |0:0 | 0:1 | 0:2|
  |1:0 | 1:1 | 1:2|
  |2:0 | 2:1 | 2:2|


    GAME BOARD (2):
    _____________
    | 0 | 1 | 2 |
    | 3 | 4 | 5 |
    | 6 | 7 | 8 |

    HAS WINNERS:
{ {0,1,2},{3,4,5},{6,7,8},
  {0,3,6},{1,4,7},{2,5,8},
  {0,4,8},{2,4,6}         };
*/

/*
нужен слой абстракции от GUI
чтобы где-то имелся объект который может представлять состояние доски
под состоянием доски я подразумеваю состояние каждого ее элемента в отдельности
как ты это сделаешь - тебе решать
тебе нужно как-то получать состояние ВСЕЙ доски

у тебя GUI должен только ПОКАЗЫВАТЬ состояние доски и давать возможность устанавливать значение в ячейке, не вникая в детали
проверкой победителя, проверкой на ошибки должен заниматся отдельный класс
который будет только сообщать есть ли победитель и что куда-то установлено значение

...хм...т.е. главный класс только отрисовывает доску и всё, больше абсолютно ничего, правильно?
и сообщает другому классу что юзер пытается установить значение в клетке

это уже детали реализации
мне на них плевать
я и так уже порядочно уточнил для тебя задачу
и ты теперь можешь мыслить на более низком уровне абстракции
потому что детали я тебе сообщил
а ты должен стремится самостоятельно создавать абстракции высших уровней
*/
