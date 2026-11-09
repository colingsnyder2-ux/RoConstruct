// roc 2012-06 0097d2b0  unit: boost::iostreams::zlib_error  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097d2b0
//
// 0097d2b0  55                   push ebp
// 0097d2b1  8bec                 mov ebp, esp
// 0097d2b3  51                   push ecx
// 0097d2b4  894dfc               mov dword ptr [ebp - 4], ecx
// 0097d2b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0097d2ba  e821000000           call 0x97d2e0
// 0097d2bf  8b4508               mov eax, dword ptr [ebp + 8]
// 0097d2c2  83e001               and eax, 1
// 0097d2c5  740c                 je 0x97d2d3
// 0097d2c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0097d2ca  51                   push ecx
// 0097d2cb  e8444e0000           call 0x982114
// 0097d2d0  83c404               add esp, 4
// 0097d2d3  8b45fc               mov eax, dword ptr [ebp - 4]
// 0097d2d6  8be5                 mov esp, ebp
// 0097d2d8  5d                   pop ebp
// 0097d2d9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
