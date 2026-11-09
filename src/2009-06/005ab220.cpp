// from server: 100% by auto
// roc 2009-06 005ab220  unit: RBX::Mesh  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ab220
//
// 005ab220  55                   push ebp
// 005ab221  8bec                 mov ebp, esp
// 005ab223  51                   push ecx
// 005ab224  894dfc               mov dword ptr [ebp - 4], ecx
// 005ab227  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab22a  e881f5ffff           call 0x5aa7b0
// 005ab22f  8b4508               mov eax, dword ptr [ebp + 8]
// 005ab232  83e001               and eax, 1
// 005ab235  740c                 je 0x5ab243
// 005ab237  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab23a  51                   push ecx
// 005ab23b  e8f2d71600           call 0x718a32
// 005ab240  83c404               add esp, 4
// 005ab243  8b45fc               mov eax, dword ptr [ebp - 4]
// 005ab246  8be5                 mov esp, ebp
// 005ab248  5d                   pop ebp
// 005ab249  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
