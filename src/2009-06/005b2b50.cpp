// from server: 100% by auto
// roc 2009-06 005b2b50  unit: RBX::RenderNew::TextureProxy  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b2b50
//
// 005b2b50  55                   push ebp
// 005b2b51  8bec                 mov ebp, esp
// 005b2b53  51                   push ecx
// 005b2b54  894dfc               mov dword ptr [ebp - 4], ecx
// 005b2b57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b2b5a  e871010000           call 0x5b2cd0
// 005b2b5f  8be5                 mov esp, ebp
// 005b2b61  5d                   pop ebp
// 005b2b62  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
