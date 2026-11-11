#pragma once
// >>> native-status (generated) -- do not edit >>>
// AdornRbxGfx2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 68b7739c | roc native-status --write
// RBX::AdornRbxGfx as compiled into the June 2008 client (inactive native recovery; the Ogre-backed Adorn).
//
// Non-colliding name (see RbxGraphics/Adorn2008.h); there is no donor AdornRbxGfx header. Needs the Ogre 1.4.5 client
// headers on the include path (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include; MaterialPtr / MeshPtr constructors and
// destructors are rgmain.dll imports).
//
// Layout evidence (original Roblox.exe):
//   * size 0x144: the only construction site 0045b425 (CRobloxWnd) pushes 0x144 to operator new and calls the
//     constructor 00674210 with the window's Ogre::VisualEngine* (+0xb8 there, allocated new(0x808) in 0045cc9c,
//     constructor 006786c0 stores the VisualEngine vtable 0084df2c, RTTI .?AVVisualEngine@Ogre@@);
//   * RTTI: vtable 0084d2a4 .?AVAdornRbxGfx@RBX@@ -> .?AVAdorn@RBX@@ at offset 0; 25 slots, ??_G 006741f0 calls the
//     out-of-line destructor 00673a90;
//   * constructor 00674210 / continuation 006743eb: vptr; +0x4 = argument; std::string(const char*) at +0x8;
//     Ogre::MaterialPtr() at +0x24 and +0x38 (rgmain import 00804300); std::vector (_Aux_cont new(4) proxy, three null
//     pointers) at +0x48, +0x60, +0xa0, +0xdc; std::map constructors at +0x78 (00671ae0) and +0xb8 / +0xf4 (00699b30,
//     folded); +0x9c = +0xd8 = 0; G3D::CoordinateFrame() 004782d0 at +0x114. Then +0x30 = sceneManager->
//     createSceneNode("a3dr%d") (attached to the root node), +0x34 = new(0x248) RbxSceneNode (ctor 00674160 stores
//     0084d30c, .?AVRbxSceneNode@Ogre@@), +0x98 = new(0x2bc) RbxEntity (ctor 0067d1f0 stores 0084e45c,
//     .?AVRbxEntity@Ogre@@), +0x38 = MaterialManager::create("loff%d");
//   * +0x44 is a signed int: prepareRenderPass 00670d50 zeroes it, adds the particle quotas of every explosion and
//     sparkle system (getParticleQuota) and compares it with `jle` / converts it with `fild`;
//   * +0x48 / +0x60 hold RbxSubEntity* (00671d60 pops +0x48 or allocates new(0x15c) RbxSubEntity, ctor 00685660 stores
//     0084e90c .?AVRbxSubEntity@Ogre@@, and pushes it on +0x60; the destructor deletes both through slot 0);
//   * +0x78 is std::map<std::string, Ogre::MeshPtr>: its _Erase 00671160 destroys MeshPtr at node +0x28 (value +0x1c)
//     and the string at node +0xc, _Isnil at node +0x35;
//   * +0xb8 / +0xf4 are std::map<std::string, Ogre::SceneNode*> (_Isnil at node +0x2d; sparkle 00674790 calls
//     getAttachedObject(0), SceneNode vtable +0x13c, on the mapped value of +0xf4) and +0xa0 / +0xdc the matching
//     std::vector<Ogre::SceneNode*> (the destructor calls getAttachedObject / getName on each element); +0x9c / +0xd8
//     are their parent nodes (getName, destroySceneNode in the destructor);
//   * +0x8 is the 2D texture name: setTexture 006700e0 assigns "" or the proxy filename (+0xc), rect2d 0066f920 passes
//     a copy of it to the 2D draw call;
//   * +0x114: setObjectToWorldMatrix 0066fac0 copies the 0x30-byte CoordinateFrame (rotation +0x114, translation
//     +0x138, read back by the transform helpers 0066faf0 / 0066fba0).
// Member names are naming choices (no symbol evidence), types and offsets are from the evidence above.
#include <string>
#include <vector>
#include <map>
#include "RbxGraphics/Adorn2008.h"
#include <OgreMaterial.h>
#include <OgreMesh.h>

struct NativeAdornRbxGfxLayout;

namespace Ogre
{
	class SceneNode;
	class VisualEngine;     // exe-local (RTTI .?AVVisualEngine@Ogre@@, size 0x808); not declared natively yet
	class RbxSceneNode;     // exe-local SceneNode subclass (0x248)
	class RbxEntity;        // exe-local Entity subclass (0x2bc)
	class RbxSubEntity;     // exe-local SubEntity subclass (0x15c)
}

namespace RBX
{
	class AdornRbxGfx : public Adorn
	{
		friend struct ::NativeAdornRbxGfxLayout;

	private:
		Ogre::VisualEngine* visualEngine;                                   // +0x04
		std::string texture2d;                                              // +0x08
		Ogre::MaterialPtr textureMaterial;                                  // +0x24
		Ogre::SceneNode* rootNode;                                          // +0x30
		Ogre::RbxSceneNode* renderNode;                                     // +0x34
		Ogre::MaterialPtr solidMaterial;                                    // +0x38
		int particleCount;                                                  // +0x44
		std::vector<Ogre::RbxSubEntity*> freeSubEntities;                   // +0x48
		std::vector<Ogre::RbxSubEntity*> usedSubEntities;                   // +0x60
		std::map<std::string, Ogre::MeshPtr> meshes;                        // +0x78
		Ogre::RbxEntity* entity;                                            // +0x98
		Ogre::SceneNode* explosionRoot;                                     // +0x9c
		std::vector<Ogre::SceneNode*> explosionNodes;                       // +0xa0
		std::map<std::string, Ogre::SceneNode*> explosions;                 // +0xb8
		Ogre::SceneNode* sparkleRoot;                                       // +0xd8
		std::vector<Ogre::SceneNode*> sparkleNodes;                         // +0xdc
		std::map<std::string, Ogre::SceneNode*> sparkles;                   // +0xf4
		G3D::CoordinateFrame objectToWorld;                                 // +0x114 (size 0x144)

		void getObjectToWorld(Ogre::Matrix4& transform, const Ogre::Vector3& offset, const Ogre::Vector3& scale,
		                      const Ogre::Quaternion& rotation);                                  // 0066faf0
		void getObjectToWorld(Ogre::Matrix4& transform);                                          // 0066fba0
		std::string uniqueName();                                                                 // 0066fc00
		void releaseSubEntities();                                                                // 00671e20

	public:
		AdornRbxGfx(Ogre::VisualEngine* visualEngine);                      // 00674210
		virtual ~AdornRbxGfx();                                             // slot 0  00673a90 / ??_G 006741f0

		virtual TextureProxyBaseRef createTextureProxy(const std::string& filename);          // slot 1  00670380
		virtual void prepareRenderPass();                                                     // slot 2  00670d50
		virtual void finishRenderPass();                                                      // slot 3  00671f90
		virtual G3D::Rect2D getViewport() const;                                              // slot 4  00670020
		virtual int getWidth() const;                                                         // slot 5  0066f900
		virtual int getHeight() const;                                                        // slot 6  0066f910
		virtual void setTexture(int id, TextureProxyBaseRef _texture);                        // slot 7  006700e0
		virtual G3D::Rect2D getTextureSize(TextureProxyBaseRef _texture) const;               // slot 8  00670210
		virtual void line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const;   // 9
		virtual void outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const;      // 10
		virtual void rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const;                          // 11
		virtual G3D::Vector2 get2DStringBounds(const std::string& s, double size, Spacing spacing) const;      // 12
		virtual G3D::Vector2 drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size,
		                                const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign,
		                                YAlign yalign, Spacing spacing) const;                                 // 13
		virtual void setObjectToWorldMatrix(const G3D::CoordinateFrame& c);                   // slot 14 0066fac0
		virtual void setColor(const G3D::Color4& color);                                      // slot 15 (empty)
		virtual void box(const G3D::AABox& box, const G3D::Color4& solidColor, const G3D::Color4& wireColor);  // 16
		virtual void sphere(const G3D::Sphere& sphere, const G3D::Color4& solidColor,
		                    const G3D::Color4& wireColor);                                    // slot 17 00672ba0
		virtual void explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor,
		                       const G3D::Color4& wireColor);                                 // slot 18 00675360
		virtual void sparkle();                                                               // slot 19 00674790
		virtual void cylinderAlongX(float radius, float length, const G3D::Color4& solidColor,
		                            const G3D::Color4& wireColor);                            // slot 20 006726a0
		virtual void ray(const G3D::Ray& ray, const G3D::Color4& color, float scale);         // slot 21 006735a0
		virtual void lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color,
		                         float scale);                                                // slot 22 (empty)
		virtual void axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor,
		                  float scale);                                                       // slot 23 (empty)
		virtual void quad(const G3D::Vector3& v0, const G3D::Vector3& v1, const G3D::Vector3& v2,
		                  const G3D::Vector3& v3, const G3D::Color4& color);                  // slot 24 00672f50
	};
}
