// from server: 100% by auto
// roc 2008-06 00551d80  unit: RBX::Render::TextureProxy  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00551d80
//
// 00551d80  55                   push ebp
// 00551d81  8bec                 mov ebp, esp
// 00551d83  51                   push ecx
// 00551d84  894dfc               mov dword ptr [ebp - 4], ecx
// 00551d87  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00551d8a  e821000000           call 0x551db0
// 00551d8f  8b4508               mov eax, dword ptr [ebp + 8]
// 00551d92  83e001               and eax, 1
// 00551d95  740c                 je 0x551da3
// 00551d97  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00551d9a  51                   push ecx
// 00551d9b  e8dae81400           call 0x6a067a
// 00551da0  83c404               add esp, 4
// 00551da3  8b45fc               mov eax, dword ptr [ebp - 4]
// 00551da6  8be5                 mov esp, ebp
// 00551da8  5d                   pop ebp
// 00551da9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
