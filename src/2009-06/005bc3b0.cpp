// from server: 100% by auto
// roc 2009-06 005bc3b0  unit: seg_005b0000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bc3b0
//
// 005bc3b0  55                   push ebp
// 005bc3b1  8bec                 mov ebp, esp
// 005bc3b3  51                   push ecx
// 005bc3b4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bc3b7  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bc3ba  8b4008               mov eax, dword ptr [eax + 8]
// 005bc3bd  8be5                 mov esp, ebp
// 005bc3bf  5d                   pop ebp
// 005bc3c0  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ?GetType@?$ConvexHull3@N@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
