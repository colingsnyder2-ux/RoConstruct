// from server: 100% by auto
// roc 2010-06 00919a20  unit: RBX::GfxAttachement  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00919a20
//
// 00919a20  55                   push ebp
// 00919a21  8bec                 mov ebp, esp
// 00919a23  51                   push ecx
// 00919a24  894dfc               mov dword ptr [ebp - 4], ecx
// 00919a27  b001                 mov al, 1
// 00919a29  8be5                 mov esp, ebp
// 00919a2b  5d                   pop ebp
// 00919a2c  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?do_always_noconv@codecvt_base@std@@MBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
