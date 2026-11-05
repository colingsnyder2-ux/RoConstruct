// from server: 100% by auto
// roc 2008-06 00546ff0  unit: seg_00540000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00546ff0
//
// 00546ff0  55                   push ebp
// 00546ff1  8bec                 mov ebp, esp
// 00546ff3  51                   push ecx
// 00546ff4  894dfc               mov dword ptr [ebp - 4], ecx
// 00546ff7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00546ffa  e821000000           call 0x547020
// 00546fff  8b4508               mov eax, dword ptr [ebp + 8]
// 00547002  83e001               and eax, 1
// 00547005  740c                 je 0x547013
// 00547007  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054700a  51                   push ecx
// 0054700b  e86a961500           call 0x6a067a
// 00547010  83c404               add esp, 4
// 00547013  8b45fc               mov eax, dword ptr [ebp - 4]
// 00547016  8be5                 mov esp, ebp
// 00547018  5d                   pop ebp
// 00547019  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
