// from server: 100% by auto
// roc 2011-06 0095ebe0  unit: Ogre::RbxMeshPartAdapter  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0095ebe0
//
// 0095ebe0  56                   push esi
// 0095ebe1  8bf1                 mov esi, ecx
// 0095ebe3  8b4608               mov eax, dword ptr [esi + 8]
// 0095ebe6  85c0                 test eax, eax
// 0095ebe8  7409                 je 0x95ebf3
// 0095ebea  50                   push eax
// 0095ebeb  e868b4eaff           call 0x80a058
// 0095ebf0  83c404               add esp, 4
// 0095ebf3  c7460800000000       mov dword ptr [esi + 8], 0
// 0095ebfa  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0095ec01  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0095ec08  5e                   pop esi
// 0095ec09  c3                   ret 
// library boost-1.40.0/libs\regex\src\instances.cpp (function ??1?$named_subexpressions@D@re_detail@boost@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/regex/src/instances.cpp
