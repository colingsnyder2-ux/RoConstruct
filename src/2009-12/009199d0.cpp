// from server: 100% by auto
// roc 2009-12 009199d0  unit: RBX::AggregateChunk  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009199d0
//
// 009199d0  55                   push ebp
// 009199d1  8bec                 mov ebp, esp
// 009199d3  51                   push ecx
// 009199d4  894dfc               mov dword ptr [ebp - 4], ecx
// 009199d7  33c0                 xor eax, eax
// 009199d9  8be5                 mov esp, ebp
// 009199db  5d                   pop ebp
// 009199dc  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?showmanyc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
