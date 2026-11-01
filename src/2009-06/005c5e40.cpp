// from server: 100% by auto
// roc 2009-06 005c5e40  unit: seg_005c0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c5e40
//
// 005c5e40  55                   push ebp
// 005c5e41  8bec                 mov ebp, esp
// 005c5e43  51                   push ecx
// 005c5e44  894dfc               mov dword ptr [ebp - 4], ecx
// 005c5e47  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c5e4a  e841000000           call 0x5c5e90
// 005c5e4f  8b4508               mov eax, dword ptr [ebp + 8]
// 005c5e52  83e001               and eax, 1
// 005c5e55  740c                 je 0x5c5e63
// 005c5e57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c5e5a  51                   push ecx
// 005c5e5b  e8d22b1500           call 0x718a32
// 005c5e60  83c404               add esp, 4
// 005c5e63  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c5e66  8be5                 mov esp, ebp
// 005c5e68  5d                   pop ebp
// 005c5e69  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
