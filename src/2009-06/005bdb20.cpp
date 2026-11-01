// from server: 100% by auto
// roc 2009-06 005bdb20  unit: RBX::AggregateChunk  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bdb20
//
// 005bdb20  55                   push ebp
// 005bdb21  8bec                 mov ebp, esp
// 005bdb23  51                   push ecx
// 005bdb24  894dfc               mov dword ptr [ebp - 4], ecx
// 005bdb27  33c0                 xor eax, eax
// 005bdb29  8be5                 mov esp, ebp
// 005bdb2b  5d                   pop ebp
// 005bdb2c  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?showmanyc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
