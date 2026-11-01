// from server: 100% by auto
// roc 2009-12 004e3770  unit: RBX::Mesh::Level  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e3770
//
// 004e3770  55                   push ebp
// 004e3771  8bec                 mov ebp, esp
// 004e3773  51                   push ecx
// 004e3774  894dfc               mov dword ptr [ebp - 4], ecx
// 004e3777  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e377a  e841e8ffff           call 0x4e1fc0
// 004e377f  8b4508               mov eax, dword ptr [ebp + 8]
// 004e3782  83e001               and eax, 1
// 004e3785  740c                 je 0x4e3793
// 004e3787  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e378a  51                   push ecx
// 004e378b  e8ca003100           call 0x7f385a
// 004e3790  83c404               add esp, 4
// 004e3793  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e3796  8be5                 mov esp, ebp
// 004e3798  5d                   pop ebp
// 004e3799  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
