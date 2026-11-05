// from server: 100% by auto
// roc 2009-06 005abf70  unit: RBX::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005abf70
//
// 005abf70  55                   push ebp
// 005abf71  8bec                 mov ebp, esp
// 005abf73  51                   push ecx
// 005abf74  894dfc               mov dword ptr [ebp - 4], ecx
// 005abf77  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005abf7a  e8f1760000           call 0x5b3670
// 005abf7f  8be5                 mov esp, ebp
// 005abf81  5d                   pop ebp
// 005abf82  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
