/** @page guideui User Input 

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidemeshes.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Working with Meshes</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidefiles.html">
Files <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

<P> %G3D provides a series of class that aid in the implementation of user
input handling.  These classes include input handlers, windows and camera
control classes.  In addition to G3D's internal functionality, it has the ability 
to interact with a variety of GUI libraries.  This tutorial should provide a good overview,
but additional documentation is availabe in the individual class documentation.

@section gui G3D::UserInput
    
<P> The G3D::UserInput class consolidates the joystick, keyboard and mouse 
into a single interface class.  This class is unique for an input class because the input
polling system is not included in the class.  An external function is required to poll
input and store it in an SDL_Event structure to be passed to the UserInput object.  This
allows any polling system to be used as long as its input is properly converted.  
<P> This class provides a basic set of functions for handling common 3D input events like 
UP, DOWN, LEFT, and RIGHT.  Furthermore, it handles mouse and joystick buttons as if they 
are 'normal' key press/release events.  The following example demonstrates the initialization 
of a UserInput object and a trivial instance where it is polled for inputs.

<PRE>
    UserInput *userInput;

    userInput = new UserInput (thisWindow);

    GEvent event;

    userInput->beginEvents();
    while (renderDevice->window()->pollEvent(&event)) {

        switch (event.type) {
        case SDL_QUIT:
            %exit(0);
            break;
        }

        if (userInput->keyPressed(SDLK_PLUS)) {
            .... do something on '+' button pressed
        }

	userInput->processEvent(event);
    }
    userInput->endEvents();

</PRE>

<P> As a default, the UIFUNCTION events UP, LEFT, DOWN and RIGHT are 
assigned to the keys WASD and the arrow keys.  If you wish to change 
the key mapping then the function setKeyMapping should be used.  UserInput 
also provides a series of functions to test for key presses, key releases, 
key status or any key pressed.  These all work similar to the <code>if</code> 
statement in the example code above.  Look at the UserInput documentation
for further explanations.
<P> It is important to note one construct of the example code.  All event 
processing takes place between the beginEvents and endEvents statements.  
Any actions outside this block will not be processed.   

@section ui_button

@section ui_fpcamera G3D::FPCameraController

<P> The G3D::FPCameraController replaces the deprecated ManualCameraController to 
implement a Quake style 3D control interface.  Its use is best illustrated in
the GApp class where it is used to implement the debugCameraController.  This 
controller is used to create a GCamera object with a desired position
and view vector.
<P> The FPCameraController is most easily used inside the doSimulation function 
of the GApplet class.  In this function, the FPCameraController->doSimulation 
function should be called with the elapsed simulation time as its argument.  The 
controller will then poll the user input and adjust the current position and look
vector to reflect the user's input.  
<P> The following code demonstrates how a child class of GApplet can create a 
FPCameraController to make use of a UserInput object.

<PRE>    

    class Demo : GApplet {
        GCamera                 camera;
        FPCameraController      cameraController;
        UserInput               userInput;
        class App               *app;

    public:
        Demo(App *_app);
        void doSimulation (double elapsed_time);
    };

    Demo::Demo (App *_app) {
        app = _app
        userInput = new UserInput();
        cameraController.init(app->renderDevice, userInput);
        cameraController.setMoveRate(10);
        cameraController.setPosition(Vector3(0, 0, 4));
        cameraController.lookAt(Vector3(0, 0, 0));
        cameraController.setActive(true);
    }


    void Demo::doSimulation (double elapsed_time) {
        cameraController.doSimulation (elapsed_time);
        camera.setCoordinateFrame(cameraController.getCoordinateFrame());
    }
</PRE>
    
@section gwindow G3D::GWindow
    
<P> G3D::GWindow is G3D's way of dealing with windows.  <B><I>Many parts of %G3D 
assume there is only one OS-level window</I></B>, therefore this class is 
to be primarily used for creating user-level windows inside the application.  
It currently does not implement an extensive input system with UI events and 
constants, but this is planned as a future addition to %G3D.  In order to 
implement more advanced input systems, consider extending or re-writing 
G3D::UserInput.
<P> If a custom window set is not desired, several GWindow child classes 
are available for streamlining the implementation process. These include 
G3D::SDLWindow (SDL), G3D::Win32Window (Win32), G3D::wxWindow (wxWidgets), 
GlutWindow (Glut) and QGWindow (Qt).  Look at the individual classes in 
their respective contribution projects for advice and demonstrations on 
how to use them:

- wxWindows: <A HREF="../contrib/wxG3DCanvas">contrib/wxG3DCanvas</A>, 
<A HREF="../contrib/CoreyGWindow">contrib/CoreyGWindow</A>/wxGWindow
- Qt: <A HREF="../contrib/CoreyGWindow">contrib/CoreyGWindow</A>/QGWindow
- Win32/MFC: <A HREF="../contrib/Win32Window">contrib/Win32Window</A>

  */
