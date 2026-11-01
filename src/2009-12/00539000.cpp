// from server: 100% by auto
// roc 2009-12 00539000  unit: G3D::VRay::?$holder  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00539000
//
// 00539000  f644240401           test byte ptr [esp + 4], 1
// 00539005  56                   push esi
// 00539006  8bf1                 mov esi, ecx
// 00539008  c74604b0cd9b00       mov dword ptr [esi + 4], 0x9bcdb0
// 0053900f  c70684fe9900         mov dword ptr [esi], 0x99fe84
// 00539015  7409                 je 0x539020
// 00539017  56                   push esi
// 00539018  e83da82b00           call 0x7f385a
// 0053901d  83c404               add esp, 4
// 00539020  8bc6                 mov eax, esi
// 00539022  5e                   pop esi
// 00539023  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ??_GFrameTimeControllerValue@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
