/**
  @file QGWindow.h
  @author Corey Taylor, corey@acz.org
  @created 2004-03-07

*/

#ifndef __QGWINDOW_H__AE
#define __QGWINDOW_H__AE

#include <G3DAll.h>

class RenderWindow;

class QGWindow: public GWindow{
public:
	QGWindow(GWindowSettings &settings, QWidget* _parent);
	~QGWindow();
	void getSettings(GWindowSettings &settings) const; 
	int width() const; 
	int height() const; 
	Rect2D dimensions() const; 
	void setDimensions(const Rect2D &dims); 
	void setPosition(int x, int y); 
	bool hasFocus() const; 
	std::string getAPIVersion() const; 
	std::string getAPIName() const; 
	void setGammaRamp(const Array< uint16 > &gammaRamp); 
	void setCaption(const std::string &caption); 
	int numJoysticks() const; 
	Vector2 joystickPosition(int stickNum) const; 
	std::string caption(); 
	void setIcon(const GImage &image); 
	void swapGLBuffers(); 
	void notifyResize(int w, int h); 
	void setRelativeMousePosition(double x, double y); 
	void setRelativeMousePosition(const Vector2 &p); 
	void getRelativeMouseState(Vector2 &position, uint8 &mouseButtons) const; 
	void getRelativeMouseState(int &x, int &y, uint8 &mouseButtons) const; 
	void getRelativeMouseState(double &x, double &y, uint8 &mouseButtons) const; 
	void setMouseCapture(bool c); 
	bool mouseCapture() const; 
	void setMouseVisible(bool b); 
	bool mouseVisible() const; 
	bool inputCapture() const;
	void getJoystickState(unsigned int stickNum, Array<float>& axis, Array<bool>& button);
    void setInputCapture(bool c);
	std::string joystickName(unsigned int sticknum);

private:
	RenderWindow* glWindow;
};

#endif