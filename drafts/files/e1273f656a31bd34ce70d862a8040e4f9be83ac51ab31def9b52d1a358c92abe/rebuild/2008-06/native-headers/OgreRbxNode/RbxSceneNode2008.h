#pragma once
// >>> native-status (generated) -- do not edit >>>
// RbxSceneNode2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d05aafae | roc native-status --write
// Ogre::RbxSceneNode as compiled into the June 2008 client (inactive native recovery; an exe-local Ogre::SceneNode
// subclass). Non-colliding name: there is no donor header for it. Needs the Ogre 1.4.5 client headers on the include
// path (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include, OGRE_NONCLIENT_BUILD not defined: SceneNode is an rgmain.dll
// import).
//
// Layout evidence (original Roblox.exe):
//   * size 0x248: 00674474 (AdornRbxGfx constructor) and 007ab230 push 0x248 to operator new before calling the
//     constructor 00674160 (call sites 006744d1 / 007ab280)
//     with (SceneManager*, const String&);
//   * RTTI: vtable 0084d30c .?AVRbxSceneNode@Ogre@@ -> SceneNode -> Node -> Renderable, all at offset 0; 116 slots (the
//     110 SceneNode slots plus 6 new ones);
//   * constructor 00674160 (header-inline, emitted with AdornRbxGfx): imported SceneNode(SceneManager*, const String&)
//     then std::map constructor (00446110, folded) at +0x228 and the vptr 0084d30c; SceneNode is 0x228 bytes;
//   * destructor 006821c0: deletes the mapped value (node +0x10) of every +0x228 entry, clears the map, destroys it
//     (00553d80, folded) and calls the imported ~SceneNode; ??_G 006741d0;
//   * +0x228 is std::map<unsigned long, Matrix4*>: setTransform 00681f90 inserts new(0x40) Matrix4 values; the key is
//     the 4-byte node +0xc;
//   * static map<const void*, Sphere>* at 0097dbc4: initializeSpheres 006822e0 allocates it (new(0x20), map ctor
//     004f0fc0); setSphere 00682350 stores the 16-byte Sphere at node +0x10 (_Buynode 00681300 copies key +0xc and four
//     floats +0x10..+0x1c, color +0x20, isnil +0x21).
// Overridden SceneNode slots: 64 _update 00681190, 86 _updateBounds 006817e0, 87 _findVisibleObjects 00681560.
// New slots 110..115 in this order: setTransform 00681f90, getTransform 006818e0, hasTransform 00681a00, setSphere
// 00682350, getSphere 00682040, hasSphere 00682100. Their names are naming choices (no symbol evidence); the
// signatures come from ret n, the key / value uses and the "Transform map error" / "bsphere map error" strings
// (getTransform / getSphere throw std::runtime_error, throw info 008d1bc8). The two setters copy their key into the
// argument slot before passing its address to find (a converted temporary), while the getters and hasX pass the
// argument slot directly, so the setters take a key type that converts to the map key. The sphere callers pass
// Ogre::SubMesh pointers (AdornRbxGfx 00673496 setSphere(getSubMesh(0), ...); RbxEntity 0067dcd9 getSphere(result of
// 006850d0)), so setSphere takes SubMesh* and the sphere map is keyed by const void* (the SubMesh* -> const void*
// conversion gives the temporary; with a const SubMesh* key the setter passes the argument directly, and with a 4-byte
// unsigned key _Buynode 00681300 copies the pair in a different order). The transform keys are typed unsigned int /
// unsigned long (setter / map); their callers are outside this block, and that pair is a codegen choice, not the
// original declaration. Bodies need /fp:fast (merge 00681250 and setSphere x87 order).
// VisibleObjectsBoundsInfo::merge 00681250 is the header-inline Ogre 1.4.5 body emitted by _findVisibleObjects.
#include <map>
#include <OgreSceneNode.h>
#include <OgreMatrix4.h>
#include <OgreSphere.h>
#include <OgreSubMesh.h>

struct NativeOgreRbxNodeLayout;

namespace Ogre
{
	class RbxSceneNode : public SceneNode
	{
		friend struct ::NativeOgreRbxNodeLayout;
		friend bool eraseSphere(const void* key); // INFERRED: original 00682150 accesses spheres.
		friend class VisualEngine;   // its destructor 0067a130 reads the node's spheres

	public:
		typedef std::map<unsigned long, Matrix4*> TransformMap;
		typedef std::map<const void*, Sphere> SphereMap;

	protected:
		TransformMap transforms;                                            // +0x228 (size 0x248)

		static SphereMap* spheres;                                          // 0097dbc4
		static void initializeSpheres();                                    // 006822e0

	public:
		RbxSceneNode(SceneManager* creator, const String& name)
			: SceneNode(creator, name)
		{
		}                                                                   // 00674160
		virtual ~RbxSceneNode();                                            // slot 0  006821c0 / ??_G 006741d0

		virtual void _update(bool updateChildren, bool parentHasChanged);  // slot 64 00681190
		virtual void _updateBounds(void);                                   // slot 86 006817e0
		virtual void _findVisibleObjects(Camera* cam, RenderQueue* queue, VisibleObjectsBoundsInfo* visibleBounds,
		                                 bool includeChildren = true, bool displayNodes = false,
		                                 bool onlyShadowCasters = false);  // slot 87 00681560

		virtual void setTransform(unsigned int key, const Matrix4& transform);    // slot 110 00681f90
		virtual const Matrix4& getTransform(unsigned long key) const;             // slot 111 006818e0
		virtual bool hasTransform(unsigned long key) const;                       // slot 112 00681a00
		virtual void setSphere(SubMesh* key, const Sphere& sphere);               // slot 113 00682350
		virtual const Sphere& getSphere(const void* key) const;                   // slot 114 00682040
		virtual bool hasSphere(const void* key) const;                            // slot 115 00682100
	};
}
