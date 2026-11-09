// from server: 100% by auto
// roc 2009-06 005af510  unit: RBX::RbxG3D::TextureProxy  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005af510
//
// 005af510  55                   push ebp
// 005af511  8bec                 mov ebp, esp
// 005af513  51                   push ecx
// 005af514  894dfc               mov dword ptr [ebp - 4], ecx
// 005af517  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005af51a  e821000000           call 0x5af540
// 005af51f  8b4508               mov eax, dword ptr [ebp + 8]
// 005af522  83e001               and eax, 1
// 005af525  740c                 je 0x5af533
// 005af527  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005af52a  51                   push ecx
// 005af52b  e802951600           call 0x718a32
// 005af530  83c404               add esp, 4
// 005af533  8b45fc               mov eax, dword ptr [ebp - 4]
// 005af536  8be5                 mov esp, ebp
// 005af538  5d                   pop ebp
// 005af539  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
