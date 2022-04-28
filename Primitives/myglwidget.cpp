#include "myglwidget.h"
#include <GL/glu.h>
#include <QApplication>
#include <QtOpenGLWidgets/QOpenGLWidget>

// Declarations des constantes
const unsigned int WIN_WIDTH_HEIGHT = 900;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH_HEIGHT, WIN_WIDTH_HEIGHT);
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r, g, b, 1.0);
}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);
}


// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation du tampon de couleur
    glClearColor(r, g, b, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Reinitialisation de la matrice courante
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, 2.0f, 10.0f);

    // Affichage des primitives
    glColor3ub(r1,g1,b1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(rot, 0., 0., 1.);
    if (form=="triangle")
    {
        glBegin(GL_TRIANGLES);
        glVertex3f(-0.25f, 0.0f, -4);
        glColor3ub(r2,g2,b2);
        glVertex3f(0.0f, 0.5f, -4);
        glColor3ub(r3,g3,b3);
        glVertex3f(0.25f, 0.0f, -4);
    }
    else if(form=="square")
    {
        glBegin(GL_QUADS);
        glVertex3f(-0.25f, -0.25f, -4);
        glVertex3f(-0.25f, 0.25f, -4);
        glColor3ub(r2,g2,b2);
        glVertex3f(0.25f, 0.25f, -4);
        glVertex3f(0.25f, -0.25f, -4);
    }
    else
    {
        glBegin(GL_POLYGON);
        glVertex3f(0.0f, -0.5f, -4);
        glVertex3f(-0.25f, -0.25f, -4);
        glVertex3f(-0.25f, 0.25f, -4);
        glColor3ub(r2,g2,b2);
        glVertex3f(0.0f, 0.5f, -4);
        glVertex3f(0.25f, 0.25f, -4);
        glColor3ub(r3,g3,b3);
        glVertex3f(0.25f, -0.25f, -4);
    }


    glEnd();
}

void MyGLWidget::keyPressEvent(QKeyEvent* keyEvent)
{
    switch (keyEvent->key())
    {
        case Qt::Key_C:
            r=float(rand())/RAND_MAX;
            g=float(rand())/RAND_MAX;
            b=float(rand())/RAND_MAX;
            this->update();
        break;
        case Qt::Key_O:
            r1=rand()%256;
            g1=rand()%256;
            b1=rand()%256;
            r2=rand()%256;
            g2=rand()%256;
            b2=rand()%256;
            r3=rand()%256;
            g3=rand()%256;
            b3=rand()%256;
            this->update();
        break;
        case Qt::Key_R:
            rot=rand()%360;
            this->update();
        break;
        case Qt::Key_Space:
            if (form=="triangle")
                form="square";
            else if (form=="square")
                form="polygon";
            else if (form=="polygon")
                form="triangle";
            this->update();
        break;

    }
}
