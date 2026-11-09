// from server: 100% by auto
// roc 2009-06 005ab400  unit: RBX::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ab400
//
// 005ab400  55                   push ebp
// 005ab401  8bec                 mov ebp, esp
// 005ab403  51                   push ecx
// 005ab404  894dfc               mov dword ptr [ebp - 4], ecx
// 005ab407  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab40a  e821090000           call 0x5abd30
// 005ab40f  8be5                 mov esp, ebp
// 005ab411  5d                   pop ebp
// 005ab412  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
