#include "Car.h"
#include "Ground.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QElapsedTimer>


// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
public:

    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);


protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    void keyPressEvent(QKeyEvent* keyEvent);


private:
    Car* maVoiture = nullptr;
    Ground* myGround = nullptr;
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
    QElapsedTimer * timer;
};
