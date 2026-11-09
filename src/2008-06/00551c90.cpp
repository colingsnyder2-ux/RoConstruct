// from server: 100% by auto
// roc 2008-06 00551c90  unit: RBX::TextureProxyBase  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00551c90
//
// 00551c90  55                   push ebp
// 00551c91  8bec                 mov ebp, esp
// 00551c93  51                   push ecx
// 00551c94  894dfc               mov dword ptr [ebp - 4], ecx
// 00551c97  8b45fc               mov eax, dword ptr [ebp - 4]
// 00551c9a  8b4028               mov eax, dword ptr [eax + 0x28]
// 00551c9d  8be5                 mov esp, ebp
// 00551c9f  5d                   pop ebp
// 00551ca0  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?GetIndices@?$ConvexHull2@M@Wml@@QBEPBHXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
