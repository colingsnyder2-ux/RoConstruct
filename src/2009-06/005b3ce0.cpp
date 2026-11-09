// from server: 100% by auto
// roc 2009-06 005b3ce0  unit: seg_005b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3ce0
//
// 005b3ce0  55                   push ebp
// 005b3ce1  8bec                 mov ebp, esp
// 005b3ce3  51                   push ecx
// 005b3ce4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3ce7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b3cea  e811000000           call 0x5b3d00
// 005b3cef  8be5                 mov esp, ebp
// 005b3cf1  5d                   pop ebp
// 005b3cf2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
