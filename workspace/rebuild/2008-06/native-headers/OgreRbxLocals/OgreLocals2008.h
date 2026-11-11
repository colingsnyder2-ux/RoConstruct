#pragma once
// >>> native-status (generated) -- do not edit >>>
// OgreLocals2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f57b2e90 | roc native-status --write
// Ogre 1.4.5 classes the June 2008 client constructs from rgmain.dll (inactive native recovery; 2008-06).
//
// Non-colliding name: no donor or other native header has this path. Needs the Ogre 1.4.5 client headers on the include
// path (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include, OGRE_NONCLIENT_BUILD undefined).
//
// The nine classes are _OgreExport classes of the Ogre 1.4.5 headers included below; nothing is re-declared here. Their
// constructors, destructors and every member are rgmain.dll imports. What the exe holds of them is only what MSVC
// generates locally for a __declspec(dllimport) polymorphic class that the exe constructs: the ??_S local vftables
// (stamped over the imported constructor's vptrs right after the call), the scalar deleting destructor ??_G and the
// this-adjusting ??_E thunks of the secondary vftables. No exe body of these classes is source code.
//
// Evidence (original Roblox.exe):
//   class                 new    construction site (imported ctor, IAT)       vftables (RTTI offset)            ??_G     ??_E thunks
//   ManualObject          0x1d4  RbxSky ctor 00680f04 (008045e8)            0084e58c (0), 0084e574 (+4)       00681160 00681180 (+4)
//   Rectangle2D           0x194  00690b20 @ 0069127e (00804ef4, bool)       0084f24c (0), 0084f238 (+4),      006918c0 006918e0 (+4)
//                                                                             0084f1f4 (+0xc8 Renderable)               006918f0 (+0xc8)
//   InstancedGeometry     0x104  0069add0 @ 0069aee6 (00804a18)             0084fc0c (slot 11 = ??_G)          0069af30
//   StaticGeometry        0xd0   0069ac50 @ 0069ad63 (00804a94)             0084fb7c (slot 10 = ??_G)          0069adb0
//   SceneNode             0x228  0069a260 @ 0069a29c (008046c4), 0069a300 @ 0069a41c (0080447c)
//                                                                             0084f934                           0069a2e0
//   MemoryDataStream      0x34   @ 00684dfc, 00691709, 004da798, 00675f46, `call edi` 00674c5e, 00674f2e ... (00804e5c)
//                                                                             00826cc4                           004dab30
//   FileStreamDataStream  0x2c   007ae290 (00804c50)                        0084d1e8                           006700c0
//   RenderQueue           0x30   RbxSceneManager 0068b727 (0080479c)        0084e9b8 (1 slot)                  0068b780
//   Animation             0xa8   0069a7d0 @ 0069a8ed (00804aa0)             0084fb30 (1 slot)                  0069a930
//   * RTTI: Rectangle2D = SimpleRenderable(MovableObject(ShadowCaster, AnimableObject +4), Renderable +0xc8);
//     ManualObject = MovableObject(ShadowCaster, AnimableObject +4); SceneNode = Node(Renderable) at 0;
//     Memory/FileStreamDataStream = DataStream at 0; InstancedGeometry, StaticGeometry, RenderQueue, Animation: no base.
//   * Every vftable slot except the ??_G / ??_E slots is an rgmain.dll import thunk.
#include <OgreManualObject.h>
#include <OgreRectangle2D.h>
#include <OgreInstancedGeometry.h>
#include <OgreStaticGeometry.h>
#include <OgreSceneNode.h>
#include <OgreDataStream.h>
#include <OgreRenderQueue.h>
#include <OgreAnimation.h>
#include <fstream>
