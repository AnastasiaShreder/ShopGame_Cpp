#include <QApplication>
#include <QScreen>
#include "game.h"

int main(int argc, char *argv[])
{
  srand(time(nullptr));
  QApplication a(argc, argv);
  Game *pGame = new Game();
  pGame->show();
  pGame->Play();
  return a.exec();
}
