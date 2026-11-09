// roc 2012-06 0097d2e0  unit: boost::iostreams::zlib_error  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097d2e0
//
// 0097d2e0  55                   push ebp
// 0097d2e1  8bec                 mov ebp, esp
// 0097d2e3  51                   push ecx
// 0097d2e4  894dfc               mov dword ptr [ebp - 4], ecx
// 0097d2e7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0097d2ea  e8f102eeff           call 0x85d5e0
// 0097d2ef  8be5                 mov esp, ebp
// 0097d2f1  5d                   pop ebp
// 0097d2f2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
