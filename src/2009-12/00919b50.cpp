// from server: 100% by auto
// roc 2009-12 00919b50  unit: RBX::AggregateChunk  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00919b50
//
// 00919b50  55                   push ebp
// 00919b51  8bec                 mov ebp, esp
// 00919b53  51                   push ecx
// 00919b54  894dfc               mov dword ptr [ebp - 4], ecx
// 00919b57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00919b5a  e8c1f7ffff           call 0x919320
// 00919b5f  8b4508               mov eax, dword ptr [ebp + 8]
// 00919b62  83e001               and eax, 1
// 00919b65  740c                 je 0x919b73
// 00919b67  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00919b6a  51                   push ecx
// 00919b6b  e8ea9cedff           call 0x7f385a
// 00919b70  83c404               add esp, 4
// 00919b73  8b45fc               mov eax, dword ptr [ebp - 4]
// 00919b76  8be5                 mov esp, ebp
// 00919b78  5d                   pop ebp
// 00919b79  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
