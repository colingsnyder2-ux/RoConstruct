/**
  @page indexedbytopic APIs by Topic

@section app Application Framework (G3DAll.h, glg3d.lib)
<I>High-level building blocks for creating applications.</I>

  <UL>
  <LI><B>3D Models</B> &nbsp; &nbsp;
    G3D::GFont,
    G3D::GLight,
    G3D::GMaterial,
    G3D::IFSModel,
    G3D::Lighting,
    G3D::LightingParameters,
    G3D::Shape,
    G3D::MD2Model,
    G3D::PosedModel,
    G3D::PosedModel2D,
    G3D::PosedModelWrapper
    G3D::Sky
    <BR>See also contrib & demo code 
    <A HREF="../contrib/ArticulatedModel">ArticulatedModel</A>, 
    <A HREF="../contrib/Q3Map">Q3Map</A>, 
    <A HREF="../contrib/IFSBuilder">IFSBuilder</A>,
    <A HREF="../contrib/ObjModel">ObjModel</A>,
    <A HREF="../demos/MD2Model_Demo">MD2Model_Demo</A>

  <LI><B>Application Structure</B> &nbsp; &nbsp;
    G3D::FirstPersonManipulator,
    G3D::GApp, 
    G3D::GApplet, 
    G3D::GAppSettings,
    G3D::GModule,
    G3D::GModuleManager
    G3D::Manipulator,
    G3D::UserInput
  <BR>
  See also demo code
    <A HREF="../demos/main.cpp">main.cpp</A>, 

  <LI><B>Effects</B> &nbsp; &nbsp;
    G3D::beginMarkShadows, 
    G3D::endMarkShadows, 
    G3D::markShadows,
    G3D::drawFeatureEdges,
    <BR>
  See also contrib & demo code
    <A HREF="../contrib/ArticulatedModel/ToneMap.h">ToneMap</A>, 
    <A HREF="../contrib/shaders">Shaders</A>, 
    <A HREF="../demos/GLSL_Demo">GLSL_Demo</A>, 
    <A HREF="../demos/ASM_Shader_Demo">ASM_Shader_Demo</A> 

   </UL>

  For GUIs see also contrib code
    <A HREF="../contrib/wxGWindow">wxGWindow</A> (using wxWidgets),
    <A HREF="../contrib/CurveEditor">CurveEditor</A> (GUI example from scratch)
  <BR>For audio see also contrib code
    <A HREF="../contrib/AudioDevice">AudioDevice</A>

@section gl Hardware Rendering (G3DAll.h, glg3d.lib)
<I>An easy-to-use wrapper for OpenGL and a platform-independent windowing system.</I>

 <UL>
  <LI><B>OpenGL Abstraction</B> &nbsp; &nbsp;
    G3D::Draw,
    G3D::Framebuffer,
    G3D::GLCaps,
    G3D::glDisableAllTextures,
    G3D::glToScreen,
    G3D::Milestone,
    G3D::ObjectShader,
    G3D::PixelProgram,
    G3D::Renderbuffer,
    G3D::RenderDevice,
    G3D::RenderDeviceSettings,
    G3D::Texture,
    G3D::TextureFormat,
    G3D::TextureManager,
    G3D::VAR,
    G3D::VARArea, 
    G3D::VertexProgram,
    G3D::VertexAndPixelShader,
    G3D::Shader

  <LI> <B>Window managment</B>&nbsp; &nbsp;
    G3D::GEvent,
    G3D::GWindow,
    G3D::SDLWindow,
    G3D::Win32Window,
    G3D::X11Window,
        <BR>
    See also contrib & demo code
    <A HREF="../contrib/GlutWindow">GlutWindow</A>, 
    <A HREF="../contrib/wxGWindow">wxGWindow</A>,
    <A HREF="../contrib/CoreyGWindow">QtWindow</A>
    <A HREF="../demos/main-no-GApp.cpp">main-no-GApp.cpp</A>, 

  <LI><B>Extensions to base OpenGL</B> &nbsp; &nbsp;
    debugAssertGLOk,
    DECLARE_GLFORMATOF,
    G3D::glLoadMatrix, 
    G3D::glLoadInvMatrix, 
    G3D::GLCaps,
    G3D::glColor,
    G3D::glMultInvMatrix, 
    G3D::glMultMatrix, 
    G3D::glMultiTexCoord,
    G3D::glNormal, 
    G3D::glTexCoord, 
    G3D::glToScreen,
    G3D::glVertex,
    G3D::sizeOfGLFormat, 
    G3D::glFormatOf, 
    G3D::glGetProcAddress,
    G3D::getOpenGLState,
    G3D::glGetInteger, 
    G3D::glGetBoolean,
    G3D::glGetDouble, 
    G3D::glGetFloat,
    G3D::glGetMatrix,
    G3D::GLenumToString
</UL>

@section math 3D Math and Systems (graphics3d.h, g3d.lib)
<I>Core data structures and system functionality.</I>

    <UL>
     <LI><B>Geometry</B> &nbsp; &nbsp;
        G3D::AABox,
        G3D::Box,
		G3D::Capsule,
		G3D::CollisionDetection,
		G3D::Color3,
		G3D::Color3uint8,
        G3D::Color4,
		G3D::Color4uint8,
		G3D::Cone,
		G3D::ConvexPolygon,
		G3D::ConvexPolygon2D,
		G3D::ConvexPolyhedron,
		G3D::CoordinateFrame,
        G3D::Cylinder,
        G3D::GCamera,
		G3D::PhysicsFrame,
		G3D::Line,
		G3D::LineSegment,
		G3D::LineSegment2D,
		G3D::Matrix3,
        G3D::Matrix4,
        G3D::MeshAlg,
        G3D::MeshBuilder,
        G3D::Quat,
		G3D::Plane,
		G3D::Ray,
        G3D::Rect2D,
        G3D::Sphere,
		G3D::Triangle,
		G3D::Vector2,
        G3D::Vector2int16,
		G3D::Vector3,
		G3D::Vector3int16,
		G3D::Vector4,
        G3D::GameTime,
        G3D::RealTime,
        G3D::tesselateComplexPolygon,
        G3D::toSeconds 
     
     <LI><B>Integer math</B> &nbsp; &nbsp;
        G3D::ceilPow2, 
        G3D::highestBit,
	    G3D::iAbs,
		G3D::iCeil,
		G3D::iClamp,
		G3D::iWrap,
		G3D::iFloor,
		G3D::iMax, 
        G3D::iMin,
	    G3D::isPow2,
		G3D::isOdd,
		G3D::isEven, 
		G3D::iSign,
		G3D::iRound,
		G3D::iRandom,
		G3D::uint8,
		G3D::uint16,
		G3D::uint32,
		G3D::uint64,
        G3D::int8,
		G3D::int16,
		G3D::int32,
		G3D::int64
     
     <LI><B>Floating point</B> &nbsp; &nbsp;
	     G3D::abs,
		 G3D::aCos,
		 G3D::aSin,
		 G3D::aTan,
		 G3D::aTan2,
         G3D::clamp,
         G3D::cyclicCatmullRomSpline,
		 G3D::float32,
         G3D::float64
         G3D::fuzzyEq,
         G3D::fuzzyNe,
         G3D::fuzzyGt,
         G3D::fuzzyGe,
         G3D::fuzzyLt,
         G3D::fuzzyLe,
         G3D::fuzzyEpsilon,
         G3D::gaussRandom,
         G3D::lerp,
		 G3D::linearSpline,
         G3D::sign,
		 G3D::rsq,
		 G3D::unitRandom,
		 G3D::random,
         G3D::symmetricRandom,
         G3D::min,
		 G3D::max,
		 G3D::square,
         G3D::sinc,
		 G3D::sumSquares,
		 G3D::distance,
         G3D::toRadians,
		 G3D::toDegrees,
		 G3D::isNaN,
		 G3D::isFinite,
         G3D::inf,
		 G3D::nan,
         G3D::wrap,
		 G3D_PI, 
         G3D_HALF_PI,
		 G3D_TWO_PI,
         G3D::rsqrt
         
     <LI><B>String</B> &nbsp; &nbsp;
        G3D::beginsWith, 
        G3D::endsWith, 
        G3D::format,
        G3D::isSpace,
        G3D::isSlash,
        G3D::isWhiteSpace,
        G3D::isDigit,
        G3D::isNewline,
        G3D::isLetter,
        G3D::isQuote,
        G3D::license, 
        G3D::vformat, 
        G3D::wordWrap, 
        G3D::stringCompare, 
        G3D::stringPtrCompare, 
        G3D::stringSplit,
        G3D::stringJoin, 
        G3D::toUpper, 
        G3D::toLower,
        G3D::NEWLINE, 
        G3D::trimWhitespace, 
        STR

     <LI><B>Data structures</B> &nbsp; &nbsp;
        G3D::AABSPTree,
		G3D::Array,
		G3D::Queue,
 	    G3D::Set,
		G3D::Table,
        G3D::ReferenceCountedObject,
        G3D::ReferenceCountedPointer,
        G3D::WeakReferenceCountedPointer

     <LI><B>Image formats</B> &nbsp; &nbsp;
        G3D::BAYER_G8B8_R8G8_to_R8G8B8_MHC,
        G3D::BAYER_G8B8_R8G8_to_Quarter_R8G8B8,
		G3D::GImage,
		G3D::GImage::Error,	
		G3D::computeNormalMap,
        G3D::flipRGBVertical,
        G3D::flipRGBAVertical,
        G3D::Quarter_R8G8B8_to_BAYER_G8B8_R8G8,
  	    G3D::RGBtoARGB,
		G3D::RGBtoBGR,
		G3D::RGBtoBGRA,
        G3D::RGBtoRGBA,
		G3D::RGBxRGBtoRGBA
        <BR>
    See also contrib code
    <A HREF="../contrib/Image">Image</A>, 
    <A HREF="../contrib/Webcam">Webcam</A>, 


     <LI><B>Debug</B> &nbsp; &nbsp;
        alwaysAssertM, 
        debugAssert, 
        debugAssertM,
        G3D::describeSystem,
        G3D::isValidHeapPointer,  
        G3D::isValidPointer,
        G3D::debugPrintf,
        G3D::Log,
        G3D::setAssertionHook,
        G3D::setFailureHook

     <LI><B>System + Files</B> &nbsp; &nbsp;
        G3D::AtomicInt32,
        G3D::BinaryFormat, G3D::byteSize, G3D::binaryFormatOf,
        G3D::BinaryInput, 
        G3D::BinaryOutput, 
        G3D::copyFile, 
        G3D::createDirectory,
        G3D::createTempFile, 
        G3D::Crypto,
        G3D::isDirectory,
        G3D::filenameContainsWildcards,
        G3D::fileExists, 
        G3D::fileLength,
        G3D::filenameBaseExt,
        G3D::filenameExt,
        G3D::filenamePath,
        G3D::fileIsNewer,
        G3D::G3DEndian,
        G3D::GThread,
        G3D::getFiles, 
        G3D::getDirs,
        G3D::msgBox,
        G3D::parseFilename, 
        G3D::prompt, 
        G3D::readFileAsString,
        G3D::System,
        G3D::Stopwatch,
        G3D::resolveFilename,
        G3D::TextInput,
		G3D::TextOutput,
        G3D::Token,
        G3D::TextInput::WrongTokenType,
        G3D::writeStringToFile

    <LI><B>Network</B> &nbsp; &nbsp;
        G3D::DiscoveryAdvertisement,
        G3D::DiscoveryClient,
        G3D::DiscoveryServer,
        G3D::DiscoverySettings,
        G3D::LightweightConduit,
        G3D::NetAddress,
        G3D::NetListener,
        G3D::NetMessage,
        G3D::NetworkDevice, 
        G3D::ReliableConduit
<BR>
  See also contrib & demo code 
    <A HREF="../contrib/pingtest">pingtest</A>, 
    <A HREF="../demos/Network_Demo">Network_Demo</A>, 
     </UL>

 <A HREF="map.png"><IMG SRC="map.png" WIDTH=128></A>
     */
