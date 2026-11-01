// from server: 100% by auto
// roc 2009-06 005c6190  unit: seg_005c0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c6190
//
// 005c6190  55                   push ebp
// 005c6191  8bec                 mov ebp, esp
// 005c6193  51                   push ecx
// 005c6194  894dfc               mov dword ptr [ebp - 4], ecx
// 005c6197  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c619a  e871070000           call 0x5c6910
// 005c619f  8be5                 mov esp, ebp
// 005c61a1  5d                   pop ebp
// 005c61a2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
