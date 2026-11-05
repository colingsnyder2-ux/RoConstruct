// from server: 100% by auto
// roc 2011-06 007c5e40  unit: RBX::EdgeEdgePair  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007c5e40
//
// 007c5e40  55                   push ebp
// 007c5e41  8bec                 mov ebp, esp
// 007c5e43  51                   push ecx
// 007c5e44  894dfc               mov dword ptr [ebp - 4], ecx
// 007c5e47  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 007c5e4a  e8b1ffffff           call 0x7c5e00
// 007c5e4f  8b4508               mov eax, dword ptr [ebp + 8]
// 007c5e52  83e001               and eax, 1
// 007c5e55  740c                 je 0x7c5e63
// 007c5e57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 007c5e5a  51                   push ecx
// 007c5e5b  e8f8410400           call 0x80a058
// 007c5e60  83c404               add esp, 4
// 007c5e63  8b45fc               mov eax, dword ptr [ebp - 4]
// 007c5e66  8be5                 mov esp, ebp
// 007c5e68  5d                   pop ebp
// 007c5e69  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
