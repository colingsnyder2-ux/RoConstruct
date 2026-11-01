// from server: 100% by auto
// roc 2009-12 00757760  unit: RBX::VFrame::?$FactoryProduct  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00757760
//
// 00757760  d9442404             fld dword ptr [esp + 4]
// 00757764  51                   push ecx
// 00757765  d91c24               fstp dword ptr [esp]
// 00757768  e8b3870100           call 0x76ff20
// 0075776d  c20400               ret 4
// library ogre-1.6.4/OgrePredefinedControllers.cpp (function ?calculate@PassthroughControllerFunction@Ogre@@UAEMM@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePredefinedControllers.cpp
