#include "Car.h"
#include <QtOpenGLWidgets/QOpenGLWidget>

Car::Car()
{
    // Initialisation des paramètres
    m_Roue = gluNewQuadric();
}

Car::~Car()
{
    // Destruction de la quadrique
    if(m_Roue)
        gluDeleteQuadric(m_Roue);
}

void Car::Display(uint64_t iTimeElapsed) const
{
    GLfloat colorAmbiante0_tab[]= {0.4, 0.5, 0.3, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante0_tab);

    GLfloat colorDiffuse0_tab[] = {0.2, 0.5, 0.3, 1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse0_tab);


    // Car
    glColor3ub(100, 50, 60);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(x1, -1.f, 0.f);
    glVertex3f(x2, -1.f, 0.f);
    glVertex3f(x2, 1.f, 0.f);
    glVertex3f(x1, 1.f, 0.f);

    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(x1, 1.f, 0.f);
    glVertex3f(x2, 1.f, 0.f);
    glVertex3f(x2, 1.f, -3.f);
    glVertex3f(x1, 1.f, -3.f);

    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(x1, -1.f, 0.f);
    glVertex3f(x2, -1.f, 0.f);
    glVertex3f(x2, -1.f, -3.f);
    glVertex3f(x1, -1.f, -3.f);

    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(x2, 1.f, 0.f);
    glVertex3f(x2, -1.f, 0.f);
    glVertex3f(x2, -1.f, -3.f);
    glVertex3f(x2, 1.f, -3.f);

    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(x1, 1.f, 0.f);
    glVertex3f(x1, -1.f, 0.f);
    glVertex3f(x1, -1.f, -3.f);
    glVertex3f(x1, 1.f, -3.f);

    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(x1, -1.f, -3.f);
    glVertex3f(x2, -1.f, -3.f);
    glVertex3f(x2, 1.f, -3.f);
    glVertex3f(x1, 1.f, -3.f);
    glEnd();

    GLfloat colorAmbiante1_tab[]= {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, colorAmbiante1_tab);

    GLfloat colorDiffuse1_tab[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, colorDiffuse1_tab);

    // Wheels
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(x2, -1.f, -0.5f);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    glTranslatef(0.f, 0.f, 0.3f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x1-0.3f, -1.f, -0.5f);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x2, -1.f, -2.5f);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    glTranslatef(0.f, 0.f, 0.3f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x1-0.3f, -1.f, -2.5f);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

}


