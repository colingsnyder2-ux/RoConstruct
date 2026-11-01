// from server: 100% by auto
// roc 2009-06 005af6d0  unit: RBX::RenderNew::TextureProxy  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005af6d0
//
// 005af6d0  55                   push ebp
// 005af6d1  8bec                 mov ebp, esp
// 005af6d3  51                   push ecx
// 005af6d4  894dfc               mov dword ptr [ebp - 4], ecx
// 005af6d7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005af6da  e8e1632800           call 0x835ac0
// 005af6df  8b4508               mov eax, dword ptr [ebp + 8]
// 005af6e2  83e001               and eax, 1
// 005af6e5  740c                 je 0x5af6f3
// 005af6e7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005af6ea  51                   push ecx
// 005af6eb  e842931600           call 0x718a32
// 005af6f0  83c404               add esp, 4
// 005af6f3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005af6f6  8be5                 mov esp, ebp
// 005af6f8  5d                   pop ebp
// 005af6f9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
