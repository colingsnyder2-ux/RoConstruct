// from server: 100% by auto
// roc 2010-06 006de310  unit: RBX::VFrame::?$FactoryProduct  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006de310
//
// 006de310  d9442404             fld dword ptr [esp + 4]
// 006de314  51                   push ecx
// 006de315  d91c24               fstp dword ptr [esp]
// 006de318  e853bf0100           call 0x6fa270
// 006de31d  c20400               ret 4
// library ogre-1.6.4/OgrePredefinedControllers.cpp (function ?calculate@PassthroughControllerFunction@Ogre@@UAEMM@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePredefinedControllers.cpp
