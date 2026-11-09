// from server: 100% by auto
// roc 2012-06 005047e0  unit: Ogre::RbxMeshPartAdapter  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005047e0
//
// 005047e0  56                   push esi
// 005047e1  8bf1                 mov esi, ecx
// 005047e3  8b4608               mov eax, dword ptr [esi + 8]
// 005047e6  85c0                 test eax, eax
// 005047e8  7409                 je 0x5047f3
// 005047ea  50                   push eax
// 005047eb  e824d94700           call 0x982114
// 005047f0  83c404               add esp, 4
// 005047f3  c7460800000000       mov dword ptr [esi + 8], 0
// 005047fa  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00504801  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00504808  5e                   pop esi
// 00504809  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
