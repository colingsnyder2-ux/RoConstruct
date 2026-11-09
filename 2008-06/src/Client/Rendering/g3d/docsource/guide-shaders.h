/**
 @page guideshaders Shaders
  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guideeffects.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Effects</A></I></FONT></TD><TD ALIGN=RIGHT>
</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidefbo.html">
Framebuffer Objects <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

  Older graphics cards provide only a fixed-function pipeline in which lighting,
  texturing, and transformation is hardwired.  The range of effects that can
  be achieved on such cards is limited.  Newer cards (GeForce3/Radeon and later) 
  have a programmable pipeline that allows C-like code to be downloaded onto 
  the card and executed for each vertex and pixel.  The latest cards are 
  programmable-only and have no dedicated circuits for the old fixed-function
  routines.  Instead they emulate the fixed-function pipeline (which is slowly
  disappearing from OpenGL and DirectX altogether!).

  The programs that execute on the graphics card are called Vertex and Pixel 
  Shaders.  %G3D also adds "primitive shaders" that execute code on the CPU
  immediately before and after a group of primitives (e.g. a triangle list).
  These are useful for setting up rendering state for the vertex shader (e.g.
  computing the object space light vector once per object instead of once
  per vertex).  All three are abstracted in the G3D::Shader class.
  
  Well-written shaders are just as fast as the fixed-function pipeline
  but offer more flexibility and are easier to write and debug than fixed function
  code.  Most new games are written for programmable cards only, although for
  the widest possible compatibility it is good to have both full-featured 
  programmable and limited-effect fixed-function pathways in rendering code.

  <TABLE ALIGN=RIGHT WIDTH=50%>
  <TD><TD>
  <IMG SRC="bumpmap-screen.jpg" WIDTH=300>
  </TD></TR>
  <TR><TD>
  <CENTER>
  The GLSL_Shader_Demo in <A HREF="../demos/GLSL_Shader_Demo">demos/GLSL_Shader_Demo</A> shows parallax bump mapping with reflections.
  The object in the image is a single quadrilateral and the perception of depth is created entirely in a pixel shader.
  </CENTER>
  </TD>
  </TR>
  </TABLE>

  @section supported Supported Languages

  We recommend writing shaders in the OpenGL shading language (GLSL).
  G3D::Shader loads GLSL shaders from strings or from files.  Set the 
  input arguments (called uniform variables) with the G3D::Shader::args::set methods,
  which are type safe.  Call G3D::RenderDevice::setShader to enable the shader
  and <CODE>RenderDevice::setShader(NULL)</CODE> to disable it.  When a shader
  is set, you can change the arguments and they will take effect immediately; there
  is no need to set the shader again.  <B>Be warned that the summer 2004 drivers from
  NVIDIA are a little buggy and the ATI ones may crash outright on GLSL programs; 
  better support is expected in the fall.</B>

  G3D::Shader uses G3D::VertexAndPixelShader internally to manage the low-level
  operations.  It is available to you, however it is unlikely you will ever
  need to use it directly.
  
  You may also write shaders in NVIDIA's Cg language, and in OpenGL assembly 
  (DirectX uses a different language  called HLSL that is nearly identical to 
  Cg and GLSL but is not directly supported). These programs are loaded 
  with a different API.  
  
  Assembly programs are loaded from strings or from 
  files with G3D::VertexProgram and G3D::PixelProgram.
See <A HREF="../demos/ASM_Shader_Demo">demos/ASM_Shader_Demo</A>.  

  Cg programs must first be compiled to assembly.  The assembly can then be loaded
  with G3D::VertexProgram and G3D::PixelProgram, which know how to parse the special
  comments that Cg adds at the top of a file.
See <A HREF="../demos/Cg_Shader_Demo">demos/Cg_Shader_Demo</A>.  

  @section tools Tools
	RenderMonkey (http://www.ati.com/developer/rendermonkey/index.html) and the
    OpenGL Shader Designer (http://www.typhoonlabs.com/) are high-level development
    environments you can use to debug your shaders before incorporating them
    into a G3D project.

    To use Cg shaders you will need the compiler from the 
    Cg Toolkit (http://developer.nvidia.com/page/cg_main.html).  Cg can also be 
    used to help debug problems with GLSL shaders using the "-oglsl" flag.

  @section sample Sample Shaders
    Hundreds of sample shaders are available in all languages.
    The OpenGL Shading Language book 
    (\htmlonly <A HREF="http://www.aw-bc.com/catalog/academic/product/0,1144,0321197895,00.html">http://www.aw-bc.com/catalog/academic/product/0,1144,0321197895,00.html</A>\endhtmlonly)
    is the official GLSL spec and contains many examples.  NVIDIA, ATI, and 3DLabs 
    each provide SDKs with tons more.
    
    Community forums on programmable cards and sample shaders are also available at
    http://www.shadertech.com/

*/