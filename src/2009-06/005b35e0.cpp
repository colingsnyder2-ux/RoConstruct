// from server: 100% by auto
// roc 2009-06 005b35e0  unit: RBX::RenderNew::TextureProxy  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b35e0
//
// 005b35e0  55                   push ebp
// 005b35e1  8bec                 mov ebp, esp
// 005b35e3  51                   push ecx
// 005b35e4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b35e7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b35ea  e8516a0000           call 0x5ba040
// 005b35ef  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b35f2  8be5                 mov esp, ebp
// 005b35f4  5d                   pop ebp
// 005b35f5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
