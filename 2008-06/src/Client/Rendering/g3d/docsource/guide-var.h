/** @page guidevar Vertex Arrays

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidenetwork.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Networking with G3D</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidemeshes.html">
Working with Meshes<IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly


  @section fast A Faster Way to Render

 There are two ways to render primitives under %G3D (and OpenGL).  The first way, explored
 in the \link guidetutorial tutorial \endlink, is:

   <PRE>
     renderDevice->beginPrimitive(RenderDevice::TRIANGLES);
        renderDevice->sendVertex(Vector3(0,0,0));
        renderDevice->sendVertex(Vector3(1,0,0));
        renderDevice->sendVertex(Vector3(1,1,0));
        ... (other vertices)
     renderDevice->endPrimitive();
   </PRE>

  There are two potential performance bottlenecks with the above code.  First, each vertex is sent
  to the graphics card every frame.  For a large model the graphics card may
  be starved waiting for new data from the CPU to come across the comparatively
  slow bus.  If many triangles share the same vertices, those vertices
  are sent multiple times.  This makes the bottleneck even worse.  Second,
  each vertex requires a separate function call.  Those individual function
  calls add up quickly for a scene with hundreds of thousands of triangles.

  @section render Rendering Vertex Arrays
  Vertex arrays (aka vertex buffers) are another way of rendering that avoids
  both bottlenecks while making it easy to manage large scenes.  Instead of sending
  vertices individually, we point at a pre-created array and send indices into the array:

  <PRE>
    renderDevice->beginIndexedPrimitives();
       renderDevice->setVertexArray(vertexArray);
       renderDevice->sendIndicies(RenderDevice::TRIANGLES, indexArray);
    renderDevice->endIndexedPrimitives();
  </PRE>

  The index array is a G3D::Array<int> or G3D::Array<int16> of numbers.
  Each of these number corresponds to the equivalent vertex in the vertexArray.
  In the example above, TRIANGLES is being used as the drawing function.
  If the indexArray in the example looks like this: <br>
  0,1,2,1,2,3,2,3,4<br>
  then the drawn shapes use the following vertices:<br>
  <PRE>
  vertexArray[0]
  vertexArray[1]
  vertexArray[2]

  vertexArray[1]
  vertexArray[2]
  vertexArray[3]

  vertexArray[2]
  vertexArray[3]
  vertexArray[4]
  </PRE>
  The other OpenGL primitive drawing functions can be used, such as POINTS, LINES, LINE_STRIP, TRIANGLE_STRIP, QUADS, and QUAD_STRIP
  If you only wish to render the vertices in sequential order, use G3D::RenderDevice::sendSequentialIndices instead.
  Just as with sendVertex-style rendering, it is possible to specify normals, colors, and texture coordinates with G3D::RenderDevice::setNormalArray and other variations.
  <br>
  <br>
  <B>NOTE:</B> When texturing with vertexArrays, the sendIndices must come last, set your texture coordinates before you send the indices.

  @section convert Converting from sendVertex to Vertex Arrays

  Say you have a shape with four distinct vertices, A, B, C, D, and the triangles you want to render are ABC and BCD.
  with sendVertex, you'd:  <br>
   <br>
  sendVertex(A); sendVertex(B); sendVertex(C); <br>
  sendVertex(B); sendVertex(C); sendVertex(D); <br>
   <br>
  with vertex arrays you make a VAR that contains A,B,C,D, and an Array<int> indexArray that contains 0,1,2,1,2,3. <br>

  @section create Creating Vertex Arrays

  Vertex arrays are created in video memory, AGP memory, or regular main memory
  depending on the capabilities of the graphics card and the usage hints supplied.
  That process is entirely managed for you.  To allocate a block of memory, called an
  area, use G3D::VARArea::create.  The resulting reference counted object
  (a G3D::VARAreaRef) will automatically
  be freed, so there is no need to ever deallocate it.

  Within the G3D::VARArea you can create multiple G3D::VAR objects, each of which is a handle
  to the vertex data on the graphics card.  There is no way to free an individual
  VAR object, but you can free all VARs in an area with G3D::VARArea::clear and
  upload new data to an existing VAR with G3D::VAR::update.

  The following example shows how to construct a VARArea and VAR within it:

  <PRE>
    Array<Vector3> data;

    data.append(Vector3(0,0,0));
    data.append(Vector3(1,0,0));
    data.append(Vector3(0,1,0));

    VARAreaRef area = VARArea::create(1024 * 10); // 10k bytes

    VAR vertexArray(data, area);
  </PRE>

  Even if you update a VAR every frame or clear and recreate it, your program will
  still be faster than the sendVertex method of rendering because Array::append calls are
  much faster than sendVertex calls.  If you can avoid changing all of the geometry
  every frame, your program will be significantly faster because very little bandwidth
  will be used rendering your model.

  @section how How Many VARAreas?
There are three reasons you might want to create different VARAreas:
<OL>
 <LI> Abstraction between different parts of your rendering system
 <LI> The only way to deallocate a VAR is to clear the whole VARArea, so objects
that are deallocated at different times must live in different areas.
 <LI> Each area has hints about how often it is updated.  If you update some
objects infrequently, you can get better performance by putting them in their
own area and creating that area with the G3D::VARArea::WRITE_ONCE hint.
</OL>

There are also reasons <I>not</I> to separate areas.  The biggest reason is that for
a given primitive, you can only use VARs within the same area (e.g. the color,
normal, texcoord, and vertex streams must be in the same area).  Also, it is
slightly faster to clear one big area than a bunch of smaller ones and
allocating VARs in one big area might give better cache performance and memory
efficiency.

  */