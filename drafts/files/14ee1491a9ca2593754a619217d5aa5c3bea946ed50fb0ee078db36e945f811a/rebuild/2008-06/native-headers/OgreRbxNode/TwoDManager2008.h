#pragma once
// Ogre::TwoDManager as compiled into the June 2008 client (inactive native recovery; an exe-local
// Ogre::RenderQueueListener that collects 2D quads and draws them from a render queue callback). Non-colliding name:
// there is no donor header for it. Needs the Ogre 1.4.5 client headers on the include path and the G3D headers.
//
// Layout evidence (original Roblox.exe):
//   * size 0x58: VisualEngine 0067bb22 pushes 0x58 to operator new, calls the constructor 006831d0 and stores the
//     object at VisualEngine +0x14, then calls setup 00682560 with (VisualEngine +0x4 scene manager, +0xc, 100, true,
//     false);
//   * RTTI: vtable 0084e7b4 .?AVTwoDManager@Ogre@@ -> RenderQueueListener at offset 0; 3 slots: ??_G 00684390,
//     renderQueueStarted 006843b0, renderQueueEnded 006843d0 (both ret 0xc);
//   * constructor 006831d0: vptr; RenderOperation() at +0x10 (vertexData +0x10 = 0, operationType +0x14 = 4,
//     useIndexes +0x18 = true, indexData +0x1c = 0; srcRenderable +0x20 left alone); HardwareVertexBufferSharedPtr()
//     at +0x24 and HardwareIndexBufferSharedPtr() at +0x30 (rgmain imports); std::list constructor 00683170 at +0x3c
//     (aux proxy +0x3c, head +0x50, size +0x54: 0x1c bytes, so the object ends at +0x58);
//   * destructor 00683240: list _Tidy 00682b40 and its aux proxy, ~HardwareIndexBufferSharedPtr, ~Hardware-
//     VertexBufferSharedPtr, then the imported RenderQueueListener vtable;
//   * setup 00682560 (ret 0x14): +0x4 = SceneManager* (addRenderQueueListener, slot +0x21c), +0xc = second argument,
//     +0x8 = uint8 queue id (compared with queueGroupId in slots 1 / 2), +0x9 = bool (slot 1 draws when false, slot 2
//     when true), +0xa = bool; then vertices.setNull(). The second argument is VisualEngine +0xc, the render target
//     that VisualEngine's destructor 0067a176 passes to Root::detachRenderTarget;
//   * list element 0x30 bytes (_Buynode 00682b20 allocates 0x38 = two links + element): rectangle 00683000 / 006830b0
//     and addQuad 00682d60 write left/top/right/bottom +0x0..+0xc, texture coordinates +0x10..+0x1c (addQuad), the
//     converted colour (RenderSystem::convertColourValue, slot +0x108) +0x20, the texture handle +0x24 (0 without a
//     texture), the operation type +0x28 (addQuad 4 = OT_TRIANGLE_LIST, 006830b0 2 = OT_LINE_LIST, 00683000 its first
//     argument) and an int +0x2c (006830b0 1, the others 0).
// The render body 006832b0 (called by slots 1 / 2) is declared but not built. Member and method names are naming
// choices (no symbol evidence); types and offsets come from the evidence above.
#include <list>
#include <OgreRenderQueueListener.h>
#include <OgreRenderOperation.h>
#include <OgreHardwareVertexBuffer.h>
#include <OgreHardwareIndexBuffer.h>
#include <OgreColourValue.h>
#include <OgreResource.h>
#include <G3D/Color4.h>

struct NativeOgreRbxNodeLayout;

namespace Ogre
{
	class SceneManager;
	class RenderTarget;

	class TwoDManager : public RenderQueueListener
	{
		friend struct ::NativeOgreRbxNodeLayout;

	public:
		struct Quad                                                         // 0x30 bytes (list node 0x38)
		{
			Real left;                                                      // +0x00
			Real top;                                                       // +0x04
			Real right;                                                     // +0x08
			Real bottom;                                                    // +0x0c
			Real u0;                                                        // +0x10
			Real v0;                                                        // +0x14
			Real u1;                                                        // +0x18
			Real v1;                                                        // +0x1c
			RGBA colour;                                                    // +0x20
			ResourceHandle texture;                                         // +0x24
			RenderOperation::OperationType operationType;                   // +0x28
			int mode;                                                       // +0x2c
		};

	private:
		SceneManager* sceneManager;                                         // +0x04
		uint8 queueId;                                                      // +0x08
		bool afterQueue;                                                    // +0x09
		bool flag;                                                          // +0x0a
		RenderTarget* target;                                               // +0x0c
		RenderOperation renderOp;                                           // +0x10
		HardwareVertexBufferSharedPtr vertexBuffer;                         // +0x24
		HardwareIndexBufferSharedPtr indexBuffer;                           // +0x30
		std::list<Quad> quads;                                              // +0x3c (size 0x58)

		void render();                                                      // 006832b0 (not built)

	public:
		TwoDManager();                                                      // 006831d0
		virtual ~TwoDManager();                                             // slot 0 00683240 / ??_G 00684390

		void setup(SceneManager* sceneManager, RenderTarget* target, uint8 queueId, bool afterQueue, bool flag);   // 00682560
		void addQuad(String textureName, const G3D::Color4& color, Real left, Real top, Real right, Real bottom,
		             Real u0, Real v0, Real u1, Real v1);                   // 00682d60
		void primitive(RenderOperation::OperationType operationType, Real left, Real top, Real right, Real bottom,
		               const G3D::Color4& color);                           // 00683000
		void outlineRectangle(Real left, Real top, Real right, Real bottom, const G3D::Color4& color);   // 006830b0

		virtual void renderQueueStarted(uint8 queueGroupId, const String& invocation,
		                                bool& skipThisInvocation);          // slot 1 006843b0
		virtual void renderQueueEnded(uint8 queueGroupId, const String& invocation,
		                              bool& repeatThisInvocation);          // slot 2 006843d0
	};
}
