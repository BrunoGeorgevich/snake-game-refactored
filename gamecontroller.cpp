#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"

GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene)
{
    timer.start( 1000/33 );
    scene.addItem(Food::getInstance());

    scene.addItem(Snake::getInstance());
    scene.installEventFilter(this);

    resume();
}

GameController::~GameController()
{
}

void GameController::snakeAteFood(Snake *snake, Food *food)
{
    scene.removeItem(food);
    delete food;

    addNewFood();
}

void GameController::snakeHitWall(Snake *snake, Wall *wall)
{
}

void GameController::snakeAteItself(Snake *snake)
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
            Snake::getInstance()->setMoveDirection(Snake::MoveLeft);
            break;
        case Qt::Key_Right:
            Snake::getInstance()->setMoveDirection(Snake::MoveRight);
            break;
        case Qt::Key_Up:
            Snake::getInstance()->setMoveDirection(Snake::MoveUp);
            break;
        case Qt::Key_Down:
            Snake::getInstance()->setMoveDirection(Snake::MoveDown);
            break;
    }
}

void GameController::addNewFood()
{
    int x, y;

    do {
        x = (int) (qrand() % 100) / 10;
        y = (int) (qrand() % 100) / 10;

        x *= 10;
        y *= 10;
    } while (Snake::getInstance()->shape().contains(Snake::getInstance()->mapFromScene(QPointF(x + 5, y + 5))));

    scene.addItem(Food::getInstance());
}

void GameController::gameOver()
{
    scene.clear();
    scene.addItem(Snake::getInstance());
    addNewFood();
}

void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               &scene, SLOT(advance()));
}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
