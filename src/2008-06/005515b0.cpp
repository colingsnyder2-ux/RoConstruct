// from server: 100% by auto
// roc 2008-06 005515b0  unit: seg_00550000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005515b0
//
// 005515b0  55                   push ebp
// 005515b1  8bec                 mov ebp, esp
// 005515b3  51                   push ecx
// 005515b4  894dfc               mov dword ptr [ebp - 4], ecx
// 005515b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005515ba  e821000000           call 0x5515e0
// 005515bf  8b4508               mov eax, dword ptr [ebp + 8]
// 005515c2  83e001               and eax, 1
// 005515c5  740c                 je 0x5515d3
// 005515c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005515ca  51                   push ecx
// 005515cb  e8aaf01400           call 0x6a067a
// 005515d0  83c404               add esp, 4
// 005515d3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005515d6  8be5                 mov esp, ebp
// 005515d8  5d                   pop ebp
// 005515d9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
