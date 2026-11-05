// from server: 100% by auto
// roc 2008-06 00540300  unit: RBX::RenderBase::AggregatingSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540300
//
// 00540300  55                   push ebp
// 00540301  8bec                 mov ebp, esp
// 00540303  51                   push ecx
// 00540304  894dfc               mov dword ptr [ebp - 4], ecx
// 00540307  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054030a  e851eeffff           call 0x53f160
// 0054030f  8b4508               mov eax, dword ptr [ebp + 8]
// 00540312  83e001               and eax, 1
// 00540315  740c                 je 0x540323
// 00540317  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054031a  51                   push ecx
// 0054031b  e85a031600           call 0x6a067a
// 00540320  83c404               add esp, 4
// 00540323  8b45fc               mov eax, dword ptr [ebp - 4]
// 00540326  8be5                 mov esp, ebp
// 00540328  5d                   pop ebp
// 00540329  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
