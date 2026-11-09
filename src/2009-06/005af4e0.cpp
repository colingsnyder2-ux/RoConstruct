// from server: 100% by auto
// roc 2009-06 005af4e0  unit: RBX::TextureProxyBase  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005af4e0
//
// 005af4e0  55                   push ebp
// 005af4e1  8bec                 mov ebp, esp
// 005af4e3  51                   push ecx
// 005af4e4  894dfc               mov dword ptr [ebp - 4], ecx
// 005af4e7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005af4ea  e871ffffff           call 0x5af460
// 005af4ef  8b4508               mov eax, dword ptr [ebp + 8]
// 005af4f2  83e001               and eax, 1
// 005af4f5  740c                 je 0x5af503
// 005af4f7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005af4fa  51                   push ecx
// 005af4fb  e832951600           call 0x718a32
// 005af500  83c404               add esp, 4
// 005af503  8b45fc               mov eax, dword ptr [ebp - 4]
// 005af506  8be5                 mov esp, ebp
// 005af508  5d                   pop ebp
// 005af509  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
