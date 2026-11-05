// roc 2012-06 00673a60  unit: RBX::AdornBillboarder  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00673a60
//
// 00673a60  55                   push ebp
// 00673a61  8bec                 mov ebp, esp
// 00673a63  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00673a66  50                   push eax
// 00673a67  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00673a6a  51                   push ecx
// 00673a6b  e860000000           call 0x673ad0
// 00673a70  83c408               add esp, 8
// 00673a73  5d                   pop ebp
// 00673a74  c3                   ret 
// copied from an identical function in another client (function ??$iter_swap@PAVEdgePlus@?$ConvexClipper@M@Wml@@PAV123@@std@@YAXPAVEdgePlus@?$ConvexClipper@M@Wml@@0@Z)

// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp