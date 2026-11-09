// from server: 100% by auto
// roc 2008-06 00551f00  unit: RBX::RenderNew::TextureProxy  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00551f00
//
// 00551f00  55                   push ebp
// 00551f01  8bec                 mov ebp, esp
// 00551f03  51                   push ecx
// 00551f04  894dfc               mov dword ptr [ebp - 4], ecx
// 00551f07  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00551f0a  e8a1c42500           call 0x7ae3b0
// 00551f0f  8b4508               mov eax, dword ptr [ebp + 8]
// 00551f12  83e001               and eax, 1
// 00551f15  740c                 je 0x551f23
// 00551f17  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00551f1a  51                   push ecx
// 00551f1b  e85ae71400           call 0x6a067a
// 00551f20  83c404               add esp, 4
// 00551f23  8b45fc               mov eax, dword ptr [ebp - 4]
// 00551f26  8be5                 mov esp, ebp
// 00551f28  5d                   pop ebp
// 00551f29  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
