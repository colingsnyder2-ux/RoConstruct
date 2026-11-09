/**
  @file RenderWindow.h
  @author Corey Taylor, corey@acz.org
  @created 2004-03-07

*/

#ifndef __RENDER_WINDOW_H__AE
#define __RENDER_WINDOW_H__AE

#include <qgl.h>

class RenderWindow: public QGLWidget{
Q_OBJECT

public:
	RenderWindow(const QGLFormat& format, QWidget* parent=0, const char* name=0, const QGLWidget* shareWidget = 0, WFlags f=0);
protected slots:
	void repaintGL();


};

#endif