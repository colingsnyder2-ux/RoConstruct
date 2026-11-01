// from server: 100% by auto
// roc 2009-12 0091bec0  unit: RBX::AggregatingSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0091bec0
//
// 0091bec0  55                   push ebp
// 0091bec1  8bec                 mov ebp, esp
// 0091bec3  51                   push ecx
// 0091bec4  894dfc               mov dword ptr [ebp - 4], ecx
// 0091bec7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0091beca  e8c1dfffff           call 0x919e90
// 0091becf  8b4508               mov eax, dword ptr [ebp + 8]
// 0091bed2  83e001               and eax, 1
// 0091bed5  740c                 je 0x91bee3
// 0091bed7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0091beda  51                   push ecx
// 0091bedb  e87a79edff           call 0x7f385a
// 0091bee0  83c404               add esp, 4
// 0091bee3  8b45fc               mov eax, dword ptr [ebp - 4]
// 0091bee6  8be5                 mov esp, ebp
// 0091bee8  5d                   pop ebp
// 0091bee9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
