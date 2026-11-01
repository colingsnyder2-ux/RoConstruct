// from server: 100% by auto
// roc 2009-06 005bf400  unit: RBX::AggregatingSceneManager::Bucket  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bf400
//
// 005bf400  55                   push ebp
// 005bf401  8bec                 mov ebp, esp
// 005bf403  51                   push ecx
// 005bf404  894dfc               mov dword ptr [ebp - 4], ecx
// 005bf407  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bf40a  e821000000           call 0x5bf430
// 005bf40f  8b4508               mov eax, dword ptr [ebp + 8]
// 005bf412  83e001               and eax, 1
// 005bf415  740c                 je 0x5bf423
// 005bf417  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bf41a  51                   push ecx
// 005bf41b  e812961500           call 0x718a32
// 005bf420  83c404               add esp, 4
// 005bf423  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bf426  8be5                 mov esp, ebp
// 005bf428  5d                   pop ebp
// 005bf429  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
