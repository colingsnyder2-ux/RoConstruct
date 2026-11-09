// from server: 100% by auto
// roc 2009-06 005b9fc0  unit: seg_005b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b9fc0
//
// 005b9fc0  55                   push ebp
// 005b9fc1  8bec                 mov ebp, esp
// 005b9fc3  51                   push ecx
// 005b9fc4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b9fc7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b9fca  e891000000           call 0x5ba060
// 005b9fcf  8be5                 mov esp, ebp
// 005b9fd1  5d                   pop ebp
// 005b9fd2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
