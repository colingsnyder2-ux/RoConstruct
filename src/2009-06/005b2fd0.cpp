// from server: 100% by auto
// roc 2009-06 005b2fd0  unit: RBX::RenderNew::TextureProxy  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b2fd0
//
// 005b2fd0  55                   push ebp
// 005b2fd1  8bec                 mov ebp, esp
// 005b2fd3  51                   push ecx
// 005b2fd4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b2fd7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b2fda  e8010d0000           call 0x5b3ce0
// 005b2fdf  8be5                 mov esp, ebp
// 005b2fe1  5d                   pop ebp
// 005b2fe2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
