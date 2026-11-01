// from server: 100% by auto
// roc 2011-06 00801fc0  unit: boost::iostreams::zlib_error  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00801fc0
//
// 00801fc0  55                   push ebp
// 00801fc1  8bec                 mov ebp, esp
// 00801fc3  51                   push ecx
// 00801fc4  894dfc               mov dword ptr [ebp - 4], ecx
// 00801fc7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00801fca  e821efedff           call 0x6e0ef0
// 00801fcf  8be5                 mov esp, ebp
// 00801fd1  5d                   pop ebp
// 00801fd2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
