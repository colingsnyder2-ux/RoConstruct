// from server: 100% by auto
// roc 2009-06 005b9c70  unit: seg_005b0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b9c70
//
// 005b9c70  55                   push ebp
// 005b9c71  8bec                 mov ebp, esp
// 005b9c73  51                   push ecx
// 005b9c74  894dfc               mov dword ptr [ebp - 4], ecx
// 005b9c77  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b9c7a  e811000000           call 0x5b9c90
// 005b9c7f  8be5                 mov esp, ebp
// 005b9c81  5d                   pop ebp
// 005b9c82  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
