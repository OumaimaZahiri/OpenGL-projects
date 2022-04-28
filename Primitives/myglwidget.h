#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>


// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);
    float r=0.85f;
    float g=0.85f;
    float b=0.85f;

    int r1=0;
    int g1=0;
    int b1=200;

    int r2=0;
    int g2=0;
    int b2=200;

    int r3=0;
    int g3=0;
    int b3=200;
    float t1=1.0f;

    int rot=0;

    std::string form="triangle";

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction listener
    void keyPressEvent(QKeyEvent* keyEvent);
};

#endif // MYGLWIDGET_H
