// from server: 100% by auto
// roc 2008-06 005526d0  unit: RBX::RenderBase::AggregateChunk  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005526d0
//
// 005526d0  55                   push ebp
// 005526d1  8bec                 mov ebp, esp
// 005526d3  51                   push ecx
// 005526d4  894dfc               mov dword ptr [ebp - 4], ecx
// 005526d7  b001                 mov al, 1
// 005526d9  8be5                 mov esp, ebp
// 005526db  5d                   pop ebp
// 005526dc  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?do_always_noconv@codecvt_base@std@@MBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
