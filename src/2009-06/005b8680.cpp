// from server: 100% by auto
// roc 2009-06 005b8680  unit: seg_005b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b8680
//
// 005b8680  55                   push ebp
// 005b8681  8bec                 mov ebp, esp
// 005b8683  51                   push ecx
// 005b8684  894dfc               mov dword ptr [ebp - 4], ecx
// 005b8687  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b868a  e811250000           call 0x5baba0
// 005b868f  8be5                 mov esp, ebp
// 005b8691  5d                   pop ebp
// 005b8692  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
