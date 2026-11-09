// from server: 100% by auto
// roc 2008-06 005461a0  unit: seg_00540000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005461a0
//
// 005461a0  55                   push ebp
// 005461a1  8bec                 mov ebp, esp
// 005461a3  51                   push ecx
// 005461a4  894dfc               mov dword ptr [ebp - 4], ecx
// 005461a7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005461aa  e841000000           call 0x5461f0
// 005461af  8b4508               mov eax, dword ptr [ebp + 8]
// 005461b2  83e001               and eax, 1
// 005461b5  740c                 je 0x5461c3
// 005461b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005461ba  51                   push ecx
// 005461bb  e8baa41500           call 0x6a067a
// 005461c0  83c404               add esp, 4
// 005461c3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005461c6  8be5                 mov esp, ebp
// 005461c8  5d                   pop ebp
// 005461c9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
