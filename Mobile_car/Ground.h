#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <QImage>
#include <QWidget>
#include <QObject>

// Classe dediee pour la gestion du sol
class Ground
{
public:
    // Constructeur avec parametres
    Ground();

    // Destructeur
    ~Ground();

    // Methode d'affichage
    void Display(uint64_t m_TimeElapsed);

    double x1 = -7;
    double x2 = -6;
    double x3 = 6;
    double x4 = 7;

    double z11 = 4;
    double z12 = 8;

    double z21 = z11 - 4;
    double z22 = z21 - 4;

    double z31 = z21 - 4;
    double z32 = z31 - 4;

    double z41 = z31 - 4;
    double z42 = z41 - 4;

    double z51 = z41 - 4;
    double z52 = -21.75;

    double zinit=-8;
    double zPos;

    float shift_=0.f;
};
