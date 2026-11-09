/** @page guideconcepts Concepts

\htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidecompiling.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Compiling and Linking</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidetutorial.html">
Tutorial <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

  This section details some high-level concepts that will make the library easier to use.

  @section imm Immediate Mode Graphics

  G3D's structure is patterned on that of OpenGL and DirectX.  The major difference
  is that it provides easier to use state and resource management.  Graphics are
  primarily at the immediate mode level: programs render using 
  G3D::RenderDevice by clearing the screen,
  configuring state for transformation and lighting, and then sending a number of triangles
  to the graphics card.  Triangles are specified by a series of vertices, each 
  with its own texture coordinate, color, and surface normal.  Animation is achieved by
  drawing frames in rapid succession.

  To render a set of triangles, call <CODE>G3D::RenderDevice::beginPrimitives(G3D::RenderDevice::TRIANGLES)</CODE>
  invoke G3D::RenderDevice::sendVertex multiple times, and then call
  G3D::RenderDevice::endPrimitives.  For higher performance, first load the vertices
  into a vertex array (G3D::VAR) in a memory area (G3D::VARArea).  G3D::Texture abstracts 
  the various texture mechanisms.  G3D::GFont can render text on screen using a series of 
  rectangles with letter textures.  See <A HREF="../demos/GLG3D_Demo">demos/GLG3D_Demo</A>
  for examples of each kind of rendering.
  
  The basic concepts of immediate mode graphics are not explained in this manual or
  in the G3D documentation.  Refer to the OpenGL manual or <A HREF="#glsites">websites</A> for an introduction to immediate mode
  hardware graphics rendering and to a textbook like <I>Computer Graphics: Principles and
  Practice</I> for information about lighting and transformations.

  @section coordinates Coordinate Systems

  RenderDevice uses separate matrices for the object-to-world, world-to-camera, and perspective
  transformations (the concatenation of the first two is the equivalent of the OpenGL ModelView
  matrix).

  <IMG SRC="coords.png" ALIGN = RIGHT>

  The default 3D coordinate system is right-handed with Y=up, X=right, and Z=towards viewer.  
  Objects "look" along their negative z-axis.  G3D assumes a compatible "world space" where 
  Y=up, X=East, and Z=South.  The default 2D coordinate system (for 2D clipping, textures,
  and viewport) has the origin in the upper-left, with Y extending downward and X extending
  to the right.

  @section ref Reference Counting
  
  G3D uses reference counting to automatically manage memory for key resources, like G3D::Textures.
  These classes are allocated with static factory methods (G3D::Texture::fromFile) instead
  of <CODE>new</CODE> and pointers are stored in Ref types (G3D::TextureRef instead of G3D::Texture*). 
  You can use the Ref type as if it were a regular pointer, sharing a single instance over 
  multiple Ref's, dynamically casting, and invoking methods with the arrow (<CODE>-\></CODE>).

  Reference counted objects automatically maintain a count of the number of pointers to them.
  When that pointer count reaches zero the object could never be used again, so it automatically
  deletes itself.  This is both convenient for objects that have no natural "owner" to delete 
  them.  It also helps avoid memory leaks because memory management is automatic.

  <CENTER><TABLE BORDER=1 WIDTH=75% BGCOLOR=#CCCCCC>
  <TR><TD>If a class has a Ref type, never create a raw pointer to it and never call <CODE>delete</CODE>
  on an instance of it.</TD></TR></TABLE></CENTER>
  
  You can create your own reference counted classes using:
  
    <PRE>
       typedef G3D::ReferenceCountedPointer<class MyClass> MyClassRef;
       class MyClass : public G3D::ReferenceCountedObject { ... };
    </PRE>

  @section nm Naming

 All G3D routines are in the "G3D" namespace and can be referenced as G3D::xxx.  
 Unlike other libraries, there is (generally) no prefix on the routines, since 
 that is the job of a namespace.

  The exception is classes like "GWindow", "GFont", and "GImage".  We ran into 
  name conflicts with X11 and Win32 APIs on these classes since those APIs don't 
  have namespaces.  It would be confusing to have both G3D::Font and Font classes
  in a system at the same time, so we opted to rename the G3D classes to have a "G" 
  on the front.

  @section stl STL vs. G3D

   In general, we recommend using STL classes like <CODE>std::string</CODE> wherever possible--
   they are standardized and do their job well.  However, for some data structures G3D provides
   alternatives because the STL implementation is not appropriate for graphics use. 
   G3D::Array, G3D::Queue, G3D::Table, and G3D::Set are written in the style of the STL with
   iterators and mostly the same methods.  However they are optimized for access patterns that 
   we have observed to be common to real-time 3D programs, are slightly easier to use, and 
   obey constraints imposed by other graphics APIs.  For example, G3D::Array guarantees that
   the base pointer is aligned to a 16-byte boundary, which is necessary for working with 
   MMX and SIMD instructions.  These classes also contain fixes for some bugs in older 
   versions of the STL.

   The G3D::System class provides platform-independent access to low-level properties of the
   platform and CPU.  It also has highly optimized routines for timing (at the cycle level)
   and memory operations like System::memcpy.

  @section layer Layered APIs
  (see namespace map)



  @section data Data Directory
   Standard (and mostly public domain) 2D and 3D data are provided with this
   library.  These may be useful as test data or for comparison with
   previously published results.
   
     <PRE>
       data           <I>Data root</I>
          image       <I>Test images</I>
          height      <I>height maps</I>
          ifs         <I>Models for use with G3D::IFSModel</I>
          sky         <I>Images and data for use with G3D::Sky</I>
          font        <I>Fonts for use with G3D::GFont</I>
          quake2      <I>Models for use with G3D::MD2Model</I>
     </PRE>

  If you use G3D::GApp and the G3D::GAppSettings::dataDir is unspecified, G3D::GApp
  will search for likely locations for the data directory.  This is convenient
  when you have many projects that share the same skybox and font, for example,
  and don't want to copy that data into each project's directory.  The feature
  is used mostly for small prototypes and student work-- when you are building 
  a distributable application you'll want to specify dataDir because your users
  won't have G3D installed.

  The search directories include the current directory, up to 5 previous from the current,
  and locations like <CODE>c:\libraries\<g3d release name>\data</CODE> that 
  are common install dirs.

  <HR>
  @section glsites OpenGL Websites
<I>(from Dominic Curran's OPENGL-GAMEDEV-L post)</I>

The Official OpenGL Site - News, downloads, tutorials, books & links:- 
http://www.opengl.org/

The archive for this mailing list can be found at:- 
http://www.egroups.com/list/opengl-gamedev-l/

The OpenGL GameDev FAQ:- 
http://www.rush3d.com/opengl/

The EFnet OpenGL FAQ:- 
http://www.geocities.com/SiliconValley/Park/5625/opengl/

The Omniverous Biped's FAQ:-
http://www.sjbaker.org/steve/omniv

OpenGL 1.1 Reference - This is pretty much the Blue book on-line:- 
http://tc1.chemie.uni-bielefeld.de/doc/OpenGL/hp/Reference.html

Red Book online:-
http://fly.cc.fer.hr/~unreal/theredbook/

Manual Pages:- 
http://pyopengl.sourceforge.net/documentation/manual/reference-GL.html

Information on the GLUT API:- 
http://www.opengl.org/developers/documentation/glut.html

The Mesa 3-D graphics library:-
http://www.mesa3d.org

SGI OpenGL Sample Implementation (downloadable source):- 
http://oss.sgi.com/projects/ogl-sample/

OpenGL site with a focused on Delphi (+ OpenGL Hardware Registry):- 
http://www.delphi3d.net/

Game Tutorials - A number of OpenGL tutorials:- 
http://www.gametutorials.com/

Some nice OpenGL tutorials for beginners:- 
http://nehe.gamedev.net/

Humus - Some cool samples with code:- 
http://esprit.campus.luth.se/~humus/

Nate Robins OpenGL Page (some tutorials and code) 
http://www.xmission.com/~nate/opengl.html

Developer Sites for Apple, ATI & Nvidia:- 
http://developer.apple.com/opengl/
http://mirror.ati.com/developer/index.html
http://developer.nvidia.com/

OpenGL Extension Registry:- 
http://oss.sgi.com/projects/ogl-sample/registry/

The Charter for this mailing list can be found at OpenGl GameDev Site:-
http://www.geocities.com/SiliconValley/Hills/9956/OpenGL/

OpenGL Usenet groups:-
news:comp.graphics.api.opengl 
*/
