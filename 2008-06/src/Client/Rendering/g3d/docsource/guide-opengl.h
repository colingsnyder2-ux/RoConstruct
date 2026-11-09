/** @page guideopengl Using OpenGL with G3D

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guideapp.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Application Framework</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidenetwork.html">
Networking with G3D <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

It is possible to mix 'raw' OpenGL calls with the G3D rendering engine. This can give more flexibility in the rendering cycle,
or be used to acheive different effects.<br>

@section limit Limitations
There is one major limitation when using raw OpenGL with G3D:<br>
The G3D RenderDevice keeps track of the current OpenGL state, because of this, OpenGL must be restored to the state in which it
started. This is especially important when dealing with OpenGL shaders.<br>
Failing to return the state to that expected by RenderDevice may cause either unexpected behaviour, or a program crash.<br>
While using raw OpenGL calls may be faster than using the equivalent G3D methods, RenderDevice will usually optimise
state calls, meaning that a sequence of RenderDevice calls will probably end up being faster than the equivalent OpenGL.<br>
When using Vertex Arrays (VAR), the overhead of calls is negligible as a single call can draw many polygons.

@section benefits Benefits
The benefit of mixing raw OpenGL with the G3D renderer is to enable effects that aren't directly supported by G3D.<br>
In particular, fog and TextureCoordinate generation are not supported as renderer method as G3D believes that shaders are
a better method of handling these calls. However, if OpenGL fog support is explicitly needed, this can be done using a
raw OpenGL command with the RenderDevice. Another case of this is glDepthRange.<br>
Also, underlying OpenGL handles can be gained from the Texture and FrameBuffer objects and bound manually, if this
is advantageous to your code.<br>
Finally, the raw OpenGL commands can be used to load OpenGL extensions, for an example of this code, see the GLCaps code for an
example of this.

@section otherinfo Other Information
OpenGL handles can be retrieved out of most G3D objects, including Texture and Framebuffer (Texture::openGLID and FrameBuffer::openglid).
Also, many G3D objects can be created out of an OpenGL handle, again including Texture (Texture::fromGL).<br>
G3D does provide a series of helper functions if you wish to use raw OpenGL with G3D.
These bridge between G3D data types and OpenGL functions. Examples of these include glVertex(Vector3) and glGetInteger.<br>
To debug raw OpenGL, use getOpenGLState, debugAssertGLOk and glEnumToString.



@section example Code Example

A simple code example using raw OpenGL vertex calls to draw a primitive shape:

<PRE>
	renderDevice->pushState();

		renderDevice->beforePrimitive();

		glPushMatrix();

		glRenderMode(GL_TRIANGLES);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);

		glPopMatrix();

		renderDevice->afterPrimitive();

	renderDevice->popState();
</PRE>


*/