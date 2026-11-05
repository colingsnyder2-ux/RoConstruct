// from server: 100% by auto
// roc 2009-06 005af400  unit: RBX::TextureProxyBase  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005af400
//
// 005af400  55                   push ebp
// 005af401  8bec                 mov ebp, esp
// 005af403  51                   push ecx
// 005af404  894dfc               mov dword ptr [ebp - 4], ecx
// 005af407  8b45fc               mov eax, dword ptr [ebp - 4]
// 005af40a  8b4028               mov eax, dword ptr [eax + 0x28]
// 005af40d  8be5                 mov esp, ebp
// 005af40f  5d                   pop ebp
// 005af410  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?GetIndices@?$ConvexHull2@M@Wml@@QBEPBHXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
