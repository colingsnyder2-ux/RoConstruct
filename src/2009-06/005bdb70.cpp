// from server: 100% by auto
// roc 2009-06 005bdb70  unit: RBX::AggregateChunk  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bdb70
//
// 005bdb70  55                   push ebp
// 005bdb71  8bec                 mov ebp, esp
// 005bdb73  51                   push ecx
// 005bdb74  894dfc               mov dword ptr [ebp - 4], ecx
// 005bdb77  b001                 mov al, 1
// 005bdb79  8be5                 mov esp, ebp
// 005bdb7b  5d                   pop ebp
// 005bdb7c  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?do_always_noconv@codecvt_base@std@@MBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
