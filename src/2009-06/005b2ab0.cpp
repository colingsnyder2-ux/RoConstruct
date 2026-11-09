// from server: 100% by auto
// roc 2009-06 005b2ab0  unit: RBX::RenderNew::TextureProxy  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b2ab0
//
// 005b2ab0  55                   push ebp
// 005b2ab1  8bec                 mov ebp, esp
// 005b2ab3  51                   push ecx
// 005b2ab4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b2ab7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b2aba  e8a1020000           call 0x5b2d60
// 005b2abf  8be5                 mov esp, ebp
// 005b2ac1  5d                   pop ebp
// 005b2ac2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
