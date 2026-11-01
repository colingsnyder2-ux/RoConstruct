// from server: 100% by auto
// roc 2009-06 005bc520  unit: seg_005b0000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bc520
//
// 005bc520  55                   push ebp
// 005bc521  8bec                 mov ebp, esp
// 005bc523  51                   push ecx
// 005bc524  894dfc               mov dword ptr [ebp - 4], ecx
// 005bc527  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bc52a  8b00                 mov eax, dword ptr [eax]
// 005bc52c  8be5                 mov esp, ebp
// 005bc52e  5d                   pop ebp
// 005bc52f  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?GetQuantity@?$UnorderedSet@VMTVertex@Wml@@@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
