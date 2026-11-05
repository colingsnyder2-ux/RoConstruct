// from server: 100% by auto
// roc 2009-06 005bf300  unit: RBX::AggregatingSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bf300
//
// 005bf300  55                   push ebp
// 005bf301  8bec                 mov ebp, esp
// 005bf303  51                   push ecx
// 005bf304  894dfc               mov dword ptr [ebp - 4], ecx
// 005bf307  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bf30a  e8b1edffff           call 0x5be0c0
// 005bf30f  8b4508               mov eax, dword ptr [ebp + 8]
// 005bf312  83e001               and eax, 1
// 005bf315  740c                 je 0x5bf323
// 005bf317  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bf31a  51                   push ecx
// 005bf31b  e812971500           call 0x718a32
// 005bf320  83c404               add esp, 4
// 005bf323  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bf326  8be5                 mov esp, ebp
// 005bf328  5d                   pop ebp
// 005bf329  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
