// from server: 100% by auto
// roc 2008-06 0054e3a0  unit: RBX::RenderBase::Mesh  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054e3a0
//
// 0054e3a0  55                   push ebp
// 0054e3a1  8bec                 mov ebp, esp
// 0054e3a3  51                   push ecx
// 0054e3a4  894dfc               mov dword ptr [ebp - 4], ecx
// 0054e3a7  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054e3aa  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0054e3ad  8be5                 mov esp, ebp
// 0054e3af  5d                   pop ebp
// 0054e3b0  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?GetQuantity@?$ConvexHull2@M@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
