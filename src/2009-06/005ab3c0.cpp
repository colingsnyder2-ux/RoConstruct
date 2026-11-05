// from server: 100% by auto
// roc 2009-06 005ab3c0  unit: RBX::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ab3c0
//
// 005ab3c0  55                   push ebp
// 005ab3c1  8bec                 mov ebp, esp
// 005ab3c3  51                   push ecx
// 005ab3c4  894dfc               mov dword ptr [ebp - 4], ecx
// 005ab3c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab3ca  e8610a0000           call 0x5abe30
// 005ab3cf  8be5                 mov esp, ebp
// 005ab3d1  5d                   pop ebp
// 005ab3d2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
