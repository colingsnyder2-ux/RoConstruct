// from server: 100% by auto
// roc 2007-03 0055db70  unit: seg_00550000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0055db70
//
// 0055db70  8a442404             mov al, byte ptr [esp + 4]
// 0055db74  884170               mov byte ptr [ecx + 0x70], al
// 0055db77  c20400               ret 4
// library ogre-1.4.9/OgreRenderSystem.cpp (function ?setWaitForVerticalBlank@RenderSystem@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreRenderSystem.cpp
