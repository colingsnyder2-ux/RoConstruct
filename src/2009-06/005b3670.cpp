// from server: 100% by auto
// roc 2009-06 005b3670  unit: RBX::RenderNew::TextureProxy  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3670
//
// 005b3670  55                   push ebp
// 005b3671  8bec                 mov ebp, esp
// 005b3673  51                   push ecx
// 005b3674  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3677  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b367a  e811000000           call 0x5b3690
// 005b367f  8be5                 mov esp, ebp
// 005b3681  5d                   pop ebp
// 005b3682  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
