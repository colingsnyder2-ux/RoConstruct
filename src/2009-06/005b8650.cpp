// from server: 100% by auto
// roc 2009-06 005b8650  unit: seg_005b0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b8650
//
// 005b8650  55                   push ebp
// 005b8651  8bec                 mov ebp, esp
// 005b8653  51                   push ecx
// 005b8654  894dfc               mov dword ptr [ebp - 4], ecx
// 005b8657  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b865a  e841000000           call 0x5b86a0
// 005b865f  8b4508               mov eax, dword ptr [ebp + 8]
// 005b8662  83e001               and eax, 1
// 005b8665  740c                 je 0x5b8673
// 005b8667  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b866a  51                   push ecx
// 005b866b  e8c2031600           call 0x718a32
// 005b8670  83c404               add esp, 4
// 005b8673  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b8676  8be5                 mov esp, ebp
// 005b8678  5d                   pop ebp
// 005b8679  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
