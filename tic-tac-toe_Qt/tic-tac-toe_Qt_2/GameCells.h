#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QLabel>
#include <QPixmap>

class GameCells : public QLabel
{
    Q_OBJECT

public:
    explicit GameCells(QLabel *parent = 0);

    int getState() const;
    void setState(int st);

    int getCurrentMoveNumber() const;
    void setMaxMoveNumber(int max_num);

private:
    QPixmap gc_pixmap[3]; // 0-empty; 1-X; 2-0
    int gc_state;
    static unsigned short gc_current_move_number, gc_max_move_number;

signals:
    void gameCellsClicked();

public slots:
    void slotGameCellsClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // GAMECELLS_H
