// from server: 100% by auto
// roc 2009-06 005bdc20  unit: RBX::AggregateChunk  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bdc20
//
// 005bdc20  55                   push ebp
// 005bdc21  8bec                 mov ebp, esp
// 005bdc23  51                   push ecx
// 005bdc24  894dfc               mov dword ptr [ebp - 4], ecx
// 005bdc27  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bdc2a  e8f1f9ffff           call 0x5bd620
// 005bdc2f  8b4508               mov eax, dword ptr [ebp + 8]
// 005bdc32  83e001               and eax, 1
// 005bdc35  740c                 je 0x5bdc43
// 005bdc37  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bdc3a  51                   push ecx
// 005bdc3b  e8f2ad1500           call 0x718a32
// 005bdc40  83c404               add esp, 4
// 005bdc43  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bdc46  8be5                 mov esp, ebp
// 005bdc48  5d                   pop ebp
// 005bdc49  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
