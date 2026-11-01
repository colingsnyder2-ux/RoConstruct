// from server: 100% by auto
// roc 2012-06 004b95c0  unit: RBX::ViewRbxGfx  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b95c0
//
// 004b95c0  8a442404             mov al, byte ptr [esp + 4]
// 004b95c4  88413a               mov byte ptr [ecx + 0x3a], al
// 004b95c7  c20400               ret 4
// library ogre-1.6.4/OgreMesh.cpp (function ?setStoreParityInW@TangentSpaceCalc@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreMesh.cpp
