#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

private slots:
    void adjustViewSize();

private:
    void initScene();
    void initSceneBackground();

    void keyPressEvent(QKeyEvent *e);

    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
};

#endif // MAINWINDOW_H
