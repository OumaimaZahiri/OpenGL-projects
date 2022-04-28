#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QKeyEvent>

// Classe dediee pour la gestion de la voiture
class Car
{
public:
    // Constructeur avec parametres
    Car();

    // Destructeur
    ~Car();

    // Methode d'affichage
    void Display(uint64_t iTimeElapsed) const;

    double x1=-1.f;
    double x2=1.f;
private:
    GLUquadric * m_Roue { nullptr };
};
