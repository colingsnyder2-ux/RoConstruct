// from server: 100% by auto
// roc 2011-06 004f5fe0  unit: RBX::VRbxRay::?$holder  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f5fe0
//
// 004f5fe0  f644240401           test byte ptr [esp + 4], 1
// 004f5fe5  56                   push esi
// 004f5fe6  8bf1                 mov esi, ecx
// 004f5fe8  c7460418afa700       mov dword ptr [esi + 4], 0xa7af18
// 004f5fef  c706f4c0a500         mov dword ptr [esi], 0xa5c0f4
// 004f5ff5  7409                 je 0x4f6000
// 004f5ff7  56                   push esi
// 004f5ff8  e85b403100           call 0x80a058
// 004f5ffd  83c404               add esp, 4
// 004f6000  8bc6                 mov eax, esi
// 004f6002  5e                   pop esi
// 004f6003  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ??_GFrameTimeControllerValue@Ogre@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
