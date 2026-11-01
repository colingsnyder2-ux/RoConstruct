// from server: 100% by auto
// roc 2010-06 004e75c0  unit: G3D::VRay::?$holder  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e75c0
//
// 004e75c0  f644240401           test byte ptr [esp + 4], 1
// 004e75c5  56                   push esi
// 004e75c6  8bf1                 mov esi, ecx
// 004e75c8  c7460490aca100       mov dword ptr [esi + 4], 0xa1ac90
// 004e75cf  c7063c0aa000         mov dword ptr [esi], 0xa00a3c
// 004e75d5  7409                 je 0x4e75e0
// 004e75d7  56                   push esi
// 004e75d8  e8bd032c00           call 0x7a799a
// 004e75dd  83c404               add esp, 4
// 004e75e0  8bc6                 mov eax, esi
// 004e75e2  5e                   pop esi
// 004e75e3  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ??_GFrameTimeControllerValue@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
