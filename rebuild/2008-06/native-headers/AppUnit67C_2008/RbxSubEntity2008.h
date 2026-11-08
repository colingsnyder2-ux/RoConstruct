#pragma once
// Ogre::RbxSubEntity as compiled into the June 2008 client (inactive native recovery; Roblox's exe-local Ogre 1.4.5
// SubEntity subclass, the image block 00684fa0..00685a40 after the RbxFont unit). Non-colliding path: there is no donor
// or other native header of this name; other native headers only forward-declare Ogre::RbxSubEntity
// (RbxGraphics/AdornRbxGfx2008.h, RenderLib/AggregateChunk2008.h). Needs the Ogre 1.4.5 client headers on the include
// path (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include, OGRE_NONCLIENT_BUILD not defined: SubEntity, ShadowCaster and
// ShadowRenderable are rgmain.dll imports).
//
// Layout evidence (original Roblox.exe):
//   * size 0x15c: AdornRbxGfx 00671d60 pushes 0x15c to operator new before the constructor 00685660 (call 00671de9);
//   * RTTI: vtable 0084e90c .?AVRbxSubEntity@Ogre@@ -> SubEntity -> Renderable at offset 0, ShadowCaster at +0xec
//     (secondary vtable 0084e8d4); the imported SubEntity is 0xec bytes (mCachedCamera +0xe8 is its last member);
//   * constructors 00685660 (Entity*, ret 4) and 00685850 (Entity*, SubMesh*, int, ret 0xc): imported
//     SubEntity(parent, 0) (0x804750), both vptrs, +0x134 = lod (0 / third argument), +0x13c = true, std::vector
//     constructor at +0x144 (aux proxy new(4) at +0x144, first / last / end +0x150 / +0x154 / +0x158), +0x130 = 0,
//     +0x140 = 0; 00685850 also stores its SubMesh* through the lod index (+0x54 for lod 0, else +0x12c + 4 * lod);
//   * destructor 00685910: deletes every +0x144 element through its virtual destructor (operator[] index loop), clears
//     and destroys the vector, restores the imported ShadowCaster vtable at +0xec and calls the imported ~SubEntity;
//   * +0xf0 Matrix4 (0x40 bytes): getWorldTransforms 00685710 copies it, getWorldPosition 006857e0 / getSquaredViewDepth
//     00685010 / getPointExtrusionDistance 00685110 read its translation (+0xfc / +0x10c / +0x11c), getWorldOrientation
//     00685730 extracts its 3x3; RbxSceneManager::renderSingleObject 0069bc50 copies the same 0x40 bytes. Never
//     initialised by the constructors (Matrix4 has a trivial default constructor);
//   * +0x130 SubMesh* lod array (one element: 00685140 scans index 0 down to 0, getSubMesh 006850d0 reads
//     +0x12c + 4 * lod for lod != 0), +0x134 int current lod (setLod 006850f0, getRenderOperation 00684fd0);
//   * +0x138 float (slots 18 / 19 00685820 / 00685830; never initialised), +0x13c bool (getCastShadows 00685700, set
//     true by both constructors), +0x140 SubMesh* (0 in both constructors; getWorldBoundingBox 00685490 and
//     getShadowVolumeRenderableIterator 00685a40 prefer it to the lod scan);
//   * +0x144 ShadowCaster::ShadowRenderableList (std::vector<ShadowRenderable*>, 0x18 bytes; elements are new(0x70)
//     RbxSubEntityShadowRenderable in 00685bf9), ending at 0x15c.
// RbxSubEntityShadowRenderable (nested, RTTI 0084e88c .?AVRbxSubEntityShadowRenderable@RbxSubEntity@Ogre@@ ->
// ShadowRenderable -> Renderable, all at offset 0): size 0x70 (new(0x70) at 00685bf9 / 0068534c); constructor 006851d0
// (ret 0x18) after the imported ShadowRenderable() (0x804730, 0x4c bytes: mRenderOp +0x34, mLightCap +0x48):
// HardwareVertexBufferSharedPtr +0x4c / +0x58, +0x6c = fifth argument, +0x64 = third argument (VertexData*),
// +0x68 = ushort source binding (findElementBySemantic(...)->getSource()); its first argument is never stored (the
// iterator passes 0 at 00685c37, the light-cap recursion passes it on). Destructor 006853a0. Slots 4 / 5 / 6 / 16
// forward to the +0x6c sub-entity's slots 4 / 5 / 6 / 17.
//
// Overridden slots of 0084e90c: 0 ??_G 00685a20, 3 getRenderOperation 00684fd0, 4 getWorldTransforms 00685710,
// 5 getWorldOrientation 00685730, 6 getWorldPosition 006857e0, 8 getSquaredViewDepth 00685010; new slots 18 / 19
// 00685820 / 00685830. ShadowCaster slots of 0084e8d4: 0 adjustor thunk 00685840, 1 getCastShadows 00685700,
// 2 getEdgeList 00685170, 3 hasEdgeList 006851a0, 4 getWorldBoundingBox 00685490, 5 getLightCapBounds 00685100,
// 6 getDarkCapBounds 00685590, 7 getShadowVolumeRenderableIterator 00685a40, 8 getPointExtrusionDistance 00685110;
// 9..11 are the imported ShadowCaster protected virtuals.
// getWorldBoundingBox 00685490 and getShadowVolumeRenderableIterator 00685a40 are declared but not built: they read
// +0xc8 (EdgeData*) / +0xec (radius) of the selected sub-mesh, members of an exe-local SubMesh subclass (prepare
// 00682430, destructor 006824e0) whose size and constructor are not derived; the imported SubMesh is 0xc4 bytes.
// Member and method names are naming choices (no symbol evidence) except the overridden Ogre virtuals; types and
// offsets come from the evidence above.
#include <OgreSubEntity.h>
#include <OgreShadowCaster.h>
#include <OgreMatrix4.h>
#include <OgreHardwareVertexBuffer.h>

struct NativeAppUnit67CLayout;

namespace Ogre
{
	class RbxSubEntity : public SubEntity, public ShadowCaster
	{
		friend struct ::NativeAppUnit67CLayout;

	public:
		class RbxSubEntityShadowRenderable : public ShadowRenderable
		{
			friend struct ::NativeAppUnit67CLayout;

		protected:
			HardwareVertexBufferSharedPtr mPositionBuffer;                  // +0x4c
			HardwareVertexBufferSharedPtr mWBuffer;                         // +0x58
			const VertexData* mCurrentVertexData;                           // +0x64
			unsigned short mOriginalPosBufferBinding;                       // +0x68
			RbxSubEntity* mSubEntity;                                       // +0x6c (size 0x70)

		public:
			RbxSubEntityShadowRenderable(Entity* parent, HardwareIndexBufferSharedPtr* indexBuffer,
			                             const VertexData* vertexData, bool createSeparateLightCap,
			                             RbxSubEntity* subEntity, bool isLightCap = false);   // 006851d0
			~RbxSubEntityShadowRenderable();                                 // 006853a0 (??_G 00685640)
			void getWorldTransforms(Matrix4* xform) const;                   // slot 4  00685450
			const Quaternion& getWorldOrientation(void) const;               // slot 5  00685460
			const Vector3& getWorldPosition(void) const;                     // slot 6  00685470
			HardwareVertexBufferSharedPtr getPositionBuffer(void);           // 00684fa0
			bool isVisible(void) const;                                      // slot 16 00685480
		};

		RbxSubEntity(Entity* parent);                                        // 00685660
		RbxSubEntity(Entity* parent, SubMesh* subMesh, int lod);             // 00685850
		virtual ~RbxSubEntity();                                             // 00685910 (??_G 00685a20)

		// Renderable / SubEntity overrides
		void getRenderOperation(RenderOperation& op);                        // slot 3  00684fd0
		void getWorldTransforms(Matrix4* xform) const;                       // slot 4  00685710
		const Quaternion& getWorldOrientation(void) const;                   // slot 5  00685730
		const Vector3& getWorldPosition(void) const;                         // slot 6  006857e0
		Real getSquaredViewDepth(const Camera* cam) const;                   // slot 8  00685010
		virtual void setCustomValue(Real value);                             // slot 18 00685820
		virtual Real getCustomValue(void) const;                             // slot 19 00685830

		// ShadowCaster overrides
		bool getCastShadows(void) const;                                     // 00685700
		EdgeData* getEdgeList(void);                                         // 00685170
		bool hasEdgeList(void);                                              // 006851a0
		const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const;   // 00685490 (not built)
		const AxisAlignedBox& getLightCapBounds(void) const;                 // 00685100
		const AxisAlignedBox& getDarkCapBounds(const Light& light, Real dirLightExtrusionDist) const;   // 00685590
		ShadowRenderableListIterator getShadowVolumeRenderableIterator(
			ShadowTechnique shadowTechnique, const Light* light, HardwareIndexBufferSharedPtr* indexBuffer,
			bool extrudeVertices, Real extrusionDistance, unsigned long flags = 0);   // 00685a40 (not built)
		Real getPointExtrusionDistance(const Light* l) const;                // 00685110

		void setMaterial(const MaterialPtr& material);                       // 006850a0
		void setSubMesh(int lod, SubMesh* subMesh);                          // 006850b0
		SubMesh* getSubMesh(int lod);                                        // 006850d0
		void setLod(int lod);                                                // 006850f0
		SubMesh* getCoarsestSubMesh(void);                                   // 00685140

	protected:
		Matrix4 mTransform;                                                  // +0xf0
		SubMesh* mLodSubMeshes[1];                                           // +0x130 (lod 1)
		int mLod;                                                            // +0x134
		Real mCustomValue;                                                   // +0x138
		bool mCastShadows;                                                   // +0x13c
		SubMesh* mShadowSubMesh;                                             // +0x140
		ShadowRenderableList mShadowRenderables;                             // +0x144 (size 0x15c)
	};
}
