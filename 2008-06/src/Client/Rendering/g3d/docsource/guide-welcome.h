/** @mainpage G3D Manual

<CENTER>
<IMG SRC="G3D.jpg">
</CENTER>

@section Welcome
<div>
\htmlonly
<IMG SRC="3dengine.jpg" style="float: right;">
\endhtmlonly
%G3D is a commercial-grade 3D Engine available as Open Source (BSD License).
It is used in games, tech demos, research papers, military simulators, and
university courses.  It provides a set of routines and structures so common
that they are needed in almost every graphics program.  It makes low-level
libraries like OpenGL and sockets easier to use without limiting functionality
or performance.  %G3D gives you a rock-solid, highly optimized base from which
to build your application.

%G3D does not contain scene graph or GUI routines.  Because of this, you have much
more flexibility in how you structure your programs.  The tradeoff is that
you have to know more about 3D programming.  %G3D is intended for users who are already
familiar with C++ and DirectX or OpenGL.  Several good GUI libraries exist and
we recommend using one with %G3D if your project has extensive UI needs.

This manual begins with a \link guidetutorial Tutorial \endlink and
\link guideapp Application Framework \endlink that help
programmers who know C++ but are either new to 3D or starting without
a base of 3D code get up and running quickly.  The demos directory also contains
a starter <A HREF="../demos/main.cpp">main.cpp</A> for the
application framework (it is how the %G3D developers usually
start a new project in their own work).

The library also provides lower-level interfaces that programmers who are
already working with OpenGL and existing code may prefer.  See the
Notes for Expert Users at the end of this chapter for more information.
</div>

@section chapters Table of Contents

This is the first release of the library to include this overview manual, and
not all sections are complete. However the individual entry points
of the library are extensively documented and new overview content will
arrive with each point release.

<TABLE BORDER=0 WIDTH=75%>
 <TR><TD VALIGN=TOP WIDTH=33%><B>Chapter</B></TD><TD VALIGN=TOP><B>Topics</B></TD></TR>

 <TR><TD VALIGN=TOP>\link guideintro Introduction \endlink</TD><TD VALIGN=TOP>
  Documentation and Support,
  Platform and Functionality,
  Design Philosophy,
  Data Formats,
  Team,
  Working With Other Libraries,
  Release Schedule,
  Beta and Deprecated APIs,
  Notes for Expert Users</TD></TR>

  <TR><TD>\link license License (BSD/IJG) \endlink</TD><TD>
  The appropriate licenses for G3D and dependencies.
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guideinstall Installing G3D \endlink</TD><TD VALIGN=TOP>
  WindowsXP/2000,
  Linux,
  OS X,
  Building the Library,
  <CODE>\#define</CODE>s</TD></TR>

  <TR><TD VALIGN=TOP>\link guidecompiling Compiling and Linking with G3D \endlink</TD><TD>
  Guides to compilation of G3D based programs and projects.
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guideconcepts Concepts \endlink</TD><TD>
  Immediate Mode Graphics,
  Coordinate Systems,
  Reference Counting,
  STL,
  Layerd APIs,
  Data Directory</TD></TR>

  <TR><TD VALIGN=TOP>\link guidetutorial Tutorial \endlink</TD><TD VALIGN=TOP>
  The G3D tutorial, an excellent place to start with G3D.
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidedebug Debugging \endlink</TD><TD VALIGN=TOP>
  Debugging in a G3D Application.
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guideapp Application Framework \endlink</TD><TD VALIGN=TOP>
   Applets, Models, Selection, FPS Controls
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guideopengl Using OpenGL with %G3D\endlink</TD><TD VALIGN=TOP>
     How to use raw OpenGL commands with G3D
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidenetwork Networking with %G3D\endlink</TD><TD VALIGN=TOP>
       Using the network interfaces of G3D
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidevar Vertex Arrays \endlink</TD><TD VALIGN=TOP>
   Creating, managing, and rendering from vertex arrays (video memory)
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidemeshes Working with Meshes \endlink</TD><TD VALIGN=TOP>
  Building meshes, Loading from disk, Mesh algorithms,
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guideui User Input\endlink</TD><TD VALIGN=TOP>
  How to manage User Input in a G3D Application.
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidefiles Files & Networks \endlink</TD><TD VALIGN=TOP>
  File Management,
  Text Files,
  Binary Files,
  Network,
  Images, Models
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidephysics Physics and Ray Tracing \endlink</TD><TD VALIGN=TOP>
  Physics,
  Ray Tracing,
  Bounding Volumes,
  BSP Tree
  </TD></TR>

  <TR><TD VALIGN=TOP>\link guidecollision Collision Detection \endlink</TD><TD VALIGN=TOP>
	Collision Detection,
	Object Intersection
  </TD></TR>


  <TR><TD VALIGN=TOP>\link guideeffects Effects \endlink</TD><TD VALIGN=TOP>
  Cartoon Rendering, Shadows, Reflections
  </TD></TR>


  <TR><TD VALIGN=TOP>\link guideshaders Shaders \endlink</TD><TD VALIGN=TOP>
  Supported Languages,
  Tools,
  Sample Shaders</TD></TR>


  <TR><TD VALIGN=TOP>\link guidefbo Framebuffer Object \endlink</TD><TD VALIGN=TOP>
  Tutorial on using framebuffer objects.</TD></TR>

 <TR><TD VALIGN=TOP>\link guidevideo Video in G3D \endlink</TD><TD VALIGN=TOP>
  Gudie to using the video support within G3D</TD></TR>


<TR><TD>\link deprecated Deprecated \endlink</TD><TD>APIs to be removed in 7.0</TD></TR>
<TR><TD>\link changelog Change Log \endlink</TD><TD>Changes between G3D Releases</TD></TR>
<TR><TD>\link faq General FAQ \endlink</TD><TD>General Frequently Asked Questions</TD></TR>
<TR><TD>\link errorfaq Error FAQ \endlink</TD><TD>Frequently Asked Questions (Common Errors)</TD></TR>
<TR><TD>\link contributors G3D Contributors \endlink</TD><TD>The G3D Team, past and present</TD></TR>
<TR><TD VALIGN=TOP COLSPAN=2>Index:
\link indexedbytopic By Topic \endlink |
Alphabetic <A HREF="classes.html">Classes</A> and <A HREF="globals_func.html">Functions</A> |
\link frequent Frequently Used (bookmark this!) \endlink
</TD></TR>
</TABLE>

<HR>
Manual and Library source code
<DT>Copyright 2004-2006, Morgan McGuire.
<DT>All rights reserved.
*/

