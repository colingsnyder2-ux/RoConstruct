// from server: 100% by auto
// roc 2008-06 0054c4b0  unit: RBX::RenderBase::Mesh  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054c4b0
//
// 0054c4b0  55                   push ebp
// 0054c4b1  8bec                 mov ebp, esp
// 0054c4b3  51                   push ecx
// 0054c4b4  894dfc               mov dword ptr [ebp - 4], ecx
// 0054c4b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054c4ba  e8b1510000           call 0x551670
// 0054c4bf  8b4508               mov eax, dword ptr [ebp + 8]
// 0054c4c2  83e001               and eax, 1
// 0054c4c5  740c                 je 0x54c4d3
// 0054c4c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054c4ca  51                   push ecx
// 0054c4cb  e8aa411500           call 0x6a067a
// 0054c4d0  83c404               add esp, 4
// 0054c4d3  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054c4d6  8be5                 mov esp, ebp
// 0054c4d8  5d                   pop ebp
// 0054c4d9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
