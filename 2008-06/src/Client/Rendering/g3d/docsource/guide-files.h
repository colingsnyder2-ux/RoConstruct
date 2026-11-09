/** @page guidefiles Working with Files & Networks
  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guideui.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
User Input</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidephysics.html">
Physics and Ray Tracing <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

  This section describes how to manipulate files on disk (file management) and how to move
  data in and out of your program through files and the network.  For the latter, %G3D
  provides support for text (ASCII) files using a tokenizer and pretty-printer and 
  for binary files and network streams using a serialization API.

  @section filemanagement File Management

  G3D wraps most operating system file services to make them cross platform and easier to
  use.

  G3D::filenameBaseExt, 
  G3D::filenameExt, and
  G3D::parseFilename process strings containing filenames.  To obtain directory listings
  (including wildcards), use G3D::getFiles, and G3D::getDirs. 

  G3D::copyFile,
  G3D::createDirectory,
  G3D::createTempFile,
  G3D::fileExists,
  G3D::fileLength, and
  G3D::resolveFilename, provide information about files and allow directory management.

  @section textfiles Text Files

  Text files are human-readable ASCII files that you can view in Notepad, Emacs, or vi.  They
  are convenient for configuration files, output logs (see also G3D::Log), and for making little 
  scripting languages.  Text files are larger and slower than binary files, so for large amounts of
  data consider using binary files instead.

  G3D::readFileAsString and G3D::writeStringToFile are the easy way to save and load strings
  directly to files.

  To help with parsing configuration and script files, the powerful G3D::TextInput provides 
  both basic text parsing and a tokenizer.  The tokenizer is particularly handy for 
  reading data files formatted in the style of C++, Java, Matlab, and Excel's CSV. 
  G3D::TextOutput supports the mirror operations for writing nicely formatted text files with nested 
  indenting.

  Many classes provide <CODE>serialize(G3D::TextOutput&)</CODE> and <CODE>deserialize(G3D::TextInput&)</CODE>
  methods so that they can automatically read and write text files.  You can call these recursively
  from your own classes to quickly implement loading and saving of complex data files.
 
  @section binaryfiles Binary Files

  Binary files contain raw byte values.  The exact format of a binary file must be known in order
  to load or edit it.  The format of data on disk often differs slightly from the format in memory.
  There are several reasons for this.  Pointers cannot be written directly to disk (since they
  refere to live memory addresses), so data structures containing pointers must be specially coded
  to use integer indices or a similar scheme.  Different compilers align the fields of a structure
  differently in memory.  For example <CODE>struct { uint8 x; uint32 y}</CODE> might be five bytes
  under one compiler and eight bytes under another in order to dword-align the <CODE>y</CODE> field.
  So that programs compiled under different compilers can parse each other's files, the binary format
  for a file will specify the exact disk layout and on load a program can adjust that layout for 
  efficient in-memory use.  A similar problem occurs between different computer architectures.  
  Big-endian (e.g., PPC, Mac, Sun) machines store integers in the opposite byte order from little-endian
  (e.g., Intel, AMD) machines.  In order for programs executing on different architectures to read
  each other's files and send data across the network the byte order must be fixed.

  G3D::BinaryInput and G3D::BinaryOutput simplify parsing and writing binary files.  They
  can handle both big- and little-endian files and make appropriate corrections for the current
  platform.  These classes also offer gzip-level compression
  and decompression simply by setting a flag.

  Many G3D classes have serialize methods that can save the state of that class
  to a text or binary output and deserialize methods that can.  The overloaded
  G3D::serialize and G3D::deserialize functions provide the same functionality
  for built-in types like bool, float, and std::string.

  @section network Network

  The network API is build on top of G3D::BinaryInput and G3D::BinaryOutput.  Any class
  that provides serialize/deserialize methods can be sent across the network.

  G3D::NetworkDevice is to sockets as G3D::RenderDevice is to OpenGL-- it wraps them
  and simplifies state management.  Use it to create G3D::ReliableConduit (TCP) and
  G3D::LightweightConduit (UDP) connections between machines.  Both use the same 
  serialize/deserialize methods as the file I/O classes.  Reliable conduits guarantee
  that messages will arrive, and that the will arrive intact and in the order they were sent.  
  Lightweight conduits guarantee that messages will either arrive intact or not arrive 
  at all, but they do not guarantee ordering or delivery and are limited in size.

  The Discovery API (G3D::DiscoveryClient and G3D::DiscoveryServer) simplifies
  LAN server browsing and peer-to-peer networking.  You can use it to locate other
  computers on the local subnet that are running your application and automatically
  connect to them.

  These functions are demonstrated in the <A HREF="../demos/Network_Demo">demo/Network_Demo</A>
  and <A HREF="../contrib/pingtest/pingtest">contrib/pingtest</A> application.

  For a higher level, Open Source network API, consider the Torque Network Library, OpenTNL
  <A HREF="http://www.opentnl.org/">http://www.opentnl.org/</A>.

  @section images Images
    
  G3D::GImage can load many kinds of image files.  It is used internally by G3D::Texture.
 
  The G3D::computeNormalMap, G3D::flipRGBVertical, G3D::RGBtoARGB, G3D::RGBtoBGR, G3D::RGBtoBGRA, G3D::RGBtoRGBA, and G3D::RGBxRGBtoRGBA
  provide some basic image management services but we do not recommend using GImage for more
  advanced image processing.   (We chose the name "G"Image so
  you can introduce your own "Image" class without a name conflict).
  Consider the Open Source use ImageMagik for serious image work, or the 
  <A HREF="../contrib/Image">contrib/Image</A> class.

  @section models Models

    <CENTER><TABLE BORDER=1 WIDTH=75% BGCOLOR=#CCCCCC>
  <TR><TD>
  G3D does not provide a scene graph-- you must write that yourself even if it is as
  simple as a G3D::Array of objects.  
    </TD></TR></TABLE></CENTER>

 
  G3D includes some (optional) structure that you can use to connect your 
  scene graph to the rendering and effect mechanisms.  All 3D scene graphs
  distinguish between <I>entities</I>, instances of objects in the world, and
  the common <I>models</I> that describe their geometry.  For example, in a battle
  game between 50 knights and 50 ogres, there might be only two models (knight and ogre) that
  are referenced by 100 entities.  This design pattern avoids storing redundant 
  geometry for the models.  

  When we say that G3D provides no scene graph we mean that it has no Entity class
  (although several of the demos contain them).  The reason is that the design of 
  an Entity is extremely application specific.  A video game may need an entity
  with a 3D position, health rating, and weapon specification.  A CAD simulation might
  instead focus on detailed parameters like electrical resistance and 3D density.

  G3D has no common "Model" base class, but it does include two model classes.
  They have no class relationship because the interface to a model is very 
  dependent on the kind of 3D data.  Here's an example.  G3D::IFSModel describes rigid bodies
  with a single texture or color.  It makes the underlying geometry available
  in great detail, but does not provide animation facilities.
  G3D::MD2Model supports Quake 2 characters.  It has methods for making a model
  run, jump, and attack, but does not directly provide the underlying geometry
  because it is stored in a compressed form.  The methods of one model class
  are simply not appropriate for another one.

  All models are eventually <I>posed</I> and sent to the graphics system for rendering.  At that point 
  the interface has specific demands and there is a common base class, G3D::PosedModel.
  The pure virtual class, G3D::PosedModel, represents part of 
  a scene graph that has been prepared for rendering.  A single model may produce multiple
  G3D::PosedModels or many models may be condensed into a single G3D::PosedModel.  Note that
  %G3D is primarily an immediate-mode rendering API.  You can render by simply making
  calls on a G3D::RenderDevice, without creating a G3D::PosedModel.  The advantage of
  G3D::PosedModel is that you can create generic rendering effects (e.g., G3D::beginShadows,
  G3D::drawFeatureEdges) and apply them to many kinds of models.

  To aid in creation of meshes and parsing other file formats, <A HREF="../contrib/IFSBuilder">
  contrib/IFSBuilder</A> is an unsupported program that parses 3DS, OBJ, and other mesh
  files and creates some procedural meshes.  You will need to edit the source code to 
  use it.

  <A HREF="../contrib/ArticulatedModel">contrib/ArticulatedModel</A> is a sophisticated
  model class that supports jointed bodies with complicated shading, reflection, and
  transparency effects.  It loads 3DS, IFS, and PLY2 files.  The demo in that package
  shows how to effectively use G3D::PosedModel for rendering transparent objects.
*/