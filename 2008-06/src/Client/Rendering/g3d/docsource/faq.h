/** @page faq General FAQ


There are several reoccuring questions that appear at the <A HREF="http://sourceforge.net/forum/forum.php?forum_id=262426">G3D forums</A>. This document answers many of the most common questions. Questions closer related to building problems may be answered in the \link guidecompiling Compiling and Linking Guide \endlink and \link errorfaq Build Error FAQ \endlink.
<P>

<B>Table of Contents</B><P>
1. <a href="#graphicscard">What hardware is supported?</a><BR>
2. <a href="#no3d">Can G3D work without a 3D card?</a><BR>
3. <a href="#matrices">G3D::Matrix4 vs. OpenGL Matrices</a><BR>
4. <a href="#pbuffers">P-Buffers and G3D</a><BR>
5. <a href="#unicode">UNICODE Font Support</a><BR>
6. <a href="#nextrelease">The next release</a><BR>
7. <a href="#slowdemos">The demos run slowly</a><BR>
8. <a href="#indexarrays">What are index arrays?</a><BR>
9. <a href="#otherlibs">Using G3D with other libraries</a><BR>
10. <a href="#intersectmodel">Proximity and ray intersection with PosedModel</a><BR>
11. <a href="#rotation">How do I rotate an object when it's drawn?</a><BR>
12. <a href="#orthographic">Is there a way to make the GCamera do an orthographic projection?</a><BR>
13. <a href="#VS2005">My G3D based project will not build with Visual Studio 2005</a><BR>
14. <a href="#fullscreen">A fullscreen application shows the window title bar</a><BR>
15. <a href="#headers">Why are the headers out of date?/What header files are included with G3D</a><BR>
16. <a href="#buildsystem">Why does the source distribution not include the build system?</a><BR>
17. <a href="#precision">Float / Double precision errors. Warnings in truncation, or overload errors with argument types</a><BR>
18. <a href="#join">How can I join the G3D Core Dev team</a><BR>

<a NAME="graphicscard"></a>
<B>What graphics hardware does G3D support?</B><P>
G3D supports any card that can run OpenGL.  G3D automatically detects and works around known bugs in older cards.  We've tested all the way back to pre-T&L cards and it still runs great.

<a NAME="no3d"></a>
<P><B>Can G3D work without a 3D graphics card?</B><P>

G3D can work with the full-featured <a href="http://www.mesa3d.org/">Mesa3D</a> and the extremely limited but always-available GDI Generic software renderers.

<a NAME="matrices"></a>
<P><B>G3D::Matrix4 vs. OpenGL Matrices</B>
<P>
User may notice passing G3D::Matrix4 as a float* to OpenGL's matrix functions has unexpected results. Similarly, copying an OpenGL float* matrix into a G3D::Matrix4 seems to store the values strangely. This is because G3D stores matrices in row major order and OpenGL stores them column major. Basically, rather than store elements contiguously by their columns, they, they are ordered by their rows. There are technical reasons to use either ordering, and it is not uncommon to encounter lively discussions arguing each representation's merits. For G3D, row major ordering was chosen for increased accessing performance at the cost of breaking an OpenGL convention. Fortunately, the conversion between OpenGL's column major ordering and G3D's row major ordering is simple: G3D::Matrix4::transpose will return a row major matrix in column major, and a column major matrix row major. Better yet, G3D's OpenGL extension will automatically perform this conversion using the G3D::CoordinateFrame objects with G3D::glLoadMatrix, G3D::glLoadInvMatrix, G3D::glMultInvMatrix, G3D::glMultMatrix, G3D::glGetFloat, and G3D::glGetMatrix. For most applications, G3D::CoordinateFrame is a better choice for rigid-body transformations than G3D::Matrix4.
<P>

<a NAME="pbuffers"></a>
<B>P-Buffers and G3D</B><P>
There is no extended functionality supporting p-buffers in G3D. This does not prevent you from using them through standard OpenGL calls, though. Using p-buffers is a recognizably difficult process, principally due to the extension's design. Fortunately, a new p-buffer specification is under work by the OpenGL review board. G3D intends to support this new specification.

<a NAME="unicode"></a>
<P><B>UNICODE Font Support</B><P>
G3D supports rendering fonts through G3D::GFont, but only through the ASCII 8-bit characters. To implement extended characters, one might attempt extending G3D::GFont for extended characters. The FreeType generates little 2D bitmaps that you have to pack into a texture (using G3D::Texture the way G3D::GFont does) for rendering.

<a NAME="nextrelease"></a>
<P><B>The Next Release, What's Coming, What's Going</B><P>
One way to check on the overall progress of a release is to check the changelog.h in CVS for fixes and features added. This is in the cpp/source/docsource directory: http://cvs.sourceforge.net/viewcvs.py/g3d-cpp/cpp/source/docsource/

Deprecated functionality is removed at major releases. (from 6.xx to 7.00)
Because G3D builds as a static lib, there is no code bloat to your final executable. I would not be concerned about the deprecated routines-- just avoid using them in new code. The list of all deprecated entry points is:
http://g3d-cpp.sourceforge.net/html/deprecated.html

<a NAME="slowdemos"></a>
<P><B>The Demos Run Slow</B><P>
Most of the G3D demos are designed to stress high-end hardware, and will likely choke lower-end systems. The most significant component affecting demo performance is the video card; even with a high-speed processor, a low-end graphics card will likely be the bottleneck in the rendering pipeline. Low performance in these demos doesn't mean G3D is "slow." The demos are intentionally constructed to test against the computational limits using methods which may not accurately represent the "real" 3D applications.<BR>
For system profiling, the developers recommend a program called 'gfxmeter'.

<a NAME="indexarrays"></a>
<P><B>What are Index Arrays?</B><P>
Say you have a shape with four distinct vertices, A, B, C, D, and the triangles you want to render are ABC and BCD.
with sendVertex, you'd:

sendVertex(A); sendVertex(B); sendVertex(C);
sendVertex(B); sendVertex(C); sendVertex(D);

with vertex arrays you make a VAR that contains A,B,C,D, and an Array<int> indexArray that contains 0,1,2 1,2,3.

In the VAR_Demo you will see an example of this in the 'main.cpp' file. The "Model" object has an array of Vector3 for vertex locations. Then, a VAR is created with a Vector3 array (one for verticies and one for normals).

<a NAME="otherlibs"></a>
<P><B>Using G3D with other libraries</B><P>
G3D is a middle-level API that is used to encapsulate and assist with common graphics tasks. It also has a very thin high-level layer (G3D::App, G3D::Applet). This can be simply ignored if you intend use some other high-level functionality, such as a Windows app you're writing or a scenegraph library. In this way, the library will make calls to G3D to do the OpenGL rendering.

However, some of these libraries even include their own render functions. In these cases, you can still use G3D to augment OpenGL functionality, but this may interfere with your library's rendering. The conditions are specific to the library, and the particular application. In any case, G3D's other non-OpenGL graphics functionality remains available; the geometry, image, and math API's may be useful depending on your needs.

Most libraries with orthogonal functionality (such as audio libraries) should operate adjacently with G3D without conflict.

For more details, see \link guideintro Working with Other Libraries \endlink.

<a NAME="intersectmodel"></a>
<P><B>Proximity and ray intersection with PosedModel</B><P>

<i>I need to intersect a ray with a PosedModel in G3D, and/or find the closest point on a model to a given point (ideally, both). Is there a way to do this in the G3D library, or do you know if there is any already-written code that can do this for us?</i>

You can get an indexed triangle list out of a posed model, which you can use to
create an array of G3D::Triangles.  The triangles have a ray intersection
method-- just choose the first intersection.  Use the posed model's bounding
boxes to test conservatively if the ray could hit the model before performing
the individual tests.

To make this faster, only construct the triangle list once on startup since the
constructor is kind of slow.  If your model is large and you're inside it (e.g.
a quake map) then you should create an AABSPTree, which will perform only
log(n) ray intersection tests on average for n triangles.

<a NAME="rotation"></a>
<P><B>How do I rotate an object when it's drawn?</B><P>

G3D maintains separate matrices for object-to-world and camera-to-world. These are what OpenGL combines into MODEL_VIEW matrix set with glMulMatrix, glTranslate, etc.

Given a G3D::box it would be drawn and rotated using something similar to this code:

renderDevice->setObjectToWorldMatrix(CoordinateFrame(Matrix3::fromAxisAngle(axis, angle), Vector3(...));
Draw::box(box, renderDevice);

Note:
G3D::Draw is easy to use and fairly powerful. It is also fairly slow (as indicated in the documentation). Consider using IFSModel or writing your own VAR code for a huge speedup.

<a NAME="orthographic"></a>
<P><B>Is there a way to make the GCamera do an orthographic projection instead of the perspective?</B><P>

No, orthographic cameras are fundamentally different from perspective cameras because there is no center of projection. An orthographic camera has to be *huge* to do what you'd want--the viewport would have to be the size of your scene. GCamera can't be adjusted to do this without breaking it.

It is possible to build your own orthographic camera since RenderDevice accepts any 4x4 matrix as the projection matrix, if anyone implements this, please let the development team know, as we'd like to use it too.

<a NAME="VS2005"></a>
<P><B>My G3D based project will not build with Visual Studio 2005</B><P>

Please see the equivalent error in the Error FAQ.

<a NAME="fullscreen"></a>
<P><B>A fullscreen application shows the window title bar.</B><P>

The window is showing the frames.
Create an unframed window with GWindowSettings::framed = false;

<a NAME="headers"></a>
<P><B>Why are the headers out of date? / What header files are included with G3D?</B><P>
We intentionally use our own version of the OpenGL headers because we have found that most Linux systems have out of date headers.<BR>
Often the user (e.g., a student) does not have root access and can't correct this, so we just supply our own.<BR>
On Linux G3D will use your libjpeg, libpng, and libz headers.  We include ours only for Win32.<BR>

<a NAME="buildsystem"></a>
<P><B>Why does the source distribution not include the build system?</B><P>
The "source" distribution intentionally does not include the G3D build system.<BR>
It is provided to help document G3D, not to rebuild it. <BR>
This is primarily because the build system is complex (it covers many platforms) and we aren't in a position to offer support for the build system yet.
It is also because building requires many files that we don't include in the source distro to make the download size smaller.<BR>
<BR>
Check out from CVS if you'd like to build G3D. Once the latest G3D source has been checked out, building is easy: <BR>on Linux, type:<BR>
<PRE>

chmod u+x build
./build install <targetdir>
</PRE>

This build command also works on Win32 and OSX, but it requires Python to be installed.<BR>

We are currently in the process of redesigning the build system; hopefully the new version will be something that we're comfortable releasing with the source distro.<BR>

<a NAME="precision"></a>
<P><B>Float / Double precision errors. Warnings in truncation, or overload errors with argument types</B><P>
In 6.08, we changed most the pass-by-value arguments from double to float to increase performance and
trigger truncation warnings (i.e., to show you where you might be losing precision).  <BR>
This will likely cause your code to generate warnings like:
<PRE>  warning C4305: 'argument' : truncation from 'double' to 'float'</PRE>
These are usually caused by using double constants for float arguments, like:<BR>
<PRE>Vector3(0.1, 2.0, 0.3). </PRE>
The solution is to use float or int constants, like:<BR>
<PRE>Vector3(0.1f, 2, 0.3f) or Vector3(0.1f, 2.0f, 0.3f). </PRE>
You can also work around this on Microsoft compilers with the command #pragma warnings (disable : 4305).<BR>

Occasionally, this change will cause an overload to become ambiguous, generating an error like:
 <PRE>error C2665: 'G3D::max' : none of the 5 overloads could convert all the argument types</PRE>
In this case, change your code to ensure that both of the arguments to the function have the same type. <BR>
E.g., <PRE>max(1.0, 2.0f) -> max(1.0f, 2.0f).</PRE>


<a NAME="join"></a>
<P><B>How can I Join the G3D Core Dev Team?</B><P>
We also always need help with documentation.  If you would
like to submit new documentation for a class or for part of
the manual, that is another good way to demonstrate your
skills.

After someone has contributed for a few months and
demonstrated both their abilities and commitment to the
project, I will invite them to join the core team.

In core team members, I value most:

- Reliability
  - Complete tasks you've committed to
  - Maintain a presence by posting in in bug tickets and forums
- Professionalism
  - Treat users and other developers with respect
  - Test changes carefully
  - Embrace the whole role: documentation, testing, advocacy
- Enthusiasm!
.
Note that we don't need the most *skilled* C++ developers in
the world--we need the most reliabile, professional, and
enthusiastic developers.

*/