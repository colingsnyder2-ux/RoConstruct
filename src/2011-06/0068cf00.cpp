// from server: 100% by auto
// roc 2011-06 0068cf00  unit: RBX::VGuiTextButton::?$FactoryProduct  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0068cf00
//
// 0068cf00  d9442404             fld dword ptr [esp + 4]
// 0068cf04  51                   push ecx
// 0068cf05  d91c24               fstp dword ptr [esp]
// 0068cf08  e853370200           call 0x6b0660
// 0068cf0d  c20400               ret 4
// library ogre-1.6.4/OgrePredefinedControllers.cpp (function ?calculate@PassthroughControllerFunction@Ogre@@UAEMM@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePredefinedControllers.cpp
