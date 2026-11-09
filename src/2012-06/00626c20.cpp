// roc 2012-06 00626c20  unit: seg_00620000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00626c20
//
// 00626c20  55                   push ebp
// 00626c21  8bec                 mov ebp, esp
// 00626c23  51                   push ecx
// 00626c24  894dfc               mov dword ptr [ebp - 4], ecx
// 00626c27  8b45fc               mov eax, dword ptr [ebp - 4]
// 00626c2a  8b00                 mov eax, dword ptr [eax]
// 00626c2c  8be5                 mov esp, ebp
// 00626c2e  5d                   pop ebp
// 00626c2f  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?GetQuantity@?$UnorderedSet@VMTVertex@Wml@@@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
