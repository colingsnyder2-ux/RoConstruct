// from server: 100% by auto
// roc 2008-06 00546170  unit: seg_00540000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00546170
//
// 00546170  55                   push ebp
// 00546171  8bec                 mov ebp, esp
// 00546173  51                   push ecx
// 00546174  894dfc               mov dword ptr [ebp - 4], ecx
// 00546177  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054617a  e851000000           call 0x5461d0
// 0054617f  8b4508               mov eax, dword ptr [ebp + 8]
// 00546182  83e001               and eax, 1
// 00546185  740c                 je 0x546193
// 00546187  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054618a  51                   push ecx
// 0054618b  e8eaa41500           call 0x6a067a
// 00546190  83c404               add esp, 4
// 00546193  8b45fc               mov eax, dword ptr [ebp - 4]
// 00546196  8be5                 mov esp, ebp
// 00546198  5d                   pop ebp
// 00546199  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
