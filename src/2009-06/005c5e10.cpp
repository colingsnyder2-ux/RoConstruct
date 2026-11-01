// from server: 100% by auto
// roc 2009-06 005c5e10  unit: seg_005c0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c5e10
//
// 005c5e10  55                   push ebp
// 005c5e11  8bec                 mov ebp, esp
// 005c5e13  51                   push ecx
// 005c5e14  894dfc               mov dword ptr [ebp - 4], ecx
// 005c5e17  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c5e1a  e851000000           call 0x5c5e70
// 005c5e1f  8b4508               mov eax, dword ptr [ebp + 8]
// 005c5e22  83e001               and eax, 1
// 005c5e25  740c                 je 0x5c5e33
// 005c5e27  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c5e2a  51                   push ecx
// 005c5e2b  e8022c1500           call 0x718a32
// 005c5e30  83c404               add esp, 4
// 005c5e33  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c5e36  8be5                 mov esp, ebp
// 005c5e38  5d                   pop ebp
// 005c5e39  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
