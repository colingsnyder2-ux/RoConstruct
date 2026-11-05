// from server: 100% by auto
// roc 2009-06 005bbe20  unit: seg_005b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bbe20
//
// 005bbe20  55                   push ebp
// 005bbe21  8bec                 mov ebp, esp
// 005bbe23  51                   push ecx
// 005bbe24  894dfc               mov dword ptr [ebp - 4], ecx
// 005bbe27  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bbe2a  e891e1ffff           call 0x5b9fc0
// 005bbe2f  8be5                 mov esp, ebp
// 005bbe31  5d                   pop ebp
// 005bbe32  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
