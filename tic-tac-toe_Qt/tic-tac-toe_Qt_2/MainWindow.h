#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "GameCells.h"

#define ROWS 3
#define COLUMNS 3

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGridLayout *main_layout;

    GameCells *Game_cells[ROWS][COLUMNS];
    static unsigned short max_moves;
    static bool game_over;

public slots:
    void getWinner();
    void blockBoard(const bool block);
};

#endif // MAINWINDOW_H
