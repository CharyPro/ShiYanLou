#ifndef STARS_H
#define STARS_H

#include <GL/glut.h>

class Star
{
public:
    Star(GLfloat radius, GLfloat distance, GLfloat speed,
         GLfloat selfSpeed, Star* parentStar);

    GLfloat radius;
    GLfloat speed, selfSpeed;
    GLfloat distance;
    GLfloat rgbaColor[4];

    Star* parentStar;

    void drawStar();
    virtual void draw(){ drawStar(); }
    virtual void update(long timeSpan);

protected:
    GLfloat alphaSelf, alpha;
};

class Planet : public Star
{
public:
    Planet(GLfloat radius, GLfloat distance, GLfloat speed,
           GLfloat selfSpeed, Star* parentStar, GLfloat rgbColor[3]);
    void drawPlanet();

    virtual void draw()
    {
        drawPlanet();
        drawStar();
    }
};

class LightPlanet : public Planet {
public:
    LightPlanet(GLfloat Radius, GLfloat Distance,
                GLfloat Speed,  GLfloat SelfSpeed,
                Star* ParentStar, GLfloat rgbColor[]);
    // 增加对提供光源的恒星绘制光照
    void drawLight();
    virtual void draw() { drawLight(); drawPlanet(); drawStar(); }
};
#endif // STARS_H
