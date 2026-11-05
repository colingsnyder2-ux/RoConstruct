/**
  @file QGWindow.h
  @author Corey Taylor, corey@acz.org
  @created 2004-03-07

*/

#include <qgl.h>

#include "QGWindow.h"
#include "RenderWindow.h"

QGWindow::QGWindow(GWindowSettings &settings, QWidget* _parent)
{
	QGLFormat format;
	format.setDoubleBuffer(true);
	format.setRgba(true);
	format.setDirectRendering(true);
	if( settings.depthBits > 0 ) format.setDepth(true);
	if( settings.alphaBits > 0 ) format.setAlpha(true);
	if( settings.stereo ) format.setStereo(true);
	if( settings.stencilBits > 0 ) format.setStencil(true);
	glWindow = new RenderWindow(format, _parent);
	glWindow->resize( settings.width, settings.height);
	glWindow->show();
}


QGWindow::~QGWindow()
{
	delete glWindow;
}


void QGWindow::getSettings(GWindowSettings &settings) const
{
	//is there a way to map true/false to values correctly?
	//do we need to do it manually from win32?  there's no guarantee anything will match.
}


int QGWindow::width() const
{
	return glWindow->width();
}


int QGWindow::height() const
{
	return glWindow->height();
}


Rect2D QGWindow::dimensions() const
{
	return Rect2D::xywh(0, 0, glWindow->width(), glWindow->height());
}


void QGWindow::setDimensions(const Rect2D &dims)
{
	glWindow->setGeometry(dims.x0(), dims.y0(), dims.width(), dims.height());
}


void QGWindow::setPosition(int x, int y)
{
	glWindow->move(x, y);
}


bool QGWindow::hasFocus() const
{
	return true;
}


std::string QGWindow::getAPIVersion() const
{
	return std::string("No name");
}


std::string QGWindow::getAPIName() const
{
	return std::string("No name");
}


void QGWindow::setGammaRamp(const Array< uint16 > &gammaRamp)
{
}


void QGWindow::setCaption(const std::string &caption)
{
	glWindow->setCaption(caption.c_str());
}


int QGWindow::numJoysticks() const
{
	return 0;
}


Vector2 QGWindow::joystickPosition(int stickNum) const
{
	return Vector2(0, 0);
}


std::string QGWindow::caption()
{
	return glWindow->caption();
}


void QGWindow::setIcon(const GImage &image)
{
//	Don't know if len is accurate from width*height*channels
//	QPixmap icon_tmp;
//	icon_tmp.loadFromData(image.byte(), image.width*image.height*image.channels); 
//	glWindow->setIcon(icon_tmp);
}


void QGWindow::swapGLBuffers()
{
	glWindow->swapBuffers();
}


void QGWindow::notifyResize(int w, int h)
{
	//needed?
}


void QGWindow::setRelativeMousePosition(double x, double y)
{
	//no known impl yet
}


void QGWindow::setRelativeMousePosition(const Vector2 &p)
{
	//no known impl yet
}


void QGWindow::getRelativeMouseState(Vector2 &position, uint8 &mouseButtons) const
{
	//no known impl yet
}


void QGWindow::getRelativeMouseState(int &x, int &y, uint8 &mouseButtons) const
{
	//no known impl yet
}


void QGWindow::getRelativeMouseState(double &x, double &y, uint8 &mouseButtons) const
{
	//no known impl yet
}


void QGWindow::setMouseCapture(bool c)
{
	if( c )
		glWindow->grabMouse();
	else
		glWindow->releaseMouse();
}


bool QGWindow::mouseCapture() const
{
	if( QWidget::mouseGrabber() == glWindow )
		return true;
	else
		return false;
}


void QGWindow::setMouseVisible(bool b)
{
	if( b )
		glWindow->show();
	else
		glWindow->hide();
}


bool QGWindow::mouseVisible() const
{
	if( mouseCapture() )
		return false;
	else
		return true;
}

bool QGWindow::inputCapture() const
{
	if( QWidget::keyboardGrabber() == glWindow )
		return true;
	else
		return false;
}

void QGWindow::getJoystickState(unsigned int stickNum, Array<float>& axis, Array<bool>& button)
{
}

void QGWindow::setInputCapture(bool c)
{
	if( c )
		glWindow->grabKeyboard();
	else
		glWindow->releaseKeyboard();
}

std::string QGWindow::joystickName(unsigned int sticknum)
{
	return std::string("");
}


