// from server: 100% by auto
// roc 2011-06 009ca720  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009ca720
//
// 009ca720  55                   push ebp
// 009ca721  8bec                 mov ebp, esp
// 009ca723  51                   push ecx
// 009ca724  894dfc               mov dword ptr [ebp - 4], ecx
// 009ca727  b001                 mov al, 1
// 009ca729  8be5                 mov esp, ebp
// 009ca72b  5d                   pop ebp
// 009ca72c  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?do_always_noconv@codecvt_base@std@@MBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
