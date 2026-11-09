/**
 @file GlutWindow.h
 @author Morgan McGuire and Dan Keefe
 */
#ifndef GLUTWINDOW_H
#define GLUTWINDOW_H

#include <G3DAll.h>


#define GLUT_API_VERSION 4
#include <GL/glut.h>



/**
 GWindow that uses the glut API http://www.opengl.org/resources/libraries/glut/spec3/spec3.html.

  Not supported by GlutWindow:
  <UL>
   <LI> Joysticks
   <LI> Gamma ramp
   <LI> Window Icons
   <LI> Input capture
  </UL>

 Additionally, Glut does not support all keystrokes (e.g. the key-down event for a modifier
 cannot be detected, scan-codes are not available) so GlutWindow fails to report some keyboard
 events.

 @cite Glut by Mark Kilgard, ported to Windows by Nate Robbins
 */
// The public API of this implementation allows only one window because it does
// not provide a mechanism for switching active windows/contexts.  However,
// internally it has been coded so that this will be a simple change.
class GlutWindow : public GWindow {
private:

    /** Has glutInit been called? (only allowed once per program)*/
    static bool             glutInitialized;

    /** Underlying glut window handle */
    int                     glutWindowHandle;

    bool                    _mouseVisible;

    std::string             _windowTitle;

    Rect2D                  _dimensions;

    GWindowSettings         settings;

    Queue<GEvent>           eventQueue;

    Vector2                 mouse;

    uint8                   mouseButtons;

    /** Where to send GLUT events */
    static GlutWindow*      currentGlutWindow;

    /** Adds an event to the queue-- is synchronized! */
    void postEvent(GEvent& evt);

    // Glut callbacks:
    static void g_reshape(int width, int height);
    static void g_keyboard(unsigned char c, int x, int y);
    static void g_keyboardspecial(int key, int x, int y);
    static void g_keyboardup(unsigned char c, int x, int y);
    static void g_keyboardspecialup(int key, int x, int y);
    static void g_mousemotion(int x, int y);
    static void g_mousebtn(int b, int s, int x, int y);
    static void g_draw();

public:

    GlutWindow(const GWindowSettings& s);
    virtual ~GlutWindow();
    virtual void getSettings(GWindowSettings& settings) const;
    virtual int width() const;
    virtual int height() const;
    virtual Rect2D dimensions() const;
    virtual void setDimensions(const Rect2D& dims);
    virtual void setPosition(int x, int y);
    virtual bool hasFocus() const;
    virtual std::string getAPIVersion() const;
    virtual std::string getAPIName() const;
    virtual void setGammaRamp(const Array<uint16>& gammaRamp);
    virtual void setCaption(const std::string& caption);
    virtual int numJoysticks() const;
    virtual std::string joystickName(unsigned int sticknum);
    virtual std::string caption();
    virtual void setIcon(const GImage& image);
    virtual void swapGLBuffers();
    virtual void notifyResize(int w, int h);
    virtual bool pollEvent(GEvent& e);

    virtual bool requiresMainLoop() const {
        return true;
    }

    virtual void runMainLoop();
    virtual void setRelativeMousePosition(double x, double y);
    virtual void setRelativeMousePosition(const Vector2& p);
    virtual void getRelativeMouseState(Vector2& position, uint8& mouseButtons) const;
    virtual void getRelativeMouseState(int& x, int& y, uint8& mouseButtons) const;
    virtual void getRelativeMouseState(double& x, double& y, uint8& mouseButtons) const;
    virtual void getJoystickState(unsigned int stickNum, Array<float>& axis, Array<bool>& button);
    virtual void setInputCapture(bool c);
    virtual bool inputCapture() const;
    virtual void setMouseVisible(bool b);
    virtual bool mouseVisible() const;
};


#endif
