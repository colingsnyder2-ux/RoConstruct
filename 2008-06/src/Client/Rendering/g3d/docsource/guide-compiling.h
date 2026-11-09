/**
  @page guidecompiling Compiling and Linking with G3D

\htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guideinstall.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Installing</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guideconcepts.html">
Concepts <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly


	@section comp Connecting your program to G3D
    On Windows, just <CODE>#include <G3DAll.h></CODE>.  Your program will automatically
    link against %G3D.
		
    On Linux you must write a Makefile and statically link against g3d.a and glg3d.a
    (release mode) or g3d-debug.a and glg3d-debug.a.  You must also link against zlib,
    sdl, and the jpeg library.  The iCompile program at http://ice.sf.net is an alternative
    to Makefiles that can automatically detect that your program uses G3D and SDL 
    and link appropriately.  

	On Mac OS X, you should follow the directions at \link guidemacosx Setting up
	a Project in Mac OS X \endlink. For information on compiling G3D, you should refer to
	\link guideinstall the Mac OS X compilation instructions \endlink.

    See the \link guidetutorial Tutorial \endlink for more details.

    Consult the \link errorfaq Error FAQ \endlink to help diagnose some common compilation
    and linking errors.
 
	@section distribfiles Files you must Distribute
	%G3D programs require SDL.dll and zlib1.dll at runtime.
    
    If you use G3D::GApp and do not specify another G3D::GAppSettings::debugFont,
    it will load the font/console-small.fnt on startup (this is located in the
    data directory).

    The BSD license requires that you have information in your documentation
    crediting the library.  For convenience, G3D::RenderDevice will automatically
    generate g3d-license.txt for you whenever your program is run (you can
    disable this behavior, of course!)

*/