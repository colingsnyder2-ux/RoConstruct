// from server: 100% by auto
// roc 2008-06 00552780  unit: RBX::RenderBase::AggregateChunk  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00552780
//
// 00552780  55                   push ebp
// 00552781  8bec                 mov ebp, esp
// 00552783  51                   push ecx
// 00552784  894dfc               mov dword ptr [ebp - 4], ecx
// 00552787  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0055278a  e8d1f9ffff           call 0x552160
// 0055278f  8b4508               mov eax, dword ptr [ebp + 8]
// 00552792  83e001               and eax, 1
// 00552795  740c                 je 0x5527a3
// 00552797  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0055279a  51                   push ecx
// 0055279b  e8dade1400           call 0x6a067a
// 005527a0  83c404               add esp, 4
// 005527a3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005527a6  8be5                 mov esp, ebp
// 005527a8  5d                   pop ebp
// 005527a9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
