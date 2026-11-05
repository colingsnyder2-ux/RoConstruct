// roc 2012-06 00675a70  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00675a70
//
// 00675a70  55                   push ebp
// 00675a71  8bec                 mov ebp, esp
// 00675a73  51                   push ecx
// 00675a74  894dfc               mov dword ptr [ebp - 4], ecx
// 00675a77  b001                 mov al, 1
// 00675a79  8be5                 mov esp, ebp
// 00675a7b  5d                   pop ebp
// 00675a7c  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?do_always_noconv@codecvt_base@std@@MBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
