/** @page guideinstall Installing G3D

  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="license.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
License</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidecompiling.html">
Compiling and Linking <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

  @section windows Windows XP & Windows 2000

   <OL>
   <LI>
   Download the latest g3d-xxx.zip from
   http://g3d-cpp.sf.net <BR>
   Unzip all of the files in the distribution to your
   library directory (e.g. <CODE>c:\\libraries</CODE>).  Note that the single download
   contains precompiled binaries for MSVC++ 6, MSVC++ 7, gcc on Linux, and Xcode and gcc on OS X.

   <LI>Download and install SDL version 1.2.7 from
   <A HREF="http://www.libsdl.org">http://www.libsdl.org</A>: <A HREF="http://www.libsdl.org/release/SDL-devel-1.2.7-VC6.zip">Win32</A>, 
   <A HREF="http://www.libsdl.org/release/SDL-devel-1.2.7-1.i386.rpm">Linux</A>,
   <A HREF="http://www.libsdl.org/release/SDL-devel-1.2.7.pkg.tar.gz">OS X</A>

   <LI>Microsft Visual C++ 6.0 and Microsoft Visual C++ 7.0 (which comes as part of Microsoft Visual Studio .NET 2002 and 2003) 
	require different versions of the library, and a few different installation steps. Precompiled binaries for MSVC 6 are located
	in win32-lib and precompiled binaries for MSVC 7 are in win32-lib7. Figure out which one you're using, and point to the right
	G3D binaries, or you will have strange trouble, including linker errors and memory leaks. 
   </LI>

   <LI><B>MSVC++ 6:</B>
   <OL>
   <LI>Install 
   <A HREF="http://download.microsoft.com/download/vstudio60ent/SP5/Wideband-Full/WIN98Me/EN-US/vs6sp5.exe">Service Pack 5</A>. 
   (Service pack 6 does not support the processor pack) 
   </LI>
   <LI>Install the 
   <A HREF="http://download.microsoft.com/download/vb60ent/Update/6/W9X2KXP/EN-US/vcpp5.exe">Processor Pack</A>.
   </LI>
   <LI>(<I>Optional</I>) Add the following lines to your Autoexp.dat file (usually in <CODE>C:\\Program Files\\Microsoft
   Visual Studio\\Common\\MSDev98\\Bin</CODE>): 

<PRE> ;; graphics3D
   %G3D::Quat=Quat(&lt;x&gt;,&lt;y&gt;,&lt;z&gt;,&lt;w&gt;)
   %G3D::Vector4=Vector4(&lt;x&gt;,&lt;y&gt;,&lt;z&gt;,&lt;w&gt;)
   %G3D::Vector3=Vector3(&lt;x&gt;,&lt;y&gt;,&lt;z&gt;)
   %G3D::Vector2=Vector2(&lt;x&gt;,&lt;y&gt;)
   %G3D::Vector4int16=Vector4(&lt;x&gt;,&lt;y&gt;,&lt;z&gt;,&lt;w&gt;)
   %G3D::Vector3int16=Vector3(&lt;x&gt;,&lt;y&gt;,&lt;z&gt;)
   %G3D::Vector2int16=Vector2(&lt;x&gt;,&lt;y&gt;)
   %G3D::Color4=Color4(&lt;r&gt;,&lt;g&gt;,&lt;b&gt;,&lt;a&gt;)
   %G3D::Color3=Color3(&lt;r&gt;,&lt;g&gt;,&lt;b&gt;)
   %G3D::Color4uint8=Color4uint8(&lt;r&gt;,&lt;g&gt;,&lt;b&gt;,&lt;a&gt;)
   %G3D::Color3uint8=Color3uint8(&lt;r&gt;,&lt;g&gt;,&lt;b&gt;)
   %G3D::NetAddress=NetAddress(&lt;addr.sin_addr.S_un.S_un_b.s_b1,u&rt;.&lt;addr.sin_addr.S_un.S_un_b.s_b2,u&rt;.&lt;addr.sin_addr.S_un.S_un_b.s_b3,u&rt;.&lt;addr.sin_addr.S_un.S_un_b.s_b4,u&rt;)

   ;; Prevent stepping into certain functions
    [ExecutionControl]
    std::*=NoStepInto
   </PRE>

   <LI>
   In Tools:Options:Directories, add the g3d include directory 
   (e.g. c:\\libraries\\g3d-6_00\\include) to the
   include list.  Make sure it preceeds all other include directories.
   <LI>
   In Tools:Options:Directories, add the g3d lib directory 
   (e.g. c:\\libraries\\g3d-6_00\\win32-lib) to the library
   list.
   </OL>
   </LI>

   <LI><B>MSVC++ 7 / .NET:</B>
   <OL>
   <LI>Go to Tools:Options. Select the Projects heading, and within that heading, Visual C++
   Directories. 
   <LI>In that panel, select "Show Directories For: Include files." 
   <LI> Add the %G3D
   include directory, G3D_ROOT/include, and the SDL include directory (e.g. C:/SDL-1.2.7/include)
   <LI>In the same panel, select "Show Directories For: Library Files."
   Add the %G3D library directory, G3D_ROOT/<B>win32-7-lib</B>.
   </OL>
   </LI>

   <LI><B>Dev-C++</B>
   
   Dev-C++ libraries must be first built. The project files are are in the source directory: Graphics3D.dev and G3DGL.dev. Follow these steps to set up and build the library:
   <OL>
   <LI>Go to Tools:Check for Updates/Packages. Select the devpaks.org Community Devpaks server, click check for updates, and within 
   the list, select <B>zlib, libjpeg, SDL</B>. Download and install these, then again for libpng. Libpng is dependent zlib so you need to first install zlib before you check libpng.
   <LI>Go to Tools:Compiler Options, click the directories tab, and the C++ includes under that.
   <LI> Add the %G3D
   include directory, G3D_ROOT/include.
   <LI>In the same panel, select "Libraries" tab.
   Add the %G3D library directory, G3D_ROOT/<B>mingw-lib</B>.
   <LI>Open and compile Graphics3D.dev
   <LI>Open and compile GLG3D.dev
   <LI>Copy the libraries G3D_ROOT/../temp/mingw32-lib/libG3D.a and G3D_ROOT/../temp/mingw32-lib/libGLG3D.a to the mingw32-lib directory.
   </OL>
   
   At this point you can now compile new G3D projects, and the demos included in the demo directories.
   </LI>
   
  <LI>
   <B>For each project you create</B>, copy <CODE>SDL.dll</CODE>, <CODE>glut32.dll</CODE>, 
      and <CODE>zlib1.dll</CODE>
      to your program directory (or put them in Windows/System)
    </OL>
   </OL>

  <P>

  @section linux Linux
  <OL>
   <LI>
   Download the latest g3d-xxx.zip from
   http://g3d-cpp.sf.net <BR>
   Unzip all of the files in the distribution to your
   library directory (e.g. <CODE>~/lib/</CODE>).
   </LI>

   <LI>Make sure that SDL <B>version 1.2.7</B> is installed on your machine. 
   Try running <CODE>sdl-config --version</CODE>. If it returns "1.2.7" then you're all set. 
   (<CODE>sdl-config</CODE> is a handy tool that tells you what flags to pass to your compiler
   and linker to use SDL. If you run into SDL trouble, <CODE>sdl-config</CODE> is your friend.)
   If <CODE>sdl-config</CODE> can't be found, or returns something other than "1.2.7", you'll 
   need to install or update SDL. Download and install SDL from
   <A HREF="http://www.libsdl.org">http://www.libsdl.org</A>. 
   </LI>

   <LI>We recommend using <A HREF="http://ice.sf.net">iCompile</A>, 
	which automatically compiles and links every C++ file in the directory it's run from, 
	so you won't need to edit it to refer to each source file (as you would with a Makefile). 
	It needs the following environment variables, which you can set in your .cshrc file using 
	setenv. If you're using iCompile,
	you will need to set up some environment variables to point to SDL and %G3D. 
	Modify the paths as appropriate for your installation:

	<CODE>
	INCLUDE ~me/libraries/g3d/include:/usr/include/SDL <BR>
	LIBRARY ~me/libraries/g3d/linux-lib<BR>
	LD_LIBRARY_PATH $LIBRARY <BR>
	CC gcc-3.2 <BR>
	CXX g++-3.2 <BR>
	</CODE>

	You are also welcome to use a makefile; set compiler and linker flags to point to SDL and %G3D.   
	</LI>

	<LI>
	Confirm that you've installed %G3D correctly by installing and running one of the demos:<BR>
	<CODE>cd g3d/demos/GLG3D_Demo</CODE><BR>
	<CODE>icompile --run</CODE><BR>
	This should run the GLG3D demo; you should see many colored airplanesflying around a pink and blue sky. 
	</LI>

  @section osx Mac OS X

  See \link guidemacosx Setting Up a Project in Mac OS X\endlink for complete instructions on getting %G3D on the mac running with your own code. 

  @section build Building G3D

  You don't have to build %G3D to use %G3D; the instructions above walk you through 
  setting up your environment to use the precompiled %G3D binaries. You may <EM>want</em>
  to build %G3D in order to: 
  <UL>
  <LI>Step into library functions while debugging
  </LI>
  <LI>Use an unsupported compiler
  </LI>
  <LI>Customize the library code.
  </LI>
  </UL>
<P>
<I>We recommend using Xcode 2.1 or 2.2 to build G3D, and then using the same version of Xcode to build your G3D programs, both using Xcode project files included in the source distribution, and from the command line. Here, we first give instructions to get prerequisites required to build either way, then directions to build with Xcode, then include the instructions for a more traditional, unix/command-line style build.</I>
</P>
<LI>
<P><B>Common Setup</B></P>
	<OL>
	<LI>Install Apple's Xcode Development Environment 2.2, from <A HREF="http://developer.apple.com/tools/download/">Apple's Developer Site</A>. (It may seem like you have to pay for the privilege of joining the Apple Developer Connection (ADC), but in fact you can get a web-only membership for free.)</LI>
	<LI>Install the <A HREF="http://www.libsdl.org/release/SDL-devel-1.2.9.pkg.tar.gz">SDL 1.2.9 Development Library</A>.</LI>
	</OL>
</LI>
<LI>
<P><B>Building G3D with Xcode</B></P>
	<OL>
	<LI>Get a copy of the source tree, either via <A HREF="http://sourceforge.net/cvs/?group_id=76879">cvs</A> or via the src zip, available on the <A HREF="http://sourceforge.net/project/showfiles.php?group_id=76879">downloads</A> page. Expand the zip.</LI>
	<LI>Double-click on <tt>G3D/cpp/G3DOSX/G3DOSX.xcodeproj</tt>. This will launch Xcode. </LI>
	<LI>In Xcode, locate the main toolbar. At the far left of the toolbar, set the active target to G3DTest. Hit "Build." </LI>
	<LI>Command-Shift-B brings up the "Build Results" window. The last line in the output in that window should be "Build succeeded."</LI>
	<LI>With the active target set to G3DTest, hit the "Run" button. The console should come up and give you lots of interesting information about G3D's performance on your machine. Congratulations, you have built G3D on Mac OS X.</LI>
	<LI>Having built G3D, you will probably want to run a demo. We recommend taking advantage of the <tt>*.xcodeproj</tt> files included in some of the demo directories. They work, if you leave them in their current directory. Open <tt>G3D/cpp/source/demos/VAR_Demo/VAR_Demo.xcode</tt>. Hit "Build and Go", and you should see little purple and orange planes flying around in a circle.</LI>
	</OL>
</LI>
<LI>
<P><B>Building G3D from the command line</B></P>
	<OL>
	<LI> <I>gcc 4.0 is the current version for Mac OS X</I></LI>
	<LI> Install the <A HREF="http://www.cwi.nl/ftp/jack/python/mac/MacPython222active.bin">Python 2.2.2 tool</A>.
	<LI> Install the <A HREF="ftp://ftp.stack.nl/pub/users/dimitri/doxygen-1.3-rc3.macosx.bin.tar.gz">Doxygen 1.3.2 tool</A>.
	<LI> Install the <A HREF="http://ftp.gnu.org/gnu/automake/automake-1.7.5.tar.gz">automake 1.7.5</A> tool (and the corresponding aclocal version).
	<LI> Install the <A HREF="http://ftp.gnu.org/gnu/autoconf/autoconf-2.57.tar.gz">autoconf 2.57</A> tool.
	<LI> Add the paths for these tools to your PATH environment variable (usually in your .cshrc, .tcshrc, or .bashrc file).

	<LI>TODO: set up LD_LIBRARY_PATH

	<LI> Log out so all changes can take effect.
	<P>
	<LI>Run "<CODE>chmod u+x build</CODE>" in the <CODE>cpp</CODE> directory.
	<LI>Run "<CODE>./build install</CODE>" in the <CODE>cpp</CODE> directory
	<LI>The library and demos will compile in the source tree
	</OL>
	</P>
</LI>
  Also see the <A HREF="build-instructions.html">build instructions</A>.
  
   \section defines #defines
    G3D pays attention to the following #defines.
   <P>
     <B>SSE</B> - Allows the use of Intel PIII SSE instructions for faster math
      routines.  On Win32, you will need the Visual Studio processor pack 
      (Free from http://msdn.microsoft.com/vstudio/downloads/ppack/default.asp)
      to build with this option.  Your code will only run on PIII or later
      machines.  <B>If you have the student edition of MSVC</B>, you must
      remove the #define SSE line from platform.h in order to build or you will get errors like <CODE>vector3.inl(24) : fatal error C1083: Cannot open include file:
   'xmmintrin.h': No such file or directory</CODE>


    <P>
	 <B>_MSC_VER</B> - Use Microsoft x86 assembly when assembly code is needed.

    <P>
     <B>NO_SDL_MAIN</B> - Do not attempt to link against sdlmain.lib.

    <P>
     <B>_DEBUG</B> - Build in debug mode and link against the debug runtime DLLs.  This enables debugAssert, 
     debugBreak, debugAssertM, array bounds checks, etc. (Can be overriden by G3D_DEBUGRELEASE)
     <P>
     <B>G3D_DEBUG</B> - Enable debugAssert, 
     debugBreak, debugAssertM, array bounds checks, but relies on the _DEBUG flag to indicate whether
     to compile in debug or release mode.(Can be overriden by G3D_DEBUGRELEASE)
   <P>
   <B>G3D_DEBUGRELEASE</B> (or G3D_RELEASEDEBUG)- Use the release build of G3D and the standard library, but keep assertions
   that check for user errors.  This mode allows your program to run fast but still be debuggable.
    <P>
     <B>G3D_DEBUG_NOGUI</B> - When building in debug mode, this flag
      says to use stdout and not popups on Windows for assertion 
      failures and error messages.  On Linux the console is always used.

      <P>
      <B>G3D_GL_ARB_multitexture_static</B> - Assume OpenGL 1.3 when compiling the G3D library (specifically for Linux).  Must be configured when the library is built.
    <P>
      <B>G3D_WINSOCK_MAJOR_VERSION</B> - Controls the Winsock version used on Win32.  Must be configured when the library is built.
      <p>
      <B>G3D_WINSOCK_MINOR_VERSION</B> - Controls the Winsock version used on Win32.  Must be configured when the library is built.
    <P>
     <B>_WIN32</B> - Build using Windows API calls 

   <P>
     The static libraries themselves are built <I>without</I> SSE.  The 
     -debug versions have _DEBUG, the regular versions do not.
   
     <P>

     <B>G3D \#defines</B> one of the following based on the platform:
     <B>G3D_WIN32, G3D_MINGW32, G3D_LINUX, G3D_OSX</B>
   <HR>
  */
