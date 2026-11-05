/**
  Binding to allow G3D within wxWindows 2.6.2.

  You must have already installed wxWindows for your platform and
  compiled it with OpenGL bindings:

    "To switch wxGLCanvas support on under Windows, edit setup.h 
     and set wxUSE_GLCANVAS to 1... on Unix, pass --with-opengl 
     to configure to compile using OpenGL or Mesa."

  <b>Including this file automatically links against all necessary
  files on Windows.</B>

  Include this before including G3D, and at the top of all your source files.

  @maintainer Morgan McGuire, matrix@graphics3d.com
  @created 2004-10-02
  @edited  2006-01-04
 */
#ifndef G3D_wxGWindow_H
#define G3D_wxGWindow_H

#define NO_SDL_MAIN
#include <G3DAll.h>

// Link against wxWindows
#ifdef G3D_WIN32
    #if defined(_DEBUG) && !defined(G3D_DEBUGRELEASE)
        #pragma comment(lib, "wxbase26d.lib")
        #pragma comment(lib, "wxmsw26d_core.lib")
        #pragma comment(lib, "wxmsw26d_gl.lib")
    #else
        #pragma comment(lib, "wxbase26.lib")
        #pragma comment(lib, "wxmsw26_core.lib")
        #pragma comment(lib, "wxmsw26_gl.lib")
    #endif

    #pragma comment(lib, "rpcrt4.lib")
    #pragma comment(lib, "comctl32.lib")
#endif

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation
#pragma interface
#endif

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/log.h"

#if !wxUSE_GLCANVAS
#error Please set wxUSE_GLCANVAS to 1 in setup.h.
#endif

#include "wx/glcanvas.h"
#include "wx/chkconf.h"

// Defined for wxGWindow
class wxG3DCanvas;

/** wxWindows implementation of G3D::GWindow.  Can either wrap an 
    existing wxGLCanvas so that it can be used with RenderDevice
    or create the wxGLCanvas for you from GWindowSettings.  */
class wxGWindow : public GWindow {
private:
    /**
     @param attribList  NULL terminated wxGLCanvas attribute list
     */
    static void makeAttribList(
        const GWindowSettings&  settings,
        Array<int>&             attribList) ;

    friend wxG3DCanvas;

    wxG3DCanvas*                window;
    GWindowSettings             settings;
    bool                        _mouseVisible;

    wxCursor                    invisible;
    wxCursor                    arrow;

    G3D::Queue< GEvent >        keyboardEvents;

    int                         clientX;
    int                         clientY;

    int                         relativeX;
    int                         relativeY;

    bool                        buttons[3];

public:

    wxGWindow(
        const GWindowSettings&  _settings,
        wxWindow*               parent,
        wxWindowID              id = -1); 

    wxGWindow(wxG3DCanvas* canvas) ;
    
    std::string getAPIVersion () const ;

    std::string getAPIName () const ;

    /** The wxWindow represented by this object */
    wxG3DCanvas* wxHandle() const ;

    virtual void swapGLBuffers() ;

    virtual void getSettings (GWindowSettings& _settings) const ;

    virtual int	width() const ;

    virtual int height() const ;

    virtual Rect2D dimensions () const ;

    virtual void setDimensions (const Rect2D &dims) ;

    virtual void setPosition (int x, int y) ;

    virtual bool hasFocus () const ;

    virtual void setGammaRamp (const Array<uint16>& gammaRamp) ;

    virtual void setCaption (const std::string& caption) ;

    virtual int numJoysticks () const ;

    virtual std::string joystickName (unsigned int sticknum) ;

    virtual std::string caption() ;

    virtual void notifyResize (int w, int h) ;

    virtual void setRelativeMousePosition(double x, double y) ;

    virtual void setRelativeMousePosition (const Vector2 &p) ;

    virtual void getRelativeMouseState (Vector2 &position, uint8 &mouseButtons) const ;

    virtual void getRelativeMouseState (int &x, int &y, uint8 &mouseButtons) const ;

    virtual void getRelativeMouseState (double &x, double &y, uint8 &mouseButtons) const ;

    virtual void getJoystickState (unsigned int stickNum, Array< float > &axis, Array< bool > &button) ;

    virtual void setInputCapture (bool c) ;

    virtual bool inputCapture () const ;

    virtual void setMouseVisible (bool b) ;

    virtual bool mouseVisible () const ;

    virtual bool pollEvent(GEvent& e) ;

    virtual bool requiresMainLoop() const {
        return true;
    }
};


class wxG3DCanvas : public wxGLCanvas {

private:

    wxGWindow*                  _gWindow;

public:

    wxG3DCanvas(wxGWindow* gWindow, wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxString& name = wxGLCanvasName, int *attribList = 0,
        const wxPalette& palette = wxNullPalette) :
            wxGLCanvas(parent, id, pos, size, style, name, attribList, palette),
            _gWindow(gWindow) {};

    void handleKeyUp(wxKeyEvent& event);

    void handleKeyDown(wxKeyEvent& event);

    void handleMouseLeftUp(wxMouseEvent& event);

    void handleMouseLeftDown(wxMouseEvent& event);

    void handleMouseRightUp(wxMouseEvent& event);

    void handleMouseRightDown(wxMouseEvent& event);
    
    void handleMouseMiddleUp(wxMouseEvent& event);
    
    void handleMouseMiddleDown(wxMouseEvent& event);

    void handleMouseMove(wxMouseEvent& event);

    void handleWindowMove(wxMoveEvent& event);

    void handleWindowClose(wxCloseEvent& event);

    void handleIdle(wxIdleEvent& event) {
        event.RequestMore(true);
        _gWindow->executeLoopBody();
    }
    
    DECLARE_EVENT_TABLE();
};

#endif
