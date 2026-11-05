// from server: 100% by auto
// roc 2008-06 0054a9c0  unit: RBX::RenderBase::Mesh  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054a9c0
//
// 0054a9c0  55                   push ebp
// 0054a9c1  8bec                 mov ebp, esp
// 0054a9c3  51                   push ecx
// 0054a9c4  894dfc               mov dword ptr [ebp - 4], ecx
// 0054a9c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054a9ca  e8c1e0ffff           call 0x548a90
// 0054a9cf  8b4508               mov eax, dword ptr [ebp + 8]
// 0054a9d2  83e001               and eax, 1
// 0054a9d5  740c                 je 0x54a9e3
// 0054a9d7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054a9da  51                   push ecx
// 0054a9db  e89a5c1500           call 0x6a067a
// 0054a9e0  83c404               add esp, 4
// 0054a9e3  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054a9e6  8be5                 mov esp, ebp
// 0054a9e8  5d                   pop ebp
// 0054a9e9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
