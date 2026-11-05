// from server: 100% by auto
// roc 2008-06 005462c0  unit: seg_00540000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005462c0
//
// 005462c0  55                   push ebp
// 005462c1  8bec                 mov ebp, esp
// 005462c3  51                   push ecx
// 005462c4  894dfc               mov dword ptr [ebp - 4], ecx
// 005462c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005462ca  e8b1aeffff           call 0x541180
// 005462cf  8be5                 mov esp, ebp
// 005462d1  5d                   pop ebp
// 005462d2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
