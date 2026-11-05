// from server: 100% by auto
// roc 2009-06 005bf350  unit: RBX::AggregatingSceneManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bf350
//
// 005bf350  55                   push ebp
// 005bf351  8bec                 mov ebp, esp
// 005bf353  51                   push ecx
// 005bf354  894dfc               mov dword ptr [ebp - 4], ecx
// 005bf357  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bf35a  e8f1050000           call 0x5bf950
// 005bf35f  8be5                 mov esp, ebp
// 005bf361  5d                   pop ebp
// 005bf362  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
