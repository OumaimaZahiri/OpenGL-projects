#include "Ground.h"
#include <QImage>
#include <QOpenGLFunctions>

Ground::Ground()
{
    zPos=zinit;
    zPos = zPos + 0.5 >= 2. ? -10. : zPos;
}

Ground::~Ground()
{
}

void Ground::Display(uint64_t m_TimeElapsed)
{
    float roadSpeed = (m_TimeElapsed % 10) / 10.;
    float grassSpeed = (m_TimeElapsed % 15) / 15.;
    float barrelSpeed = 0.5;

    shift_=shift_+0.5f;
    shift_=0.5-100.f*floor(0.5/100.f);

    QImage grass = QImage(":/grass.jpg");
    grass = grass.convertToFormat(QImage::Format_RGBA8888);

    QImage road = QImage(":/road.jpg");
    road = road.convertToFormat(QImage::Format_RGBA8888);

    QImage sky = QImage(":/sky.jpg");
    sky = sky.convertToFormat(QImage::Format_RGBA8888);

    QImage barrel = QImage(":/barrel.jpg");
    barrel = barrel.convertToFormat(QImage::Format_RGBA8888);


    GLuint* textures=new GLuint[4];
    glGenTextures(4, textures);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, sky.width(), sky.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, sky.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //Sky
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glTexCoord2f(0,0); glVertex3f(-70, -5, -25);
    glTexCoord2f(0,1); glVertex3f(-70, 100, -25);
    glTexCoord2f(1,1); glVertex3f(70, 100, -25);
    glTexCoord2f(1,0); glVertex3f(70, -5, -25);
    glEnd();

    //Grass
    //glClearColor(0.8f, 196, 236, 1.0);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, grass.width(), grass.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, grass.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
    glColor3ub(86,125,70);
    glTexCoord2f(0, 5 + grassSpeed); glVertex3f(-70, -5, -25);
    glTexCoord2f(0, 0 + grassSpeed); glVertex3f(-70, -5, 8);
    glTexCoord2f(5, 0 + grassSpeed); glVertex3f(70, -5, 8);
    glTexCoord2f(5, 5 + grassSpeed); glVertex3f(70, -5, -25);
    glEnd();

    //Road

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, road.width(), road.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, road.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBegin(GL_QUADS);
    glTexCoord2f(1,10 + roadSpeed); glVertex3f(-8, -4, -21.75);
    glTexCoord2f(1,0 + roadSpeed); glVertex3f(-8, -4, 8);
    glTexCoord2f(0,0 + roadSpeed); glVertex3f(8, -4, 8);
    glTexCoord2f(0,10 + roadSpeed); glVertex3f(8, -4, -21.75);
    glEnd();

    //Fuel
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, barrel.width(), barrel.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, barrel.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    zPos = true ? zPos + barrelSpeed : zPos;

    glPushMatrix();
    GLUquadric* m_barrel = gluNewQuadric();
    gluQuadricOrientation(m_barrel,GLU_OUTSIDE);
    glTranslatef(8, 0,  zPos-15);
    glRotated(90., 1., 0., 0.);
    gluQuadricTexture(m_barrel, GLU_TRUE);
    glRotated(0., barrelSpeed, 0., 0.);
    gluCylinder(m_barrel,1., 1., 4., 40., 40.);
    gluQuadricTexture(m_barrel, GL_FALSE);

    glTranslatef(0.f, 0.f, 3.f);
    gluDisk(m_barrel, 0.0, 1., 30, 1);
    glTranslatef(0.f, 0.f, -3.f);
    gluDisk(m_barrel, 0.0, 1., 30, 1);
    glPopMatrix();

    gluDeleteQuadric(m_barrel);

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);

}
