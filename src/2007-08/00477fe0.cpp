// from server: 100% by EspClaude
// from server: 62% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_aaf3b727599393f2.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 RenderDevice layout: no generation/stencilBits/depthBits members (lightSaturation at +0x10,
// state at +0x120, _numTextures/_numTextureCoords at +0x118/+0x11c, framebuffer test at +0x3e8 in the target).
/**
  @file RenderDevice.h

  Graphics hardware abstraction layer (wrapper for OpenGL).

  You can freely mix OpenGL calls with RenderDevice, just make sure you put
  the state back the way you found it or you will confuse RenderDevice.

  @maintainer Morgan McGuire, morgan@graphics3d.com
  @created 2001-05-29
  @edited  2006-03-04

  Copyright 2001-2006, Morgan McGuire
*/

#ifndef GLG3D_RENDERDEVICE_H
#define GLG3D_RENDERDEVICE_H

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/GLight.h"
#include "G3D/TextOutput.h"
#include "G3D/MeshAlg.h"
#include "GLG3D/Texture.h"
#include "GLG3D/Milestone.h"
#include "GLG3D/VertexProgram.h"
#include "GLG3D/PixelProgram.h"
#include "GLG3D/Shader.h"
#include "GLG3D/VARArea.h"
#include "GLG3D/GWindowSettings.h"
#include "GLG3D/GWindow.h"
#include "GLG3D/GLCaps.h"
#include "GLG3D/VAR.h"
#include "GLG3D/Framebuffer.h"

namespace G3D {

class VAR;


/**
 You must call RenderDevice::init() before using the RenderDevice.
  
 Rendering interface that abstracts OpenGL.  OpenGL is a basically
 good API with some rough spots.  Three of these are addressed by
 RenderDevice.  First, OpenGL state management is both tricky and
 potentially slow.  Second, OpenGL functions are difficult to use
 because many extensions have led to an evolutionary rather than
 designed API.  For type safety, new enums are introduced for values
 instead of the traditional OpenGL GLenum's, which are just ints.
 Third, OpenGL intialization is complicated.  This interface
 simplifies it significantly.

 <P> NICEST line and point smoothing is enabled by default (however,
 you need to set your alpha blending mode to see it).

 <P> glEnable(GL_NORMALIZE) is set by default.  glEnable(GL_COLOR_MATERIAL) 
     is enabled by default.  You may be able to get a slight speed increase
     by disabling GL_NORMALIZE or using GL_SCALE_NORMAL instead.

 <P> For stereo rendering, set <CODE>GWindow::Settings::stereo = true</CODE>
     and use RenderDevice::setDrawBuffer to switch which eye is being rendered.  Only
     use RenderDevice::beginFrame/RenderDevice::endFrame once per frame,
     but do clear both buffers separately.

 <P> The only OpenGL calls <B>NOT</B> abstracted by RenderDevice are
     fog and texture coordinate generation.  For everything else, use
     RenderDevice.

 <P>
 Example
  <PRE>
   RenderDevice renderDevice = new RenderDevice();
   renderDevice->init(GWindow::Settings());
  </PRE>

  <P>
  Example 2 (textured quad)
  <PRE>
    RenderDevice* renderDevice = new RenderDevice();
    renderDevice->init(640, 480);

    TextureRef sprite = new Texture("Grass Texture", "image.jpg");

    renderDevice->beginFrame();
    renderDevice->pushState();
    renderDevice->clear(true, true, true);
    renderDevice->setCullFace(RenderDevice::CULL_NONE);
    renderDevice->setProjectionMatrix(Matrix4::perspectiveProjection(-.2, .2, -.15, .15, .2, 200));
    renderDevice->setTexture(0, sprite);
    renderDevice->setColor(Color3::white());
    renderDevice->beginPrimitive(RenderDevice::QUADS);
        renderDevice->setTexCoord(0,  Vector2(0, 1));
        renderDevice->sendVertex(Vector3(-3, -3, -5));
        
        renderDevice->setTexCoord(0,  Vector2(1, 1));
        renderDevice->sendVertex(Vector3( 3, -3, -5));
        
        renderDevice->setTexCoord(0,  Vector2(1, 0));
        renderDevice->sendVertex(Vector3( 3,  3, -5));

        renderDevice->setTexCoord(0,  Vector2(0, 0));
        renderDevice->sendVertex(Vector3(-3,  3, -5));
    renderDevice->endPrimitive();
    renderDevice->popState();

    renderDevice->endFrame();

    while (true);

    renderDevice->cleanup();
    </PRE>

  <P>

  G3D::RenderDevice supports "X_CURRENT" as an option for most settings.

  <P>
 <B>Stereo Rendering</B>
  You can render in stereo (on a stereo capable card) by rendering twice,
  once for each eye's buffer:

  <pre>
    void doGraphics() {
        glDrawBuffer(GL_BACK_LEFT); 
        for (int count = 0; count < 2; ++count) {
           ... (put your normal rendering code here)
           glDrawBuffer(GL_BACK_RIGHT);
        }
    }
  </pre>

  Only flip the buffers once; that is, call renderDevice->swapBuffers
  once per frame (not once per eye).  If you use G3D::GApp, it takes
  care of this for you.

  <B>Multiple displays</B>
  If you are using multiple synchronized displays (e.g. the CAVE),
  see:
  http://www.nvidia.com/object/IO_10753.html
  and
  http://www.cs.unc.edu/Research/stc/FAQs/nVidia/FrameLock-V1.0C.pdf

  GLCaps loads the relevant extensions for you, but you must make
  the synchronizing calls yourself (typically, immediately before
  you call swap buffers).

  <P>
  <B>Raw OpenGL Calls</B>
  RenderDevice allows you to mix your own OpenGL calls with RenderDevice calls.
  It assumes that you restored the OpenGL state after your OpenGL calls, however.
  It is not safe to mix arbitrary OpenGL calls with Shaders, however.  The 
  G3D::Shader API supports more features than OpenGL shaders and does not work
  well with low-level OpenGL.  You may find that the "wrong" shader is bound
  when you execute OpenGL calls.
 */
class RenderDevice {
public:
    enum Primitive {LINES = MeshAlg::LINES, 
                    LINE_STRIP = MeshAlg::LINE_STRIP, 
                    TRIANGLES = MeshAlg::TRIANGLES, 
                    TRIANGLE_STRIP = MeshAlg::TRIANGLE_STRIP,
                    TRIANGLE_FAN = MeshAlg::TRIANGLE_FAN, 
                    QUADS = MeshAlg::QUADS, 
                    QUAD_STRIP = MeshAlg::QUAD_STRIP, 
                    POINTS = MeshAlg::POINTS};
   	
    /** RENDER_CURRENT = preserve whatever the render mode is currently set to.  */
    enum RenderMode {RENDER_SOLID, RENDER_WIREFRAME, RENDER_POINTS, RENDER_CURRENT};

    
    enum {MAX_LIGHTS = 8};

private:

    friend class VAR;
    friend class VARArea;
    friend class Milestone;
    friend class UserInput;
    friend class VertexAndPixelShader;

    GWindow*                    _window;

    /** Should the destructor delete _window?*/
    bool                        deleteWindow;

    /**
     Status and debug statements are written to this log.
     */
    class Log*                  debugLog;

    void setGamma(
        double                  brightness,
        double                  gamma);

    /**
     The intensity at which lights saturate.
     */
    double                      lightSaturation;

	void setVideoMode();

    /**
     For counting the number of beginFrame/endFrames.
     */
    int                         beginEndFrame;

    bool                        _swapBuffersAutomatically;

    /** True after endFrame until swapGLBuffers is invoked.
        Used to correctly manage value changes of _swapBuffersAutomatically
        so that a frame not intended to be seen is never rendered.*/
    bool                        swapGLBuffersPending;

    /** Sets the texture matrix without checking to see if it needs to
        be changed.*/
    void forceSetTextureMatrix(int unit, const float* m);
    void forceSetTextureMatrix(int unit, const double* m);

    /** Time at which the previous endFrame() was called */
    double                      lastTime;

    /** Exponentially weighted moving average frame rate */
    double                      emwaFrameRate;

    /** Argument to last beginPrimitive() */
    Primitive                   currentPrimitive;

    /** Number of vertices since last beginPrimitive() */
    int                         currentPrimitiveVertexCount;
   
    /** Helper for setXXXArray.  Sets the currentVARArea and
        makes some consistency checks.*/
    void setVARAreaFromVAR(const class VAR& v);

    /** The area used inside of an indexedPrimitives call. */
    VARAreaRef                  currentVARArea;

    /** Number of triangles since last beginFrame() */
    int                         triangleCount;

    double                      emwaTriangleCount;
    double                      emwaTriangleRate;

	/** Updates the triangle count based on the primitive.
    
        This method no longer counts the number of primitives but
        calculates the triangles used in that number of primitives.
        LINE and POINT primitives are given one triangle count each. */
	void countTriangles(RenderDevice::Primitive primitive, int numVertices);

    std::string                 cardDescription;

    /**
     Sets the milestones on the currentVARArea.
     */
    void setVARAreaMilestone();

    /** Called by sendIndices. */
    void internalSendIndices(
        RenderDevice::Primitive primitive,
        size_t                  indexSize, 
        int                     numIndices, 
        const void*             index);

    /**
     VertexAndPixelShader is set lazily.  This ensures that the current value is actually bound
     so that the argument list can be bound.  Called from VertexAndPixelShader::bindArgList and
     from beforePrimitive.*/
    void forceVertexAndPixelShaderBind();

    uint32 mDebugNumMajorOpenGLStateChanges;
    uint32 mDebugNumMinorOpenGLStateChanges;
    uint32 mDebugNumMajorStateChanges;
    uint32 mDebugNumMinorStateChanges;
    uint32 mDebugPushStateCalls;

    static std::string dummyString;

	/** Returns true if the frame buffer is complete, or a string in 
        whyIncomplete explaining the problem.
        Potentially slow. */
    bool checkFramebuffer(std::string& whyIncomplete = dummyString) const;

public:

	class DebugSettings {
	public:
		/** 
		Stop rendering after @a primitiveCutoff primitives (i.e., RenderDevice::beginPrimitive or 
		RenderDevice::sendIndices calls) have been processed.  The last primitive rendered before 
		the cutoff will be shown as a wireframe mesh.

        -1 means render all.  Default is -1
		*/
		int				primitiveCutoff;

		/** Forces wireframe mode for all primitives. Default is false. */
		bool			forceWireframe;

        enum Pipeline {
            // Ignore all draw calls
            PIPELINE_NONE,

            // Process vertices but not pixels
            PIPELINE_VERTICES_ONLY,

            // Process full pipeline of vertices and pixels
            PIPELINE_FULL
        };

        /** Default is PIPELINE_FULL */
        Pipeline        pipeline;

        enum Reveal {
            REVEAL_COLOR,
            REVEAL_DEPTH,
            REVEAL_STENCIL,
            REVEAL_ALPHA,
            REVEAL_OVERDRAW
        };

        /** Default is REVEAL_COLOR */
        Reveal          reveal;
	};


	class StatusInfo {
	public:
		uint32			minorStateChangeCount;
		uint32			minorOpenGLStateChangeCount;

		uint32			majorStateChangeCount;
		uint32			majorOpenGLStateChangeCount;

		uint32			pushStateCount;

		uint32			primitiveCount;

		/** Triangles in the last frame */
		uint32			triangleCount;

		/** Amount of time spent in swapbuffers (when large, indicates 
		    that the GPU is blocking the CPU). */
		RealTime		swapbuffersTime;

        /** Inverse of beginframe->endframe time.  Accounts for the frame
            timing of the system as a whole, not just graphics.*/
		float			frameRate;

		/** Exponentially weighted moving average of frame rate */
		float			smoothFrameRate;

		float			triangleRate;		
	};

    // These are abstracted to make it easy to put breakpoints in them
    /**
      State change to RenderDevice.
      Use to update the state change statistics when raw OpenGL calls are made. */
    inline void majStateChange(int inc = 1) {
        mDebugNumMajorStateChanges += inc;
    }

    /** 
      State change to RenderDevice.
     Use to update the state change statistics when raw OpenGL calls are made. */
    inline void minStateChange(int inc = 1) {
        mDebugNumMinorStateChanges += inc;
    }

    /** 
     State change to OpenGL (possibly because of a state change to RenderDevice).
      Use to update the state change statistics when raw OpenGL calls are made. */
    inline void majGLStateChange(int inc = 1) {
        mDebugNumMajorOpenGLStateChanges += inc;
    }

    /** 
      State change to OpenGL (possibly because of a state change to RenderDevice).
      Use to update the state change statistics when raw OpenGL calls are made. */
    inline void minGLStateChange(int inc = 1) {
        mDebugNumMinorOpenGLStateChanges += inc;
    }

    /** Allows the UserInput to find the RenderDevice 
        @deprecated */
    static RenderDevice*        lastRenderDeviceCreated;

    /** Number of RenderDevice state changes.
    
        "OpenGL state changes" are those that forced underlying OpenGL
        state changes; RenderDevice optimizes away redundant state
        changes so many changes will not affect OpenGL. 
        
        Many programs are limited by the number of GL state
        changes; sorting objects in the render pipeline to minimize this 
        can dramatically increase performance.

        Major state changes are texture, shader, camera, and projection changes.
        These are particularly expensive because they can cause cache misses and
        pipeline stalls.  Graphics cards can handle about
        100 of these in real-time. Minor state changes are color, vertex,
        and test changes.  About 2000 of these can be made per frame in real-time.

        One way to locate the code that causes state changes is to put breakpoints
        in RenderDevice::minGLStateChange and RenderDevice::majGLStateChange
        and look at the call stack.

        Zeroed by beginFrame.*/
    uint32 debugNumMajorOpenGLStateChanges() const;
    uint32 debugNumMinorOpenGLStateChanges() const;
    uint32 debugNumMajorStateChanges() const;
    uint32 debugNumMinorStateChanges() const;
    uint32 debugNumPushStateCalls() const;

    RenderDevice();

    ~RenderDevice();


    /**
     Prints a human-readable description of this machine
     to the text output stream.  Either argument may be NULL.
     */
    void describeSystem(
        TextOutput& t);

    inline void describeSystem(
        std::string&        s) {
    
        TextOutput t;
        describeSystem(t);
        t.commitString(s);
    }

    /**
     Checkmarks all RenderDevice state (anything that can be set 
     using RenderDevice methods).

     If you are using some other OpenGL state that is not covered by
     any of the above (e.g., the glReadBuffer and other buffer options),
     you can call glPushAttrib(GL_ALL_ATTRIB_BITS) immediately before 
     pushState to ensure that it is pushed as well.
     */
    void pushState();

    /**
     Sets all state to a clean rendering environment.
     */
    void resetState();

    /**
     Restores all state to whatever was pushed previously.  Push and 
     pop must be used in matching pairs.
     */
    void popState();

    /** To clear the alpha portion of the color buffer, remember to
        enable alpha write */
    void clear(bool clearColor, bool clearDepth, bool clearStencil);

    /** Clears color, depth, and stencil. */
    void clear() {
        clear(true, true, true);
    }

    enum DepthTest   {DEPTH_GREATER,     DEPTH_LESS,       DEPTH_GEQUAL,  
                      DEPTH_LEQUAL,      DEPTH_NOTEQUAL,   DEPTH_EQUAL,   
                      DEPTH_ALWAYS_PASS, DEPTH_NEVER_PASS, DEPTH_CURRENT};

    enum AlphaTest   {ALPHA_GREATER,     ALPHA_LESS,       ALPHA_GEQUAL,  
                      ALPHA_LEQUAL,      ALPHA_NOTEQUAL,   ALPHA_EQUAL,  
                      ALPHA_ALWAYS_PASS, ALPHA_NEVER_PASS, ALPHA_CURRENT};

    enum StencilTest {STENCIL_GREATER,   STENCIL_LESS,     STENCIL_GEQUAL,
                      STENCIL_LEQUAL,    STENCIL_NOTEQUAL, STENCIL_EQUAL, 
                      STENCIL_ALWAYS_PASS, STENCIL_NEVER_PASS, STENCIL_CURRENT};

    enum BlendFunc   {BLEND_SRC_ALPHA,   BLEND_ONE_MINUS_SRC_ALPHA, BLEND_ONE,
                      BLEND_ZERO, BLEND_SRC_COLOR,  BLEND_DST_COLOR,  
                      BLEND_ONE_MINUS_SRC_COLOR, BLEND_CURRENT};

    enum BlendEq     {BLENDEQ_MIN,       BLENDEQ_MAX,      BLENDEQ_ADD,
                      BLENDEQ_SUBTRACT,  BLENDEQ_REVERSE_SUBTRACT,
                      BLENDEQ_CURRENT};

    enum StencilOp   {STENCIL_INCR_WRAP, STENCIL_DECR_WRAP,
                      STENCIL_KEEP,      STENCIL_INCR,     STENCIL_DECR,
                      STENCIL_REPLACE,   STENCIL_ZERO,     STENCIL_INVERT, 
                      STENCILOP_CURRENT};

    enum CullFace    {CULL_FRONT,        CULL_BACK,        CULL_NONE,
                      CULL_CURRENT};

    enum ShadeMode   {SHADE_FLAT,        SHADE_SMOOTH,     SHADE_CURRENT};

    /**
      Arguments to setTextureCombineMode

      TEX_INTERPOLATE = GL_DECAL (blend between previous and current texture based on current alpha)

      Note: GL_INTERPOLATE_ARB is not supported because it takes two arguments.  You can access it
      yourself using glTexEnvi.

      TEX_BLEND = GL_BLEND (for luminance textures, blend against a constant)
      
      TEX_ADD is only present if GLCaps::supports("GL_EXT_texture_env_add")
      See http://oss.sgi.com/projects/ogl-sample/registry/ARB/texture_env_add.txt
    
      TEX_ADD_SIGNED and TEX_SUBTRACT are only present if GLCaps::supports("GL_ARB_texture_env_combine")
      See http://oss.sgi.com/projects/ogl-sample/registry/ARB/texture_env_combine.txt

      TEX_DOT3_RGB and TEX_DOT3_RGBA are only present if GLCaps::supports("GL_ARB_texture_env_dot3")
      http://oss.sgi.com/projects/ogl-sample/registry/ARB/texture_env_dot3.txt
    */
    enum CombineMode {TEX_REPLACE, TEX_BLEND, TEX_INTERPOLATE, TEX_ADD, TEX_MODULATE, 
                      TEX_ADD_SIGNED, TEX_SUBTRACT, TEX_DOT3_RGB, TEX_DOT3_RGBA,
                      TEX_CURRENT};

    #define MAX_BUFFER_SIZE 27

    enum Buffer      {BUFFER_NONE, BUFFER_FRONT_LEFT, BUFFER_FRONT_RIGHT, BUFFER_BACK_LEFT,
                      BUFFER_BACK_RIGHT, BUFFER_FRONT, BUFFER_BACK, BUFFER_LEFT, BUFFER_RIGHT, 
                      BUFFER_FRONT_AND_BACK, BUFFER_CURRENT,
                      BUFFER_COLOR0, BUFFER_COLOR1, BUFFER_COLOR2, BUFFER_COLOR3,
                      BUFFER_COLOR4, BUFFER_COLOR5, BUFFER_COLOR6, BUFFER_COLOR7,
                      BUFFER_COLOR8, BUFFER_COLOR9, BUFFER_COLOR10, BUFFER_COLOR11,
                      BUFFER_COLOR12, BUFFER_COLOR13, BUFFER_COLOR14, BUFFER_COLOR15};

    GLenum BufferToGL[MAX_BUFFER_SIZE];

    /**
     Call to begin the rendering frame.
     */
    void beginFrame();

    /**
     Call to end the current frame and schedules a GWindow::swapGLBuffers call
     to occur some time before beginFrame.  Because that swapGLBuffers might not
     actually occur until the next beginFrame, there is up to one frame of latency
     on the image displayed.  This allows the CPU to execute while 
     the GPU is still rendering, providing net higher performance.
     */
    void endFrame();

    inline bool swapBuffersAutomatically() const {
        return _swapBuffersAutomatically;
    }

    /** 
        By default, GWindow::swapGLBuffers is invoked automatically
        between RenderDevice::endFrame and the following RenderDevice::beginFrame
        to update the front buffer (what the user sees) from the back buffer (where
        rendering commands occur).  You may want to suppress this behavior, for example,
        in order
        to render to the back buffer and capture the result in a texture.
    
        The state of swapBuffersAutomatically is <B>not</B> stored by
        RenderDevice::pushState because it is usually invoked outside
        of RenderDevice::beginFrame / endFrame. 
    */
    void setSwapBuffersAutomatically(bool b);

    /**
     Returns an estimate of the number of frames rendered per second.
     The result is smoothed using an exponentially weighted moving
     average filter so it is robust to unequal frame rendering times.
     */
    double getFrameRate() const;

    /**
     Returns an estimate of the triangles rendered per second.  The
     result is smoothed using an exponentially weighted moving average
     filter.
     */
    double getTriangleRate() const;

    /**
     Returns an estimate of the triangles rendered per frame.  The
     result is smoothed using an exponentially weighted moving average
     filter.
     */
    double getTrianglesPerFrame() const;

	/** Returns the number of triangles rendered since beginFrame.*/
	inline int getTriangleCount() const {
		return triangleCount;
	}

    /**
     Use ALWAYS_PASS to shut off testing.
     */
    void setDepthTest(DepthTest test);
    void setStencilTest(StencilTest test);

    void setRenderMode(RenderMode mode);
    RenderMode renderMode() const;

    /**
     Sets the constant used in the stencil test and operation (if op == STENCIL_REPLACE)
     */
    void setStencilConstant(int reference);

	/** If the alpha test is ALPHA_CURRENT, the reference is ignored */
    void setAlphaTest(AlphaTest test, double reference);

    AlphaTest alphaTest() const;

    double alphaTestReference() const;

    /**
     Sets the frame buffer that is written to.  Used to intentionally
     draw to the front buffer and for stereo rendering.  Its operation is sensitive
     to the current framebuffer being written to. If the framebuffer is the primary
     display then only visible buffers may be specified.  If the framebuffer is an
     application-created framebuffer then only color attachments may be specified.
     */
    void setDrawBuffer(Buffer drawBuffer);

    inline Buffer drawBuffer() const {
        return state.drawBuffer;
    }

    inline void setDepthRange(double low, double high);

    /** @deprecated Use setColorWrite */
    inline void enableColorWrite();
    inline void disableColorWrite();

    /** Color writing is on by default.  Disabling color write allows a program to 
        render to the depth and stencil buffers without creating a visible image in the frame buffer.  
        This is useful for occlusion culling, shadow rendering, and some computational solid geometry algorithms.  
        Rendering may be significantly accelerated when color write is disabled. */
    inline void setColorWrite(bool b);

    /** Returns true if colorWrite is enabled */
    bool colorWrite() const;

    /** Defaults to true if the screen has an alpha channel, otherwise
        defaults to false.
        @deprecated Use setAlphaWrite */
    inline void enableAlphaWrite();
    inline void disableAlphaWrite();

    /** The frame buffer may optionally have an alpha channel for each pixel, depending on how
        the G3D::GWindow was initialized (see G3D::RenderDevice::init, and G3D::GWindow::Settings).
        When the alpha channel is present, rendering to the screen also renders to the alpha 
        channel by default.  Alpha writing is used for render-to-texture and deferred lighting effects.
    
        Rendering to the alpha channel does not produce transparency effects--this is an alpha
        output, not an alpha input.  See RenderDevice::setBlendFunc for a discussion of blending.*/
    inline void setAlphaWrite(bool b);

    /** @deprecated Use setDepthWrite */
    inline void enableDepthWrite();
    inline void disableDepthWrite();
    inline void setDepthWrite(bool b);

    /** Returns true if depthWrite is enabled */
    bool depthWrite() const;

    /** Returns true if alphaWrite is enabled */
    bool alphaWrite() const;

    /**
     Equivalent to glShadeModel
     */
    inline void setShadeMode(ShadeMode s);

    /**
     If wrapping is not supported on the device, the nearest mode is
     selected.  Unlike OpenGL, stencil writing and testing are
     independent. You do not need to enable the stencil test to use
     the stencil op.

     Use KEEP, KEEP, KEEP to disable stencil writing.  Equivalent to a
     combination of glStencilTest, glStencilFunc, and glStencilOp.


     If there is no depth buffer, the depth test always passes.  If there
     is no stencil buffer, the stencil test always passes.
     */
    void setStencilOp(
        StencilOp                       fail,
        StencilOp                       zfail,
        StencilOp                       zpass);

    /**
     When GLCaps::GL_ARB_stencil_two_side is true, separate
     stencil operations can be used for front and back faces.  This
     is useful for rendering shadow volumes.
     */
    void setStencilOp(
        StencilOp                       frontStencilFail,
        StencilOp                       frontZFail,
        StencilOp                       frontZPass,
        StencilOp                       backStencilFail,
        StencilOp                       backZFail,
        StencilOp                       backZPass);

    /**
     Equivalent to <A HREF="http://developer.3dlabs.com/GLmanpages/glblendfunc.htm">glBlendFunc</A>
	 and <A HREF="http://developer.apple.com/documentation/Darwin/Reference/ManPages/man3/glBlendEquation.3.html">glBlendEquation</A>.

     Use 
       <CODE>setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ZERO, RenderDevice::BLENDEQ_ADD)</CODE>
     to shut off blending.
     
     Use 
       <CODE>setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA, RenderDevice::BLENDEQ_ADD)</CODE>
     for unmultiplied alpha blending and
       <CODE>setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA, RenderDevice::BLENDEQ_ADD)</CODE>
     for premultiplied alpha.

	 %Draw your objects from back to front, objects with alpha last. Objects with alpha only get drawn properly if the things
	 they're occluding have been drawn before the alpha'd objects. 

	 Generally, turn alpha on, draw your alpha-blended things, then turn alpha off. 
     */
    void setBlendFunc(
        BlendFunc                       src,
        BlendFunc                       dst,
        BlendEq                         eq = BLENDEQ_ADD);

    /** 
      Sets a 2D clipping region (OpenGL scissor region) relative to the current window
      dimensions (not the viewport).
      Prevents rendering outside the clip region.  Use disableClip2D to turn off.

      Default is off.

      Note that the clip uses G3D 2D coordinates, where the upper-left of the window
      is (0, 0).
      */
    void enableClip2D(const Rect2D& clip);
    void disableClip2D();

    /**
     Equivalent to glLineWidth.
     */
    void setLineWidth(
        double                          width);

    /**
     Equivalent to glPointSize.
     */
    void setPointSize(
        double                          diameter);

    /**
     This is not the OpenGL MODELVIEW matrix: it is a matrix that maps
     object space to world space.  The actual MODELVIEW matrix
     is cameraToWorld.inverse() * objectToWorld.  You can retrieve it
     with getModelViewMatrix.
     */
    void setObjectToWorldMatrix(
        const CoordinateFrame&          cFrame);

    const CoordinateFrame& getObjectToWorldMatrix() const;

    /**
     See RenderDevice::setObjectToWorldMatrix.
     */
    void setCameraToWorldMatrix(
        const CoordinateFrame&          cFrame);

    const CoordinateFrame& getCameraToWorldMatrix() const;

    Matrix4 getProjectionMatrix() const;

    /**
     cameraToWorld.inverse() * objectToWorld
     */
    CoordinateFrame getModelViewMatrix() const;

    /**
     projection() * cameraToWorld.inverse() * objectToWorld
     */
    Matrix4 getModelViewProjectionMatrix() const;


    /**
    To set a typical 3D perspective matrix, use either
     <CODE>renderDevice->setProjectionMatrix(Matrix4::perspectiveProjection(...)) </CODE>
     or call setProjectionAndCameraMatrix.
     */
    void setProjectionMatrix(const Matrix4& P);

    /**
     m is a 16-element matrix in row major order for multiplying
     texture coordinates:

     v' = M v

     Matrix is column major.

     All texture operations check textureUnit against the number of
     available texture units when in debug mode.

     Equivalent to glMatrixMode(GL_TEXTURE); glLoadMatrix(...); on a transposed matrix.
     */
    void setTextureMatrix(
        uint                    textureUnit,
        const float*            m);

    void setTextureMatrix(
        uint                    textureUnit,
        const double*           m);

    void setTextureMatrix(
        uint                    textureUnit,
        const Matrix4&          m);

    void setTextureMatrix(
        uint                    textureUnit,
        const CoordinateFrame&  c);

    /** A bias affects which MIP-map level is used. bias = 0 uses the MIP-map level
        automatically computed.  Bias > 0 selects a blurrier mipmap (avoids aliasing
        artifacts).  Bias < 0 selects a sharper mipmap (avoids blur).  Integer
        values correspond to a whole mip-level shift.  Default is 0.

        See also http://oss.sgi.com/projects/ogl-sample/registry/EXT/texture_lod_bias.txt.
    */
    void setTextureLODBias(
        uint                    unit,
        float                   bias);

    /**
     The matrix returned may not be the same as the
     underlying hardware matrix-- the y-axis is flipped
     in hardware when a texture with invertY = true is specified.
     */
    Matrix4 getTextureMatrix(uint textureUnit);

    /**
     The combine mode specifies how to combine the result of a texture
     lookup with the accumulated fragment value (e.g. the output of
     the previous combine or the constant color for the first texture
     unit).

     Consider using shaders on newer cards instead of texture combiners; 
     they are much easier to use.  See also
     http://oss.sgi.com/projects/ogl-sample/registry/ARB/texture_env_crossbar.txt
     http://oss.sgi.com/projects/ogl-sample/registry/ARB/texture_env_dot3.txt

     The initial combine op is TEX_MODULATE 
     Equivalent to glTexEnv.
     */
    void setTextureCombineMode(
        uint                      textureUnit,
        const CombineMode         texCombine);


    /**
     Resets the matrix, texture, combine op, and constant for a texture unit.
     */
    void resetTextureUnit(
        uint                      textureUnit);

    /**
     Equivalent to glPolygonOffset
     */
    void setPolygonOffset(
        double                  offset);

    /**
     Set the vertex color (equivalent to glColor).
     */
    inline void setColor(const Color4& color) {
        state.color = color;
        glColor4fv(state.color);
    }


    inline void setColor(const Color3& color) {
        state.color = Color4(color, 1);
        glColor3fv(state.color);
    }

    /**
     Equivalent to glNormal
     */
    void setNormal(const Vector3& normal);

    /**
     Equivalent to glTexCoord
     */
    void setTexCoord(uint textureUnit, const Vector4& texCoord);
    void setTexCoord(uint textureUnit, const Vector3& texCoord);
    void setTexCoord(uint textureUnit, const Vector3int16& texCoord);
    void setTexCoord(uint textureUnit, const Vector2& texCoord);
    void setTexCoord(uint textureUnit, const Vector2int16& texCoord);
    void setTexCoord(uint textureUnit, double texCoord);

    /**
     Equivalent to glCullFace
     */
    void setCullFace(CullFace f);

    /**
     Number that the use must multiply all light intensities by 
     to account for the device's brightness.
     */
    inline double getBrightScale() const {
        return brightScale;
    }

    /**
     (0, 0) is the <B>upper</B>-left corner of the screen.
     */
    void setViewport(const Rect2D& v);
    Rect2D getViewport() const;

    /**
     Vertices are "sent" rather than "set" because they
     cause action.
     */
    void sendVertex(const Vector2& vertex);
    void sendVertex(const Vector3& vertex);
    void sendVertex(const Vector4& vertex);

    void setProjectionAndCameraMatrix(const class GCamera& camera);

    /**
     Analogous to glBegin.  See the example in the detailed description
     section of this page.
     */
    void beginPrimitive(Primitive p);

    /**
     Analogous to glEnd.  See the example in the detailed description
     section of this page.
     */
    void endPrimitive();

	void beginIndexedPrimitives();
	void endIndexedPrimitives();

    /** The vertex, normal, color, and tex coord arrays need not come from
        the same VARArea. 

        The format of a VAR array is restricted depending on its use.  The
        following table (from http://oss.sgi.com/projects/ogl-sample/registry/ARB/vertex_program.txt)
        shows the underlying OpenGL restrictions:

     <PRE>

                                       Normal    
      Command                 Sizes    ized?   Types
      ----------------------  -------  ------  --------------------------------
      VertexPointer           2,3,4     no     short, int, float, double
      NormalPointer           3         yes    byte, short, int, float, double
      ColorPointer            3,4       yes    byte, ubyte, short, ushort,
                                               int, uint, float, double
      IndexPointer            1         no     ubyte, short, int, float, double
      TexCoordPointer         1,2,3,4   no     short, int, float, double
      EdgeFlagPointer         1         no     boolean
      VertexAttribPointerARB  1,2,3,4   flag   byte, ubyte, short, ushort,
                                               int, uint, float, double
      WeightPointerARB        >=1       yes    byte, ubyte, short, ushort,
                                               int, uint, float, double
      VertexWeightPointerEXT  1         n/a    float
      SecondaryColor-         3         yes    byte, ubyte, short, ushort,
        PointerEXT                             int, uint, float, double
      FogCoordPointerEXT      1         n/a    float, double
      MatrixIndexPointerARB   >=1       no     ubyte, ushort, uint

      Table 2.4: Vertex array sizes (values per vertex) and data types.  The
      "normalized" column indicates whether fixed-point types are accepted
      directly or normalized to [0,1] (for unsigned types) or [-1,1] (for
      singed types). For generic vertex attributes, fixed-point data are
      normalized if and only if the <normalized> flag is set.

  </PRE>
    
    */
	void setVertexArray(const class VAR& v);

	void setNormalArray(const class VAR& v);
	void setColorArray(const class VAR& v);
	void setTexCoordArray(unsigned int unit, const class VAR& v);

    /** Returns the GWindow used by this RenderDevice */
    GWindow* window() const;

    /**
     Vertex attributes are a generalization of the various per-vertex
     attributes that relaxes the format restrictions.  There are at least
     16 attributes on any card (some allow more).  These attributes have
     special meaning under the fixed function pipeline, as follows:

    <PRE>
    Generic
    Attribute   Conventional Attribute       Conventional Attribute Command
    ---------   ------------------------     ------------------------------
         0      vertex position              Vertex
         1      vertex weights 0-3           WeightARB, VertexWeightEXT
         2      normal                       Normal
         3      primary color                Color
         4      secondary color              SecondaryColorEXT
         5      fog coordinate               FogCoordEXT
         6      -                            -
         7      -                            -
         8      texture coordinate set 0     MultiTexCoord(TEXTURE0, ...)
         9      texture coordinate set 1     MultiTexCoord(TEXTURE1, ...)
        10      texture coordinate set 2     MultiTexCoord(TEXTURE2, ...)
        11      texture coordinate set 3     MultiTexCoord(TEXTURE3, ...)
        12      texture coordinate set 4     MultiTexCoord(TEXTURE4, ...)
        13      texture coordinate set 5     MultiTexCoord(TEXTURE5, ...)
        14      texture coordinate set 6     MultiTexCoord(TEXTURE6, ...)
        15      texture coordinate set 7     MultiTexCoord(TEXTURE7, ...)
       8+n      texture coordinate set n     MultiTexCoord(TEXTURE0+n, ...)
    </PRE>

      @param normalize If true, the coordinates are forced to a [0, 1] scale
    */
    void setVertexAttribArray(unsigned int attribNum, const class VAR& v, bool normalize);

    /**
     Draws the specified kind of primitive from the current vertex array.
     */
	template<class T>
	void sendIndices(RenderDevice::Primitive primitive, int numIndices, 
                     const T* index) {
		debugAssertM(currentFramebufferComplete(), "Incomplete Framebuffer");
        internalSendIndices(primitive, sizeof(T), numIndices, index);

        // Mark all active arrays as busy.
        setVARAreaMilestone();

		countTriangles(primitive, numIndices);
	}

    /**
     Renders sequential vertices from the current vertex array.
     (Equivalent to glDrawArrays)
     */
    void sendSequentialIndices(RenderDevice::Primitive primitive, int numVertices);

    /**
     Draws the specified kind of primitive from the current vertex array.
     */
	template<class T>
	void sendIndices(RenderDevice::Primitive primitive, 
                     const Array<T>& index) {
		sendIndices(primitive, index.size(), index.getCArray());
	}

    void setStencilClearValue(int s);
    void setDepthClearValue(double d);
    void setColorClearValue(const Color4& c);

    /**
     Devices with more textures than texture units (e.g. GeForceFX)
     
     @param textureUnit >= 0
     @param texture Set to NULL to disable the unit
     */
    void setTexture(
        uint                textureUnit,
        TextureRef          texture);

    /** Returns the number of textures available.  May be higher
        than the number of texture units if the programmable
        pipeline provides more textures than the fixed function
        pipeline.*/
    uint numTextures() const;

    /** Returns the number of texture units 
        (texture + reg combiner + matrix) available.
        This only applies to the fixed function pipeline.
    */
    uint numTextureUnits() const;

    /** Returns the number of texture coordinates allowed.
        This may be greater than the number of texture matrices.*/
    uint numTextureCoords() const;

    /**
     Used by G3D::Shader.  Most programs do not need to call this directly.

     Set the current shader.  You may call VertexAndPixelShader::bindArgList either
     before or after this, or use the variation of this call that
     includes an arg list.

     See also G3D::setShader. 
     */
    void setVertexAndPixelShader(const VertexAndPixelShaderRef& s);

    /** Throws VertexAndPixelShader::ArgumentError if the arguments provided
      do not match the arguments declared */
    void setVertexAndPixelShader(const VertexAndPixelShaderRef& s,
            const VertexAndPixelShader::ArgList& args);

    /** @deprecated */
	void setObjectShader(const ObjectShaderRef& s);

    /**
     A G3D::Shader abstracts the programmable graphics pipeline.
     It contains routines that execute before and after
     each primitive group to set other RenderDevice state.     
     */
	void setShader(const ShaderRef& s);

    /**
     Automatically enables vertex programs when they are set. 
     Assumes GLCaps::supports_GL_ARB_vertex_program() is true.

     Don't mix VertexPrograms (old API) with VertexShaders (new API).

     @param vp Set to NULL to use the fixed function pipeline.
     @deprecated Use G3D::RenderDevice::setShader
     */
    void setVertexProgram(const VertexProgramRef& vp);

    /**
     Sets vertex program arguments for vertex programs outputted by Cg.
     The names of arguments are read from comments.

     <PRE>
        ArgList args;
        args.set("MVP", renderDevice->getModelViewProjection());
        args.set("height", 3);
        args.set("viewer", Vector3(1, 2, 3));
        renderDevice->setVertexProgram(toonShadeVP, args);
     </PRE>


     Don't mix VertexPrograms (old API) with VertexShaders (new API).
     @param args must include *all* arguments or an assertion will fail
     @deprecated Use G3D::RenderDevice::setShader
     */
    void setVertexProgram(const VertexProgramRef& vp,
                          const GPUProgram::ArgList& args);

    /**
     (Automatically enables pixel programs when they are set.) 
     Assumes GPUProgram() is true.
     Don't mix PixelPrograms (old API) with PixelShaders (new API).
     @param pp Set to NULL to use the fixed function pipeline.
     @deprecated Use G3D::RenderDevice::setShader
     */
    void setPixelProgram(const PixelProgramRef& pp);

    /**
     It is recommended to call RenderDevice::pushState immediately before
     setting the pixel program, since the arguments can affect texture
     state that will only be restored with RenderDevice::popState.
     Don't mix PixelPrograms (old API) with PixelShaders (new API).
     @deprecated Use RenderDevice::setShader
     */
    void setPixelProgram(const PixelProgramRef& pp,
                         const GPUProgram::ArgList& args);
    
    /**
      Reads a depth buffer value (1 @ far plane, 0 @ near plane) from
      the given screen coordinates (x, y) where (0,0) is the top left
      corner of the width x height screen.  Result is undefined for x, y not
      on screen.

      The result is sensitive to the projection and camera to world matrices.

      If you need to read back the entire depth buffer, use OpenGL glReadPixels
      calls instead of many calls to getDepthBufferValue.
     */
    double getDepthBufferValue(
        int                 x,
        int                 y) const;


    /**
     Description of the graphics card and driver version.
     */
    std::string getCardDescription() const;


    /** When enabled and lighting is enabled, shades backfaces with reversed normals.
        See glLightModeli. */
    void enableTwoSidedLighting();
    void disableTwoSidedLighting();

	/** Automatically called immediately before a primitive group.  User code should only
        call this if making raw OpenGL calls (i.e., "glBegin"), in which case it should be
        called immediately before the glBegin and afterPrimitve should be called immediately
        after the glEnd.
      */
    void beforePrimitive();

    /** Automatically called immediately after a primitive group. See also beforePrimitive.*/
    void afterPrimitive();

private:

	/** Called immediately before a primitive group 
        @deprecated*/
	inline void runObjectShader();


    /**
     For performance, we don't actually unbind a texture when
     turning off a texture unit, we just disable it.  If it 
     is enabled with the same texture, we've saved a swap.
    */
    uint32               currentlyBoundTexture[GLCaps::G3D_MAX_TEXTURE_UNITS];

    /**
     Snapshot of the state maintained by the render device.
     */
    // WARNING: if you add state, you must initialize it in
    // the constructor and RenderDevice::init and set it in
    // setState().
    class RenderState {
    public:
        friend class RenderDevice;

        class TextureUnit {
        public:
            Vector4                 texCoord;

            /** NULL if not bound */
            TextureRef              texture;

            float                   textureMatrix[16];
            CombineMode             combineMode;
            float                   LODBias;

            TextureUnit();

            inline bool operator==(const TextureUnit& other) const {
                return 
                    (texCoord == other.texCoord) &&
                    (texture == other.texture) &&
                    (memcmp(textureMatrix, other.textureMatrix, sizeof(float)*16) == 0) &&
                    (combineMode == other.combineMode) &&
                    (LODBias == other.LODBias);
            }

            inline bool operator!=(const TextureUnit& other) const {
                return !(*this == other);
            }
        };

        class Lights {
        public:
            GLight                      light[MAX_LIGHTS];
            bool                        lightEnabled[MAX_LIGHTS];
            bool                        twoSidedLighting;

            // Ambient light level
            Color4                      ambient;
            bool                        lighting;

            /** True if lights have been written to since the last pushState.
                This is set to false in pushState and to true whenever
                a light changes.*/
            bool                        changed;

            // default changed to true so that a fresh Lights object will
            // provoke a state reset.  Pushstate supresses this
            Lights() : changed(true) {}

            bool operator==(const Lights& other) const;

            inline bool operator!=(const Lights& other) const {
                return !(*this == other);
            }
        };

        class Stencil {
        public:
            StencilTest                 stencilTest;
            int                         stencilReference;
            int                         stencilClear;
            StencilOp                   frontStencilFail;
            StencilOp                   frontStencilZFail;
            StencilOp                   frontStencilZPass;
            StencilOp                   backStencilFail;
            StencilOp                   backStencilZFail;
            StencilOp                   backStencilZPass;
          
            bool operator==(const Stencil& other) const;

            inline bool operator!=(const Stencil& other) const {
                return !(*this == other);
            }
        };

        class Matrices {
        public:
            CoordinateFrame             objectToWorldMatrix;
            CoordinateFrame             cameraToWorldMatrix;
            CoordinateFrame             cameraToWorldMatrixInverse;
            Matrix4                     projectionMatrix;
            bool                        changed;

            inline Matrices() : changed(true) {}

            bool operator==(const Matrices& other) const;

            inline bool operator!=(const Matrices& other) const {
                return !(*this == other);
            }
        };

        Lights                      lights;

        Rect2D                      viewport;
        Rect2D                      clip2D;
        bool                        useClip2D;

        bool                        depthWrite;
        bool                        colorWrite;
        bool                        alphaWrite;

        Buffer                      drawBuffer;

		FramebufferRef				framebuffer;

        DepthTest                   depthTest;
        AlphaTest                   alphaTest;
        double                      alphaReference;

        double                      depthClear;
        Color4                      colorClear;

        CullFace                    cullFace;

        Stencil                     stencil;
        
        BlendFunc                   srcBlendFunc;
        BlendFunc                   dstBlendFunc;
        BlendEq                     blendEq;
        
        ShadeMode                   shadeMode;
    
        double                      polygonOffset;

        RenderMode                  renderMode;

        Color3                      specular;
        double                      shininess;

        double                      lowDepthRange;
        double                      highDepthRange;

        VertexAndPixelShaderRef     vertexAndPixelShader;

        /** @deprecated */
		ObjectShaderRef				objectShader;

        ShaderRef                   shader;

        /** @deprecated */
        VertexProgramRef            vertexProgram;
        /** @deprecated */
        PixelProgramRef             pixelProgram;

        double                      lineWidth;
        double                      pointSize;

        Color4                      color;
        Vector3                     normal;

        /** Index of the highest texture unit that changed since pushState,
            used for short-circuiting work in popstate */
        int                         highestTextureUnitThatChanged;
        TextureUnit                 textureUnit[GLCaps::G3D_MAX_TEXTURE_UNITS];
        Matrices                    matrices;

        inline void touchedTextureUnit(int u) {
            highestTextureUnitThatChanged = iMax(highestTextureUnitThatChanged, u);
        }

        RenderState(int width = 1, int height = 1, int highestTextureUnitThatChanged = GLCaps::G3D_MAX_TEXTURE_UNITS);

        bool operator==(const RenderState& other) const;
    };

    VertexAndPixelShaderRef         lastVertexAndPixelShader;

    GLint toGLStencilOp(RenderDevice::StencilOp op) const;

    /**
     True between beginPrimitive and endPrimitive
     */
    bool                            inPrimitive;

    /** True while invoking a Shader's methods */
    bool                            inShader;

	bool						    inIndexedPrimitive;

    int                             _numTextureUnits;

    int                             _numTextures;

    int                             _numTextureCoords;

    /**
     Called from the various setXLight functions.
     @param force When true, OpenGL state is changed
     regardless of whether RenderDevice thinks it is up to date.
     */
    void setLight(int i, const GLight* light, bool force);

    /**
     Current render state.
     */
    RenderState                     state;

    /**
     Old render states
     */
    Array<RenderState>              stateStack;

    /** Only called from pushState */
    void setState(
        const RenderState&          newState);

    /**
     Amount to multiply colors by due to gamma.
     */
    double                          brightScale;

    bool                            _initialized;
    bool                            cleanedup;

    /** Cache of values supplied to supportsTextureFormat.
        Works on pointers since there is no way for users
        to construct their own TextureFormats.
     */
    Table<const TextureFormat*, bool>      _supportedTextureFormat;

	void push2D(const FramebufferRef& fb, const Rect2D& viewport);

    /** Sets the stencil test using the two-sided extension appropriate to this machine.*/
    void _setStencilTest(StencilTest test, int reference);

public:

    /** @deprecated 
      Use GLCaps::supports instead.
     */
    bool supportsOpenGLExtension(const std::string& extension) const;

    /** Returns true if the given texture format is supported on this device.
        Cannot be called between beginPrimitive and endPrimitive.
        @deprecated
        Use GLCaps::supports.*/
    bool supportsTextureFormat(const TextureFormat* fmt);

    /**
      When true, the 6-argument version of RenderDevice::setStencilOp
      can set the front and back operations to different values.

      @deprecated 
      Use GLCaps::supports_two_sided_stencil instead.
     
    */
    bool supportsTwoSidedStencil() const;

    /**
     When true, Texture::DIM_2D_RECT textures can be created.
     @deprecated
     Use GLCaps::supports_GL_EXT_texture_rectangle instead.
     */
    bool supportsTextureRectangle() const;

    /**
     @deprecated
     Use VertexAndPixelShader
     */
    inline bool supportsVertexProgram() const;

    /**
     When true, NVIDIA Vertex Program 2.0 vertex programs can
     be loaded by VertexProgram.
     @deprecated
     Use VertexAndPixelShader
     */
    bool supportsVertexProgramNV2() const;

    /**
     @deprecated
     Use VertexAndPixelShader
     */
    inline bool supportsPixelProgram() const;

    /**
     When true, VAR arrays will be in video, not main memory,
     and much faster.
     @deprecated
     Use GLCaps::supports_GL_ARB_vertex_buffer_object instead.
     */
    bool supportsVertexBufferObject() const;

    /**
     Returns a value that you should DIVIDE light intensities by
     based on the gamma.  This is automatically handled if you
     use setLight()
     */
    inline double getLightSaturation() const {
        return lightSaturation;
    }

    /**
     Sets the framebuffer to render to.  Use NULL to set the desired rendering 
     target to the windowing system display.

	 Note that if the new framebuffer has different dimensions than the current one
	 the projectionMatrix and viewport will likely be incorrect.

     @param fbo Framebuffer to render to.
    */
    void setFramebuffer(const FramebufferRef &fbo);

    /**
     Checks to ensure that the current framebuffer is complete and error free.  

     @return false On Incomplete Framebuffer Error
     @return true On Complete Framebuffer
    */
    inline bool currentFramebufferComplete(std::string& whyIncomplete = dummyString) const {
        return state.framebuffer.isNull() || 
			   checkFramebuffer(whyIncomplete);
    }

    void push2D();

	/** 
	 Pushes all state, switches to the new framebuffer, and resizes the viewport and projection matrix accordingly.
	 */
    void push2D(const FramebufferRef& fb);

    /**
     Set up for traditional 2D rendering (origin = upper left, y increases downwards).
     
     Note: the viewport will range up to the number of pixels (e.g., (0,0)-(640,480)), as
     recommended in http://msdn.microsoft.com/library/default.asp?url=/library/en-us/opengl/apptips_7wqb.asp .
     Push2D also translates (sets the cameraToWorldMatrix) by (0.375, 0.375, 0) as recommended
     in the OpenGL manual.  This helps avoid rasterization holes due to float-to-int roundoff.

     */
    void push2D(const Rect2D& viewport);
    void pop2D();
 
    /**
     Automatically constructs a Win32Window (on Win32), X11Window (on Linux) or SDLWindow (OS X) then calls the other init
     routine (provided for backwards compatibility).  The constructed
     window is deleted on shutdown.
     */
    bool init(const GWindow::Settings& settings = GWindow::Settings(), class Log* log = NULL);

    /**
     The renderDevice will <B>not</B> delete the window on cleanup.
     */
    bool init(GWindow* window, class Log* log = NULL);

    /** Returns true after RenderDevice::init has been called. */
    bool initialized() const;

    inline const Color4& color() const {
        return state.color;
    }

    inline ShadeMode shadeMode() const {
        return state.shadeMode;
    }

	/**
	 Shuts down the system.  This should be the last call you make.
	 */
    void cleanup();

    /**
     Set the titlebar caption
     */
    void setCaption(const std::string& caption);

    /**
     Takes a JPG screenshot of the front buffer and saves it to a file.
     Returns the name of the file that was written.
     Example: renderDevice->screenshot("screens/"); 
     */
    std::string screenshot(const std::string& filepath) const;

    /**
     Notify RenderDevice that the window size has changed.  
     Called in response to a user resize event.  An example
     using SDL:
     <PRE>
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
            case SDL_VIDEORESIZE:
                {
                    renderDevice->notifyResize(event.resize.w, event.resize.h);
                    Rect2D full(0, 0, renderDevice->getWidth(), renderDevice->getHeight());
                    renderDevice->setViewport(full);
                }
                break;
            }
        }

     </PRE>
     */
    void notifyResize(int w, int h);

    /**
     Takes a screenshot and puts the data into the G3D::GImage dest variable.
     @param useBackBuffer If true, the image is read from the back buffer instead
     of the front buffer (default false).
     @param getAlpha If true, the alpha channel of the frame buffer is also read back.
     */
    void screenshotPic(GImage& dest, bool useBackBuffer = false, bool getAlpha = false) const;

	/**
     @deprecated
	 */
    int G3D_DEPRECATED getWidth() const;

	/**
	 Pixel dimensions of the OpenGL window interior
	 */
    int width() const;

    /**
     @deprecated
     */
    int G3D_DEPRECATED getHeight() const;

	/**
	 Pixel dimensions of the OpenGL window interior
	 */
    int height() const;

    /**
     You must also enableLighting.  Ambient light is handled separately.
     Lighting is automatically adjusted to the lightSaturation value.

     Lights are specified in <B>world space</B>-- they are not affected
     by the camera or object matrix.  Unlike OpenGL, you do not need to
     reset lights after you change the camera matrix.

     Inside a shader, lights set with setLight (which appear as gl_Light)
     are still in world space.

     setLight(i, NULL) disables a light.
     */
    void setLight(int num, const GLight& light);
    void setLight(int num, void*);

    /**
     Sets the current specular coefficient used in the lighting equation.
     Should be on the range 0 (perfectly diffuse) to 1 (bright specular
     highlight).
     */
    void setSpecularCoefficient(float s);
    void setSpecularCoefficient(const Color3& c);

    /**
     Sets the current shininess exponent used in the lighting equation.
     On the range 0 (large highlight) to 255 (tiny, focussed highlight).
     */
    void setShininess(float s);

    /**
     You must also RenderDevice::enableLighting.
     */
    void setAmbientLightColor(
        const Color3&        color);

    void setAmbientLightColor(
        const Color4&        color);

    /**
     Equivalent to glEnable(GL_LIGHTING).

     On initialization, RenderDevice configures the color material as follows
     (it will be this way unless you change it):
     <PRE>
      float spec[] = {1.0f, 1.0f, 1.0f, 1.0f};
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
      glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10);
      glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
     </PRE>
     */
    void enableLighting();
    void disableLighting();

    /**
     Multiplies v by the current object to world and world to camera matrices,
     then by the projection matrix to obtain a 2D point and z-value.  
     
     The result is the 2D position to which the 3D point v corresponds.  You
     can use this to make results rendered with push2D() line up with those
     rendered with a 3D transformation.
     */
    Vector4 project(const Vector4& v) const;
    Vector4 project(const Vector3& v) const;


    /**
     Returns a new Milestone that can be passed to setMilestone and waitForMilestone.
     Milestones are garbage collected.
     */
    MilestoneRef createMilestone(const std::string& name);

    /**
     Inserts a milestone into the GPU processing list.  You can later call
     waitForMilestone to force the CPU to stall until the GPU has reached
     this milestone.
     <P>
     A milestone may be set multiple times, even without waiting for it in between.
     There is no requirement that a milestone be waited for once set.  Milestone
     setting transcends and is not affected by pushState()/popState() or beginFrame()/endFrame().
     */
    void setMilestone(const MilestoneRef& m);

    /**
     Stalls the CPU until the GPU has finished the milestone.  It is an error
     to wait for a milestone that was not set since it was last waited for.
     */
    void waitForMilestone(const MilestoneRef& m);

    /**
     Call within RenderDevice::pushState()...popState() so that you can
     restore the texture coordinate generation that will be configured
     on the unit as a result of this call.

     @param lightMVP The modelview projection matrix that
            was used to render the shadow map originally
            (you can get this from RenderDevice::getModelViewProjectionMatrix() 
            while rendering the shadow map).
     @param textureUnit The texture unit to use for shadowing. 0...RenderDevice::numTextureUnits()
            That unit cannot be used for texturing at the same time.
     */
    void configureShadowMap(
        uint                textureUnit,
        const Matrix4&      lightMVP,
        const TextureRef&   shadowMap);

    /**
     Call within RenderDevice::pushState()...popState() so that you can
     restore the texture coordinate generation.  Note that you can 
     obtain the reflection texture (aka environment map) from G3D::Sky
     or by loading it with G3D:Texture::fromFile.

     @param textureUnit The texture unit to use for shadowing. 0...RenderDevice::numTextureUnits()
            That unit cannot be used for texturing at the same time.
     */

    void configureReflectionMap(
        uint                textureUnit,
        TextureRef          reflectionTexture);

    #ifdef G3D_WIN32
        HDC getWindowHDC() const;
    #endif

};


inline void RenderDevice::setAlphaWrite(bool a) {
    if (a) {
        enableAlphaWrite();
    } else {
        disableAlphaWrite();
    }
}


inline void RenderDevice::setColorWrite(bool a) {
    if (a) {
        enableColorWrite();
    } else {
        disableColorWrite();
    }
}


inline void RenderDevice::setDepthWrite(bool a) {
    if (a) {
        enableDepthWrite();
    } else {
        disableDepthWrite();
    }
}


inline void RenderDevice::enableAlphaWrite() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (! state.alphaWrite) {
        minGLStateChange();
        GLint c = state.colorWrite ? GL_TRUE : GL_FALSE;
        glColorMask(c, c, c, GL_TRUE);
        state.alphaWrite = true;
    }
}


inline void RenderDevice::disableAlphaWrite() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.alphaWrite) {
        minGLStateChange();
        GLint c = state.colorWrite ? GL_TRUE : GL_FALSE;
        glColorMask(c, c, c, GL_FALSE);
        state.alphaWrite = false;
    }
}

inline void RenderDevice::enableColorWrite() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (! state.colorWrite) {
        minGLStateChange();
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, state.alphaWrite ? GL_TRUE : GL_FALSE);
        state.colorWrite = true;
    }
}


inline void RenderDevice::disableColorWrite() {
    debugAssert(! inPrimitive);

    minStateChange();
    if (state.colorWrite) {
        minGLStateChange();
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, state.alphaWrite ? GL_TRUE : GL_FALSE);
        state.colorWrite = false;
    }
}


inline void RenderDevice::enableDepthWrite() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (! state.depthWrite) {
        minGLStateChange();
        glDepthMask(GL_TRUE);
        state.depthWrite = true;
    }
}


inline void RenderDevice::disableDepthWrite() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.depthWrite) {
        minGLStateChange();
        glDepthMask(GL_FALSE);
        state.depthWrite = false;
    }
}


inline void RenderDevice::setShadeMode(ShadeMode s) {
    minStateChange();
    if (s != state.shadeMode) {
        state.shadeMode = s;
        glShadeModel((s == SHADE_FLAT) ? GL_FLAT : GL_SMOOTH);
        minGLStateChange();
    }
}


inline void RenderDevice::setDepthRange(
    double              low,
    double              high) {

    majStateChange();

    if ((state.lowDepthRange != low) ||
        (state.highDepthRange != high)) {
        glDepthRange(low, high);
        state.lowDepthRange = low;
        state.highDepthRange = high;

        minGLStateChange();
    }
}


inline void RenderDevice::runObjectShader() {
	if (! state.objectShader.isNull()) {
		state.objectShader->run(this);
	}
}


inline bool RenderDevice::supportsPixelProgram() const {
    return GLCaps::supports_GL_ARB_fragment_program();
}


inline bool RenderDevice::supportsVertexProgram() const {
    return GLCaps::supports_GL_ARB_vertex_program();
}


} // namespace

#endif

/**
 @file RenderDevice.cpp
 
 @maintainer Morgan McGuire, morgan@graphics3d.com
 
 @created 2001-07-08
 @edited  2006-01-30
 */

#include "G3D/platform.h"
#include "G3D/Log.h"
#include "G3D/GCamera.h"
#include "GLG3D/glcalls.h"
#include "GLG3D/RenderDevice.h"
#include "GLG3D/Texture.h"
#include "GLG3D/getOpenGLState.h"
#include "GLG3D/VARArea.h"
#include "GLG3D/VAR.h"
#include "GLG3D/Framebuffer.h"
#include "G3D/fileutils.h"
#include <time.h>
#ifdef G3D_WIN32
    #include "GLG3D/Win32Window.h"
#else
    #include "GLG3D/SDLWindow.h"    
#endif
#include "GLG3D/GLCaps.h"

namespace G3D {

const GWindow* GWindow::m_current = NULL;


RenderDevice* RenderDevice::lastRenderDeviceCreated = NULL;


GLenum BufferToGL[MAX_BUFFER_SIZE] = {GL_NONE,
                                      GL_FRONT_LEFT,
                                      GL_FRONT_RIGHT,
                                      GL_BACK_LEFT,
                                      GL_BACK_RIGHT,
                                      GL_FRONT,
                                      GL_BACK,
                                      GL_LEFT,
                                      GL_RIGHT,
                                      GL_FRONT_AND_BACK,
                                      0xFFFF,                   //BUFFER_CURRENT
                                      GL_COLOR_ATTACHMENT0_EXT,
                                      GL_COLOR_ATTACHMENT1_EXT,
                                      GL_COLOR_ATTACHMENT2_EXT,
                                      GL_COLOR_ATTACHMENT3_EXT,
                                      GL_COLOR_ATTACHMENT4_EXT,
                                      GL_COLOR_ATTACHMENT5_EXT,
                                      GL_COLOR_ATTACHMENT6_EXT,
                                      GL_COLOR_ATTACHMENT7_EXT,
                                      GL_COLOR_ATTACHMENT8_EXT,
                                      GL_COLOR_ATTACHMENT9_EXT,
                                      GL_COLOR_ATTACHMENT10_EXT,
                                      GL_COLOR_ATTACHMENT11_EXT,
                                      GL_COLOR_ATTACHMENT12_EXT,
                                      GL_COLOR_ATTACHMENT13_EXT,
                                      GL_COLOR_ATTACHMENT14_EXT,
                                      GL_COLOR_ATTACHMENT15_EXT};

static GLint toGLBlendFunc(RenderDevice::BlendFunc b) {
    switch (b) {
    case RenderDevice::BLEND_SRC_ALPHA:
        return GL_SRC_ALPHA;
        
    case RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA:
        return GL_ONE_MINUS_SRC_ALPHA;

    case RenderDevice::BLEND_ONE:
        return GL_ONE;
        
    case RenderDevice::BLEND_ZERO:
        return GL_ZERO;

    case RenderDevice::BLEND_SRC_COLOR:
        return GL_SRC_COLOR;

    case RenderDevice::BLEND_DST_COLOR:
        return GL_DST_COLOR;

    case RenderDevice::BLEND_ONE_MINUS_SRC_COLOR:
        return GL_ONE_MINUS_SRC_COLOR;

    default:
        debugAssertM(false, "Fell through switch");
        return GL_ZERO;
    }
}

static void _glViewport(double a, double b, double c, double d) {
    glViewport(iRound(a), iRound(b), 
	       iRound(a + c) - iRound(a), iRound(b + d) - iRound(b));
}

static GLenum primitiveToGLenum(RenderDevice::Primitive primitive) {
	switch (primitive) {
    case RenderDevice::LINES:
		return GL_LINES;

    case RenderDevice::LINE_STRIP:
		return GL_LINE_STRIP;

    case RenderDevice::TRIANGLES:
		return GL_TRIANGLES;

    case RenderDevice::TRIANGLE_STRIP:
		return GL_TRIANGLE_STRIP;

    case RenderDevice::TRIANGLE_FAN:
		return GL_TRIANGLE_FAN;

    case RenderDevice::QUADS:
		return GL_QUADS;

    case RenderDevice::QUAD_STRIP:
		return GL_QUAD_STRIP;

    case RenderDevice::POINTS:
        return GL_POINTS;

    default:
        debugAssertM(false, "Fell through switch");
        return 0;
    }
}


std::string RenderDevice::getCardDescription() const {
    return cardDescription;
}


RenderDevice::RenderDevice() : _window(NULL), deleteWindow(false) {

    _initialized = false;
    cleanedup = false;
    inPrimitive = false;
    inShader = false;
    _numTextureUnits = 0;
    _numTextures = 0;
    _numTextureCoords = 0;
    emwaFrameRate = 0;
    lastTime = System::getTick();

    for (int i = 0; i < GLCaps::G3D_MAX_TEXTURE_UNITS; ++i) {
        currentlyBoundTexture[i] = 0;
    }

    lastRenderDeviceCreated = this;
}


void RenderDevice::setVARAreaMilestone() {
    currentVARArea->renderDevice = this;

    if (VARArea::mode == VARArea::VBO_MEMORY) {
        // We don't need milestones when using VBO; the spec guarantees
        // correct synchronization.
        return;
    }

    MilestoneRef milestone = createMilestone("VAR Milestone");
    setMilestone(milestone);

    debugAssert(currentVARArea.notNull());

    // Overwrite any preexisting milestone
    currentVARArea->milestone = milestone;
}


RenderDevice::~RenderDevice() {
    debugAssertM(cleanedup, "You deleted a RenderDevice without calling RenderDevice::cleanup()");
}

/**
 Used by RenderDevice::init.
 */
static const char* isOk(bool x) {
    return x ? "ok" : "UNSUPPORTED";
}

/**
 Used by RenderDevice::init.
 */
static const char* isOk(void* x) {
    // GCC incorrectly claims this function is not called.
    return isOk(x != NULL);
}


bool RenderDevice::supportsOpenGLExtension(
    const std::string& extension) const {

    return GLCaps::supports(extension);
}


bool RenderDevice::init(
    const GWindowSettings&      _settings,
    Log*                        log) {

    deleteWindow = true;
    #ifdef G3D_WIN32
        return init(Win32Window::create(_settings), log);
    #else
        return init(new SDLWindow(_settings), log);
    #endif
}


GWindow* RenderDevice::window() const {
    return _window;
}


bool RenderDevice::init(GWindow* window, Log* log) {
    debugAssert(! initialized());
    debugAssert(window);

    _swapBuffersAutomatically = true;
    swapGLBuffersPending = false;
    _window = window;

    GWindowSettings settings;
    window->getSettings(settings);
    
    // Load the OpenGL extensions if they have not already been loaded.
    GLCaps::loadExtensions(log);

    debugLog = log;

    beginEndFrame = 0;
    if (debugLog) {debugLog->section("Initialization");}

    debugAssert((settings.lightSaturation >= 0.5) && 
                (settings.lightSaturation <= 2.0));

    // Under Windows, reset the last error so that our debug box
    // gives the correct results
    #ifdef G3D_WIN32
        SetLastError(0);
    #endif

	const int minimumDepthBits    = iMin(16, settings.depthBits);
	const int desiredDepthBits    = settings.depthBits;

	const int minimumStencilBits  = settings.stencilBits;
	const int desiredStencilBits  = settings.stencilBits;

    // Don't use more texture units than allowed at compile time.
    if (GLCaps::supports_GL_ARB_multitexture()) {
        _numTextureUnits = iMin(GLCaps::G3D_MAX_TEXTURE_UNITS, 
                                glGetInteger(GL_MAX_TEXTURE_UNITS_ARB));
    } else {
        _numTextureUnits = 1;
    }

    // NVIDIA cards with GL_NV_fragment_program have different 
    // numbers of texture coords, units, and textures
    if (GLCaps::supports("GL_NV_fragment_program")) {
        glGetIntegerv(GL_MAX_TEXTURE_COORDS_NV, &_numTextureCoords);
        _numTextureCoords = iClamp(_numTextureCoords,
                                   _numTextureUnits,
                                   GLCaps::G3D_MAX_TEXTURE_UNITS);

        glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS_NV, &_numTextures);
        _numTextures = iClamp(_numTextures,
                              _numTextureUnits, 
                              GLCaps::G3D_MAX_TEXTURE_UNITS);
    } else {
        _numTextureCoords = _numTextureUnits;
        _numTextures      = _numTextureUnits;
    }

    if (! GLCaps::supports_GL_ARB_multitexture()) {
        // No multitexture
        if (debugLog) {
            debugLog->println("No GL_ARB_multitexture support: "
                              "forcing number of texture units "
                              "to no more than 1");
        }
        _numTextureCoords = iMax(1, _numTextureCoords);
        _numTextures      = iMax(1, _numTextures);
        _numTextureUnits  = iMax(1, _numTextureUnits);
    }
    debugAssertGLOk();

    if (debugLog) {
		int t = 0;
       
        int t0 = 0;
        if (GLCaps::supports_GL_ARB_multitexture()) {
            t = t0 = glGetInteger(GL_MAX_TEXTURE_UNITS_ARB);
        }

		if (GLCaps::supports_GL_ARB_fragment_program()) {
			t = glGetInteger(GL_MAX_TEXTURE_IMAGE_UNITS_ARB);
		}

        debugLog->printf("numTextureCoords                      = %d\n"
                         "numTextures                           = %d\n"
                         "numTextureUnits                       = %d\n"
                         "glGet(GL_MAX_TEXTURE_UNITS_ARB)       = %d\n"
                         "glGet(GL_MAX_TEXTURE_IMAGE_UNITS_ARB) = %d\n",
                         _numTextureCoords, _numTextures, _numTextureUnits,
                         t0,
						 t);
    }

    if (debugLog) {debugLog->println("Setting video mode");}

    setVideoMode();

    if (!strcmp((char*)glGetString(GL_RENDERER), "GDI Generic") && debugLog) {
        debugLog->printf(
         "\n*********************************************************\n"
           "* WARNING: This computer does not have correctly        *\n"
           "*          installed graphics drivers and is using      *\n"
           "*          the default Microsoft OpenGL implementation. *\n"
           "*          Most graphics capabilities are disabled.  To *\n"
           "*          correct this problem, download and install   *\n"
           "*          the latest drivers for the graphics card.    *\n"
           "*********************************************************\n\n");
    }

	glViewport(0, 0, getWidth(), getHeight());

    int depthBits, stencilBits, redBits, greenBits, blueBits, alphaBits;
    depthBits       = glGetInteger(GL_DEPTH_BITS);
    stencilBits     = glGetInteger(GL_STENCIL_BITS);
    redBits         = glGetInteger(GL_RED_BITS);
    greenBits       = glGetInteger(GL_GREEN_BITS);
    blueBits        = glGetInteger(GL_BLUE_BITS);
    alphaBits       = glGetInteger(GL_ALPHA_BITS);
    debugAssertGLOk();

    bool depthOk   = depthBits >= minimumDepthBits;
    bool stencilOk = stencilBits >= minimumStencilBits;

    if (debugLog) {
        debugLog->printf("Operating System: %s\n",
                         System::operatingSystem().c_str());

        debugLog->printf("Processor Architecture: %s\n\n", 
                         System::cpuArchitecture().c_str());

        debugLog->printf("GL Vendor:      %s\n", GLCaps::vendor().c_str());

        debugLog->printf("GL Renderer:    %s\n", GLCaps::renderer().c_str());

        debugLog->printf("GL Version:     %s\n", GLCaps::glVersion().c_str());

        debugLog->printf("Driver version: %s\n\n", GLCaps::driverVersion().c_str());

		std::string extStringCopy = (char*)glGetString(GL_EXTENSIONS);

        debugLog->printf(
            "GL extensions: \"%s\"\n\n",
            extStringCopy.c_str());
    }
 

    cardDescription = GLCaps::renderer() + " " + GLCaps::driverVersion();

    if (debugLog) {
    debugLog->section("Video Status");

    GWindowSettings actualSettings;
    window->getSettings(actualSettings);

    // This call is here to make GCC realize that isOk is used.
    (void)isOk(false);
    (void)isOk((void*)NULL);

    debugLog->printf(
             "Capability    Minimum   Desired   Received  Ok?\n"
             "-------------------------------------------------\n"
             "* RENDER DEVICE \n"
             "Depth       %4d bits %4d bits %4d bits   %s\n"
             "Stencil     %4d bits %4d bits %4d bits   %s\n"
             "Alpha                           %4d bits   %s\n"
             "Red                             %4d bits   %s\n"
             "Green                           %4d bits   %s\n"
             "Blue                            %4d bits   %s\n"
             "FSAA                      %2d    %2d    %s\n"

             "Width             %8d pixels           %s\n"
             "Height            %8d pixels           %s\n"
             "Mode                 %10s             %s\n\n",

             minimumDepthBits, desiredDepthBits, depthBits, isOk(depthOk),
             minimumStencilBits, desiredStencilBits, stencilBits, isOk(stencilOk),

             alphaBits, "ok",
             redBits, "ok", 
             greenBits, "ok", 
             blueBits, "ok", 

             settings.fsaaSamples, actualSettings.fsaaSamples,
             isOk(settings.fsaaSamples == actualSettings.fsaaSamples),

             settings.width, "ok",
             settings.height, "ok",
             (settings.fullScreen ? "Fullscreen" : "Windowed"), "ok"
             );
    }



	inPrimitive        = false;
	inIndexedPrimitive = false;

    if (debugLog) debugLog->println("Done initializing RenderDevice.\n");

    _initialized = true;

    if (alphaBits != 0) {
        enableAlphaWrite();
    }

    setCaption("3D");
    
    _window->m_renderDevice = this;

    return true;
}


bool RenderDevice::initialized() const {
    return _initialized;
}


#ifdef G3D_WIN32

HDC RenderDevice::getWindowHDC() const {
    return wglGetCurrentDC();
}

#endif

void RenderDevice::setGamma(
    double              brightness,
    double              gamma) {
    
    Array<uint16> gammaRamp(256);

    for (int i = 0; i < 256; ++i) {
        gammaRamp[i] =
            (uint16)min(65535, 
                      max(0, 
                      (int)(pow((brightness * (i + 1)) / 256.0, gamma) * 65535 + 0.5)));
	}
    
    _window->setGammaRamp(gammaRamp);
}


void RenderDevice::notifyResize(int w, int h) {
    _window->notifyResize(w, h);
}


void RenderDevice::setVideoMode() {

    debugAssertM(stateStack.size() == 0, 
                 "Cannot call setVideoMode between pushState and popState");
    debugAssertM(beginEndFrame == 0, 
                 "Cannot call setVideoMode between beginFrame and endFrame");

    // Reset all state

    GWindowSettings settings;
    _window->getSettings(settings);

    // Set the refresh rate
    #ifdef G3D_WIN32
        if (wglSwapIntervalEXT != NULL) {
            if (debugLog) {
                if (settings.asychronous) {
                    debugLog->printf("wglSwapIntervalEXT(0);\n");
                } else {
                    debugLog->printf("wglSwapIntervalEXT(1);\n");
                }
            }
            wglSwapIntervalEXT(settings.asychronous ? 0 : 1);
        }
    #endif

    {
        if (debugLog) {
            debugLog->printf("Setting brightness to %g\n", 
                                        settings.lightSaturation);
        }
        // Adjust the gamma so that changing the 
        // light intensities won't affect the actual screen
        // brightness.  This method due to John Carmack.
        lightSaturation = settings.lightSaturation;
        brightScale = 1.0 / lightSaturation;
        setGamma(lightSaturation, 1.0);
        if (debugLog) debugLog->println("Brightness set.");
    }

    // Enable proper specular lighting
    if (GLCaps::supports("GL_EXT_separate_specular_color")) {
        if (debugLog) {
            debugLog->println("Enabling separate specular lighting.\n");
        }
        glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL_EXT, 
                      GL_SEPARATE_SPECULAR_COLOR_EXT);
        debugAssertGLOk();
    } else if (debugLog) {
        debugLog->println("Cannot enable separate specular lighting, extension not supported.\n");
    }


    // Make sure we use good interpolation.
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Smoothing by default on NVIDIA cards.  On ATI cards
    // there is a bug that causes shaders to generate incorrect
    // results and run at 0 fps, so we can't enable this.
    if (! beginsWith(GLCaps::vendor(), "ATI")) {
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POINT_SMOOTH);
    }
    

    // glHint(GL_GENERATE_MIPMAP_HINT_EXT, GL_NICEST);
    if (GLCaps::supports("GL_ARB_multisample")) {
        glEnable(GL_MULTISAMPLE_ARB);
    }

    debugAssertGLOk();
    if (GLCaps::supports("GL_NV_multisample_filter_hint")) {
        glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    }

    resetState();

    if (debugLog) debugLog->printf("Done setting initial state.\n");
}


void RenderDevice::setCaption(const std::string& caption) {
    _window->setCaption(caption);
}


int RenderDevice::getWidth() const {
	return width();
}


int RenderDevice::getHeight() const {
	return height();
}


int RenderDevice::width() const {
	if (state.framebuffer.isNull()) {
	    return _window->width();
	} else {
		return state.framebuffer->width();
	}
}


int RenderDevice::height() const {
	if (state.framebuffer.isNull()) {
	    return _window->height();
	} else {
		return state.framebuffer->height();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////


Vector4 RenderDevice::project(const Vector3& v) const {
    return project(Vector4(v, 1));
}


Vector4 RenderDevice::project(const Vector4& v) const {
    return glToScreen(v);
}


void RenderDevice::cleanup() {
    debugAssert(initialized());

    if (debugLog) {debugLog->println("Shutting down RenderDevice.");}

    if (debugLog) {debugLog->println("Restoring gamma.");}
    setGamma(1, 1);

    if (debugLog) {debugLog->println("Freeing all VAR memory");}

    if (deleteWindow) {
        if (debugLog) {debugLog->println("Deleting window.");}
        VARArea::cleanupAllVARAreas();
        delete _window;
    }

    cleanedup = true;
}


void RenderDevice::push2D() {
    push2D(getViewport());
}

void RenderDevice::push2D(const Rect2D& viewport) {
	push2D(NULL, viewport);
}

void RenderDevice::push2D(const FramebufferRef& fb) {
	const Rect2D& viewport = fb.notNull() ? fb->rect2DBounds() : Rect2D::xywh(0, 0, _window->width(), _window->height());
	push2D(fb, viewport);
}

void RenderDevice::push2D(const FramebufferRef& fb, const Rect2D& viewport) {
    pushState();

	setFramebuffer(fb);
    setDepthTest(DEPTH_ALWAYS_PASS);
    disableLighting();
    setCullFace(CULL_NONE);
    disableDepthWrite();
    setViewport(viewport);
	setObjectToWorldMatrix(CoordinateFrame());

    // 0.375 is a float-to-int adjustment.  See: http://msdn.microsoft.com/library/default.asp?url=/library/en-us/opengl/apptips_7wqb.asp
    //setCameraToWorldMatrix(CoordinateFrame(Matrix3::identity(), Vector3(-0.375, -0.375, 0.0)));

    setCameraToWorldMatrix(CoordinateFrame());

    setProjectionMatrix(Matrix4::orthogonalProjection(viewport.x0(), viewport.x0() + viewport.width(), viewport.y0() + viewport.height(), viewport.y0(), -1, 1));
}


void RenderDevice::pop2D() {
    popState();
}

////////////////////////////////////////////////////////////////////////////////////////////////
RenderDevice::RenderState::RenderState(int width, int height, int htutc) :

    // WARNING: this must be kept in sync with the initialization code
    // in init();
    viewport(Rect2D::xywh(0, 0, width, height)),

    useClip2D(false),

    depthWrite(true),
    colorWrite(true),
    alphaWrite(false),

    depthTest(DEPTH_LEQUAL),
    alphaTest(ALPHA_ALWAYS_PASS),
    alphaReference(0.0) {

	framebuffer = NULL;

    lights.twoSidedLighting =    false;


    srcBlendFunc                = BLEND_ONE;
    dstBlendFunc                = BLEND_ZERO;
    blendEq                     = BLENDEQ_ADD;

    drawBuffer                  = BUFFER_BACK;

    stencil.stencilTest         = STENCIL_ALWAYS_PASS;
    stencil.stencilReference    = 0;
    stencil.frontStencilFail    = STENCIL_KEEP;
    stencil.frontStencilZFail   = STENCIL_KEEP;
    stencil.frontStencilZPass   = STENCIL_KEEP;
    stencil.backStencilFail     = STENCIL_KEEP;
    stencil.backStencilZFail    = STENCIL_KEEP;
    stencil.backStencilZPass    = STENCIL_KEEP;

    polygonOffset               = 0;
    lineWidth                   = 1;
    pointSize                   = 1;

    renderMode                  = RenderDevice::RENDER_SOLID;

    shininess                   = 15;
    specular                    = Color3::white() * 0.8f;

    lights.ambient              = Color4(0.25f, 0.25f, 0.25f, 1.0f);

    lights.lighting             = false;
    color                       = Color4(1,1,1,1);
    normal                      = Vector3(0,0,0);

    // Note: texture units and lights initialize themselves

    matrices.objectToWorldMatrix         = CoordinateFrame();
    matrices.cameraToWorldMatrix         = CoordinateFrame();
    matrices.cameraToWorldMatrixInverse  = CoordinateFrame();

    stencil.stencilClear        = 0;
    depthClear                  = 1;
    colorClear                  = Color4(0,0,0,1);

    shadeMode                   = SHADE_FLAT;

    vertexAndPixelShader        = NULL;
	objectShader				= NULL;
    shader                      = NULL;
    vertexProgram               = NULL;
    pixelProgram                = NULL;

    for (int i = 0; i < MAX_LIGHTS; ++i) {
        lights.lightEnabled[i] = false;
    }

    // Set projection matrix
    double aspect;
    aspect = (double)viewport.width() / viewport.height();

    matrices.projectionMatrix = Matrix4::perspectiveProjection(-aspect, aspect, -1, 1, 0.1f, 100.0f);

    cullFace                    = CULL_BACK;

    lowDepthRange               = 0;
    highDepthRange              = 1;


    highestTextureUnitThatChanged = htutc;
}


RenderDevice::RenderState::TextureUnit::TextureUnit() : texture(NULL), LODBias(0) {
    texCoord        = Vector4(0,0,0,1);
    combineMode     = TEX_MODULATE;

    // Identity texture matrix
    memset(textureMatrix, 0, sizeof(float) * 16);
    for (int i = 0; i < 4; ++i) {
        textureMatrix[i + i * 4] = (float)1.0;
    }
}


void RenderDevice::resetState() {
    state = RenderState(getWidth(), getHeight());

	glClearDepth(1.0);

    glEnable(GL_NORMALIZE);

    debugAssertGLOk();
    if (GLCaps::supports_GL_EXT_stencil_two_side()) {
        glEnable(GL_STENCIL_TEST_TWO_SIDE_EXT);
    }

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    // Compute specular term correctly
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    debugAssertGLOk();

    if (debugLog) debugLog->println("Setting initial rendering state.\n");
    glDisable(GL_LIGHT0);
    debugAssertGLOk();
    {
        // WARNING: this must be kept in sync with the 
        // RenderState constructor
        state = RenderState(getWidth(), getHeight(), iMax(_numTextures, _numTextureCoords) - 1);

        _glViewport(state.viewport.x0(), state.viewport.y0(), state.viewport.width(), state.viewport.height());
        glDepthMask(GL_TRUE);
        glColorMask(1,1,1,0);

        if (GLCaps::supports_GL_EXT_stencil_two_side()) {
            glActiveStencilFaceEXT(GL_BACK);
        }
        for (int i = 0; i < 2; ++i) {
            glStencilMask((GLuint)~0);
            glDisable(GL_STENCIL_TEST);
            glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
            glStencilFunc(GL_ALWAYS, 0, 0xFFFFFFFF);
            glDisable(GL_ALPHA_TEST);
            if (GLCaps::supports_GL_EXT_stencil_two_side()) {
                glActiveStencilFaceEXT(GL_FRONT);
            }
        }

        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_SCISSOR_TEST);

        glDisable(GL_BLEND);
        glDisable(GL_POLYGON_OFFSET_FILL);
        glLineWidth(1);
        glPointSize(1);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, state.lights.ambient);
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, state.lights.twoSidedLighting);

        glDisable(GL_LIGHTING);

        glDrawBuffer(GL_BACK);
        glGetError();

        for (int i = 0; i < MAX_LIGHTS; ++i) {
            setLight(i, NULL, true);
        }
        glColor4d(1, 1, 1, 1);
        glNormal3d(0, 0, 0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        setShininess(state.shininess);
        setSpecularCoefficient(state.specular);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glShadeModel(GL_FLAT);

        glClearStencil(0);
        glClearDepth(1);
        glClearColor(0,0,0,1);
        glMatrixMode(GL_PROJECTION);
        glLoadMatrix(state.matrices.projectionMatrix);
        glMatrixMode(GL_MODELVIEW);

        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);

        glDepthRange(0, 1);

        // Set up the texture units.
        if (glMultiTexCoord4fvARB != NULL) {
            for (int t = _numTextureCoords - 1; t >= 0; --t) {
                float f[] = {0,0,0,1};
                glMultiTexCoord4fvARB(GL_TEXTURE0_ARB + t, f);
            }
        } else if (_numTextureCoords > 0) {
            glTexCoord(Vector4(0,0,0,1));
        }

        if (glActiveTextureARB != NULL) {
            glActiveTextureARB(GL_TEXTURE0_ARB);
        }
    }
    debugAssertGLOk();

}


bool RenderDevice::RenderState::Lights::operator==(const Lights& other) const {
    for (int L = 0; L < MAX_LIGHTS; ++L) {
        if ((lightEnabled[L] != other.lightEnabled[L]) ||
            (lightEnabled[L] && (light[L] != other.light[L]))) {
            return false;
        }
    }

    debugAssertM(changed == false,
        "Should never enter lighting comparison "
        "when lighting has not changed.");

    return 
        (lighting == other.lighting) && 
        (ambient == other.ambient) &&
        (twoSidedLighting == other.twoSidedLighting);
}


bool RenderDevice::RenderState::Stencil::operator==(const Stencil& other) const {
    return 
        (stencilTest == other.stencilTest) &&
        (stencilReference == other.stencilReference) &&
        (stencilClear == other.stencilClear) &&
        (frontStencilFail == other.frontStencilFail) &&
        (frontStencilZFail == other.frontStencilZFail) &&
        (frontStencilZPass == other.frontStencilZPass) &&
        (backStencilFail == other.backStencilFail) &&
        (backStencilZFail == other.backStencilZFail) &&
        (backStencilZPass == other.backStencilZPass);
}


bool RenderDevice::RenderState::Matrices::operator==(const Matrices& other) const {
    return
        (objectToWorldMatrix == other.objectToWorldMatrix) &&
        (cameraToWorldMatrix == other.cameraToWorldMatrix) &&
        (projectionMatrix == other.projectionMatrix);
}


void RenderDevice::setState(
    const RenderState&          newState) {

    // The state change checks inside the individual
    // methods will (for the most part) minimize
    // the state changes so we can set all of the
    // new state explicitly.
    
	// Set framebuffer first, since it can affect the viewport
	if (state.framebuffer != newState.framebuffer) {
		setFramebuffer(newState.framebuffer);

		// Intentionally corrupt the viewport, forcing renderdevice to reset it
		state.viewport = Rect2D::xywh(-1,-1,-1,-1);
	}

    setViewport(newState.viewport);
    debugAssertGLOk();

    if (newState.useClip2D) {
        enableClip2D(newState.clip2D);
    } else {
        disableClip2D();
    }
    
    if (newState.depthWrite) {
        enableDepthWrite();
    } else {
        disableDepthWrite();
    }

    if (newState.colorWrite) {
        enableColorWrite();
    } else {
        disableColorWrite();
    }

    if (newState.alphaWrite) {
        enableAlphaWrite();
    } else {
        disableAlphaWrite();
    }
    debugAssertGLOk();

    setDrawBuffer(newState.drawBuffer);

    setShadeMode(newState.shadeMode);
    setDepthTest(newState.depthTest);
    debugAssertGLOk();

    if (newState.stencil != state.stencil) {
        setStencilConstant(newState.stencil.stencilReference);

		debugAssertGLOk();
        setStencilTest(newState.stencil.stencilTest);

        setStencilOp(
            newState.stencil.frontStencilFail, newState.stencil.frontStencilZFail, newState.stencil.frontStencilZPass,
            newState.stencil.backStencilFail, newState.stencil.backStencilZFail, newState.stencil.backStencilZPass);

        setStencilClearValue(newState.stencil.stencilClear);
    }

    setDepthClearValue(newState.depthClear);

    setColorClearValue(newState.colorClear);

    setAlphaTest(newState.alphaTest, newState.alphaReference);

    setBlendFunc(newState.srcBlendFunc, newState.dstBlendFunc, newState.blendEq);

    setRenderMode(newState.renderMode);
    setPolygonOffset(newState.polygonOffset);
    setLineWidth(newState.lineWidth);
    setPointSize(newState.pointSize);

    setSpecularCoefficient(newState.specular);
    setShininess(newState.shininess);

    if (state.lights.changed) {//(newState.lights != state.lights) {
        if (newState.lights.lighting) {
            enableLighting();
        } else {
            disableLighting();
        }

        if (newState.lights.twoSidedLighting) {
            enableTwoSidedLighting();
        } else {
            disableTwoSidedLighting();
        }

        setAmbientLightColor(newState.lights.ambient);

        for (int i = 0; i < MAX_LIGHTS; ++i) {
            if (newState.lights.lightEnabled[i]) {
                setLight(i, newState.lights.light[i]);
            } else {
                setLight(i, NULL);
            }
        }
    }

    setColor(newState.color);
    setNormal(newState.normal);

    for (int u = state.highestTextureUnitThatChanged; u >= 0; --u) {
        if (newState.textureUnit[u] != state.textureUnit[u]) {

            if (u < (int)numTextures()) {
                setTexture(u, newState.textureUnit[u].texture);

                if (u < (int)numTextureUnits()) {
                    setTextureCombineMode(u, newState.textureUnit[u].combineMode);
                    setTextureMatrix(u, newState.textureUnit[u].textureMatrix);

                    setTextureLODBias(u, newState.textureUnit[u].LODBias);
                }
            }
            setTexCoord(u, newState.textureUnit[u].texCoord);            
        }
    }

    setCullFace(newState.cullFace);

    setDepthRange(newState.lowDepthRange, newState.highDepthRange);

    if (state.matrices.changed) { //(newState.matrices != state.matrices) { 
        if (newState.matrices.cameraToWorldMatrix != state.matrices.cameraToWorldMatrix) {
            setCameraToWorldMatrix(newState.matrices.cameraToWorldMatrix);
        }

        if (newState.matrices.objectToWorldMatrix != state.matrices.objectToWorldMatrix) {
            setObjectToWorldMatrix(newState.matrices.objectToWorldMatrix);
        }

        setProjectionMatrix(newState.matrices.projectionMatrix);
    }

    setVertexAndPixelShader(newState.vertexAndPixelShader);
	setObjectShader(newState.objectShader);
    setShader(newState.shader);

    if (supportsVertexProgram()) {
        setVertexProgram(newState.vertexProgram);
    }

    if (supportsPixelProgram()) {
        setPixelProgram(newState.pixelProgram);
    }
    
    // Adopt the popped state's deltas relative the state that it replaced.
    state.highestTextureUnitThatChanged = newState.highestTextureUnitThatChanged;
    state.matrices.changed = newState.matrices.changed;
    state.lights.changed = newState.lights.changed;
}


void RenderDevice::enableTwoSidedLighting() {
    minStateChange();
    if (! state.lights.twoSidedLighting) {
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
        state.lights.twoSidedLighting = true;
        state.lights.changed = true;
        minGLStateChange();
    }
}


void RenderDevice::disableTwoSidedLighting() {
    minStateChange();
    if (state.lights.twoSidedLighting) {
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);
        state.lights.twoSidedLighting = false;
        state.lights.changed = true;
        minGLStateChange();
    }
}


void RenderDevice::beforePrimitive() {
	if (! state.shader.isNull()) {
        debugAssert(! inShader);
        inShader = true;
		state.shader->beforePrimitive(this);
        inShader = false;
	}

    // If a Shader was bound, it will force this.  Otherwise we need to do so.
    forceVertexAndPixelShaderBind();
}


void RenderDevice::afterPrimitive() {
	if (! state.shader.isNull()) {
        debugAssert(! inShader);
		inShader = true;
        state.shader->afterPrimitive(this);
        inShader = false;
	}
}


void RenderDevice::setSpecularCoefficient(const Color3& c) {
    minStateChange();
    if (state.specular != c) {
        state.specular = c;

        static float spec[4];
        spec[0] = c[0];
        spec[1] = c[1];
        spec[2] = c[2];
        spec[3] = 1.0f;

        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
        minGLStateChange();
    }
}


void RenderDevice::setSpecularCoefficient(float s) {
    setSpecularCoefficient(s * Color3::white());
}


void RenderDevice::setShininess(float s) {
    minStateChange();
    if (state.shininess != s) {
        state.shininess = s;
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, s);
        minGLStateChange();
    }
}


void RenderDevice::setRenderMode(RenderMode m) {
    minStateChange();

    if (m == RENDER_CURRENT) {
        return;
    }

    if (state.renderMode != m) {
        minGLStateChange();
        state.renderMode = m;
        switch (m) {
        case RENDER_SOLID:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;

        case RENDER_WIREFRAME:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;

        case RENDER_POINTS:
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            break;

        case RENDER_CURRENT:
            return;
            break;
        }
    }
}


RenderDevice::RenderMode RenderDevice::renderMode() const {
    return state.renderMode;
}


void RenderDevice::setDrawBuffer(Buffer b) {
    minStateChange();

    if (b == BUFFER_CURRENT) return;

    if (state.framebuffer.isNull()) {
        alwaysAssertM((b >= BUFFER_NONE) && (b <= BUFFER_CURRENT), 
                  "Drawing to a color buffer is only supported by application-created framebuffers!");
    } else {
        alwaysAssertM((b >= BUFFER_CURRENT) && (b <= BUFFER_COLOR15), 
                  "Visible buffers cannot be specified for application-created framebuffers!");
    }

    if (b != state.drawBuffer) {
        minGLStateChange();
        state.drawBuffer = b;
        glDrawBuffer (BufferToGL[state.drawBuffer]);
    }
}


void RenderDevice::setCullFace(CullFace f) {
    minStateChange();
    if (f != state.cullFace) {
        minGLStateChange();
        switch (f) {
        case CULL_FRONT:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT);
            break;

        case CULL_BACK:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            break;

        case CULL_NONE:
            glDisable(GL_CULL_FACE);
            break;

        default:
            debugAssertM(false, "Fell through switch");
        }

        state.cullFace = f;
    }
}



void RenderDevice::pushState() {
    debugAssert(! inPrimitive);

    stateStack.push(state);

    // Record that that the lights and matrices are unchanged since the previous state.
    // This allows popState to restore the lighting environment efficiently.

    state.lights.changed = false;
    state.matrices.changed = false;
    state.highestTextureUnitThatChanged = -1;

    mDebugPushStateCalls += 1;
}


void RenderDevice::popState() {
    debugAssert(! inPrimitive);
    debugAssertM(stateStack.size() > 0, "More calls to RenderDevice::pushState() than RenderDevice::popState().");
    setState(stateStack.last());
    stateStack.popDiscard();
}


void RenderDevice::clear(bool clearColor, bool clearDepth, bool clearStencil) {
    debugAssert(! inPrimitive);
#   ifdef G3D_DEBUG
    std::string why;
    debugAssertM(currentFramebufferComplete(why), why);
#   endif
    majStateChange();
    majGLStateChange();

    GLint mask = 0;

    // TODO: do we need to enable write to clear these buffers?
    pushState();
    if (clearColor) {
        mask |= GL_COLOR_BUFFER_BIT;
        enableColorWrite();
    }

    if (clearDepth) {
        mask |= GL_DEPTH_BUFFER_BIT;
        enableDepthWrite();
    }

    int oldMask;
    glGetIntegerv(GL_STENCIL_WRITEMASK, &oldMask);

    if (clearStencil) {
        mask |= GL_STENCIL_BUFFER_BIT;
        glStencilMask((GLuint)~0);
        minGLStateChange();
        minStateChange();
    }

    glClear(mask);
    glStencilMask(oldMask);
    minGLStateChange();
    minStateChange();
    popState();
}


uint RenderDevice::numTextureUnits() const {
    return _numTextureUnits;
}


uint RenderDevice::numTextures() const {
    return _numTextures;
}


uint RenderDevice::numTextureCoords() const {
    return _numTextureCoords;
}


void RenderDevice::beginFrame() {
    if (swapGLBuffersPending) {
        _window->swapGLBuffers();
        swapGLBuffersPending = false;
    }

    mDebugNumMajorOpenGLStateChanges = 0;
    mDebugNumMinorOpenGLStateChanges = 0;
    mDebugNumMajorStateChanges = 0;
    mDebugNumMinorStateChanges = 0;
    mDebugPushStateCalls = 0;

    ++beginEndFrame;
    triangleCount = 0;
    debugAssertM(beginEndFrame == 1, "Mismatched calls to beginFrame/endFrame");
    pushState();
}


void RenderDevice::setSwapBuffersAutomatically(bool b) {
    if (b == _swapBuffersAutomatically) {
        // Setting to current state; nothing to do.
        return;
    }

    if (swapGLBuffersPending) {
        // Process the pending swap buffers call
        _window->swapGLBuffers();
        swapGLBuffersPending = false;
    }

    _swapBuffersAutomatically = b;
}


void RenderDevice::endFrame() {
    --beginEndFrame;
    debugAssertM(beginEndFrame == 0, "Mismatched calls to beginFrame/endFrame");

    popState();

    // Schedule a swap buffer iff we are handling them automatically.
    swapGLBuffersPending = _swapBuffersAutomatically;

    debugAssertM(stateStack.size() == 0, "Missing RenderDevice::popState or RenderDevice::pop2D.");

    double now = System::getTick();
    double dt = now - lastTime;
    if (dt == 0) {
        dt = 0.0001;
    }

    {
        // high frame rate: A (interpolation parameter) is small
        // low frame rate: A is big
        const double A = clamp(dt, .07, 1);
    
        emwaFrameRate     = lerp(emwaFrameRate, 1 / dt, A);
        emwaTriangleRate  = lerp(emwaTriangleRate, triangleCount / dt, A);
        emwaTriangleCount = lerp(emwaTriangleCount, triangleCount, A);
    }

    if ((emwaFrameRate == inf()) || (isNaN(emwaFrameRate))) {
        emwaFrameRate = 1000000;
    } else if (emwaFrameRate < 0) {
        emwaFrameRate = 0;
    }

    if ((emwaTriangleRate == inf()) || isNaN(emwaTriangleRate)) {
        emwaTriangleRate = 1e20;
    } else if (emwaTriangleRate < 0) {
        emwaTriangleRate = 0;
    }

    if ((emwaTriangleCount == inf()) || isNaN(emwaTriangleCount)) {
        emwaTriangleRate = 1e20;
    } else if (emwaTriangleCount < 0) {
        emwaTriangleCount = 0;
    }

    lastTime = now;
}


bool RenderDevice::alphaWrite() const {
    return state.alphaWrite;
}


bool RenderDevice::depthWrite() const {
    return state.depthWrite;
}


bool RenderDevice::colorWrite() const {
    return state.colorWrite;
}


void RenderDevice::setStencilClearValue(int s) {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.stencil.stencilClear != s) {
        minGLStateChange();
        glClearStencil(s);
        state.stencil.stencilClear = s;
    }
}


void RenderDevice::setDepthClearValue(double d) {
    minStateChange();
    debugAssert(! inPrimitive);
    if (state.depthClear != d) {
        minGLStateChange();
        glClearDepth(d);
        state.depthClear = d;
    }
}


void RenderDevice::setColorClearValue(const Color4& c) {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.colorClear != c) {
        minGLStateChange();
        glClearColor(c.r, c.g, c.b, c.a);
        state.colorClear = c;
    }
}


void RenderDevice::setViewport(const Rect2D& v) {
    minStateChange();
    if (state.viewport != v) {
        // Flip to OpenGL y-axis
		float h = height();
        _glViewport(v.x0(), h - v.y1(), v.width(), v.height());
        state.viewport = v;
        minGLStateChange();
    }
}


void RenderDevice::enableClip2D(const Rect2D& clip) {
    minStateChange();
    minGLStateChange();
    state.clip2D = clip;

	int clipX0 = iFloor(clip.x0());
	int clipY0 = iFloor(clip.y0());
	int clipX1 = iCeil(clip.x1());
	int clipY1 = iCeil(clip.y1());

	glScissor(clipX0, getHeight() - clipY1, clipX1 - clipX0, clipY1 - clipY0);

    if (! state.useClip2D) {
        glEnable(GL_SCISSOR_TEST);
        minStateChange();
        minGLStateChange();
    }
    state.useClip2D = true;
}


void RenderDevice::disableClip2D() {
    minStateChange();
    if (state.useClip2D) {
        minGLStateChange();
        glDisable(GL_SCISSOR_TEST);
    }
    state.useClip2D = false;
}


void RenderDevice::setProjectionAndCameraMatrix(const GCamera& camera) {
    double pixelAspect = state.viewport.width() / state.viewport.height();

    // Half extents of viewport
    double y = -camera.getNearPlaneZ() * tan(camera.getFieldOfView() / 2.0);
    double x = y * pixelAspect;

    double r, l, t, b, n, f;
    n = -camera.getNearPlaneZ();
    f = -camera.getFarPlaneZ();
    r = x;
    l = -x;
    t = y;
    b = -y;

    setProjectionMatrix(Matrix4::perspectiveProjection(l, r, b, t, n, f));
	setCameraToWorldMatrix(camera.getCoordinateFrame());
}


Rect2D RenderDevice::getViewport() const {
    return state.viewport;
}


void RenderDevice::setFramebuffer(const FramebufferRef &fbo) {
    // Check for extension
    majStateChange();
    if (fbo != state.framebuffer) {
        majGLStateChange();
        // Set Framebuffer
        if (fbo.isNull()) {
            state.drawBuffer = BUFFER_BACK;
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        } else {
            state.drawBuffer = BUFFER_COLOR0;
            debugAssertM(GLCaps::supports_GL_EXT_framebuffer_object(), 
                "Framebuffer Object not supported!");
            glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo->openGLID());
        }
        state.framebuffer = fbo;
    }
}


void RenderDevice::setDepthTest(DepthTest test) {
    debugAssert(! inPrimitive);

    minStateChange();

	if (test == DEPTH_CURRENT) {
		return;
	}

    if (state.depthTest != test) {
        minGLStateChange();
        if (test == DEPTH_ALWAYS_PASS) {
            glDisable(GL_DEPTH_TEST);
        } else {
            minStateChange();
            minGLStateChange();
            glEnable(GL_DEPTH_TEST);
            switch (test) {
            case DEPTH_LESS:
                glDepthFunc(GL_LESS);
                break;

            case DEPTH_LEQUAL:
                glDepthFunc(GL_LEQUAL);
                break;

            case DEPTH_GREATER:
                glDepthFunc(GL_GREATER);
                break;

            case DEPTH_GEQUAL:
                glDepthFunc(GL_GEQUAL);
                break;

            case DEPTH_EQUAL:
                glDepthFunc(GL_EQUAL);
                break;

            case DEPTH_NOTEQUAL:
                glDepthFunc(GL_NOTEQUAL);
                break;

            case DEPTH_NEVER_PASS:
                glDepthFunc(GL_NEVER);
                break;

            default:
                debugAssertM(false, "Fell through switch");
            }
        }

        state.depthTest = test;

    }
}

static GLenum toGLEnum(RenderDevice::StencilTest t) {

    switch (t) {
    case RenderDevice::STENCIL_CURRENT:
        return 0;

    case RenderDevice::STENCIL_ALWAYS_PASS:
        return GL_ALWAYS;

    case RenderDevice::STENCIL_LESS:
        return GL_LESS;

    case RenderDevice::STENCIL_LEQUAL:
        return GL_LEQUAL;

    case RenderDevice::STENCIL_GREATER:
        return GL_GREATER;

    case RenderDevice::STENCIL_GEQUAL:
        return GL_GEQUAL;

    case RenderDevice::STENCIL_EQUAL:
        return GL_EQUAL;

    case RenderDevice::STENCIL_NOTEQUAL:
        return GL_NOTEQUAL;

    case RenderDevice::STENCIL_NEVER_PASS:
        return GL_NEVER;

    default:
        debugAssertM(false, "Fell through switch");
        return GL_NONE;
    }
}


void RenderDevice::_setStencilTest(RenderDevice::StencilTest test, int reference) {

	if (test == RenderDevice::STENCIL_CURRENT) {
		return;
	}

    const GLenum t = toGLEnum(test);

    if (GLCaps::supports_GL_EXT_stencil_two_side()) {
        // NVIDIA/EXT
        glActiveStencilFaceEXT(GL_BACK);
        glStencilFunc(t, reference, 0xFFFFFFFF);
        glActiveStencilFaceEXT(GL_FRONT);
        glStencilFunc(t, reference, 0xFFFFFFFF);
        minGLStateChange(4);
    } else if (GLCaps::supports_GL_ATI_separate_stencil()) {
        // ATI
        glStencilFuncSeparateATI(t, t, reference, 0xFFFFFFFF);
        minGLStateChange(1);
    } else {
        // Default OpenGL
        glStencilFunc(t, reference, 0xFFFFFFFF);
        minGLStateChange(1);
    }
}


void RenderDevice::setStencilConstant(int reference) {
    minStateChange();

    debugAssert(! inPrimitive);
    if (state.stencil.stencilReference != reference) {

        state.stencil.stencilReference = reference;
        _setStencilTest(state.stencil.stencilTest, reference);
        minStateChange();

    }
}


void RenderDevice::setStencilTest(StencilTest test) {
    minStateChange();

	if (test == STENCIL_CURRENT) {
		return;
	}

    debugAssert(! inPrimitive);

    if (state.stencil.stencilTest != test) {
        glEnable(GL_STENCIL_TEST);

        if (test == STENCIL_ALWAYS_PASS) {

            // Can't actually disable if the stencil op is using the test as well
            // due to an OpenGL limitation.
            if ((state.stencil.frontStencilFail   == STENCIL_KEEP) &&
                (state.stencil.frontStencilZFail  == STENCIL_KEEP) &&
                (state.stencil.frontStencilZPass  == STENCIL_KEEP) &&
                (! GLCaps::supports_GL_EXT_stencil_two_side() ||
                 ((state.stencil.backStencilFail  == STENCIL_KEEP) &&
                  (state.stencil.backStencilZFail == STENCIL_KEEP) &&
                  (state.stencil.backStencilZPass == STENCIL_KEEP)))) {
                minGLStateChange();
                glDisable(GL_STENCIL_TEST);
            }

        } else {

            _setStencilTest(test, state.stencil.stencilReference);
        }

        state.stencil.stencilTest = test;

    }
}


RenderDevice::AlphaTest RenderDevice::alphaTest() const {
    return state.alphaTest;
}


double RenderDevice::alphaTestReference() const {
    return state.alphaReference;
}


void RenderDevice::setAlphaTest(AlphaTest test, double reference) {
    debugAssert(! inPrimitive);

    minStateChange();

	if (test == ALPHA_CURRENT) {
		return;
	}

    if ((state.alphaTest != test) || (state.alphaReference != reference)) {
        minGLStateChange();
        if (test == ALPHA_ALWAYS_PASS) {
            
            glDisable(GL_ALPHA_TEST);

        } else {

            glEnable(GL_ALPHA_TEST);
            switch (test) {
            case ALPHA_LESS:
                glAlphaFunc(GL_LESS, reference);
                break;

            case ALPHA_LEQUAL:
                glAlphaFunc(GL_LEQUAL, reference);
                break;

            case ALPHA_GREATER:
                glAlphaFunc(GL_GREATER, reference);
                break;

            case ALPHA_GEQUAL:
                glAlphaFunc(GL_GEQUAL, reference);
                break;

            case ALPHA_EQUAL:
                glAlphaFunc(GL_EQUAL, reference);
                break;

            case ALPHA_NOTEQUAL:
                glAlphaFunc(GL_NOTEQUAL, reference);
                break;

            case ALPHA_NEVER_PASS:
                glAlphaFunc(GL_NEVER, reference);
                break;

            default:
                debugAssertM(false, "Fell through switch");
            }
        }

        state.alphaTest = test;
        state.alphaReference = reference;
    }
}




GLint RenderDevice::toGLStencilOp(RenderDevice::StencilOp op) const {

    switch (op) {
    case RenderDevice::STENCIL_KEEP:
        return GL_KEEP;

    case RenderDevice::STENCIL_ZERO:
        return GL_ZERO;

    case RenderDevice::STENCIL_REPLACE:
        return GL_REPLACE;

    case RenderDevice::STENCIL_INVERT:
        return GL_INVERT;

    case RenderDevice::STENCIL_INCR_WRAP:
        if (GLCaps::supports_GL_EXT_stencil_wrap()) {
            return GL_INCR_WRAP_EXT;
        }
        // Intentionally fall through

    case RenderDevice::STENCIL_INCR:
        return GL_INCR;


    case RenderDevice::STENCIL_DECR_WRAP:
        if (GLCaps::supports_GL_EXT_stencil_wrap()) {
            return GL_DECR_WRAP_EXT;
        }
        // Intentionally fall through

    case RenderDevice::STENCIL_DECR:
        return GL_DECR;

    default:
        debugAssertM(false, "Fell through switch");
        return GL_KEEP;
    }
}


void RenderDevice::setShader(const ShaderRef& s) {
    majStateChange();

	if (s != state.shader) {
        debugAssertM(! inShader, "Cannot set the Shader from within a Shader!");
		state.shader = s;
	}
}


void RenderDevice::setObjectShader(const ObjectShaderRef& s) {
	if (s != state.objectShader) {
		state.objectShader = s;
	}
}


void RenderDevice::forceVertexAndPixelShaderBind() {
    // Only change the vertex shader if it does not match the one used last time.
    if (lastVertexAndPixelShader != state.vertexAndPixelShader) {

        majGLStateChange();
        if (state.vertexAndPixelShader.isNull()) {
            // Disables the programmable pipeline
            glUseProgramObjectARB(0);
        } else {
            glUseProgramObjectARB(state.vertexAndPixelShader->glProgramObject());
        }
        debugAssertGLOk();

        lastVertexAndPixelShader = state.vertexAndPixelShader;
    }
}


void RenderDevice::setVertexAndPixelShader(const VertexAndPixelShaderRef& s) {
    majStateChange();

    if (s != state.vertexAndPixelShader) {

        state.vertexAndPixelShader = s;

        if (s.notNull()) {
            alwaysAssertM(s->ok(), s->messages());
        }

        // The actual shader will change in beforePrimitive or when the arg list is bound.
    }
}


void RenderDevice::setVertexAndPixelShader(
    const VertexAndPixelShaderRef&          s,
    const VertexAndPixelShader::ArgList&    args) {

    setVertexAndPixelShader(s);

    if (s.notNull()) {
        s->bindArgList(this, args);
    }
}


void RenderDevice::setVertexProgram(const VertexProgramRef& vp) {
    majStateChange();
    if (vp != state.vertexProgram) {
        if (state.vertexProgram != (VertexProgramRef)NULL) {
            state.vertexProgram->disable();
        }

        majGLStateChange();
        if (vp != (VertexProgramRef)NULL) {
            debugAssert(supportsVertexProgram());
            vp->bind();
        }

        state.vertexProgram = vp;
    }
}


void RenderDevice::setVertexProgram(
    const VertexProgramRef& vp,
    const GPUProgram::ArgList& args) {

    setVertexProgram(vp);
    
    vp->setArgs(this, args);
}


void RenderDevice::setPixelProgram(const PixelProgramRef& pp) {
    majStateChange();
    if (pp != state.pixelProgram) {
        if (state.pixelProgram != (PixelProgramRef)NULL) {
            state.pixelProgram->disable();
        }
        if (pp != (PixelProgramRef)NULL) {
            debugAssert(supportsPixelProgram());
            pp->bind();
        }
        majGLStateChange();
        state.pixelProgram = pp;
    }
}


void RenderDevice::setPixelProgram(
    const PixelProgramRef& pp,
    const GPUProgram::ArgList& args) {

    setPixelProgram(pp);
    
    pp->setArgs(this, args);
}


void RenderDevice::setStencilOp(
    StencilOp                       frontStencilFail,
    StencilOp                       frontZFail,
    StencilOp                       frontZPass,
    StencilOp                       backStencilFail,
    StencilOp                       backZFail,
    StencilOp                       backZPass) {

    minStateChange();

	if (frontStencilFail == STENCILOP_CURRENT) {
		frontStencilFail = state.stencil.frontStencilFail;
	}
	
	if (frontZFail == STENCILOP_CURRENT) {
		frontZFail = state.stencil.frontStencilZFail;
	}
	
	if (frontZPass == STENCILOP_CURRENT) {
		frontZPass = state.stencil.frontStencilZPass;
	}

	if (backStencilFail == STENCILOP_CURRENT) {
		backStencilFail = state.stencil.backStencilFail;
	}
	
	if (backZFail == STENCILOP_CURRENT) {
		backZFail = state.stencil.backStencilZFail;
	}
	
	if (backZPass == STENCILOP_CURRENT) {
		backZPass = state.stencil.backStencilZPass;
	}
    
	if ((frontStencilFail  != state.stencil.frontStencilFail) ||
        (frontZFail        != state.stencil.frontStencilZFail) ||
        (frontZPass        != state.stencil.frontStencilZPass) || 
        (GLCaps::supports_two_sided_stencil() && 
        ((backStencilFail  != state.stencil.backStencilFail) ||
         (backZFail        != state.stencil.backStencilZFail) ||
         (backZPass        != state.stencil.backStencilZPass)))) { 

        if (GLCaps::supports_GL_EXT_stencil_two_side()) {
            // NVIDIA

            // Set back face operation
            glActiveStencilFaceEXT(GL_BACK);
            glStencilOp(
                toGLStencilOp(backStencilFail),
                toGLStencilOp(backZFail),
                toGLStencilOp(backZPass));
            
            // Set front face operation
            glActiveStencilFaceEXT(GL_FRONT);
            glStencilOp(
                toGLStencilOp(frontStencilFail),
                toGLStencilOp(frontZFail),
                toGLStencilOp(frontZPass));

            minGLStateChange(4);

        } else if (GLCaps::supports_GL_ATI_separate_stencil()) {
            // ATI
            minGLStateChange(2);
            glStencilOpSeparateATI(GL_FRONT, 
                toGLStencilOp(frontStencilFail),
                toGLStencilOp(frontZFail),
                toGLStencilOp(frontZPass));

            glStencilOpSeparateATI(GL_BACK, 
                toGLStencilOp(backStencilFail),
                toGLStencilOp(backZFail),
                toGLStencilOp(backZPass));

        } else {
            // Generic OpenGL

            // Set front face operation
            glStencilOp(
                toGLStencilOp(frontStencilFail),
                toGLStencilOp(frontZFail),
                toGLStencilOp(frontZPass));

            minGLStateChange(1);
        }


        // Need to manage the mask as well

        if ((frontStencilFail  == STENCIL_KEEP) &&
            (frontZPass        == STENCIL_KEEP) && 
            (frontZFail        == STENCIL_KEEP) &&
            (! GLCaps::supports_two_sided_stencil() ||
            ((backStencilFail  == STENCIL_KEEP) &&
             (backZPass        == STENCIL_KEEP) &&
             (backZFail        == STENCIL_KEEP)))) {

            // Turn off writing.  May need to turn off the stencil test.
            if (state.stencil.stencilTest == STENCIL_ALWAYS_PASS) {
                // Test doesn't need to be on
                glDisable(GL_STENCIL_TEST);
            }

        } else {

            debugAssertM(glGetInteger(GL_STENCIL_BITS) > 0,
                "Allocate stencil bits from RenderDevice::init before using the stencil buffer.");

            // Turn on writing.  We also need to turn on the
            // stencil test in this case.

            if (state.stencil.stencilTest == STENCIL_ALWAYS_PASS) {
                // Test is not already on
                glEnable(GL_STENCIL_TEST);
                _setStencilTest(state.stencil.stencilTest, state.stencil.stencilReference);
            }
        }

        state.stencil.frontStencilFail  = frontStencilFail;
        state.stencil.frontStencilZFail = frontZFail;
        state.stencil.frontStencilZPass = frontZPass;
        state.stencil.backStencilFail   = backStencilFail;
        state.stencil.backStencilZFail  = backZFail;
        state.stencil.backStencilZPass  = backZPass;
    }
}


void RenderDevice::setStencilOp(
    StencilOp           fail,
    StencilOp           zfail,
    StencilOp           zpass) {
    debugAssert(! inPrimitive);

    setStencilOp(fail, zfail, zpass, fail, zfail, zpass);
}


static GLenum toGLBlendEq(RenderDevice::BlendEq e) {
    switch (e) {
    case RenderDevice::BLENDEQ_MIN:
        debugAssert(GLCaps::supports("GL_EXT_blend_minmax"));
        return GL_MIN;

    case RenderDevice::BLENDEQ_MAX:
        debugAssert(GLCaps::supports("GL_EXT_blend_minmax"));
        return GL_MAX;

    case RenderDevice::BLENDEQ_ADD:
        return GL_FUNC_ADD;

    case RenderDevice::BLENDEQ_SUBTRACT:
        debugAssert(GLCaps::supports("GL_EXT_blend_subtract"));
        return GL_FUNC_SUBTRACT;

    case RenderDevice::BLENDEQ_REVERSE_SUBTRACT:
        debugAssert(GLCaps::supports("GL_EXT_blend_subtract"));
        return GL_FUNC_REVERSE_SUBTRACT;

    default:
        debugAssertM(false, "Fell through switch");
        return GL_ZERO;
    }
}


void RenderDevice::setBlendFunc(
    BlendFunc src,
    BlendFunc dst,
    BlendEq   eq) {
    debugAssert(! inPrimitive);

    minStateChange();
	if (src == BLEND_CURRENT) {
		src = state.srcBlendFunc;
	}

	if (dst == BLEND_CURRENT) {
		dst = state.dstBlendFunc;
	}

    if (eq == BLENDEQ_CURRENT) {
        eq = state.blendEq;
    }

    if ((state.dstBlendFunc != dst) ||
        (state.srcBlendFunc != src) ||
        (state.blendEq != eq)) {

        minGLStateChange();

        if ((dst == BLEND_ZERO) && (src == BLEND_ONE) && ((eq == BLENDEQ_ADD) || (eq == BLENDEQ_SUBTRACT))) {
            glDisable(GL_BLEND);
        } else {
            glEnable(GL_BLEND);
            glBlendFunc(toGLBlendFunc(src), toGLBlendFunc(dst));

            debugAssert(eq == BLENDEQ_ADD ||
                GLCaps::supports("GL_EXT_blend_minmax") ||
                GLCaps::supports("GL_EXT_blend_subtract"));

            static bool supportsBlendEq = GLCaps::supports("GL_EXT_blend_minmax");

            if (supportsBlendEq && (glBlendEquationEXT != 0)) {
                glBlendEquationEXT(toGLBlendEq(eq));
            }
        }
        state.dstBlendFunc = dst;
        state.srcBlendFunc = src;
        state.blendEq = eq;
    }
}


void RenderDevice::setLineWidth(
    double               width) {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.lineWidth != width) {
        glLineWidth(width);
        minGLStateChange();
        state.lineWidth = width;
    }
}


void RenderDevice::setPointSize(
    double               width) {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.pointSize != width) {
        glPointSize(width);
        minGLStateChange();
        state.pointSize = width;
    }
}


void RenderDevice::setAmbientLightColor(
    const Color4&        color) {
    debugAssert(! inPrimitive);

    minStateChange();
    if (color != state.lights.ambient) {
        float c[] =
            {color.r / lightSaturation,
             color.g / lightSaturation,
             color.b / lightSaturation,
             1.0f};
    
        state.lights.changed = true;
        minGLStateChange();
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, c);
        state.lights.ambient = color;
    }
}


void RenderDevice::setAmbientLightColor(
    const Color3&        color) {
    setAmbientLightColor(Color4(color, 1.0));
}


void RenderDevice::enableLighting() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (! state.lights.lighting) {
        glEnable(GL_LIGHTING);
        minGLStateChange();
        state.lights.lighting = true;
        state.lights.changed = true;
    }
}


void RenderDevice::disableLighting() {
    debugAssert(! inPrimitive);
    minStateChange();
    if (state.lights.lighting) {
        glDisable(GL_LIGHTING);
        minGLStateChange();
        state.lights.lighting = false;
        state.lights.changed = true;
    }
}


void RenderDevice::setObjectToWorldMatrix(
    const CoordinateFrame& cFrame) {
    
    minStateChange();
    debugAssert(! inPrimitive);

    // No test to see if it is already equal; this is called frequently and is
    // usually different.
    state.matrices.changed = true;
    state.matrices.objectToWorldMatrix = cFrame;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrix(state.matrices.cameraToWorldMatrixInverse * state.matrices.objectToWorldMatrix);
    minGLStateChange();
}


const CoordinateFrame& RenderDevice::getObjectToWorldMatrix() const {
    return state.matrices.objectToWorldMatrix;
}


void RenderDevice::setCameraToWorldMatrix(
    const CoordinateFrame& cFrame) {

    debugAssert(! inPrimitive);
    majStateChange();
    majGLStateChange();
    
    state.matrices.changed = true;
    state.matrices.cameraToWorldMatrix = cFrame;
    state.matrices.cameraToWorldMatrixInverse = cFrame.inverse();

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrix(state.matrices.cameraToWorldMatrixInverse * state.matrices.objectToWorldMatrix);

    // Reload lights since the camera matrix changed.  We must do this even for lights
    // that are not enabled since those lights will not be re-set at the GL level if they
    // are enabled without being otherwise changed.  Of course, we must follow up by disabling
    // those lights again.
    for (int i = 0; i < MAX_LIGHTS; ++i) {
        bool wasEnabled = state.lights.lightEnabled[i];
        setLight(i, &state.lights.light[i], true);
        if (! wasEnabled) {
            setLight(i, NULL);
        }
    }
}


const CoordinateFrame& RenderDevice::getCameraToWorldMatrix() const {
    return state.matrices.cameraToWorldMatrix;
}


Matrix4 RenderDevice::getProjectionMatrix() const {
    return state.matrices.projectionMatrix;
}


CoordinateFrame RenderDevice::getModelViewMatrix() const {
    return state.matrices.cameraToWorldMatrixInverse * getObjectToWorldMatrix();
}


Matrix4 RenderDevice::getModelViewProjectionMatrix() const {
    return getProjectionMatrix() * getModelViewMatrix();
}


void RenderDevice::setProjectionMatrix(const Matrix4& P) {
    minStateChange();
    if (state.matrices.projectionMatrix != P) {
        state.matrices.projectionMatrix = P;
        state.matrices.changed = true;
        glMatrixMode(GL_PROJECTION);
        glLoadMatrix(P);
        glMatrixMode(GL_MODELVIEW);
        minGLStateChange();
    }
}


void RenderDevice::forceSetTextureMatrix(int unit, const double* m) {
    float f[16];
    for (int i = 0; i < 16; ++i) {
        f[i] = m[i];
    }

    forceSetTextureMatrix(unit, f);
}


void RenderDevice::forceSetTextureMatrix(int unit, const float* m) {
    minStateChange();
    minGLStateChange();

    state.touchedTextureUnit(unit);
    memcpy(state.textureUnit[unit].textureMatrix, m, sizeof(float)*16);
    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB + unit);
    }

    // Transpose the texture matrix
    float tt[16];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tt[i + j * 4] = m[j + i * 4];
        }
    }
    glMatrixMode(GL_TEXTURE);
    glLoadMatrixf(tt);

    TextureRef texture = state.textureUnit[unit].texture;

    // invert y
    if ((texture != NULL) && texture->invertY) {

        float ymax = 1.0;
    
        if (texture->getDimension() == Texture::DIM_2D_RECT) {
            ymax = texture->getTexelHeight();
        }

        float m[16] = 
        { 1,  0,  0,  0,
          0, -1,  0,  0,
          0,  0,  1,  0,
          0,  ymax,  0,  1};

        glMultMatrixf(m);
    }

}


Matrix4 RenderDevice::getTextureMatrix(uint unit) {
    debugAssertM((int)unit < _numTextureUnits,
        format("Attempted to access texture unit %d on a device with %d units.",
        unit, _numTextureUnits));

    const float* M = state.textureUnit[unit].textureMatrix;

    return Matrix4(M[0], M[4], M[8],  M[12],
                   M[1], M[5], M[9],  M[13],
                   M[2], M[6], M[10], M[14],
                   M[3], M[7], M[11], M[15]);
}



void RenderDevice::setTextureMatrix(
    uint                 unit,
	const Matrix4&	     m) {

	float f[16];
	for (int r = 0; r < 4; ++r) {
		for (int c = 0; c < 4; ++c) {
			f[r * 4 + c] = m[r][c];
		}
	}

	setTextureMatrix(unit, f);
}


void RenderDevice::setTextureMatrix(
    uint                 unit,
    const double*        m) {

    debugAssert(! inPrimitive);
    debugAssertM((int)unit < _numTextureUnits,
        format("Attempted to access texture unit %d on a device with %d units.",
        unit, _numTextureUnits));

    forceSetTextureMatrix(unit, m);
}


void RenderDevice::setTextureMatrix(
    uint                 unit,
    const float*        m) {

    debugAssert(! inPrimitive);
    debugAssertM((int)unit < _numTextureUnits,
        format("Attempted to access texture unit %d on a device with %d units.",
        unit, _numTextureUnits));

    if (memcmp(m, state.textureUnit[unit].textureMatrix, sizeof(float)*16)) {
        forceSetTextureMatrix(unit, m);
    }
}


void RenderDevice::setTextureMatrix(
    uint                    unit,
    const CoordinateFrame&  c) {

    float m[16] = 
    {c.rotation[0][0], c.rotation[0][1], c.rotation[0][2], c.translation.x,
     c.rotation[1][0], c.rotation[1][1], c.rotation[1][2], c.translation.y,
     c.rotation[2][0], c.rotation[2][1], c.rotation[2][2], c.translation.z,
                    0,                0,                0,               1};

    setTextureMatrix(unit, m);
}


void RenderDevice::setTextureLODBias(
    uint                    unit,
    float                   bias) {

    minStateChange();
    if (state.textureUnit[unit].LODBias != bias) {
        state.touchedTextureUnit(unit);

        if (GLCaps::supports_GL_ARB_multitexture()) {
            glActiveTextureARB(GL_TEXTURE0_ARB + unit);
        }

        state.textureUnit[unit].LODBias = bias;

        minGLStateChange();
        glTexEnvf(GL_TEXTURE_FILTER_CONTROL_EXT, GL_TEXTURE_LOD_BIAS_EXT, bias);
    }
}


void RenderDevice::setTextureCombineMode(
    uint                    unit,
    const CombineMode       mode) {

    minStateChange();
	if (mode == TEX_CURRENT) {
		return;
	}

    debugAssertM((int)unit < _numTextureUnits,
        format("Attempted to access texture unit %d on a device with %d units.",
        unit, _numTextureUnits));

    if ((state.textureUnit[unit].combineMode != mode)) {
        minGLStateChange();
        state.touchedTextureUnit(unit);

        state.textureUnit[unit].combineMode = mode;

        if (GLCaps::supports_GL_ARB_multitexture()) {
            glActiveTextureARB(GL_TEXTURE0_ARB + unit);
        }

        static const bool hasAdd = GLCaps::supports("GL_EXT_texture_env_add");
        static const bool hasCombine = GLCaps::supports("GL_ARB_texture_env_combine");
        static const bool hasDot3 = GLCaps::supports("GL_ARB_texture_env_dot3");

        switch (mode) {
        case TEX_REPLACE:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
            break;

        case TEX_BLEND:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
            break;

        case TEX_MODULATE:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            break;

        case TEX_INTERPOLATE:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
            break;

        case TEX_ADD:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, hasCombine ? GL_ADD : GL_BLEND);
            break;

        case TEX_SUBTRACT:
            // (add and subtract are in the same extension)
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, hasAdd ? GL_SUBTRACT_ARB : GL_BLEND);
            break;

        case TEX_ADD_SIGNED:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, hasAdd ? GL_ADD_SIGNED_ARB : GL_BLEND);
            break;
            
        case TEX_DOT3_RGB:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, hasDot3 ? GL_DOT3_RGB_ARB : GL_BLEND);
            break;
             
        case TEX_DOT3_RGBA:
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, hasDot3 ? GL_DOT3_RGBA_ARB : GL_BLEND);
            break;

        default:
            debugAssertM(false, "Unrecognized texture combine mode");
        }
    }
}


void RenderDevice::resetTextureUnit(
    uint                    unit) {
    debugAssertM((int)unit < _numTextureUnits,
        format("Attempted to access texture unit %d on a device with %d units.",
        unit, _numTextureUnits));

    RenderState newState(state);
    state.textureUnit[unit] = RenderState::TextureUnit();
    state.touchedTextureUnit(unit);
    setState(newState);
}


void RenderDevice::setPolygonOffset(
    double              offset) {
    debugAssert(! inPrimitive);

    minStateChange();

    if (state.polygonOffset != offset) {
        minGLStateChange();
        if (offset != 0) {
            glEnable(GL_POLYGON_OFFSET_FILL);
            glEnable(GL_POLYGON_OFFSET_LINE);
            glEnable(GL_POLYGON_OFFSET_POINT);
            glPolygonOffset(offset, sign(offset));
        } else {
            glDisable(GL_POLYGON_OFFSET_POINT);
            glDisable(GL_POLYGON_OFFSET_FILL);
            glDisable(GL_POLYGON_OFFSET_LINE);
        }
        state.polygonOffset = offset;
    }
}


void RenderDevice::setNormal(const Vector3& normal) {
    state.normal = normal;
    glNormal3fv(normal);
    minStateChange();
    minGLStateChange();
}


void RenderDevice::setTexCoord(uint unit, const Vector4& texCoord) {
    debugAssertM((int)unit < _numTextureCoords,
        format("Attempted to access texture coordinate %d on a device with %d coordinates.",
        unit, _numTextureCoords));

    state.textureUnit[unit].texCoord = texCoord;
    if (GLCaps::supports_GL_ARB_multitexture()) {
        glMultiTexCoord(GL_TEXTURE0_ARB + unit, texCoord);
    } else {
        debugAssertM(unit == 0, "This machine has only one texture unit");
        glTexCoord(texCoord);
    }
    state.touchedTextureUnit(unit);
    minStateChange();
    minGLStateChange();
}


void RenderDevice::setTexCoord(uint unit, const Vector3& texCoord) {
    setTexCoord(unit, Vector4(texCoord, 1));
}


void RenderDevice::setTexCoord(uint unit, const Vector3int16& texCoord) {
    setTexCoord(unit, Vector4(texCoord.x, texCoord.y, texCoord.z, 1));
}


void RenderDevice::setTexCoord(uint unit, const Vector2& texCoord) {
    setTexCoord(unit, Vector4(texCoord, 0, 1));
}


void RenderDevice::setTexCoord(uint unit, const Vector2int16& texCoord) {
    setTexCoord(unit, Vector4(texCoord.x, texCoord.y, 0, 1));
}


void RenderDevice::setTexCoord(uint unit, double texCoord) {
    setTexCoord(unit, Vector4(texCoord, 0, 0, 1));
}


void RenderDevice::sendVertex(const Vector2& vertex) {
    debugAssertM(inPrimitive, "Can only be called inside beginPrimitive()...endPrimitive()");
    glVertex2fv(vertex);
    ++currentPrimitiveVertexCount;
}


void RenderDevice::sendVertex(const Vector3& vertex) {
    debugAssertM(inPrimitive, "Can only be called inside beginPrimitive()...endPrimitive()");
    glVertex3fv(vertex);
    ++currentPrimitiveVertexCount;
}


void RenderDevice::sendVertex(const Vector4& vertex) {
    debugAssertM(inPrimitive, "Can only be called inside beginPrimitive()...endPrimitive()");
    glVertex4fv(vertex);
    ++currentPrimitiveVertexCount;
}


void RenderDevice::beginPrimitive(Primitive p) {
    debugAssertM(! inPrimitive, "Already inside a primitive");
    debugAssertM( currentFramebufferComplete(), "Bound Framebuffer Incomplete!");

    beforePrimitive();
	runObjectShader();
    
    inPrimitive = true;
    currentPrimitiveVertexCount = 0;
    currentPrimitive = p;

    debugAssertGLOk();

    glBegin(primitiveToGLenum(p));
}


void RenderDevice::endPrimitive() {
    debugAssertM(inPrimitive, "Call to endPrimitive() without matching beginPrimitive()");

    mDebugNumMinorStateChanges += currentPrimitiveVertexCount;
    mDebugNumMinorOpenGLStateChanges += currentPrimitiveVertexCount;
	countTriangles(currentPrimitive, currentPrimitiveVertexCount);

    glEnd();
    inPrimitive = false;

    afterPrimitive();
}


void RenderDevice::countTriangles(RenderDevice::Primitive primitive, int numVertices) {
	switch (primitive) {
    case LINES:
        triangleCount += (numVertices / 2);
        break;

    case LINE_STRIP:
        triangleCount += (numVertices - 1);
        break;

    case TRIANGLES:
        triangleCount += (numVertices / 3);
        break;

    case TRIANGLE_STRIP:
    case TRIANGLE_FAN:
        triangleCount += (numVertices - 2);
        break;

    case QUADS:
        triangleCount += ((numVertices / 4) * 2);
        break;

    case QUAD_STRIP:
        triangleCount += (((numVertices / 2) - 1) * 2);
        break;

    case POINTS:
        triangleCount += numVertices;
        break;
    }
}


void RenderDevice::setTexture(
    uint                unit,
    TextureRef          texture) {

    // NVIDIA cards have more textures than texture units.
    // "fixedFunction" textures have an associated unit 
    // and must be glEnabled.  Programmable units *cannot*
    // be enabled.
    bool fixedFunction = ((int)unit < _numTextureUnits);

    debugAssertM(! inPrimitive, 
                 "Can't change textures while rendering a primitive.");

    debugAssertM((int)unit < _numTextures,
        format("Attempted to access texture %d"
               " on a device with %d textures.",
               unit, _numTextures));

    TextureRef oldTexture = state.textureUnit[unit].texture;
    majStateChange();

    if (oldTexture == texture) {
        return;
    }

    majGLStateChange();

    state.textureUnit[unit].texture = texture;
    state.touchedTextureUnit(unit);

    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB + unit);
    }

    // Turn off whatever was on previously if this is a fixed function unit
    if (fixedFunction) {
        glDisableAllTextures();
    }

    if (texture.notNull()) {
        GLint id = texture->getOpenGLID();
        GLint u = texture->getOpenGLTextureTarget();

        if ((GLint)currentlyBoundTexture[unit] != id) {
            glBindTexture(u, id);
            currentlyBoundTexture[unit] = id;
        }

        if (fixedFunction) {
            glEnable(u);
        }
    } else {
        // Disabled texture unit
        currentlyBoundTexture[unit] = 0;
    }

    // Force a reload of the texture matrix if invertY != old invertY.
    // This will take care of flipping the texture when necessary.
    if (oldTexture.isNull() ||
        texture.isNull() ||
        (oldTexture->invertY != texture->invertY)) {

        if (fixedFunction) {
            // We can only set the matrix for some units
            forceSetTextureMatrix(unit, state.textureUnit[unit].textureMatrix);
        }
    }

}


double RenderDevice::getDepthBufferValue(
    int                     x,
    int                     y) const {

    GLfloat depth;

    glReadPixels(x,
		         (getHeight() - 1) - y,
                 1, 1,
                 GL_DEPTH_COMPONENT,
		         GL_FLOAT,
		         &depth);

    return depth;
}


/**
 Returns the current date as a string in the form YYYY-MM-DD
 */
static std::string currentDateString() {
    time_t t1;
    time(&t1);
    tm* t = localtime(&t1);
    return format("%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday); 
}


void RenderDevice::screenshotPic(GImage& dest, bool useBackBuffer, bool getAlpha) const {
    if (useBackBuffer) {
        glReadBuffer(GL_BACK);
    } else {
        glReadBuffer(GL_FRONT);
    }
    
    int ch = getAlpha ? 4 : 3;

    if ((dest.channels != ch) ||
        (dest.width != getWidth()) ||
        (dest.height != getHeight())) {
        // Only resize if the current size is not correct
        dest.resize(getWidth(), getHeight(), ch);
    }

    glPushClientAttrib(GL_CLIENT_PIXEL_STORE_BIT);

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, getWidth(), getHeight(), 
        getAlpha ? GL_RGBA : GL_RGB,
        GL_UNSIGNED_BYTE, dest.byte());    

    glPopClientAttrib();

    // Flip right side up
    if (getAlpha) {
        flipRGBAVertical(dest.byte(), dest.byte(), getWidth(), getHeight());
    } else {
        flipRGBVertical(dest.byte(), dest.byte(), getWidth(), getHeight());
    }

    // Restore the read buffer to the back
    glReadBuffer(GL_BACK);

    int i;
    double s = getLightSaturation();

    if (s != 1.0) {
        // Adjust the coloring for gamma correction
        // Lookup table for mapping v -> v * lightSaturation;
        uint8 L[255];
        uint8 *data = dest.byte();
        
        for (i = 255; i >= 0; --i) {
            L[i] = iMin(255, iRound((double)i * s));
        }

        // skip the alpha channel if there is one
        int sz = dest.width * dest.height * dest.channels;
        for (i = 0; i < sz; i += ch) {
            for (int c = 0; c < 3; ++c) {
                data[i + c] = L[data[i + c]];
            }
        }
    }

}


std::string RenderDevice::screenshot(const std::string& filepath) const {
    GImage screen;
    int i;

    screenshotPic(screen);

    // Save the file
    std::string basename = currentDateString();
    std::string filename;
    i = 0;
    do {
        filename = filepath + basename + "_" + format("%03d", i) + ".jpg";
        ++i;
    } while (fileExists(filename));   

    screen.save(filename);

    return filename;
}


bool RenderDevice::supportsTextureFormat(const TextureFormat* fmt) {
    debugAssertM(! inPrimitive, 
        "Cannot call supportsTextureFormat between beginPrimitive and endPrimitive.");
    return GLCaps::supports(fmt);
}


double RenderDevice::getFrameRate() const {
    return emwaFrameRate;
}


double RenderDevice::getTriangleRate() const {
    return emwaTriangleRate;
}


double RenderDevice::getTrianglesPerFrame() const {
    return emwaTriangleCount;
}


void RenderDevice::beginIndexedPrimitives() {
	debugAssert(! inPrimitive);
	debugAssert(! inIndexedPrimitive);

    // TODO: can we avoid this push?
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT); 

	inIndexedPrimitive = true;
}


void RenderDevice::endIndexedPrimitives() {
	debugAssert(! inPrimitive);
	debugAssert(inIndexedPrimitive);


  if (GLCaps::supports_GL_ARB_vertex_buffer_object()) {
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
  }


	glPopClientAttrib();
	inIndexedPrimitive = false;
    currentVARArea = NULL;
}


void RenderDevice::setVARAreaFromVAR(const class VAR& v) {
	debugAssert(inIndexedPrimitive);
	debugAssert(! inPrimitive);
    alwaysAssertM(currentVARArea.isNull() || (v.area == currentVARArea), 
        "All vertex arrays used within a single begin/endIndexedPrimitive"
        " block must share the same VARArea.");

    majStateChange();

    if (v.area != currentVARArea) {
        currentVARArea = const_cast<VAR&>(v).area;

        if (VARArea::mode == VARArea::VBO_MEMORY) {
            // Bind the buffer (for MAIN_MEMORY, we need do nothing)
            glBindBufferARB(GL_ARRAY_BUFFER_ARB, currentVARArea->glbuffer);
            majGLStateChange();
        }
    }

}


void RenderDevice::setVertexArray(const class VAR& v) {
    setVARAreaFromVAR(v);
	v.vertexPointer();
}


void RenderDevice::setVertexAttribArray(unsigned int attribNum, const class VAR& v, bool normalize) {
    setVARAreaFromVAR(v);
	v.vertexAttribPointer(attribNum, normalize);
}


void RenderDevice::setNormalArray(const class VAR& v) {
    setVARAreaFromVAR(v);
	v.normalPointer();
}


void RenderDevice::setColorArray(const class VAR& v) {
    setVARAreaFromVAR(v);
	v.colorPointer();
}


void RenderDevice::setTexCoordArray(unsigned int unit, const class VAR& v) {
    setVARAreaFromVAR(v);
	v.texCoordPointer(unit);
}


MilestoneRef RenderDevice::createMilestone(const std::string& name) {
    return new Milestone(name);
}


void RenderDevice::setMilestone(const MilestoneRef& m) {
    minStateChange();
    minGLStateChange();
    m->set();
}


void RenderDevice::waitForMilestone(const MilestoneRef& m) {
    minStateChange();
    minGLStateChange();
    m->wait();
}


void RenderDevice::setLight(int i, const GLight& light) {
    
    setLight(i, &light, false);
}


void RenderDevice::setLight(int i, void* x) {
    debugAssert(x == NULL); (void)x;
    setLight(i, NULL, false);
}


void RenderDevice::setLight(int i, const GLight* _light, bool force) {
    debugAssert(i >= 0);
    debugAssert(i < MAX_LIGHTS);
    int gi = GL_LIGHT0 + i;

    const GLight& light = *_light;


    minStateChange();

    if (_light == NULL) {

        if (state.lights.lightEnabled[i] || force) {
            // Don't bother copying this light over
            state.lights.lightEnabled[i] = false;
            state.lights.changed = true;
            glDisable(gi);
        }

        minGLStateChange();
    
    } else {

        for (int j = 0; j < 3; ++j) {
            debugAssert(light.attenuation[j] >= 0);
        }

    
        if (! state.lights.lightEnabled[i] || force) {
            glEnable(gi);
            state.lights.lightEnabled[i] = true;
            state.lights.changed = true;
        }

    
        if ((state.lights.light[i] != light) || force) {
            state.lights.changed = true;
            state.lights.light[i] = light;

            minGLStateChange();

            Color4 zero(0, 0, 0, 1);
            Color4 brightness(light.color / lightSaturation, 1);

            int mm = glGetInteger(GL_MATRIX_MODE);
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();
                glLoadIdentity();
                glLoadMatrix(state.matrices.cameraToWorldMatrixInverse);
                glLightfv(gi, GL_POSITION,              light.position);
                glLightfv(gi, GL_SPOT_DIRECTION,        light.spotDirection);
                glLightf (gi, GL_SPOT_CUTOFF,           light.spotCutoff);
                glLightfv(gi, GL_AMBIENT,               zero);
                if (light.diffuse) {
                    glLightfv(gi, GL_DIFFUSE,               brightness);
                } else {
                    glLightfv(gi, GL_DIFFUSE,               zero);
                }
                if (light.specular) {
                    glLightfv(gi, GL_SPECULAR,              brightness);
                } else {
                    glLightfv(gi, GL_SPECULAR,              zero);
                }
                glLightf (gi, GL_CONSTANT_ATTENUATION,  light.attenuation[0]);
                glLightf (gi, GL_LINEAR_ATTENUATION,    light.attenuation[1]);
                glLightf (gi, GL_QUADRATIC_ATTENUATION, light.attenuation[2]);
            glPopMatrix();
            glMatrixMode(mm);
        }    
    }
    
}


void RenderDevice::configureShadowMap(
    uint                unit,
    const Matrix4&      lightMVP,
    const TextureRef&   shadowMap) {

    minStateChange();
    minGLStateChange();

    // http://www.nvidia.com/dev_content/nvopenglspecs/GL_ARB_shadow.txt

    debugAssertM(shadowMap->getFormat()->OpenGLBaseFormat == GL_DEPTH_COMPONENT,
        "Can only configure shadow maps from depth textures");

    debugAssertM(shadowMap->depthReadMode() != Texture::DEPTH_NORMAL,
        "Shadow maps must be configured for either Texture::DEPTH_LEQUAL"
        " or Texture::DEPTH_GEQUAL comparisions.");

    debugAssertM(GLCaps::supports_GL_ARB_shadow(),
        "The device does not support shadow maps");


    // Texture coordinate generation will use the current MV matrix
    // to determine OpenGL "eye" space.  We want OpenGL "eye" space to
    // be our world space, so set the object to world matrix to be the
    // identity.
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadMatrix(state.matrices.cameraToWorldMatrixInverse);

    setTexture(unit, shadowMap);
    
    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB + unit);
    }

    static const Matrix4 bias(
        0.5f, 0.0f, 0.0f, 0.5f,
        0.0f, 0.5f, 0.0f, 0.5f,
        0.0f, 0.0f, 0.5f, 0.5f - .000001f,
        0.0f, 0.0f, 0.0f, 1.0f);
    
    Matrix4 textureMatrix = glGetMatrix(GL_TEXTURE_MATRIX);

	Matrix4 textureProjectionMatrix2D =
        textureMatrix * bias * lightMVP;

	// Set up tex coord generation - all 4 coordinates required
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_S, GL_EYE_PLANE, textureProjectionMatrix2D[0]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, textureProjectionMatrix2D[1]);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE, textureProjectionMatrix2D[2]);
	glEnable(GL_TEXTURE_GEN_R);
	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_Q, GL_EYE_PLANE, textureProjectionMatrix2D[3]);
	glEnable(GL_TEXTURE_GEN_Q);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


void RenderDevice::configureReflectionMap(
    uint                textureUnit,
    TextureRef          reflectionTexture) {

    debugAssert(reflectionTexture->getDimension() == Texture::DIM_CUBE_MAP);

    // Texture coordinates will be generated in object space.
    // Set the texture matrix to transform them into camera space.
    CoordinateFrame cframe = getCameraToWorldMatrix();

    // The environment map assumes we are always in the center,
    // so zero the translation.
    cframe.translation = Vector3::zero();

    // The environment map is in world space.  The reflection vector
    // will automatically be multiplied by the object->camera space 
    // transformation by hardware (just like any other vector) so we 
    // take it back from camera space to world space for the correct
    // vector.
    setTexture(textureUnit, reflectionTexture);

    setTextureMatrix(textureUnit, cframe);

    minStateChange();
    minGLStateChange();
    glActiveTextureARB(GL_TEXTURE0_ARB + textureUnit);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP_ARB);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP_ARB);
    glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP_ARB);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_GEN_R);
}


void RenderDevice::sendSequentialIndices(RenderDevice::Primitive primitive, int numVertices) {

    beforePrimitive();
	runObjectShader();

    glDrawArrays(primitiveToGLenum(primitive), 0, numVertices);
    // Mark all active arrays as busy.
    setVARAreaMilestone();

	countTriangles(primitive, numVertices);
    afterPrimitive();

    minStateChange();
    minGLStateChange();
}


void RenderDevice::internalSendIndices(
    RenderDevice::Primitive primitive,
    size_t                  indexSize, 
    int                     numIndices, 
    const void*             index) {

    beforePrimitive();
	runObjectShader();

	GLenum i;

	switch (indexSize) {
	case sizeof(uint32):
		i = GL_UNSIGNED_INT;
		break;

	case sizeof(uint16):
		i = GL_UNSIGNED_SHORT;
		break;

	case sizeof(uint8):
		i = GL_UNSIGNED_BYTE;
		break;

	default:
		debugAssertM(false, "Indices must be either 8, 16, or 32-bytes each.");
        i = 0;
	}

    GLenum p = primitiveToGLenum(primitive);

	glDrawElements(p, numIndices, i, index);

    afterPrimitive();
}


bool RenderDevice::supportsTwoSidedStencil() const {
    return GLCaps::supports_GL_EXT_stencil_two_side();
}


bool RenderDevice::supportsTextureRectangle() const {
    return GLCaps::supports_GL_EXT_texture_rectangle();
}


bool RenderDevice::supportsVertexProgramNV2() const {
    return GLCaps::supports_GL_NV_vertex_program2();
}


bool RenderDevice::supportsVertexBufferObject() const { 
    return GLCaps::supports_GL_ARB_vertex_buffer_object();
}


uint32 RenderDevice::debugNumMajorOpenGLStateChanges() const {
    return mDebugNumMajorOpenGLStateChanges;
}


uint32 RenderDevice::debugNumPushStateCalls() const {
    return mDebugPushStateCalls;
}


uint32 RenderDevice::debugNumMinorOpenGLStateChanges() const {
    return mDebugNumMinorOpenGLStateChanges;
}


uint32 RenderDevice::debugNumMajorStateChanges() const {
    return mDebugNumMajorStateChanges;
}


uint32 RenderDevice::debugNumMinorStateChanges() const {
    return mDebugNumMinorStateChanges;
}

std::string RenderDevice::dummyString;
bool RenderDevice::checkFramebuffer(std::string& whyNot) const {
    GLenum status;
    status = (GLenum)glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT);

    switch(status) {
    case GL_FRAMEBUFFER_COMPLETE_EXT:
        return true;

    case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENTS_EXT:
        whyNot = "Framebuffer Incomplete: Incomplete Attachment.";
		break;

    case GL_FRAMEBUFFER_UNSUPPORTED_EXT:
        whyNot = "Unsupported framebuffer format.";
		break;

    case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT:
        whyNot = "Framebuffer Incomplete: Missing attachment.";
		break;

    case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT:
        whyNot = "Framebuffer Incomplete: Attached images must have same dimensions.";
		break;

    case GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT:
        whyNot = "Framebuffer Incomplete: Attached images must have same format.";
		break;

    case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT:
        whyNot = "Framebuffer Incomplete: Missing draw buffer.";
		break;

    case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT:
        whyNot = "Framebuffer Incomplete: Missing read buffer.";
		break;

    default:
        whyNot = "Framebuffer Incomplete: Unknown error.";
    }

    return false;    
}


/////////////////////////////////////////////////////////////////////////////////////


static void var(TextOutput& t, const std::string& name, const std::string& val) {
    t.writeSymbols(name,"=");
    t.writeString(val);
    t.writeNewline();
}


static void var(TextOutput& t, const std::string& name, const bool val) {
    t.writeSymbols(name, "=", val ? "Yes" : "No");
    t.writeNewline();
}


static void var(TextOutput& t, const std::string& name, const int val) {
    t.writeSymbols(name,"=");
    t.writeNumber(val);
    t.writeNewline();
}


void RenderDevice::describeSystem(
    TextOutput& t) {

    t.writeSymbols("GPU", "{");
    t.writeNewline();
    t.pushIndent();
        var(t, "Chipset", GLCaps::renderer());
        var(t, "Vendor", GLCaps::vendor());
        var(t, "Driver", GLCaps::driverVersion());
        var(t, "OpenGL version", GLCaps::glVersion());
        var(t, "Textures", GLCaps::numTextures());
        var(t, "Texture coordinates", GLCaps::numTextureCoords());
        var(t, "Texture units", GLCaps::numTextureUnits());
    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();

    GWindow* w = window();
    GWindowSettings settings;
    w->getSettings(settings);

    t.writeSymbols("Window", "{");
    t.writeNewline();
    t.pushIndent();
        var(t, "API", w->getAPIName());
        var(t, "Version", w->getAPIVersion());
        t.writeNewline();

        var(t, "In focus", w->hasFocus());
        var(t, "Centered", settings.center);
        var(t, "Framed", settings.framed);
        var(t, "Visible", settings.visible);
        var(t, "Resizable", settings.resizable);
        var(t, "Full screen", settings.fullScreen);
        var(t, "Top", settings.y);
        var(t, "Left", settings.x);
        var(t, "Width", settings.width);
        var(t, "Height", settings.height);
        var(t, "Refresh rate", settings.refreshRate);
        t.writeNewline();

        var(t, "Alpha bits", settings.alphaBits);
        var(t, "Red bits", settings.rgbBits);
        var(t, "Green bits", settings.rgbBits);
        var(t, "Blue bits", settings.rgbBits);
        var(t, "Depth bits", settings.depthBits);
        var(t, "Stencil bits", settings.stencilBits);
        var(t, "Asynchronous", settings.asychronous);
        var(t, "Stereo", settings.stereo);
        var(t, "FSAA samples", settings.fsaaSamples);

    t.popIndent();
    t.writeSymbols("}");
    t.writeNewline();
    t.writeNewline();
}

} // namespace

