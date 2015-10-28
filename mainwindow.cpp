#include <QGraphicsView>
#include <QTimer>

#include "constants.h"
#include "mainwindow.h"
#include "snake.h"
#include "food.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      timer(new QTimer())
{
    setCentralWidget(view);
    resize(600, 600);

    initScene();
    initSceneBackground();

    scene->addItem(Food::getInstance());
    scene->addItem(Snake::getInstance());

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));

    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start( 1000/33 );
}

void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    view->setBackgroundBrush(QBrush(bg));
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->type() == QEvent::KeyPress)
        Snake::getInstance()->notifyObservers(e);
}
