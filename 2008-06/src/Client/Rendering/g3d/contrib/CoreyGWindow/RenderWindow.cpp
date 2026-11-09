/**
  @file RenderWindow.cpp
  @author Corey Taylor, corey@acz.org
  @created 2004-03-07

*/

#include <G3DAll.h>
#include "RenderWindow.h"

/* test sample
extern Log* debugLog;
extern RenderDevice* renderDevice;
extern GFontRef gfont;
extern UserInput* userInput;
extern GCamera* camera;
extern ManualCameraController* controller;
*/

RenderWindow::RenderWindow( const QGLFormat & format, QWidget* parent, const char* name, const QGLWidget* shareWidget, WFlags f)
:QGLWidget(format, parent, name, shareWidget, f)
{
	//setup paint timer with 0-wait somewhere
}

void RenderWindow::repaintGL()
{
/* test sample
    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    renderDevice->beginFrame();
      // Cyan background
	    glClearColor(0.1f, 0.5f, 1.0f, 0.0f);

        renderDevice->clear(true, true, true);
        renderDevice->pushState();

            renderDevice->setProjectionAndCameraMatrix(*camera);
        
            // Setup lighting
            renderDevice->enableLighting();

            renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));

            renderDevice->setAmbientLightColor(lighting.ambient);

            Draw::axes(renderDevice);

            renderDevice->disableLighting();
           
			renderDevice->push2D();
            std::string s = G3D::format("%d fps", iRound(renderDevice->getFrameRate()));
            gfont->draw2D(s, Vector2(10, 10));
			renderDevice->pop2D();

        renderDevice->popState();
	    
    renderDevice->endFrame();
*/
}