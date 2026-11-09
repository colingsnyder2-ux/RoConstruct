// from server: 100% by auto
// roc 2009-06 005c0000  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c0000
//
// 005c0000  55                   push ebp
// 005c0001  8bec                 mov ebp, esp
// 005c0003  51                   push ecx
// 005c0004  894dfc               mov dword ptr [ebp - 4], ecx
// 005c0007  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c000a  e8b1fdffff           call 0x5bfdc0
// 005c000f  8b4508               mov eax, dword ptr [ebp + 8]
// 005c0012  83e001               and eax, 1
// 005c0015  740c                 je 0x5c0023
// 005c0017  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c001a  51                   push ecx
// 005c001b  e8128a1500           call 0x718a32
// 005c0020  83c404               add esp, 4
// 005c0023  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c0026  8be5                 mov esp, ebp
// 005c0028  5d                   pop ebp
// 005c0029  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
