// from server: 100% by auto
// roc 2008-06 00551d50  unit: RBX::TextureProxyBase  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00551d50
//
// 00551d50  55                   push ebp
// 00551d51  8bec                 mov ebp, esp
// 00551d53  51                   push ecx
// 00551d54  894dfc               mov dword ptr [ebp - 4], ecx
// 00551d57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00551d5a  e891ffffff           call 0x551cf0
// 00551d5f  8b4508               mov eax, dword ptr [ebp + 8]
// 00551d62  83e001               and eax, 1
// 00551d65  740c                 je 0x551d73
// 00551d67  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00551d6a  51                   push ecx
// 00551d6b  e80ae91400           call 0x6a067a
// 00551d70  83c404               add esp, 4
// 00551d73  8b45fc               mov eax, dword ptr [ebp - 4]
// 00551d76  8be5                 mov esp, ebp
// 00551d78  5d                   pop ebp
// 00551d79  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
