#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

//void Score::increase()
//{
//  m_nScore += 10;
//  setPlainText(QString("Score : ") + QString::number(m_nScore));
//}
int Score::getScore(){
    return score;
}
