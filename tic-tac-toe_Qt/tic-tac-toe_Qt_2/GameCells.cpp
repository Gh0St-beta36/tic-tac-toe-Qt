#include "GameCells.h"

GameCells::GameCells(QLabel *parent) :
    QLabel(parent)
{
    gc_pixmap[0].load("images/empty.jpg");
    gc_pixmap[1].load("images/X.jpg");
    gc_pixmap[2].load("images/0.jpg");
    this->setState(0);

    connect(this, SIGNAL(gameCellsClicked()), this, SLOT(slotGameCellsClicked()));
}
unsigned short GameCells::gc_current_move_number = 0;
unsigned short GameCells::gc_max_move_number = 0;

int GameCells::getState()const { return this->gc_state; }

void GameCells::setState(int st){
    if(st > 3 || st < 0)
        st = 0;

    this->gc_state = st;
    this->setPixmap(gc_pixmap[st]);
}

int GameCells::getCurrentMoveNumber()const { return this->gc_current_move_number; }
void GameCells::setMaxMoveNumber(int max_num){ this->gc_max_move_number = max_num; }

void GameCells::mousePressEvent(QMouseEvent *event){
    emit gameCellsClicked();
}

void GameCells::slotGameCellsClicked(){
    if(gc_current_move_number % 2 == 0){ // if now move 'X'
        if(this->getState() == 0){ // if this cell is empty
            this->setState(1); // set 'X'
            ++gc_current_move_number;
            }
        }
    else{ // else move '0'
        if(this->getState() == 0){ // if this cell is empty
            this->setState(2); // set '0'
            ++gc_current_move_number;
            }
        }
}
