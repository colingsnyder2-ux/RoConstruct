// from server: 100% by auto
// roc 2009-06 005abe80  unit: RBX::Mesh  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005abe80
//
// 005abe80  55                   push ebp
// 005abe81  8bec                 mov ebp, esp
// 005abe83  51                   push ecx
// 005abe84  894dfc               mov dword ptr [ebp - 4], ecx
// 005abe87  8b45fc               mov eax, dword ptr [ebp - 4]
// 005abe8a  8b401c               mov eax, dword ptr [eax + 0x1c]
// 005abe8d  8be5                 mov esp, ebp
// 005abe8f  5d                   pop ebp
// 005abe90  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?GetQuantity@?$ConvexHull2@M@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
