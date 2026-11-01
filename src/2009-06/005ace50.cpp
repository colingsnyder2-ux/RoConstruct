// from server: 100% by auto
// roc 2009-06 005ace50  unit: RBX::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ace50
//
// 005ace50  55                   push ebp
// 005ace51  8bec                 mov ebp, esp
// 005ace53  51                   push ecx
// 005ace54  894dfc               mov dword ptr [ebp - 4], ecx
// 005ace57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ace5a  e8410a0000           call 0x5ad8a0
// 005ace5f  8be5                 mov esp, ebp
// 005ace61  5d                   pop ebp
// 005ace62  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
