#pragma once
// Ogre 1.4.5's default scene queries as the June 2008 client sees them (inactive native recovery; 2008-06).
//
// Non-colliding name: no donor or other native header has this path. Needs the Ogre 1.4.5 client headers on the include
// path (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include, OGRE_NONCLIENT_BUILD undefined).
//
// The five classes are the _OgreExport classes declared in OgreSceneManager.h; nothing is re-declared here. Their
// constructors, destructors and every inherited / overridden member are rgmain.dll imports. What the exe holds of them is
// only what MSVC generates locally for a __declspec(dllimport) polymorphic class that the exe constructs: the vtables
// (stamped over the imported constructor's vptrs right after the call), the scalar deleting destructors ??_G and the
// this-adjusting ??_E thunks of the secondary (listener) vtables at +0x34. They come from the create*Query bodies of
// Roblox's RbxSceneManager fork (native-classes/OgreRbxSceneManager.cpp, `new Default...SceneQuery(this)`), the only
// references to the vtables.
//
// Evidence (original Roblox.exe):
//   class                                   new   ctor call (import)  vtable    +0x34 vtable  ??_G      ??_E +0x34
//   DefaultAxisAlignedBoxSceneQuery         0x5c  0068cb09 (00804810) 0084eab8  0084eaa8      0068cb60  0068d630
//   DefaultSphereSceneQuery                 0x4c  0068cbb9 (00804850) 0084eafc  0084eaec      0068cc10  0068d640
//   DefaultPlaneBoundedVolumeListSceneQuery 0x54  0068cc69 (00804860) 0084eb40  0084eb30      0068ccc0  0068d620
//   DefaultRaySceneQuery                    0x6c  0068cd19 (0080486c) 0084eb84  0084eb74      0068cd70  0068d660
//   DefaultIntersectionSceneQuery           0x3c  0068cdc9 (008048a0) 0084ebdc  0084ebcc      0068ce10  0068d650
//   * new sizes: createAABBQuery 0068cad0, createSphereQuery 0068cb80, createPlaneBoundedVolumeQuery 0068cc30,
//     createRayQuery 0068cce0, createIntersectionQuery 0068cd90 (counted by record_native_ogre_scene_manager.py).
//   * RTTI: each vtable's COL names the class at offset 0; the hierarchy puts SceneQuery at 0 and the listener base
//     (SceneQueryListener, RaySceneQueryListener, IntersectionSceneQueryListener) at mdisp 0x34.
//   * vtables: 12 slots (Region queries, Intersection), 17 slots (Ray); 3 slots in each +0x34 vtable. Every slot except
//     slot 0 is an rgmain.dll import thunk.
//   * ??_G: call [__imp_??1Default...SceneQuery], operator delete 006a067a when (flags & 1).
#include <OgreSceneManager.h>
#include <OgreSceneQuery.h>
