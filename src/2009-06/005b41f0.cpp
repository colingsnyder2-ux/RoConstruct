// from server: 100% by auto
// roc 2009-06 005b41f0  unit: seg_005b0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b41f0
//
// 005b41f0  55                   push ebp
// 005b41f1  8bec                 mov ebp, esp
// 005b41f3  51                   push ecx
// 005b41f4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b41f7  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b41fa  83c008               add eax, 8
// 005b41fd  8be5                 mov esp, ebp
// 005b41ff  5d                   pop ebp
// 005b4200  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ?GetConnectivity@?$ConvexHull3@M@Wml@@QBEABV?$vector@HV?$allocator@H@std@@@std@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
