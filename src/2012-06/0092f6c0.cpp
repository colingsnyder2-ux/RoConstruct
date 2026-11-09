// roc 2012-06 0092f6c0  unit: RBX::CellEdgeEdgePair  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0092f6c0
//
// 0092f6c0  55                   push ebp
// 0092f6c1  8bec                 mov ebp, esp
// 0092f6c3  51                   push ecx
// 0092f6c4  894dfc               mov dword ptr [ebp - 4], ecx
// 0092f6c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0092f6ca  e8a1ffffff           call 0x92f670
// 0092f6cf  8b4508               mov eax, dword ptr [ebp + 8]
// 0092f6d2  83e001               and eax, 1
// 0092f6d5  740c                 je 0x92f6e3
// 0092f6d7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0092f6da  51                   push ecx
// 0092f6db  e8342a0500           call 0x982114
// 0092f6e0  83c404               add esp, 4
// 0092f6e3  8b45fc               mov eax, dword ptr [ebp - 4]
// 0092f6e6  8be5                 mov esp, ebp
// 0092f6e8  5d                   pop ebp
// 0092f6e9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
