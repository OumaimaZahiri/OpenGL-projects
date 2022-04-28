#include "myglwidget.h"
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <QTimer>


// Declarations des constantes
const unsigned int WIN = 900;

// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN, WIN);

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f;
        update();
    });

    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    myGround = new Ground();
    maVoiture = new Car();


    timer = new QElapsedTimer();
    timer->start();

}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
       glFrustum(-5, 5, -5, 5, 2, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la position de la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 4.f, 4.f, 0.0f, 0.0f, 0.f, 0.0f, 1.0f, 0.0f);

    GLfloat colorAmbiante_tab[]= {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, colorAmbiante_tab);

    GLfloat colorDiffuse_tab[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, colorDiffuse_tab);

    GLfloat light_tab[] = {0.0, 4.f, -26.f, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_tab);


    GLfloat colorAmbiante_tab1[]= {0.2, 0.2, 0.2, 1.0};
    glLightfv(GL_LIGHT1, GL_AMBIENT, colorAmbiante_tab1);

    GLfloat colorDiffuse_tab1[] = {0.8, 0.8, 0.8, 1.0};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, colorDiffuse_tab1);

    GLfloat light_tab1[] = {0.0, 4.f, 26.f, 1.0};
    glLightfv(GL_LIGHT1, GL_POSITION, light_tab1);

    glEnable(GL_TEXTURE_2D);

    // Affichage du background
    glDisable(GL_LIGHTING);
    glPushMatrix();
    myGround->Display(m_TimeElapsed);
    glPopMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);


    // Affichage de la voiture
    glPushMatrix();
    maVoiture->Display(m_TimeElapsed);
    glPopMatrix();
}

void MyGLWidget::keyPressEvent(QKeyEvent* keyEvent)
{
    switch (keyEvent->key())
    {
        case Qt::Key_Left:
        if (maVoiture->x1==-1)
        {
            maVoiture->x1=-4.f;
            maVoiture->x2=-2.f;
        }
        else if(maVoiture->x1==2.f)
        {
            maVoiture->x1=-1.f;
            maVoiture->x2=1.f;
        }
            this->update();
        break;
        case Qt::Key_Right:
        if (maVoiture->x1==-1)
        {
            maVoiture->x1=2.f;
            maVoiture->x2=4.f;
        }
        else if(maVoiture->x1==-4.f)
        {
            maVoiture->x1=-1.f;
            maVoiture->x2=1.f;
        }
            this->update();
        break;
        case Qt::Key_Up:
        break;
        case Qt::Key_Down:
        break;
    }
}
