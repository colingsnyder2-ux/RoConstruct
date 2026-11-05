// from server: 100% by auto
// roc 2008-06 0054ac70  unit: RBX::RenderBase::Mesh  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054ac70
//
// 0054ac70  55                   push ebp
// 0054ac71  8bec                 mov ebp, esp
// 0054ac73  51                   push ecx
// 0054ac74  894dfc               mov dword ptr [ebp - 4], ecx
// 0054ac77  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ac7a  e861781300           call 0x6824e0
// 0054ac7f  8b4508               mov eax, dword ptr [ebp + 8]
// 0054ac82  83e001               and eax, 1
// 0054ac85  740c                 je 0x54ac93
// 0054ac87  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ac8a  51                   push ecx
// 0054ac8b  e8ea591500           call 0x6a067a
// 0054ac90  83c404               add esp, 4
// 0054ac93  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054ac96  8be5                 mov esp, ebp
// 0054ac98  5d                   pop ebp
// 0054ac99  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
