// from server: 100% by auto
// roc 2009-12 004e37a0  unit: RBX::Mesh  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e37a0
//
// 004e37a0  55                   push ebp
// 004e37a1  8bec                 mov ebp, esp
// 004e37a3  51                   push ecx
// 004e37a4  894dfc               mov dword ptr [ebp - 4], ecx
// 004e37a7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e37aa  e8c1e8ffff           call 0x4e2070
// 004e37af  8b4508               mov eax, dword ptr [ebp + 8]
// 004e37b2  83e001               and eax, 1
// 004e37b5  740c                 je 0x4e37c3
// 004e37b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 004e37ba  51                   push ecx
// 004e37bb  e89a003100           call 0x7f385a
// 004e37c0  83c404               add esp, 4
// 004e37c3  8b45fc               mov eax, dword ptr [ebp - 4]
// 004e37c6  8be5                 mov esp, ebp
// 004e37c8  5d                   pop ebp
// 004e37c9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
