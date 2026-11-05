/**
 @page changelog Change Log

<IMG SRC="G3D.gif" ALIGN=RIGHT>
<P>

   Major version numbers introduce API changes that are not backwards
   compatible.  Minor versions are backwards compatible to the
   previous major release [except for bug fixes].  Deprecated functionality
   will be supported until (at least) the next major release.

   <TABLE><TR><TD>
   <I>The next major, incompatible release will be G3D 7.00, planned for release in January 2007 (there will be betas
      and point releases before then). We plan to streamline the API by making the following changes:</I>
     <UL>
       <LI>All <A HREF="deprecated.html">deprecated</A> functionality will be removed.
       <LI>G3D::Sky create methods will no longer accept a G3D::RenderDevice.
       <LI>G3D::GFont::fromFile method will no longer accept a G3D::RenderDevice.
       <LI>All accessor "get" methods that return a value will have their prefix removed (e.g., G3D::RenderDevice::getObjectToWorldMatrix -> G3D::RenderDevice::objectToWorldMatrix).
       <LI>G3D::MeshAlg arguments will change-- e.g., many routines will no longer compute face/vertex normals for you
       <LI>SDL will no longer be automatically linked into the Win32 build
       <LI>Some contrib classes will move into the main API (e.g., SuperShader, ArticulatedModel, ToneMap, Matrix)
       <LI>GApplet methods will change to exclusively use the onUserInput, onGraphics, etc. forms.  doGraphics, etc. forms will be removed. 
       <LI>G3D::GEvent will become a standalone class instead of a typedef.  All event constants will be renamed.
       <LI>The main headers and library names may change
       <LI>The directory structure for third party libraries (e.g., libjpeg) may change
     </UL>
   </TD></TR></TABLE>

   <P>
   Changes in 6.09:
   <UL>
    <LI> glDepthBoundsEXT
    <LI> G3D::Quat::sameRotation
    <LI> Full loading of the GL_ATI_separate_stencil extension, support within RenderDevice
    <LI> platform.h undefines WIN32_LEAN_AND_MEAN, NOMINMAX after it has defined them
    <LI> G3D::Texture::Settings::maxMipMap
    <LI> Renamed Texture::Parameters to Texture::Settings (backwards compatible typedef added)
    <LI> Optimized IFSModel rendering by increasing internal VAR cache size and reducing the number of state changes.  
        Can now render more than 1000 IFSModels at 30 fps on GeForce 7800.
    <LI> G3D::System::mallocStatus
    <LI> Range checking on Vector2int16::operator[]
    <li> GImage::BAYER_G8R8_B8G8_to_R8G8B8_MHC, GImage::BAYER_B8G8_G8R8_to_R8G8B8_MHC
    <LI> IFSModel and MD2Model now allocated their posed models using System::malloc
    <LI> Increased the memory maintained by G3D::System for buffer pools up to a total of 13 MB: 
         8 MB tiny (preallocated), 1 MB small (on demand), 4 MB medium (on demand).  This was observed to 
         dramatically increase performance (15x) in real programs that were 
         performance limited by memory allocation time.
    <LI> NetworkDevice now uses Winsock2.0 on Windows (controlled by the G3D_WINSOCK_MAJOR_VERSION/G3D_WINSOCK_MINOR_VERSION settings in NetAddress.h)
    <LI> G3D::Manipulator
    <LI> G3D::GApplet now runs installed G3D::GModules (except for graphics, which is left to the progrmamer)
    <LI> G3D::GApp::addModule, G3D::GApplet::addModule, G3D::GApp::removeModule, G3D::GApplet::removeModule
    <LI> G3D::GModule, G3D::GModuleManager
    <LI> G3D::System::getEnv()
    <LI> G3D::PosedModel2D
    <LI> G3D::DXCaps
    <LI> Increased precision of several Quat operations
	<LI> G3D::Quat::fuzzyEq
	<LI> G3D::Quat::operator-
    <LI> G3D::LineSegment::length, G3D::LineSegment::point
	<LI> Increased fuzzyEpsilon by a factor of 10 to take into account the new float32 focus of the APIs
    <LI> G3D::RegistryUtil
    <LI> G3D::LineSegment2D
    <LI> G3D::ConvexPolygon2D
    <LI> G3D::AxesShape
    <LI> contrib/shaders/showDepth
    <LI> G3D::Crypto with MD5 and CRC32 hashes
    <LI> TextureManager::findTexture, TextureManager::cacheTexture [Erik]
    <LI> Win32Window::_directInput created on-demand [Erik]
    <LI> WeakReferenceCountedPointer has more comparison operators [Erik]
    <LI> GImage::resolveFormat utility function [Erik]
    <LI> GLCaps supports MESA
    <LI> G3D::Win32Window and G3D::SDLWindow now release input capture and make the mouse visible on destruction
    <LI> G3D::GWindow::setInputCaptureCount, G3D::GWindow::inputCaptureCount, G3D::GWindow::incInputCaptureCount, G3D::GWindow::decInputCaptureCount
    <LI> GImage::makeCheckerboard
    <LI> G3D::Vector3::one()
    <LI> G3D::Shader now supports g3d_size(sampler2D) and g3d_invSize(sampler2D) extensions in GLSL shaders.
    <LI> Renamed GAppSettings to G3D::GApp::Settings (old name is supported but deprecated)
	<LI> Renamed GWindowSettings to G3D::GWindow::Settings (old name is supported but deprecated)
	<LI> Renamed TextInput::Options to G3D::TextInput::Options (old name is supported but deprecated)
    <LI> G3D::FPManualController::setAutoActive for World of Warcraft style controller
    <LI> G3D::isSlash, G3D::isQuote
    <LI> G3D::GApplet::onEvent can now consume (i.e., prevent G3D::GApp from seeing) the event
    <LI> G3D::CoordinateFrame::fuzzyIsIdentity, G3D::CoordinateFrame::isIdentity, G3D::CoordinateFrame::fuzzyEq
    <LI> Matrix3::isOrthonormal
    <LI> [1421201] Removed excess gl (NVIDIA) headers
    <LI> Win32Window destructor now releases the mouse if it was captured and the current GL context is that window and the window was not created from an existing HDC/HWND
    <LI> Fix: com.graphics3d.g3d.ReliableConduit now correctly selects on the waiting socket
	<LI> Fix: [ 1166057 ]  AABSPTree::beginBoxIntersection
    <LI> Fix: GLCaps::supports(TextureFormat) now returns correct results on all cards
    <LI> Fix: Shadow map rendering of default PosedModels now enables lighting
    <LI> Fix: G3D::UserInput now restores the mouse position after pureDeltaMouse is turned off
    <LI> Fix: G3D::Win32Window now clips precisely to the client area during an input grab.
	<LI> Fix: [ 1383042 ] free static variables on shutdown
	<LI> Fix: [1449115 ] Texture loading for odd-byte rows
    <LI> Fix: G3D::Win32Window now produces correct character and scan codes for key events
    <LI> Fix: G3D::GApplet::onEvent calls GApplet::processEvent by default
    <LI> Fix: [ 1444320 ] TextInput parsed ".1" as "1" instead of "0.1"
    <LI> Fix: G3D::Shape::type is now const
    <LI> Fix: 0 --> 0.0f FrameBuffer.h [Erik]
    <LI> Fix: Fixed Texture read-back dimensions for cube-map
    <LI> Fix: Missing #include in LightingParameters.h [Erik]
    <LI> Fix: Quad triangle counts are now accurate (were off by factor of 4 in 6.08)
    <LI> Fix: contrib/ArticulatedModel now correctly masks all components using the diffuse alpha in fixed function mode
    <LI> Fix: G3D::CoordinateFrame::getHeading was flipped front-to-back
    <LI> Fix: [ 1404487 ] Missing Alt key up/down events on Win32
    <LI> Fix: [ 1484924 ] collisionTimeForMovingPointFixedBox normals
   </UL>
  <P>   
   Changes in 6.08:
    <UL>      
	  <LI> Moved Win32 linker statements out of platform.h for IncrediBuild compatibility.
      <LI> G3D::Texture and G3D::Sky now accept a rescaling factor
      <LI> Added GFont::fromMemory() [Corey]
      <LI> Added optional argument to Quat::slerp() for slerp/lerp angle threshold. [Corey]
      <LI> Across-the-board performance optimizations.  Most apps should render 10% faster.
           Includes removal of Milestones when using VBO VAR [Nick Bray], GFont::draw2D and 
           Draw::rect2D stripped down to raw OpenGL, consistent internal use of float,
           increased RenderDevice state change optimization.
	  <LI> Minimized header interdependencies (GLG3D headers no longer include all of G3D)
      <LI> Added GThread and GMutex classes. [Corey]
      <LI> Added TextureFormat::fromCode(). [Corey]
      <LI> Added Plane::distance() and Plane::closestPoint() helper methods. [Corey] 
      <LI> G3D::TextureFormat::code, G3D::TextureFormat::colorSpace
      <LI> <B>incompatible change</B> G3D::MeshAlg::computeTangentSpace basis now computes a right-handed coordinate frame,
           where the binormal direction is the negative of the direction it faced in G3D 6.07.
      <LI> Exposed G3D::RenderDevice::beforePrimitive and G3D::RenderDevice::afterPrimitive to end-user code for
           integrating raw OpenGL calls.
      <LI> G3D::Framebuffer and G3D::Renderbuffer to implement the Framebuffer_object extension [Dan Hilferty]
      <LI> G3D::Shader::hasArgument
      <LI> G3D::Texture::getImage
      <LI> Changed SECOND, MINUTE, DAY, HOUR, SUNRISE, SUNSET, MIDNIGHT, METER, KILOMETER to enum values instead of #defines
      <LI> G3D::Texture::Parameters; deprecated most Texture constructors in favor of ones that use this class
      <LI> Moved most image manipulation routines into GImage.
      <LI> G3D::GImage now allocates the underlying buffer in multiples of bytes to allow slight overflor for MMX algorithms
      <LI> G3D::GImage::BAYER_R8G8_G8R8_to_R8G8B8_MHC
      <LI> G3D::GImage::R8G8B8_to_Y8U8V8
      <LI> G3D::GImage::Y8U8V8_to_R8G8B8
      <LI> G3D::GImage now supports PPM binary
      <LI> Various Rect2D helpers [Nick Bray]
      <LI> ConvexPolyhedron improved clipping [Nick Bray]
      <LI> G3D::System::build
      <LI> G3D::System::calloc
      <LI> G3D::GImage::convertToRGBA
      <LI> contrib/AVI can read most AVI files on Windows.
      <LI> contrib/wxGWindow now uses wxWidgets 2.6.2
      <LI> G3D_DEBUG now controls whether debug code is enabled; it defaults to the value of _DEBUG
      <LI> zlib upgraded to 1.2.3 [Corey]
      <LI> zlib now statically linked on Win32 (no longer requires zlib1.dll at runtime) [Corey]
      <LI> G3D::MeshShape
      <LI> Changed std::string hashCode to use CRC32 to reduce collisions
      <LI> G3D::crc32
      <LI> Added occlusion query #defines [Nick Bray]
	  <LI> G3D::Win32Window now shares textures and vertex buffers across all GL contexts
	  <LI> G3D::Win32Window now enforces single-threading among GL contexts
	  <LI> G3D::GLCaps::slowVBO
	  <LI> G3D::VARArea now uses main memory vertex buffers on cards with slow VBO implementations.
	  <LI> G3D::Matrix3::toString [Peter]
	  <LI> G3D::Matrix4::toString [Peter]
	  <LI> G3D::Color3::fromHSV [Peter]
	  <LI> G3D::Color3::toHSV   [Peter]
	  <LI> G3D::Color3::jetColorMap [Peter]
      <LI> Optimized G3D::iRound (now faster than casting!)
      <LI> G3D::MD2Model::create now accepts a scale factor
      <LI> #G3D_DEPRECATED macro
      <LI> #G3D_CHECK_PRINTF_ARGS, #G3D_CHECK_VPRINTF_ARGS macros to allow
           checking of printf argument strings under gcc at compile time with
           -Wformat.
      <LI> G3D::TextInput::filename
      <LI> G3D::TextInput::Options::msvcSpecials
      <LI> G3D::TextInput::Options::startingLineNumberOffset
      <LI> G3D::TextInput::readSymbolToken [cgd]
      <LI> G3D::TextInput::readStringToken [cgd]
      <LI> G3D_DEPRECATED macro
      <LI> Threadsafe G3D::ReferenceCountedPointer
      <LI> G3D::AtomicInt32
      <LI> G3D::GThread [Corey]
      <LI> G3D::Array::popDiscard
      <LI> Optimized multi-argument Array::append
      <LI> G3D::GFont 2x faster than in G3D 6.07
      <LI> G3D::RenderDevice::pushState 2x faster than in G3D 6.07
      <LI> G3D::RenderDevice::pushState no longer stores GL texgen and fog information           
      <LI> G3D::Draw::fastRect2D
      <LI> G3D::System::outOfMemoryCallback
      <LI> G3D::Queue::fastClear [Chris Demetriou]
      <LI> G3D::Rect2D::x0y1 and x1y0
      <LI> G3D::GLCaps bug tests now run in a separate GL context [Erik Cassel]
      <LI> G3D::GApplet tracks real and simulation time.
      <LI> contrib/Q3Map updated to correctly render instanced objects [Alex Rice]
      <LI> G3D::GWindow subclasses now required to invoke GWindow::loadExtensions
      <LI> G3D::Quat::log for non-unit quats and for real-only quats.
      <LI> G3D::GApplet::doUserInput
      <LI> G3D::GApp prints time for each component
      <LI> G3D::Stopwatch
      <LI> G3D::GWindow::renderDevice()
      <LI> G3D::GWindow::current()
      <LI> G3D::GLCaps::hasBug_redBlueMipmapSwap and workaround for G3D::Texture on Radeon 7500
      <LI> Fix: CollisionDetection::penetrationDepthForFixedSphereFixedPlane() contact point and normal values. [Corey]
      <LI> Fix: Quat::slerp has invalid shortest path [Corey]
      <LI> Fix: G3D::drawFeatureEdges now uses correctly normalized face edges (and offers a crease angle)
	  <LI> Fix: G3D::SDLWindow now releases the mouse on Linux during an assertion.
      <LI> Fix: All keys are reset to up when Win32Window loses focus. [Corey]
      <LI> Fix: gaussRandom is unit gaussian [Corey]
      <LI> Fix: [ 1418276 ] 6.08: Unsupported format for depth texture
      <LI> Fix: Ignoring extra/unused set Shader arguments. [Corey]
      <LI> Fix: [ 1229205 ] uniform texture array (Could not set indexed array uniforms). [Corey]
      <LI> Fix: <B>incompatible change</B> BinaryInput/BinaryOutput copy constructors and assignments were accessible. [Corey]
      <LI> Fix: RenderDevice::screenshotPic would corrupt GImage's heap. [Corey]
      <LI> Fix: Alt-Tab window switching caused an invalid Alt key state. [Corey]
      <LI> Fix: Incorrect window size event in Win32Window sent to OpenGL. [Corey]
      <LI> Fix: [ 1227915 ] Textures don't bind on ATI under GLSL.
      <LI> Fix: [ 1358477 ] ray-plane intersection bug [Dan Keefe]
      <LI> Fix: [ 1370665 ] hash_map moved to stdext in VC8 (2005)
      <LI> Fix: ToneMap extended to use DIM_2D_NPOT instead of DIM_2D_RECT
      <LI> Fix: Texture::copyFromScreen now works with DIM_2D_NPOT textures
	  <LI> Fix: Wrapped debugAssertM in do {} while (0) to ensure correct compilation in single-line statements [ERik Cassel]
      <LI> Fix: G3D::Draw::cylinder now renders the bottom correctly
      <LI> Fix: Array::front now compiles under gcc
      <LI> Fix: G3D::Ray::distance used to measure against the origin [David]
      <LI> Fix: [ 1293151 ] ArticulatedModel clipping on Radeon -- disabled auto-mipmap generation on mobile radeon 9xxx
      <LI> Fix: G3D::TextInput now parses ^=, character 255 correctly [cgd]
      <LI> Fix: G3D::TextInput now reports line numbers correctly with raw newlines [cgd]
      <LI> Fix: .ICO files with transparency loaded incorrectly [Corey]
      <LI> Fix: G3D::Draw::rect2DBorder inner border was 1 pixel too thick.
      <LI> Fix: [ 1326173 ] Win32Window::init should call makeCurrent.[Erik Cassel]
      <LI> Fix: [ 1326423 ] G3D::Queue::_copy broken [Chris Demetriou]
      <LI> Fix: [ 1313293 ] 6.08: TextInput gets symbol extendedType() wrong [Chris Demetriou]
      <LI> Fix: IFSModel::save, for PLY2  forgot newlines [Peter]
      <LI> Fix: Quat(Matrix3) now computes trace correctly (gave negative quats in some cases) 
      <LI> Fix: Setting RenderDevice::polygonOffset now always produces a depth shift,
                even for faces perpendicular to the view axis.
      <LI> Fix: GImage now auto-resolves formats for files with 1 character base names
      <LI> Fix: WeakReferenceCountedPointer cycle bug
      <LI> Fix: Corrected lag encountered when using some ReliableConduit constructors [Dan Keefe]
    </UL>

  <P>
   Changes in 6.07:
   <UL>
    <LI> G3D::GWindow::makeCurrent
    <LI> Win32 release binaries now built with no debug information (used to have line numbers)
    <LI> AABox::AABox enforces the constraint low <= high
    <LI> Optimized G3D::Array, Table, Queue, and Set for performance.  Now significantly (up to 10x) faster
         than their std::counterparts.
    <LI> G3D::Vector3(Vector2, float) constructor
    <LI> G3D::Vector2::fastDirection
    <LI> G3D::TextInput::Options::cComments
    <LI> G3D::TextInput::Options::escapeSequencesInStrings
    <LI> G3D::TextInput::Options::otherCommentCharacter2
    <LI> G3D::TextInput::WrongString
    <LI> GLCaps::supports_GL_ATI_separate_stencil
    <LI> GLCaps can now test a card/driver and detect specific bugs:
        <ul><li>G3D::GLCaps::hasBug_glMultiTexCoord3fvARB
        <LI> G3D::GLCaps::hasBug_normalMapTexGen
        </ul>
    <LI> G3D::ReferenceCountedPointer::downcast for non VC6 compilers
    <LI> Improved G3D::ReferenceCountedPointer documentation to make subclassing features clearer
    <LI> Moved typedef for uint into G3D namespace and into g3d (was in glg3d)
    <LI> G3D::Shape
    <LI> G3D::Cylinder
    <LI> G3D::System::malloc, G3D::System::realloc, G3D::System::free for fast allocation of small objects
    <LI> G3D::Draw::plane
    <LI> G3D::Draw::cylinder
    <LI> G3D::gaussRandom
    <LI> GCamera deserialize(BinaryInput) & serialize(BinaryOutput) functions [Peter]
    <LI> G3D::GApp now writes a description of the whole system to the log to aid debugging.
    <LI> [ 1217928 ] OpenGL occlusion query entry points are loaded on initialization
    <LI> New texture interpolation modes: BILINEAR_MIPMAP, NEAREST_MIPMAP, NEAREST_NO_MIPMAP
    <LI> New texture formats:
      <UL>
        <LI> G3D::TextureFormat::L16;
        <LI> G3D::TextureFormat::L16F;
        <LI> G3D::TextureFormat::L32F;
        <LI> G3D::TextureFormat::A16;
        <LI> G3D::TextureFormat::A16F;
        <LI> G3D::TextureFormat::A32F;
        <LI> G3D::TextureFormat::LA4;
        <LI> G3D::TextureFormat::LA16;
        <LI> G3D::TextureFormat::LA16F;
        <LI> G3D::TextureFormat::LA32F;
        <LI> G3D::TextureFormat::RGB16;
        <LI> G3D::TextureFormat::RGB16F;
        <LI> G3D::TextureFormat::RGB32F;
        <LI> G3D::TextureFormat::RGBA16;
        <LI> G3D::TextureFormat::RGBA16F;
        <LI> G3D::TextureFormat::RGBA32F;
      </UL>
     <LI> isValidPointer and isValidHeapPointer no longer check the Win32 debug heap in order to support offset and padded memory blocks.
     <LI> Restructured unit tests
     <LI> G3D::CoordinateFrame::lookRay [David Baszucki]
     <LI> G3D::System::describeSystem, G3D::NetworkDevice::describeSystem, G3D::RenderDevice::describeSystem
     <LI> G3D::Array performance tuning for short arrays and arrays of small objects
     <LI> Added glext.h entries for GL_ARB_draw_buffers, GL_ARB_texture_rectangle, 
          GL_ARB_color_buffer_float, GL_ARB_half_float_pixel, GL_ARB_texture_float, 
          and GL_ARB_pixel_buffer_object extensions
     <LI> IFSModel::create  added weld option, defaults to true (to keep compatibility). [Peter]
     <LI> G3D::RenderDevice::alphaTestReference, RenderDevice::alphaTest
     <LI> G3D::VAR::set
     <LI> G3D::Log::vprintf
     <LI> G3D::WeakReferenceCountedPointer
     <LI> GCC 4.0 build support added [Corey]
     <LI> G3D::CoordinateFrame::lookAt now gives a valid output even when look == up
     <LI> contrib/GChunk
     <LI> GLCaps now loads GL_EXT_framebuffer_object functions
     <LI> Added MSVC 6 support for C99 restrict keyword
     <LI> G3D::Win32Window properly resizes viewport on window resize [Corey]
     <LI> G3D::BinaryFormat, G3D::byteSize, G3D::binaryFormatOf
     <LI> Removed dead ManualCameraControllerHelper code
     <li> Added consistent area and volume methods to geometric primitives, deprecated old methods.
     <LI> Fast G3D::BinaryInput::read / G3D::BinaryOutput::write methods for arrays 
     <LI> Enabled cube mapping on Radeon mobility cards and added a workaround to the known problems with texcoords on those cards.
     <LI> Can now create G3D::Win32Window with existing HWND and HDC [Corey]
     <LI> G3D::VertexAndPixelShader::ArgList::set(std::string, Array<T>)-- [ 1192401 ] Shader support arrays
     <LI> Fix: SDLWindow used std::string's instead of C strings in printf and format inside some exception handling code. [Peter]
     <LI> G3D::X11Window (same as SDLWindow in this release)
     <LI> Fix: [ 1277854 ] Win32Window fails on 24-bit modes
     <LI> RFE: [ 1242466 ] Inline Matrix3 methods
     <LI> Fix: [ 1226272 ] end caps of capsules in wrong position
     <LI> Fix: G3D::TextureFormat::LA8 now has 8-bits per channel
     <LI> Fix: [ 1124491 ] Remove GL_SAMPLER_2DRECT_ARB
     <LI> Fix: [ 1257113 ] G3D::Queue problems comining pushFront and pushBack
     <LI> Fix: MeshAlg::Weld now linear time (was O(n^2) due to a bug)
     <LI> Fix: [ 1298873 ] fast & correct CoordinateFrame::lerp
   </UL>

  <P>
   Changes in 6.06:
   <UL>
    <LI> G3D::Lighting::emissiveScale
    <LI> G3D::RenderDevice::drawBuffer
    <LI> G3D::RenderDevice::debugNumMinorStateChanges, debugNumMinorOpenGLStateChanges, debugNumMajorStateChanges, debugNumMajorOpenGLStateChanges.
    <LI> In stereo mode, Texture::copyFromScreen automatically chooses the left/right buffer to read based on the current glDrawBuffer
    <LI> contrib/ArticulatedModel/ToneMap
    <LI> Lazy state changes for shaders
    <LI> 50% performance improvement for G3D::BinaryInput, G3D::BinaryOutput when machine endian matches file endian
    <LI> Textures load with default of maxAnisotroy = 2.0
    <LI> maxAnisotropy argument to G3D::Texture constructors.
    <LI> GLCaps now loads GL_ATI_fragment_shader extension
    <LI> contrib/ArticulatedModel now supports rigid body hierarchies
    <LI> Added TEX_SUBTRACT, TEX_ADD_SIGNED, TEX_DOT3, TEX_DOT3_RGBA modes for G3D::RenderDevice::setTextureCombineMode
    <LI> G3D::RenderDevice now cleans up all static G3D::VARArea s when it shuts down
    <LI> FIX: [ 1208157 ] GLSL slow on ATI
    <LI> FIX: Off-by-one on viewport scale for 2D rendering
    <LI> FIX: MeshAlg::computeTangentSpaceBasis now works correctly
    <LI> FIX: 6.05 enabled all fixed function lights by default.  This caused major performance problems on some cards.
    <LI> FIX: Extended cube map workaround to all Radeon Mobility cards
    <LI> FIX: Added check for glBlendEq before calling in RenderDevice
    <LI> FIX: Added a test for GL_EXT_texture_env_add in RenderDevice
    <LI> FIX: [ 1191817 ] unsigned warnings in BinaryInput
   </UL>

   <P>
   Changes in 6.05:
   <UL>
     <LI> G3D::BAYER_G8B8_R8G8_to_R8G8B8_MHC
     <LI> G3D::Quarter_R8G8B8_to_BAYER_G8B8_R8G8
     <LI> G3D::BAYER_G8B8_R8G8_to_Quarter_R8G8B8
     <LI> contrib/Matrix
     <LI> contrib/Java
     <LI> Texture::alphaOnlyVersion
     <LI> Draw::sphere speed improved over 25% with single quad strip (improves Draw::capsule) [Corey]
     <LI> Allow 1-channel GImage saving - BMP (expanded to RGB), PNG [Corey]
     <LI> Allow 1-channel GImage loading - PNG [Corey]
     <LI> Added shader and framebuffer extensions to glext.h 
     <LI> All files used during current execution are available via G3D::getFiles() [Corey]
     <LI> Implemented OSX version of glGetCurrentContext with CGL. [Corey + Derek]
     <LI> ReferenceCountedObject is-in-heap checks were removed to allow better multiple and virtual inheritance for reference counted objects.  ReferenceCountedPointer still appropriately checks does an is-in-heap check on assignment. [Corey]
     <LI> Added Dev C++ compatability
     <LI> glGetAttribLocationARB
     <LI> Changed GLight == operator to not use memcpy (was causing issues due to byte padding on some compilers)
     <LI> Made CoordinateFrame destructor non-virtual (eliminates vtable)
     <LI> Added new FAQ documentation
     <LI> Added support to G3D::BinaryInput and G3D::BinaryOutput 
          reading and writing huge (larger than available memory) files.
          Files are still restricted to about 2 GB total, and compressed
          files must fit entirely in memory.
     <LI> Tweaked allocation strategy for small G3D::Array
     <LI> G3D::Texture::rect2DBounds, G3D::Texture::vector2Bounds
     <LI> G3D::Vector4 * G3D::Vector4, Vector4 / Vector4
     <LI> G3D::Array::operator=(std::vector)
     <LI> G3D::Sky::getEnvironmentMap now returns the top texture on machines
          that don't support cube maps.
     <LI> glDisableAllTextures()
     <LI> G3D::setFailureHook
     <LI> G3D::Shader::fromStrings now accepts optional names for the vertex and pixel shader
     <LI> G3D::Shader no longer requires values for declared but unused uniform variables
     <LI> G3D::RenderDevice now stores texture matrix at 32-bit precision (for faster push/popState)
     <LI> G3D::RenderDevice::setTextureLODBias
     <LI> G3D::Shader now supports shadow map arguments
     <LI> G3D::Shader::ArgList checks to see if Texture arguments are null
     <LI> G3D::RenderDevice::setAlphaWrite now defaults to true if the GWindow has an alpha channel.
     <LI> G3D::RenderDevice::screenshotPic now supports alpha
     <LI> contrib/VideoSerializer
     <LI> G3D::BinaryOutput::writeBits, G3d::BinaryInput::readBits
     <LI> G3D::Sky can now be initialized with a NULL renderDevice, provided a non-null one
          is used with the G3D::Sky::render method.
     <LI> G3D::pi(), G3D::halfPi(), G3D::twoPi() added to replace defines [Corey]
     <LI> contrib/Q3Map
     <LI> Increased G3D::Draw::sphere performance using vertex arrays.
     <LI> G3D::Array::fastClear
     <LI> G3D::AABSPTree::insert(Array<T>)
     <LI> G3D::Texture::sizeOfAllTexturesInMemory
     <LI> G3D::VARArea::sizeOfAllVARAreasInMemory
     <LI> G3D::RenderDevice stores cameraToWorldMatrixInverse for faster coordinate system changes.
     <LI> inlined G3D::Matrix3::operator= for performance
     <LI> Created installer for Windows install [Corey]
     <LI> Reorganized the documentation topic index based on abstraction level, added hyperlinks to demo/contrib code
     <LI> G3D::ReliableConduit and G3D::LightweightConduit now send and receive
          objects directly; no need to make a G3D::NetMessage.  G3D::NetMessage
          and associated methods are now deprecated.
     <LI> Win32 GUI G3D::prompt now auto-expands \\n to \\r\\n in prompt string [Corey]
     <LI> G3D::Draw::frustum
     <LI> Increased timeout and attempts for G3D::ReliableConduit to handle huge (1 MB) packets
     <LI> G3D::BinaryOutput::reset (memory writing only; not supported for disk)
     <LI> Reduced overhead for G3D::ReliableConduit and 
          G3D::LightWeightConduit send routines
     <LI> Added PPM/PGM/PBM ASCII encode/decode support to G3D::GImage [Corey]
     <LI> New G3D::PosedModel rendering methods appropriate for shadow casting
           (with efficient default implementations).
     <LI> G3D::Lighting
     <LI> Changed RenderDevice::TEX_INTERPOLATE to mean GL_DECAL and added TEX_BLEND for GL_BLEND
     <LI> G3D::CoordinateFrame::upVector
     <LI> G3D::GLight::diffuse
     <LI> G3D::Rect2D::contains is now const
     <LI> Rewrote G3D::BinaryOutput to not use G3D::Array
     <LI> G3D::MD2Model::textureMatrix
     <LI> G3D::MeshAlg::computeBounds(vertex, index, ...)
     <LI> G3D::RenderDevice::colorWriteEnabled(), depthWriteEnabled, alphaWriteEnabled
     <LI> G3D::RenderDevice::setSpecularCoefficient(Color3)
     <LI> G3D::VAR::maxSize
     <LI> G3D::RenderDevice::enableTwoSidedLighting
     <LI> G3D::PosedModel::hasTransparency
     <LI> G3D::PosedModel::sort
     <LI> G3D::RenderDevice::renderMode
     <LI> G3D::MeshAlg::computeNormals(geometry, indexArray);
     <LI> contrib/ArticulatedModel (beta 3DS support)
     <LI> G3D::RenderDevice::swapBuffersAutomatically allows caller to suppress page flip.
     <LI> Added coordinate system documentation.
     <LI> RenderDevice::enableClip2D, RenderDevice::disableClip2D (scissor region)
     <LI> contrib/wxGWindow is stable and full featured-- use wxWidgets 2.5.3 with G3D!
     <LI> G3D::fileIsNewer
     <LI> G3D::isDirectory
     <LI> G3D::filenameContainsWildcards
     <LI> G3D::filenamePath
     <LI> G3D::Draw::lineSegment now accepts a scale (allowing arrows and axes to thicken appropriately)
     <LI> G3D::Rect2D::largestCenteredSubRect
     <LI> G3D::Matrix4::serialize, G3D::Matrix4::deserialize
     <LI> glTexImage3DEXT
     <LI> Removed glut.lib and glut.dll from the win32-lib directory.
     <LI> G3D::writeStringToFile, G3D::TextOutput, and G3D::BinaryOutput now flush by default (safe, not fast).
     <LI> Shifted push2D by 0.375 pixels as recommended in the OpenGL guide to bias integer coords towards pixel centers
     <LI> G3D::Draw::rect2DBorder
     <LI> G3D::Rect2D::border
     <LI> G3D::RenderDevice now creates a G3D::Win32Window on Windows instead of a G3D::SDLWindow.  SDLWindow is now
          deprecated on Windows.
     <LI> G3D::VARArea now updates allocation sizes instead of G3D::VAR internally.  Added
          more accessor methods to VARArea to futher remove VAR from VARArea internals. [Corey]
     <LI> VARSystem.cpp moved to VARArea.cpp - filename change only! [Corey]
     <LI> Linux build system updated:
          Builds only static libraries, Does not require libtool/libtoolize anymore,
          Does not check for or require libraries that normally linked with the .so files,
          Automatically builds Test project with iCompile during install. [Corey]
     <LI> G3D::Quat::deserialize, G3D::Quat::serialize
     <LI> G3D::PhysicsFrame::deserialize, G3D::PhysicsFrame::serialize
     <LI> G3D::TextInput::Options::singleQuotedStrings (defaults to true, changing the behavior
	      from previous versions).
	 <LI> G3D::Token::extendedType returns information disambiguating characters and strings
	      and floats and ints.
     <LI> Added data/ah64-body and ah64-rotor
     <LI> demos/Network_Demo now uses a helicopter model instead of a plane
     <LI> G3D::VARArea::gl_vertexBufferObject and G3D::VARArea::gl_basePointer for breaking
          the VARArea abstraction.
     <LI> GLG3D.h no longer links against SDLMain.lib on Windows if _CONSOLE is defined
          (since console programs have no WinMain).
     <LI> SDL's redefinition of main is cleared when not linking sdlmain.lib [Corey]
     <LI> Moved contrib/Win32Window to G3D::Win32Window
     <LI> G3D::TextInput::readSymbols
     <LI> contrib/Image [Morgan]
     <LI> contrib/wxGWindow [Morgan]
     <LI> Added support for full-screen antialiasing to contrib/Win32Window
     <LI> Added joystick support to contrib/Win32Window [Corey]
     <LI> Win32Window fully-implements GWindow [Corey]
     <LI> Texture now supports DDS(2D/CubeMap) and PNG files [Corey]
     <LI> Added Win32 pbuffer routines (no G3D wrapper, though-- we're waiting for the new ARB API).
     <LI> G3D::PosedModel::texCoords
     <LI> G3D::IFSModel now loads IFS 1.1 [Peter]
     <LI> G3D::IFSModel now loads and saves PLY2 files (plain text IFS format) [Peter]
     <LI> Automatically switch to glCompressedTexImage2D in G3D::Texture::fromMemory [Corey]
     <LI> Added G3D::Sky::fromCubeMap for preloaded CubeMap TextureRef's [Corey]
     <LI> Added G3D::Sky::fromFile and deprecated Sky::create [Corey]
     <LI> Demo and Test projects now build with iCompile, which is included [Corey]
     <LI> Fix: TextOutput::writeString now escapes special characters
     <LI> Fix: AABSPTree::serializeStructure
     <LI> Fix: Properly handle gl_ uniforms on Radeon for Shader
     <LI> Fix: [ 875467 ] OS X debugBreak (requires default XCode debug menu item 'Break on DebugStr()') [Corey + Derek]
     <LI> Fix: Can make a G3D::Texture::fromGImage with one channel (defaults to L8 format)
     <LI> Fix: [ 1149972 ] 6.05: Make Sky render correctly on low-end cards (no Cube mapping) [Corey]
     <LI> Fix: [ 1032742 ] OS X _DEBUG not defined [Derek]
     <LI> Fix: 16-bit integer reads in BinaryInput that always reversed endianness. (OSX file reading) [Corey + Derek]
     <LI> Fix: Matrix4 operator[] was returning a matrix value cast to a pointer [Corey]
     <LI> Fix: Matrix3 and Matrix4 had missing float* / const float* operators [Corey]
     <LI> Fix: Rect2D::clip broken for types other than Vector2
     <LI> Fix: RenderDevice::configureShadowMap result depends on objectToWorldMatrix
     <LI> Fix: [ 1150650 ] DebugBreak() undefined
     <LI> Fix: [ 1111534 ] Network Demo crashes starting 2nd server on same machine
     <LI> Fix: [ 1102091 ] ReliableConduit::receive times out
     <LI> Fix: Implemented MD2Model::objectSpaceBoundingX methods.
     <LI> Fix: G3D::Triangle::area is now zero for zero-area triangles (was inf)
     <LI> Fix: AABSPTree with extent on MSVC 6 no longer enters infinite loop in std::sort
     <LI> Fix: [ 1105641 ] Does not build with g++ 3.4.x [Corey]
     <LI> Fix: [ 1103619 ] RenderDevice::countPrimitive is wrong (changed to RenderDevice::countTriangles) [Corey]
     <LI> Fix: AABSPTree::BoxIntersectionIterator doesn't compile
     <LI> Fix: [ 1101680 ] copyfile won't overwrite (on Windows now overwrites) [Corey]
     <LI> Fix: [ 1101646 ] GCamera::frustum incorrect for non-square viewport
     <LI> Fix: Ultra bright lens flare at sunset [Nicholas Bray]
     <LI> Fix: IP address strings were reversed by NetAddress(std::string) 
     <LI> Fix: TextInput now returns end of file token for files without trailing whitespace
     <LI> Fix: [ 1094166 ] 6.05: Release mouse stuck on x-axis [Corey + Morgan]
     <LI> Fix: Recognize buggy ATI Radeon Mobility cube maps and work around
     <LI> Fix: Textures now initialize without setting error bit on cards without GL_ARB_shadow
     <LI> Fix: filenameBaseExt now operates correctly on strings with both \ and / slashes.
     <LI> Fix: [ 1062659 ] BinaryInput::BinaryInput() memory leak
     <LI> Fix: Removed RenderDevice::polygonCount, which was never used.
     <LI> Fix: TextInput::readNumber no longer accepts double preceeding +/- on numbers when Options::signedNumbers is true
     <LI> Fix: [ 1038733 ] GWindow cannot set icon properly [Corey]
     <LI> Fix: [ 939400 ] Linux mouse set position (Wild camera swinging on startup) [Corey]
     <LI> Fix: [ 1042591 ] Software GL Causes Assertion [Corey]
     <LI> Fix: [ 1036634 ] debugAssert doesn't work on MSVC 7 [Corey]
     <LI> Fix: [ 1049024 ] Fix compile warnings from gcc/Linux build [Corey]
     <LI> Fix: [ 1051272 ] Win32Window doesn't use GWindowSettings properly. [Corey]
     <LI> Fix: Win32Window clips the proper cursor region during input capture. [Corey]
     <LI> Fix: GWindows now center and maximize on the primary monitor for Windows.
     <LI> Fix: [ 1052945 ] TextOutput wordWrap starts on newlines
     <LI> Fix: [ 1050957 ] TextInput readNumber support for capital 'E' numbers.
     <LI> Fix: [ 1049674 ] TextInput failes on X. numbers.
     <LI> Fix: [ 1044028 ] Linux TextOutput Warning
     <LI> Fix: [ 1032750 ] Grayscale JPG errors [Corey]
     <LI> Fix: [ 1036225 ] Encode TGA support strips alpha channel [Corey]
     <LI> Fix: [ 1038631 ] CoordinateFrame::slerp (Quat::slerp has fix) [Corey]
     <LI> Fix: [ 1033686 ] GImage::GImage(filename) dies on certain (BMP) images [Corey]
     <LI> Fix: Texture mapping modes for pre-OpenGL 1.3 cards [Dan & Morgan]
   </UL>

   <P>
   Changes in 6.04:
   <UL>
     <LI> G3D Manual! [ Morgan and Sascha ]
     <LI> Initial MSVC7 build script.  MSVC7 is not an officially supported platform
          however the release contains MSVC7 precompiled binaries and the build script
          will automatically build on both 6 and 7.
     <LI> Improved performance of G3D::writeStringToFile
     <LI> G3D::ReferenceCountedPointer assignment now allows compile time subtyping
     <LI> G3D::ReferenceCountedPointer != operator
     <LI> G3D::ReferenceCountedPointer::notNull
     <LI> G3D::GLight::directional now normalizes the light vector
     <LI> G3D::setAssertionHook
     <LI> [ 1029256 ] G3D::Shader / G3D::VertexAndPixelShader define g3d_ uniforms inside shaders
     <LI> static G3D::IFSModel::save/load for writing/reading IFS files
     <LI> G3D::TextInput allows ' inside quoted strings
     <LI> G3D::TextInput allows \ as a symbol token
     <LI> G3D::TextInput supports an arbitrary comment character (e.g. '#')
     <LI> Precompiled binaries for VisualC++ 7 (.NET 2002/2003)
     <LI> VisualC++ 7 (.NET 2002/2003) supported by build script
	 <LI> Build now MOVEs binaries instead of COPYing them on Windows (allows
	      two compilers to output to the same location)
     <LI> G3D Guide overview documentation
     <LI> Changelog and Error FAQ moved under Doxygen
     <LI> Build scripts and documentation now under the 'doc' .dsp on Windows
     <LI> Textures now support a DepthReadMode that can be used to perform hardware
	     shadow map comparisions.  <B>RenderDevice::configureShadowMap now requires 
		 an appropriately configured texture-- in previous releases it would
		 reconfigure the texture for you.</B>
     <LI> G3D::UserInput::keyReleased, G3D::UserInput::ReleasedKeys
     <LI> G3D::Array::randomElement
     <LI> G3D::Array::insert
     <LI> G3D::RenderDevice::getObjectToWorldMatrix and getCameraToWorldMatrix now return 
          const CoordinateFrame&
	 <LI> Optimized G3D::Array::randomize
     <LI> G3D::cyclicCatmullRomSpline
     <LI> G3D::wrap
     <LI> contrib/AudioDevice
     <LI> G3D::System::time();
	 <LI> More precise System::sleep
     <LI> G3D::IFSModel::pose with no arguments
     <LI> G3D::AABSPTree::serializeStructure, deserializeStructure,
     <LI> serialize(Vector3::Axis, BinaryOutput), deserialize(Vector3::Axis, BinaryInput),
     <LI> "glslc" GLSL compiler in the tools directory for getting compile-time errors from shaders 
     <LI> GLCaps::init now takes optional debug log
	 <LI> G3D::VertexAndPixelShader static constructors take optional 'debug' argument
     <LI> GWindowSettings::visible; Win32Window can now start invisible
     <LI> [ 991147 ] glBlendEquationEXT, RenderDevice::BlendEq, min, max, subtract, reverse subtract alpha blending
     <LI> [ 989785 ] Draw::rect2D
	 <LI> GLCaps::numTextureCoords, GLCaps::numTextureUnits, GLCaps::numTextures
	 <LI> GLCaps::G3D_MAX_TEXTURE_UNITS
     <LI> Rect2D::corner
     <LI> GCamera::getFrustum, GCamera::frustum, GCamera::Frustum, GCamera::Frustum::Face
     <LI> Plane constructor that accepts Vector4s (possibly at infinity)
     <LI> AABox::inf, AABox::zero, AABox::maxFinite
     <LI> AABox::intersects(Sphere)
     <LI> Vector3::minFinite, Vector3::maxFinite
	 <LI> Plane::halfSpaceContainsFinite
	 <LI> Plane::halfSpaceContains(Vector4)
     <LI> AABSPTree::getIntersectingMembers(Array<Plane>) 
	 <LI> AABSPTree::getIntersectingMembers(GCamera::Frustum) for view-frustum culling
	 <LI> AABSPTree::getIntersectingMembers(Sphere)
     <LI> AABox::split
     <LI> Extended AABox::culledBy, Box::culledBy, and Sphere::culledBy with extra
	        information for bounding volume hierarchies
     <LI> G3D::computeNormalMap
     <LI> Matrix3::fuzzyEq(Matrix3)
     <LI> Removed System::sleep(0.02) from GLG3D demo to give more accurate performance measure
     <LI> [ 965824 ] changed link library defaults
     <LI> serialize/deserialize for int, bool, double, float, std::string
     <LI> G3D::TextOutput
     <LI> [ 976924 ] Texture::texelWidth
     <LI> [ 973413 ] VertexAndPixelShader::ArgList::set can be called more than once per variable
     <LI> GWindow::setIcon(std::string filename)
     <LI> Texture::fromMemory that takes a single image (instead of an array of images)
     <LI> [972604] RenderDevice::setTextureMatrix(uint, Matrix4)
     <LI> [972747] Rect2D::center
     <LI> GImage and Texture now load ICO files
	 <LI> GL_SAMPLER_1D_ARB, 2D, 3D, CUBE
	 <LI> Win32Window mouse events
	 <LI> Added normals to AABox collision results
     <LI> Fix: [ 1026534 ]various cast bugs using Ref types.  
          Removed G3D::ReferenceCountedPointer implicit cast to underlying pointer type
          This is technically an <B>incompatible change</B>, however we found no occurance
          in the library or demos using this that was not a bug! 
     <LI> Fix: VAR constructor takes VARAreaRef instead of VARArea* <B>Incompatible change</B>
     <LI> Fix: ManualCameraController is prevented from looking precisely along the Y-axis, which would cause 
	           a singularity.
	 <LI> Fix: Added '?' as a valid symbol Token
	 <LI> Fix: [ 946235 ] GFont::align right w/ fixed_spacing
	 <LI> Fix: [ 1001033 ] RenderDevice with 0 texture units
	 <LI> Fix: GLCaps:: ARB stencil two side -> EXT stencil two side (stencilled shadows were broken)
	 <LI> Fix: [ 993449 ] vsnprintf crashes MSVC 7
	 <LI> Fix: [ 991320 ] Pointer truncation Warnings
	 <LI> Fix: [ 981440 ] AUTO with Texture::fromMemory
	 <LI> Fix: Plane::halfSpaceContains now works for infinite and semi-infinite points
     <LI> Fix: [ 979032 ] Quat <-> Matrix3 roundtrip inverts
	 <LI> Fix: [ 976743 ] document GLCaps functions
	 <LI> Fix: [ 976746 ] #include GLCaps in g3dall
	 <LI> Fix: [ 973550 ] sampler2DRect now supported in GLSL shaders (NVIDIA only; ATI drivers are broken)
	 <LI> Fix: [ 973490 ] Win32Window width/height off by non-client amount
     <LI> Fix: [ 961827 ] In debug mode, RenderDevice tries to access 
	            GL_MAX_TEXTURE_IMAGE_UNITS_ARB and an assertion fails on cards that
				don't support it.
	 <LI> Fix: Texture binding for VertexAndPixelShader
   </UL>

   <P>
   Changes in 6.03:
   <UL>
     <LI> Matrix4::approxCoordinateFrame
     <LI> Vector2(const Vector2int16&) [Giulio]
     <LI> RenderDevice::setObjectShader
     <LI> RenderDevice::setVertexAndPixelShader
     <LI> G3D::RenderDevice supports "..._CURRENT" as an option for most settings
     <LI> inf -> inf(), nan -> nan(), NAN -> NAN()
	        <B>This is an incompatible change-- it was needed to fix a bug with the order
			   of initialization of globals</B>
     <LI> GImage::sizeInMemory
     <LI> Defined std::ostream << NetAddress, std::ostream << Vector3 
     <LI> 'build doc' copies the contrib directory to the install directory
     <LI> LightweightConduit::PacketSizeException
     <LI> Quat::unitRandom() [Giulio]
     <LI> Color3::wheelRandom
     <LI> GImage::save and encode now const [Thanks Arni Mar Jonsson]
     <LI> LightweightConduit::send that accepts multiple destinations
	 <LI> ReliableConduit::multisend
     <LI> Moved IFSBuilder from demos to contrib
     <LI> LightweightConduit and ReliableConduit send/receive can now take references as well as pointers
     <LI> RenderDevice::clear() that takes no arguments
     <LI> RenderDevice::setShader
     <LI> G3D::GApp now catches ShaderGroup::ArgumentError exceptions
     <LI> System::operatingSystem() now includes a version number on Linux
     <LI> SDLWindow no longer initializes the audio system; use SDL_InitSubsytem if you need audio.
     <LI> Extended GLenumToString with GL_SHADER_OBJECTS_ARB types.
     <LI> NVIDIA p-buffer: GLX_SAMPLE_BUFFERS_ARB, GLX_SAMPLES_ARB, GLX_FLOAT_COMPONENTS_NV,
	      glXDestroyGLXPbufferSGIX, glXChooseFBConfigSGIX, glXCreateGLXPbufferSGIX, 
	      glXCreateContextWithConfigSGIX, glXQueryGLXPbufferSGIX
     <LI> NVIDIA swap lock: glXJoinSwapGroupNV, glXBindSwapBarrierNV, glXQuerySwapGroupNV, 
          glXQueryMaxSwapGroupsNV, glXQueryFrameCountNV, glXResetFrameCountNV
	 <LI> GWindow::requiresMainLoop, GWindow::runMainLoop (Beta)
     <LI> GWindow::pollEvent, SDLWindow::pollEvent
     <LI> G3D::GApp accepts an optional GWindow on construction
     <LI> G3D::VertexAndPixelShader, G3D::ObjectShader (Beta)
     <LI> Deprecated GPUProgram, VertexProgram, and PixelProgram (the OpenGL 1.5 shaders
	      follow a different paradigm than the OpenGL 1.3 ones, so the G3D API must change
		  to match it).
     <LI> Support for GL_ARB_vertex_shader, GL_ARB_fragment_shader, and GL_ARB_shader_objects
     <LI> G3D::drawFeatureEdges
     <LI> const Array<Vector3>& G3D::MD2Model::PosedModel::objectSpaceFaceNormals();
	 <LI> G3D::RenderDevice::sendSequentialIndices
     <LI> Network_Demo
     <LI> contrib/Win32Window
	 <LI> contrib/pingtest
     <LI> contrib/GlutWindow [Morgan and Dan Keefe]
	 <LI> contrib/ObjModel [Corey Taylor]
     <LI> G3D::GLCaps
	 <LI> GAppSettings::logFilename
	 <LI> Deprecated RenderDevice::suportsOpenGLExtension, RenderDevice::supportsTextureFormat,
	      other supports shortcuts (use GLCaps instead).
	 <LI> DiscoveryClient::cleanup
	 <LI> Optimized BinaryInput::readUInt32, readUInt16
     <LI> Extended network documentation
     <LI> 'fastlib' build target for G3D library developers
	 <LI> glGetVector2, glGetVector3, glGetVector4
	 <LI> float * Quat (double * Quat already existed)
	 <LI> GApp automatically generates g3d-license.txt at runtime ([RFE#856338] CREDIT.TXT)
	 <LI> G3D::license
	 <LI> Removed several large files (tag, ppt, exe) from the source zipfile, bringing it down to 3 MB
     <LI> Improved CoordinateFrame:pointToObjectSpace() (RFE#715996) [Giulio]
     <LI> [RFE#945935] Make static constants into functions [Giulio]
     <LI> Fix: LightweightConduit::send verifies that the packet size is smaller than the UDP limit
	 <LI> Fix: Multitexture on ATI and Wildcat cards
	 <LI> Fix: Incorrect occlusion in GLG3D_Demo (was caused by global constant problem)
     <LI> Fix: [BUG#949377] Checks for stencil extensions [Giulio]
     <LI> Fix: [BUG#922725] Non-multitexture implementation for getTextureState() [Giulio]
	 <LI> Fix: Restore ambient light color after RenderDevice::popState
	 <LI> Fix: RenderDevice now initializes OpenGL extensions before testing for multitexture [Erik Cassel, Dan Keefe]
	 <LI> Fix: Bottom clipping plane of GCamera frustum now correct (was slanted incorrectly, making frustum too big)
     <LI> Fix: GFont::draw2D now returns correct y value (used to be too small)
	 <LI> Fix: NetworkDevice now returns useful hostname on Linux (used to be "localhost")
	 <LI> Fix: The conduit returned from NetworkDevice::createReliableConduit now has ok() == false when connect fails
	 <LI> Fix: Tangent space computation of constant u, v now correct (was missing a factor of 2, leading to slight errors) [Max McGuire]
	 <LI> Fix: [ 925456 ] select broken on Linux (Networking was broken on Linux)
	 <LI> Fix: getDepthBufferValue off by 1 [Andi Fein]
   </UL>

   <P>
   Changes in 6.02:
   <UL>
     <LI> Default constructor for Line.
     <LI> Various patches to make G3D work with the CAVE [Dan Keefe]
     <LI> AABox::set
     <LI> Made GWindow::setPosition non-const
     <LI> VARArea now tests for the presence of all VBO extensions, on the freak chance that
	      a driver has only partial support (due to a bug)
     <LI> Linux build statically links OpenGL 1.2.1 and loads extensions through OpenGL 1.5
   	      to work around Wildcat Linux driver bug (Windows and Mac statically link OpenGL 1.1 
		  and load extensions through OpenGL 1.5)
     <LI> Triangle stores precomputed edge lengths
     <LI> Ray-triangle with vertex weights
     <LI> Highly optimized ray-triangle intersection test [Tomas Moller & Ben Trumbore]
     <LI> Create a texture from 6 different cube-map filenames
     <LI> Added contrib directory built as part of the 'doc' target
	 <LI> contrib/CoreyGWindow: GWindow implementations for various platforms
     <LI> AABSPSet::beginRayIntersection [Pete Hopkins]
     <LI> AABSPTree::beginBoxIntersection
     <LI> CollisionDetection::intersectionTimeForMovingPointFixedAABox, Ray::intersectionTime(AABox)
	 [Pierre Terdiman and Andrew Woo]
     <LI> Triangle::center
     <LI> Renamed KDTreeSet to AABSPTree, old name is #defined 
     <LI> RenderDevice now works on cards without multitexture
     <LI> void glTexCoord(const G3D::Vector4& t); [Dan Keefe]
	 <LI> Overloaded float, double, and int * Matrix3
     <LI> Fix: [ 923944 ] Matrix/Quat ambiguity
     <LI> Fix: fuzzyEq(inf, inf) is true
	 <LI> Fix: Triangle::randomPoint returns values outside the triangle
     <LI> Fix: [ 913763 ] tokenTypeToString(Token::END)
	 <LI> Fix: Compute number of texture coordinates before RenderDevice::setVideoMode [Dan Keefe]
     <LI> Changed the default depth bits to '0' for wider compatibility
	      (Fix: Unable to create OpenGL screen: Couldn't find matching GLX visual)
     <LI> Fix: [912305] Table, Queue, and Set assignment operators do not free old values 
     <LI> Fix: Separate specular and Multisample on Tablet PC w/ Trident [Dan Keefe]
     <LI> Fix: Linux debug build now has line numbers
     <LI> Upgraded to SDL 1.2.7
	        Fix: [ 838030 ] SDL 1.2.6 blocks prompt
			Fix: FSAA does not work under SDL
			Fix: Default Win32 refresh rate
     <LI> Draw::vertexVectors
     <LI> New meshes from Brown University: hemisphere.ifs, curvy.ifs, head.ifs,
	       closed-low-poly-teapot.ifs, bump.ifs
     <LI> GLight::specular
     <LI> SDLWindow::setWindowDimensions and setWindowPosition now work on Win32
     <LI> GWindowSettings::x, GWindowSettings::y, GWindowSettings::center
     <LI> System::setEnv
     <LI> [ 909999 ] GWindow Joystick interface
     <LI> double * Quat ([ 909305 ] scalar * {quat, vector, matrix})
	 <LI> Increased the precision of several Vector2 and Vector3 methods
     <LI> MeshAlg::computeNormals now returns 0 instead of NaN for degenerate normals
     <LI> Updated main-no-GApp.cpp for 6.02
     <LI> RenderDevice::screenshotPic can copy from the back buffer
     <LI> Improved VAR documentation.
     <LI> If NO_SDL_MAIN is defined, G3D does not attempt to link against sdlmain.lib
     <LI> UserInput::setPureDeltaMouse
     <LI> UserInput::mouseXY, mouseX, mouseY
	 <LI> UserInput::mouseDXY
	 <LI> Deprecated UserInput keyMapping constructor argument
     <LI> RenderDevice::setDrawBuffer [Dan Keefe]
     <LI> GFont::draw3D [Dan Keefe]
     <LI> GImage::pixel3(x, y) and GImage::pixel4(x, y)
	 <LI> debugAssert, debugBreak, debugAssertM, etc. all release input grab 
          when an assertion fails (Win32 and Linux) and restore it when the 
          program continues (Win32).  This also fixes the DirectInput laggy 
          cursor that occurs after a break.
   </UL>

   <P>
   Changes in 6.01:
   <UL>
     <LI> Default constructor for G3D::LineSegment
     <LI> Rect2D::clipPoly (Pete & Morgan)
	 <LI> Draw::poly2D, Draw::poly2DOutline (Pete & Morgan)
	 <LI> Added instructions for rotated text to G3D::GFont::draw2D
	 <LI> Fix: iRandom now compiles correctly under gcc.
     <LI> Fix: [ 852076 ] Compute better/faster vertex normals in MeshAlg
	      MeshAlg::computeNormals now weighs adjacent faces by their area
     <LI> Fix: [ 896028 ] Textures broken on Trident TabletPC (Dan Keefe)
	 <LI> Fix: [ 860800 ] ManualCameraController cursor jumps
     <LI> Fix: G3D::UserInput no longer offsets the mouse position by 1/2 pixel
     <LI> Fix: Alt-Tab no longer toggles the GApp camera before switching windows
     <LI> Fix: [ 901248 ] Font bounds y-value incorrect
	 <LI> Fix: G3D::PhysicsFrame::toCoordinateFrame() was rotated by 90 degrees
     <LI> Fix: [ 895493 ] Radeon 7500 Cube Map
	 <LI> Fix: G3D::MeshAlg::computeWeld produces linker errors on Linux
     <LI> G3D::TextInput::peekLineNumber(), G3D::TextInput::peekCharacterNumber()
     <LI> G3D::GAppSettings::dataDir
     <LI> html/gettingstarted.html
     <LI> G3D::MeshAlg::debugCheckConsistency
     <LI> G3D::MD2Model and G3D::IFSModel now weld their adjacency information
     <LI> Renamed/retyped G3D::PosedModel::adjacentFaces to G3D::PosedModel::vertices 
	   (most programs can be fixed by changing the type from Array< Array<int> > to
	   Array<MeshAlg::Vertex> and adjacentVertexArray[v] to vertexArray[v].faceIndex)
	 <LI> Shadow volumes now use the welded adjacency information
	 <LI> G3D::PosedModel now offers both welded and non-welded adjacency information
     <LI> G3D::contains for C-Arrays
     <LI> Generate .tag files in the build
     <LI> G3D::MeshAlg::computeAdjacency does not merge colocated vertices
     <LI> G3D::MeshAlg::computeAdjacency does not remove degenerate faces and edges
     <LI> G3D::MeshAlg::Vertex
     <LI> G3D::Vector3::directionOrZero
     <LI> G3D::GMaterial
     <LI> ManualCameraController renamed to G3D::FPCameraController
     <LI> glGetCurrentContext (beta)
     <LI> G3D::RenderDevice::supportsTextureFormat
     <LI> G3D::Vector3::magnitude
     <LI> G3D::Vector3::cross() [returns Matrix3]
     <LI> G3D::Quat changes (API is still in beta)
	 <LI> G3D::Quat::norm now returns the 2-norm, not the function Dave Eberly uses.
     <LI> Matrix3 default constructor
     <LI> Switched UserInput to use SDLWindow internally
	 <LI> Switched RenderDevice to use SDLWindow internally
	 <LI> G3D::Window
	 <LI> G3D::SDLWindow
     <LI> Renamed G3D::RenderDeviceSettings to G3D::WindowSettings (with a typedef for the old name)
     <LI> IFSModel now loads models with up to 10 million polygons (like the buddha).
	 <LI> Internal G3D::KDTreeSet state now private.
   </UL>

   <P>
   Changes in 6.00:
   <UL>
     <LI> FIX: warning: passing `double' for argument 1 of `void G3D::Queue<T>::repackAndRealloc(int)'
     <LI> Optimized static Matrix3::transpose (36 cycle) and
	      Matrix3::mul (52 cycle) variations.
     <LI> Changed some lerp arguments from float to double
	 <LI> MeshAlg::computeTangentSpaceBasis
	 <LI> Draw::axes now uses scale to compute axis length
     <LI> New ParallaxBump demo
     <LI> Changed several Vector3 return values from float to double
     <LI> Real-world stars, sun, and moon path (Nick Musurca)
     <LI> Now compiles under MSVC++ 7.0 (David Baszucki)
	 <LI> Now compiles under g++ OS/X (Ben Landon)
     <LI> Changed the default RenderDeviceSettings::alphaBits to 0 in the hope that it
	      will work with more graphics cards.
     <LI> Matrix3::fromX methods became factory methods
     <LI> G3D::sinc
     <LI> Multi-platform lib directories
     <LI> Vector3::average(), Color3::average(), Vector3::sum(), Color3::sum()
     <LI> Ray::reflect, Ray::refract
     <LI> Physically correct sky model
     <LI> FIX: Older graphics cards can now initialize properly
     <LI> Increased fuzzyEpsilon to 0.000001
     <LI> Color3::max, Color3::min, Color4::max, Color4::min
     <LI> Array::sortSubArray
     <LI> GCamera::getClipPlanes now takes a G3D::Array
     <LI> G3D::AABox
     <LI> Box::randomInteriorPoint, Box::randomSurfacePoint
     <LI> Vector3::cosRandom, Vector3::hemiRandom, Vector3::reflectAbout, Vector3::reflectionDirection, Vector3::refractionDirection
     <LI> log(Color3)
     <LI> Upgraded to zlib 1.2.1
     <LI> VAR::valid (Peter)
     <LI> System::getLocalTime, System::getTicks
	 <LI> High-performance cycle count and time queries on Linux
     <LI> UserInput::anyKeyPressed
     <LI> G3D::Box now provides axes, center, and extent information
	        (serialization is backwards compatible to 5.xx)
     <LI> TextInput's exceptions now provide file, line, and character numbers
	      as well as preformatted error messages in the style of MSVC++.
     <LI> G3D::Texture::fromGImage
     <LI> G3D::TextInput now parses hex numbers of the form 0x#####
     <LI> G3D::CollisionDetection::penetrationDepthForFixedSphereFixedPlane
	 <LI> G3D::CollisionDetection::penetrationDepthForFixedSphereFixedBox
     <LI> G3D::beginMarkShadows, G3D::endMarkShadows, G3D::markShadows
     <LI> GFont::draw2D now returns the string bounds
     <LI> Sphere::surfaceArea, Sphere::volume, Box::surfaceArea, Box::volume
     <LI> Two-sided stencil operations
     <LI> Removed G3D::Real
     <LI> FIX: [ 855947 ] Fonts are broken on Radeon
     <LI> Switched vertex arrays to use the new ARB_vertex_buffer_object extension.
	      Compared to 5.xx rendering speed: NVIDIA/Win32 is the same (fast),
		  ATI and Linux rendering are about 10x faster.  The API has changed
		  slightly-- most significant, the vertex, normal, color, etc. arrays
		  must all come from the same VARArea now.
     <LI> Disabled the "conditional is constant" level 4 warning on Windows
	      that is triggered by the for-loop scoping fix.
     <LI> G3D::LightingParameters::directionalLight
     <LI> G3D::TextureManager (Peter S. & Morgan)
     <LI> Flipped skybox X-axis to match OpenGL cube map coordinates
     <LI> Texture now uses hardware MIP-map generation
     <LI> Texture::copyFromScreen for cube map faces
     <LI> RenderDevice::configureReflectionMap
     <LI> RenderDevice::configureShadowMap
     <LI> Renamed CFont to GFont
     <LI> Renamed CImage to GImage
	 <LI> G3D::Matrix3::getRow
	 <LI> Added optional argument drawCelestialBodies to Sky::create.
     <LI> RenderDevice::getTextureMatrix
     <LI> Depth Textures
	 <LI> Texture::createEmpty
	 <LI> RenderDevice::setViewport has flipped the y-axis since version 5.00
     <LI> ReferenceCountedPointer::isLastReference
     <LI> Support for textures beyond the number of texture units (which occurs on NVIDIA cards)
     <LI> G3D::PosedModel
	 <LI> G3D::IFSModel
     <LI> G3D::CoordinateFrame::normalToObjectSpace, G3D::CoordinateFrame::normalToWorldSpace
     <LI> Simplified arguments on Texture::copyFromScreen
     <LI> Moved Camera in GLG3D to GCamera in G3D
     <LI> Moved setProjectionAndCameraMatrix from Camera to RenderDevice
     <LI> Moved G3D::Rect2D to G3D from GLG3D, changed interface
     <LI> G3D::setRenderMode
     <LI> G3D::RenderDevice::setSpecularCoefficient, G3D::RenderDevice::setShininess
     <LI> G3D::GLight
	 <LI> Renamed G3D::RenderDevice::configureDirectionalLight, configurePointLight to G3D::RenderDevice::setLight
     <LI> Changed G3D::Rect2D to use doubles
     <LI> G3D::Camera::setPosition()
     <LI> G3D::Camera::lookAt()
	 <LI> G3D::ManualCameraController::setPosition()
     <LI> G3D::System::getTick, G3D::System::getLocalTime
     <LI> Fixed [ 839618 ] peak var only updated on reset()
     <LI> G3D::Array::findIndex (thanks to David Baszucki for the suggestion)
     <LI> Removed RenderDevice::setProjectionMatrix3D and RenderDevice::setProjectionMatrix2D
     <LI> RenderDevice::project 
     <LI> RenderDevice::push2D() now uses the current viewport instead of full screen by default
     <LI> RenderDevice::getViewport
     <LI> G3D::SimTime
     <LI> Sky::render no longer needs a camera matrix (it gets it from the render device)
     <LI> SkyRef, Sky::create()
     <LI> Removed Sky::getName
     <LI> Removed RenderDevice::setAmbientLightLevel (duplicated RenderDevice::setAmbientLightColor)
     <LI> G3D::GApp, G3D::GApplet, G3D::GAppSettings
     <LI> RenderDevice::getCardDescription
     <LI> GPUProgram interface for setting program constants [Peter, Morgan & Dan]
     <LI> RenderDevice::getModelViewMatrix
     <LI> RenderDevice::getModelViewProjectionMatrix
     <LI> RenderDevice::getProjectionMatrix
     <LI> Documented some more common compiler errors.
     <LI> Moved RenderDevice::debugDraw methods to the Draw class, changed rendering from
	      cylinders to lines for wireframe (for performance)
     <LI> Ray::direction no longer has unit length
     <LI> Line::point, Line::direction
	 <LI> LineSegment::endPoint
     <LI> IFSBuilder loads Brown University Sketch Model (sm) format
	 <LI> New IFS models: angel, distributor-cap, dragon2, duck, elephant, hippo, hub, mech-part, rotor, sandal, trumpet, venus-torso, woman
     <LI> RenderDevices are now optionally resizable
     <LI> MeshAlg::computeWeld
     <LI> Array::randomize
     <LI> Table now refuses to push the load factor above 19/20 and stops rehashing
	 <LI> Table always keeps an odd number of buckets
     <LI> Sphere::randomInteriorPoint, Sphere::randomSurfacePoint
	 <LI> LineSegment::randomPoint
	 <LI> Hardcoded some common paths into demoFindData
     <LI> Deprecated old RenderDevice::init method.	      
     <LI> Full screen anti-aliasing (FSAA)
     <LI> G3D::RenderDeviceSettings
     <LI> All 2, 3, and 4 character swizzles for Vector2, Vector3, Vector4 are defined.
     <LI> G3D::rsqrt
     <LI> Most vector methods are also defined as functions now
	 <LI> sign(Vector2), sign(Vector3), sign(Vector4)
	 <LI> G3D::Matrix4
     <LI> Changed G3D_VER from double to integer
     <LI> G3D::lerp
     <LI> Changed G3D::PI, G3D::HALF_PI, and G3D::TWO_PI to #defines
     <LI> Vector2::clamp, Vector3::clamp, Vector4::clamp
     <LI> Changed order of arguments to all lerp methods to match DirectX/Cg
	 <LI> Changed order of arguments to G3D::clamp and G3D::iClamp to match DirectX/Cg
     <LI> G3D::ManualCameraController::ManualCameraController now requires a G3D::UserInput
	 <LI> G3D::UserInput::appHasFocus
     <LI> G3D::ManualCameraController now stops tracking the mouse when the app loses focus
     <LI> G3D::ManualCameraController::setActive
	 <LI> G3D::ManualCameraController now manages the mouse cursor instead of G3D::RenderDevice
	 <LI> G3D::UserInput::getMouseXY, G3D::UserInput::getXY
     <LI> RenderDevice::debugDrawVertexNormals
     <LI> GPUProgram, VertexProgram, and PixelProgram now recognize the output of the
	      Cg compiler and automatically bind constants.
     <LI> RenderDevice now loads glActiveStencilFaceEXT
     <LI> RenderDevice::numTextureCoords
     <LI> Moved changelog to a separate page
	 <LI> Reformatted overview to be smaller
     <LI> Added model debugging info to the IFSBuilder display
     <LI> Welded some broken vertices in the teapot.ifs file
     <LI> Renamed Font.* to CFont.*
     <LI> CFont::draw2DString renamed to CFont::draw2D (use a #define to port old code)
     <LI> MeshAlg
     <LI> RenderDevice now enables GL_COLOR_MATERIAL by default
     <LI> msgBox
     <LI> MD2 model gallery in documentation (Kevin)
     <LI> MD2Documentor (Kevin)
     <LI> debugAssertGLOk macro
     <LI> VertexProgram now supports NVIDIA Vertex Program 2.0
     <LI> RenderDevice now loads glGenProgramsNV, glDeleteProgramsNV, glBindProgramNV, glLoadProgramNV, glTrackMatrixNV, glProgramParameter4fvNV, glGetProgramParameterfvNV, glGetProgramParameterdvNV extensions	 
     <LI> VertexProgram and PixelProgram static factory methods now return reference counted values.
     <LI> Split the reference value from RenderDevice::setStencilTest into setStencilConstant
     <LI> RenderDevice::STENCIL_INVERT, RenderDevice::STENCIL_REPLACE, RenderDevice::STENCIL_ZERO 
     <LI> Added brighten argument to Texture::fromFile
     <LI> Increased CImage JPEG save quality
     <LI> RenderDevice::screenshot now returns the name of the file that was written
     <LI> nextPowerOf2 renamed to ceilPow2
     <LI> System::alignedMalloc, System::alignedFree
     <LI> Carbon, Crackman, Edenmill, Futurist, Interplanetary,
          Iomanoid, Starlight, Lesser, and Wild fonts by Ray Larabie.
          Like all of our fonts, they are free, but please consider a
          donation to him if you like them.  http://www.larabiefonts.com/
     <LI> MD2Model_Demo
     <LI> G3D::MD2Model
     <LI> FIX: Fixed a bug in Array shrinking that could cause memory corruption
     <LI> FIX: RenderDevice windows with an aspect ratio of less than 1 now allowed.
     <LI> FIX: TextInput now parses '#', '~', '~=', '&', '&&', '|', '||' correctly
     <LI> VARArea::reset() now waits for rendering calls using its vertex
          arrays to complete before wiping the memory.
     <LI> G3D::filenameBaseExt, G3D::filenameExt
     <LI> VARArea::finish()
     <LI> Milestone
	 <LI> TextInput::Options::signedNumbers
     <LI> RenderDevice now loads glFlushVertexArrayRangeNV
     <LI> Vector2int16
     <LI> RenderDevice::freeVARSize()
     <LI> Array now allocates 16-byte aligned pointers.
     <LI> Decreased the default camera movement rate by 50% for better resolution.
     <LI> RenderDevice enables GL_NORMALIZE by default
     <LI> Improved the performance of Array::append/Array::push/Array::next
	 <LI> Fix: [ 875219 ] Array::sort must use std::sort
     <LI> Array::next
     <LI> Array::reverse
     <LI> PCX file loading
     <LI> Test images
     <LI> Color3uint8 as uint8[] addressing
     <LI> Color4uint8 as uint8[] addressing
     <LI> Removed const from VAR::pointer
     <LI> ReferenceCountedPointer::isNull
     <LI> alwaysAssertM
     <LI> Log::common, Log::getCommonLogFilename
     <LI> Switched from static to dynamic linking of zlib
     <LI> Upgraded to zlib 1.1.3
     <LI> On Win32 the lib list is automatically updated through pragmas
          (5.xx programs should revert to linking against default libraries)
     <LI> Increased default sky quality to 1.00
     <LI> G3D::CFontRef
     <LI> RenderDevice now loads all register combiner extensions (NVIDIA only)
     <LI> Sky::getEnvironmentMap
     <LI> Sky implementation now uses a cube map (when one is available)
     <LI> G3D::Sky constructor now takes a render device
     <LI> Rotated Sky box 90 degrees to match environment maps
     <LI> G3D::Sky now takes the environment filenames as "sky_*.jpg" instead of "sky_ft.jpg"
     <LI> Added default filename for Sky constructor
     <LI> Added caustics textures created with Kjell Andersson's generator http://www.lysator.liu.se/~kand/caustics/
     <LI> #defined "for" under MSVC so that it obeys C99 scoping rules
     <LI> System::consoleKeyPressed
     <LI> System::consoleClearScreen
     <LI> System::consoleReadKey
     <LI> NetMessage::type()
     <LI> Changed the Conduit message protocol to include a message type.
          The API is backwards compatible to 5.01 even though the protocol is not.
     <LI> Removed optional argument maxSize from LightweightConduit::receive.
     <LI> NetAddress::serialize
     <LI> NetAddress::deserialize
     <LI> NetAddress == NetAddress
     <LI> hashCode(NetAddress)
     <LI> RenderDevice::init now prints ATI or NVIDIA driver version to the log under Windows
     <LI> readme.html library build instructions now have downloads for required libraries
     <LI> Library list has changed for Win32 (added version.lib)
     <LI> System::cpuArchitecture
     <LI> System::operatingSystem
     <LI> double-precision Plane::getEquation
     <LI> Vector2::lerp
     <LI> Platform specific #defines G3D_WIN32, G3D_LINUX, G3D_OSX
     <LI> G3D::Array::contains
     <LI> G3D::Queue::contains
     <LI> G3D::TextureFormat
     <LI> G3D::Texture::DIM_CUBE_MAP
     <LI> G3D::Texture resizes non-power of two textures
     <LI> G3D::Texture constructors are completely changed from 5.01 (and hopefully easier to use)
     <LI> G3D::CImage now supports images with alpha
     <LI> Removed most of the width/height arguments from G3D::Camera methods
     <LI> BinaryInput::readBytes and BinaryOutput::writeBytes now take void* as an argument to avoid casting
     <LI> Plane::fromEquation
     <LI> Removed Plane::getNormal (use Plane::normal instead)
     <LI> Removed CDTriangle (use G3D::Triangle instead)
     <LI> Removed Font (use G3D::CFont instead)
     <LI> FIX: Camera::getClipPlanes now transforms infinite planes correctly.
     <LI> FIX: The last reference of an RGC pointer assigned to itself no
               longer tries to collect before re-assigning
   </UL>

   <P>
   Changes in 5.01
   <UL>
     <LI> G3D::tesselateComplexPolygon
	 <LI> G3D::ConvexPolygon
	 <LI> G3D::ConvexPolyhedron
     <LI> G3D::iClamp, G3D::clamp
	 <LI> G3D::iWrap
	 <LI> G3D::iRandom, G3D::random
     <LI> G3D::getFiles
     <LI> G3D::getDirs
     <LI> G3D::VAR::pointer
     <LI> G3D::realWorldLocalTime
     <LI> G3D::Texture::TRANSPARENT_BORDER
     <LI> DECLARE_GLFORMATOF
     <LI> G3D::System::machineEndian
     <LI> G3D::VertexProgram, G3D::VertexProgramRef, G3D::RenderDevice::setVertexProgram
     <LI> G3D::PixelProgram, G3D::PixelProgramRef, G3D::RenderDevice::setPixelProgram
     <LI> G3D::GPUProgram, G3D::GPUProgramRef
     <LI> G3D::sizeOfGLFormat
     <LI> G3D::RenderDevice::setVertexAttrib
     <LI> G3D::Vector2*=Vector2, /= Vector2, * Vector2, / Vector2
     <LI> glFormatOf
     <LI> G3D::Color4uint8
     <LI> G3D::Color3uint8
     <LI> G3D::Vector3int16
     <LI> G3D::System::currentProgramFilename
     <LI> CImage::insertRedAsAlpha
     <LI> CImage::stripAlpha
     <LI> Texture::hasAlpha
     <LI> Added support for TGA with alpha channel
     <LI> Re-implemented Texture to support a broader range of formats and cleaner implementation.
     <LI> Fix: Improved Texture::LUMINANCE support
     <LI> Added == and != overloads for TextureRef so that "a != NULL" is now legal and does not require a cast to TextureRef.
     <LI> G3D::CFont is a typedef for G3D::Font to avoid name conflicts with X11 Font under Linux.  In future releases, the name Font will be deprecated.
     <LI> RenderDevice::setPointSize
	 <LI> Added a new teapot (teapot.ifs) that is closed, with a properly fitting top.  The classic teapot is now called "utah-teapot.ifs" (Sebastian Schuberth and Simon Winkelbach)
     <LI> RenderDevice::init now loads glPointParameterfvARB, glPointParameterfARB,
        glMultiDrawArraysEXT, and glMultiDrawElementsEXT functions.
     <LI> GLenumToString(4) now returns "GL_TRIANGLES" instead of "GL_LINE_BIT" (both are correct)
     <LI> Added TextInput::Options to optionally allow C++ comments to
          be treated as two slashes instead of a comment
     <LI> Added data/image/meter.jpg, a meter stick texture convenient for testing
     <LI> Added sansserif, news, and terminal fonts based on Bitstream's <A HREF="http://www.gnome.org/fonts/">free fonts</A>
     <LI> RenderDevice::numTextureUnits
     <LI> Added stars to night Sky
     <LI> Added classic GL dinosaur model as data/ifs/dinosaur.ifs
     <LI> Documented G3D::glGetProcAddress
     <LI> Fix: Texture now restored GL_ENABLE bits properly after creation
     <LI> Fix: Texture::sizeInMemory now accounts for MIP-map levels
     <LI> Fix: Fonts and skies now adjust their brightness for the screen gamma level
     <LI> Fix: Strange compilation bug was causing Sky to be black for some programs
     <LI> resolveFilename
     <LI> GLProgram_Demo to show how to use vertex programs in G3D
     <LI> Support for GL_ARB_vertex_program 
     <LI> Modified ManualCameraController so that diagonal movement does not exceed
          maximum rate.
     <LI> Added support for non-GL_FLOAT vertex arrays to RenderDevice
     <LI> Added support for Wavefront OBJ files to IFSBuilder
     <LI> Removed duplicate copies of SDL.dll from the source tree
     <LI> Renamed G3D::CDTriangle to G3D::Triangle
     <LI> Added several G3D::Triangle methods
     <LI> Moved CollisionDetection::primaryAxis to Vector3::primaryAxis
     <LI> Fix: Texture::sizeInMemory now returns correct results for RGB8 textures.
     <LI> Changed texture constructors in ways that slightly break backwards compatibility
     <LI> Deprecated several arguments to the texture constructors.
   </UL>


   Changes in 5.00
   <UL>
     <LI> Color3::operator*=(const Color3&)
     <LI> Color3::operator*(const Color3&)
     <LI> Eliminated duplicate GL headers [James O'Sullivan]
     <LI> Linux Makefiles [James O'Sullivan, Jordan Parker]
     <LI> RenderDevice::getProjectionMatrixParams
     <LI> RenderDevice::debugDrawCylinder
     <LI> Added an option to not copy input memory for BinaryInput
     <LI> Added data/ifs/sphere.ifs
     <LI> Added data/ifs/spikeball.ifs
     <LI> Added a new (imperfect) demo/tool that converts 3DS and MD2 to IFS.
     <LI> Added RenderDevice to the Font constructor
     <LI> Removed RenderDevice from Font::drawString
     <LI> Included glut32.lib, .dll, and .h (Version 3.7.6) in the distribution. 
          The windows glut port is by Nate Robbins and is from 
          http://www.xmission.com/~nate/glut.html. 
          glut was originally written by Mark Kilgard.
     <LI> Modified OpenGL headers to work cross platform, with the latest NVIDIA extensions
     <LI> Changed library name from graphics3D.lib to G3D.lib, same for
          debug version.
     <LI> Changed directory structure and added readme.html to explain
          the new setup.
     <LI> Changed BinaryInput::readBytes to allow reading onto the stack
     <LI> Added Vector4::isFinite
     <LI> G3D::CDTriangle (for 35% faster collision detection)
     <LI> CollisionDetection::closestPointToRectangle
     <LI> CollisionDetection::movingSpherePassesThroughFixedBox
     <LI> CollisionDetection::movingSpherePassesThroughFixedSphere
     <LI> Changed CollisionDetection::movingXFixedTriangle arguments
     <LI> CollisionDetection::collisionTimeForMovingSphereFixedSphere
     <LI> Changed CollisionDetection::distanceToX methods to closestPointToX
     <LI> Vector3::NAN3
     <LI> Made Vector3::isUnit fuzzy
     <LI> Made Vector3::isZero fuzzy
     <LI> Fix: Texture(std::string, std::string) constructor now works for alpha-only textures. 
     <LI> FIX: Array now calls copy constructor when resizing
     <LI> FIX: Triangle-sphere and rectangle-sphere collision detection
              returned an incorrect collision location; now fixed.
     <LI> FIX: changed VectorX::isFinite to call isFinite (used to give bad result for NaNs)
     <LI> FIX: Used the normalized edge to compute intersection in
            CollisionDetection::distanceToTrianglePerimeter
     <LI> FIX: Changed the order of corners returned from Box::getFaceCorners so the
	      face is ccw, facing out
     <LI> FIX: ManualCameraController::lookAt now faces along the -z axis.
     <LI> FIX: data/ifs/icosa.ifs model is now an icosahedron
     <LI> Made Set::begin() and Set::end() const
     <LI> Added ifdef _WIN32 all over for typedefing types from Windows to Linux and vice versa.
     <LI> G3D::isNaN, G3D::isFinite
     <LI> Added a single triangle triangle.ifs file
     <LI> G3D::LineSegment
     <LI> RenderDevice::debugDrawRay
     <LI> CoordinateFrame::toObjectSpace(Ray&)
     <LI> CoordinateFrame::toObjectSpace(Box&)
     <LI> CoordinateFrame::toObjectSpace(Sphere&)
     <LI> Changed CollisionDetection routines to return the surface normal of the
          surface at the collision location.
	 <LI> CollisionDetection::collisionTimeForMovingPointFixedCapsule
	 <LI> CollisionDetection::collisionTimeForMovingSphereFixedCapsule
     <LI> G3D::Capsule class
     <LI> Removed e-mail addresses from contributor list to protect them from spammers
     <LI> Linux port [Hari Khalsa & Chris Kern]
     <LI> Added serialize and deserialize methods, deserializing constructor to
	      Vector2, Vector3, Vector4, Color3, Color4, Matrix3, CoordinateFrame, Box,
		  Sphere, Plane, Ray, Line, Capsule, LineSegment
	 <LI> Moved parts of Plane.h into Plane.cpp
     <LI> BinaryInput::readBool8 and BinaryOutput::writeBool8
     <LI> G3D::System [based on Michael Herf, Rob Wyatt, and Benjamin
           Jurke's work]
     <LI> Networking infrastructure: G3D::NetworkDevice, G3D::NetAddress,
          G3D::ReliableConduit, G3D::LightweightConduit, G3D::NetListener
     <LI> G3D::Camera
     <LI> Vector2::toString
     <LI> G3D::createTempFile
     <LI> G3D::fileLength
     <LI> UserInput::setKeyMapping
     <LI> UserInput::keyCodeToString, UserInput::stringToKeyCode
     <LI> JPEG library uses createTempFile
     <LI> JPEG library will allocate up to 6MB before resorting to temp 
          files-- faster and more reliable
     <LI> Moved SDL initialization to RenderDevice constructor from the init
          method so extension can be used earlier
     <LI> Support for up to 8 texture units, no longer crashes on machines 
          that have more than 4 units
     <LI> Made Arrays allocate at least 32 bytes when resized to improve
          performance of small char stacks
     <LI> Added UserInput key codes for mouse wheel buttons
     <LI> UserInput::keyPressed, UserInput::pressedKeys()
     <LI> UserInput::KeyCode
     <LI> Renamed UserInput::poll() to UserInput::endEvents(), added 
          UserInput::beginEvents()
     <LI> Moved custom UserInput key codes into an enum so they are 
          compile-time constants
     <LI> Changed all <io.h> to <stdio.h> for cross-platform [Rob & Chris]
     <LI> Moved LITTLE_ENDIAN and BIG_ENDIAN constants to an enum and renamed 
          them to G3D_LITTLE_ENDIAN and G3D_BIG_ENDIAN for cross-platform 
          [Rob & Chris]
     <LI> Permanently fixed the precision of Real to be 32-bit float.
     <LI> RenderDevice now loads the NVIDIA VAR fence extensions.
     <LI> Renamed RenderDevice::begin to RenderDevice::beginPrimitive, same 
     for end.
     <LI> Redesigned the vertex array system; see VAR and VARArea.
     <LI> Changed GLG3D demo to demonstrate the use of the new VAR and 
        VARArea classes
     <LI> CoordinateFrame(Vector3) constructor.
     <LI> Improved the performance of zero-radius sphere [aka point] 
          collision detection
   </UL>

   <P>
    Changes in 4.01
   <UL>
     <LI> trimWhitespace()
     <LI> Pointwise multiplication and division for Vector3
     <LI> Array::sort now uses > operator by default; two alternative sort methods allow qsort style sorting
     <LI> Texture::copyFromScreen
     <LI> Texture::invertY
     <LI> BinaryInput/BinaryOutput compression (via zlib)
     <LI> Alpha-only G3D::Texture mode
     <LI> G3D::Font and fonts in data/font
     <LI> Array::fastRemove
     <LI> TextInput [Morgan & Aaron]
     <LI> Color4::CLEAR
     <LI> Table [] operator now returns a non-const reference
     <LI> RenderDevice::getFrameRate, RenderDevice::getTriangleRate, RenderDevice::getTriangleCount
     <LI> ManualCameraController::setMoveRate, ManualCameraController::setTurnRate
     <LI> LightingParameters default constructor
     <LI> Vector2, Vector3, Vector4 isZero(), isUnit(), isFinite()
     <LI> Vector4::length(), Vector4::squaredLength()
     <LI> isValidPointer now returns false for 0xFEEEFEEE
     <LI> RenderDevice checks for texture compression extensions
     <LI> Restructured the directories for the CPP sources (only affects people who build G3D)
     <LI> Included NVIDIA and SGI OpenGL headers in the distribution, changed install notes
     <LI> Fixed a bug that previously prevented textures from being garbage collected
     <LI> Fixed Line::distance returning values too small
     <LI> Fixed Plane(normal, point) constructor to compute point from normalized direction [Kevin]
     <LI> LED font by Matthew Welch daffy-duck@worldnet.att.net
     <LI> VenusRising font by Ray Larabie <A HREF="mailto:drowsy@cheerful.com">drowsy@cheerful.com</A>
     <LI> VideoFreak font by Jakob Fischer pizzadude@pizzadude.dk
   </UL>

   <P>
   Changes in 4.00
   <UL>
     <LI> Moved texture combine modes from Textures onto RenderDevice texture units
     <LI> Documented RenderDevice::getHDC() (Windows only)
     <LI> Renamed RenderDevice::swapBuffers() to RenderDevice::endFrame(), added corresponding RenderDevice::beginFrame()
     <LI> Moved getNumJoySticks from RenderDevice to UserInput
     <LI> Added TEX_ADD combine mode
     <LI> Table::getKeys and Set::getMembers now have overloads that take an Array as input.
     <LI> BinaryOutput::getCArray
     <LI> RenderDevice::getObjectToWorldMatrix(), RenderDevice::getCameraToWorldMatrix()
     <LI> RenderDevice::debugDrawAxes(), RenderDevice::debugDrawBox(), RenderDevice::debugDrawSphere()
     <LI> Color3::Color3(const Vector3&) and Color4::Color4(const Vector4&)
     <LI> Moved hashCode(const Vector3&) and hashCode(const Vector4&) to the global namespace [Kevin]
     <LI> isValidPointer now returns false for 0xCCCCCCCC and 0xDEADBEEF
     <LI> Fix: RenderDevice::setPolygonOffset now affects polygons rendered in line and point mode
     <LI> Fix: Sun is now invisible after it goes below the horizon
     <LI> Fix: BinaryInput now supports endian-ness correctly in memory read mode
     <LI> Fix: Table.copyFrom and copy constructor now work
   </UL>

   <P>
   Changes in 3.02
   <UL>
     <LI> Built libraries using "Multithreaded DLL" [Kevin & Darius]
     <LI> Added depth, color, and stencil bit depth preferences to G3D::RenderDevice
     <LI> G3D::Sky (plus sky directory in the data distribution)
     <LI> Sky cube data [Jauhn Dabz, jauhn@yahoo.com, http://nullpoint.fragland.net]
     <LI> G3D::UserInput
     <LI> G3D::ManualCameraController
     <LI> G3D::LightingParameters
     <LI> G3D::toSeconds, G3D::AMPM, G3D::GameTime, G3D::RealTime
     <LI> G3D::RenderDevice::project
     <LI> G3D::linearSpline
     <LI> G3D::Color3::fromARGB and G3D::Color4::fromARGB
     <LI> Added non-const G3D::Array::last() [Kevin]
     <LI> Modified G3D::RenderDevice::configureDirectionalLight to operate in world space
     <LI> Fix: Flipped the y-axis of G3D::RenderDevice::getDepthBufferValue so it matches the documentation.
     <LI> Removed brief descriptions from documentation
     <LI> Removed sqrt, sin, cos, etc. that conflict with standard library names
     <LI> Removed TWO_PI constant
     <LI> Removed G3D::Matrix3 virtual destructor
     <LI> Removed G3D::Quat virtual destructor [Kevin]
   </UL>

  
   Changes in 3.01
   <UL>
     <LI> Changed an assert() to debugAssert() in Queue.h
     <LI> G3D::Table doesn't grow the number of buckets under bad hash codes [Morgan & Darius]
     <LI> G3D::Table allocates only 10 initial buckets
     <LI> G3D::Table::debugGetLoad()
     <LI> G3D::CollisionDetection::collisionTimeForMovingPointFixedRectangle
     <LI> G3D::CollisionDetection::collisionTimeForMovingPointFixedBox
     <LI> G3D::Ray::intersectionTime, G3D::Ray::unit()
     <LI> G3D::Log [Morgan & Aaron]
     <LI> G3D::RenderDevice (OpenGL state abstraction.  VertexBuffer support is beta only)
     <LI> G3D::Texture (includes texture compression, image loading, and texture rectangle)
     <LI> Added a comment to the vector classes noting that they can't be sublcassed [Kevin Egan]
   </UL>

   Changes in 3.00
   <UL>
     <LI> G3D::NEWLINE
     <LI> writeStringToFile
     <LI> Fixed empty stringJoin bug
     <LI> Fixed parseFilename with no path bug
     <LI> Vector3::INF3, Vector3::ZERO3
     <LI> G3D::PhysicsFrame (beta-- this interface is going to change in 4.00)
     <LI> G3D::Vector4
     <LI> G3D::Queue
     <LI> Default constructor for G3D::CImage
     <LI> G3D::isValidHeapPointer, G3D::isValidPointer
     <LI> G3D::Ray
     <LI> CImage copy constructor, CImage::load
     <LI> Removed \#pragma once for gcc compatibility
     <LI> Renamed several hashcode methods to hashCode
     <LI> Fixed fuzzy math to work with infinite numbers
     <LI> Fixed Table::remove(), Set::remove() bug [Darius Jazayeri]
     <LI> G3D::CoordinateFrame.toObjectSpace(Vector4), G3D::CoordinateFrame.toWorldSpace(Vector4)
     <LI> Added the data directory
     <LI> G3D::CollisionDetection
     <LI> G3D::Sphere::culledBy()
     <LI> Added the GLG3D library [Morgan McGuire & Seth Block]
     <LI> Changed SDL_GL_Demo to use GLG3D, rotate triangle, and use color blending
     <LI> Fixed debugPrintf to handle long strings on Win32
     <LI> Wrapped the MMX headers with \#ifdefs [Nate Miller]
     <LI> Moved OpenGL code out of CoordinateFrame.h/cpp
     <LI> Fixed BinaryInput readVector*, readColor* to read in correct order [Nate Miller]
     <LI> BinaryInput::readVector4, BinaryInput::readColor4, BinaryOutput::writeVector4, BinaryOutput::writeColor4
     <LI> IFS_Demo for loading IFS files, dealing with models in OpenGL [Nate Miller]
   </UL>

   <P>
   Changes in 2.00
   <UL>
     <LI> Vector2 members renamed to x,y from s,t
     <LI> Added SDL_GL_Demo and Win32_Demo
     <LI> Removed Group
   </UL>

   <P>
   Changes in 1.10
   <UL>
     <LI> CImage, color conversion routines [Morgan McGuire, John Chisholm, and Edward Resnick]
     <LI> Array dereference for BinaryInput
     <LI> BinaryInput from memory
     <LI> BinaryOutput to memory
     <LI> toUpper(std::string), toLower(std::string)
     <LI> Group::clear()
     <LI> inf, nan as global constants (double precision)
     <LI> Can iterate over const Tables
     <LI> Table::deleteValues()
     <LI> Fixed an off-by-one bug in BinaryInput::readString()
     <LI> beginsWith() and wordWrap() string utilities
     <LI> prompt dialogs have fixed width font [Kurt Miller]
     <LI> iMax(), iMin()
     <LI> Array::sort()
     <LI> stringCompare(), stringPtrCompare()
     <LI> readFileAsString()
     <LI> Fixed textPrompt() to wait for input
     <LI> BinaryInput.getFilename(), BinaryOutput.getFilename()
     <LI> ReferenceCount [Justin Miller]
     <LI> endsWith()
     <LI> stringSplit(), stringJoin()
     <LI> Renamed format.* to stringutils.*
     <LI> fileExists(), parseFilename(), createDirectory(), copyFile()
     <LI> highestBit() [Jukka Liimatta]
     <LI> flipRGBVertical()
     <LI> Changed all header guards to use G3D_ prefix
     <LI> ConvexPolyhedron
     <LI> Virtual destructors on almost all objects.
     <LI> RGBtoBGR()
     <LI> Color4
     <LI> Array::pop(bool shrinkArray=true)
     <LI> Vector2::isFinite, Vector2::fuzzyEq, Vector::fuzzyNe
   </UL>
   <P>

   Changes in 1.09
   <UL>
     <LI> Removed pointer hash [Aaron Orenstein]
     <LI> Changed some includes from quotes to pointy brackets [Aaron Orenstein]
     <LI> Sphere::toString() 
     <LI> Plane::toString()
     <LI> Added a change log
   </UL>

   */
