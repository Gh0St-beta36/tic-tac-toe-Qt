#ifndef GAMECELLS_H
#define GAMECELLS_H

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
    void setCurrentMoveNumber(const unsigned short move_number);
    void setMaxMoveNumber(int max_num);

private:
    QPixmap gc_pixmap[3]; // 0-empty; 1-X; 2-0
    int gc_state;
    static unsigned short gc_current_move_number, gc_max_move_number;

signals:
    void gameCellClicked();

public slots:
    void slotgameCellClicked();

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // GAMECELLS_H
