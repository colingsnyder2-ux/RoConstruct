// from server: 100% by auto
// roc 2009-06 005abf40  unit: RBX::Mesh  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005abf40
//
// 005abf40  55                   push ebp
// 005abf41  8bec                 mov ebp, esp
// 005abf43  51                   push ecx
// 005abf44  894dfc               mov dword ptr [ebp - 4], ecx
// 005abf47  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005abf4a  e841000000           call 0x5abf90
// 005abf4f  8b4508               mov eax, dword ptr [ebp + 8]
// 005abf52  83e001               and eax, 1
// 005abf55  740c                 je 0x5abf63
// 005abf57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005abf5a  51                   push ecx
// 005abf5b  e8d2ca1600           call 0x718a32
// 005abf60  83c404               add esp, 4
// 005abf63  8b45fc               mov eax, dword ptr [ebp - 4]
// 005abf66  8be5                 mov esp, ebp
// 005abf68  5d                   pop ebp
// 005abf69  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
