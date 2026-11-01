// from server: 100% by auto
// roc 2009-06 005b3690  unit: RBX::RenderNew::TextureProxy  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3690
//
// 005b3690  55                   push ebp
// 005b3691  8bec                 mov ebp, esp
// 005b3693  51                   push ecx
// 005b3694  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3697  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b369a  e8b1df0000           call 0x5c1650
// 005b369f  8be5                 mov esp, ebp
// 005b36a1  5d                   pop ebp
// 005b36a2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
