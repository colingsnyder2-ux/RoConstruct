// from server: 100% by auto
// roc 2011-06 00801f90  unit: boost::iostreams::zlib_error  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00801f90
//
// 00801f90  55                   push ebp
// 00801f91  8bec                 mov ebp, esp
// 00801f93  51                   push ecx
// 00801f94  894dfc               mov dword ptr [ebp - 4], ecx
// 00801f97  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00801f9a  e821000000           call 0x801fc0
// 00801f9f  8b4508               mov eax, dword ptr [ebp + 8]
// 00801fa2  83e001               and eax, 1
// 00801fa5  740c                 je 0x801fb3
// 00801fa7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00801faa  51                   push ecx
// 00801fab  e8a8800000           call 0x80a058
// 00801fb0  83c404               add esp, 4
// 00801fb3  8b45fc               mov eax, dword ptr [ebp - 4]
// 00801fb6  8be5                 mov esp, ebp
// 00801fb8  5d                   pop ebp
// 00801fb9  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
