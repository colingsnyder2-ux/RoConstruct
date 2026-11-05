// from server: 100% by auto
// roc 2008-06 00540410  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540410
//
// 00540410  55                   push ebp
// 00540411  8bec                 mov ebp, esp
// 00540413  51                   push ecx
// 00540414  894dfc               mov dword ptr [ebp - 4], ecx
// 00540417  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054041a  e821000000           call 0x540440
// 0054041f  8b4508               mov eax, dword ptr [ebp + 8]
// 00540422  83e001               and eax, 1
// 00540425  740c                 je 0x540433
// 00540427  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054042a  51                   push ecx
// 0054042b  e84a021600           call 0x6a067a
// 00540430  83c404               add esp, 4
// 00540433  8b45fc               mov eax, dword ptr [ebp - 4]
// 00540436  8be5                 mov esp, ebp
// 00540438  5d                   pop ebp
// 00540439  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
