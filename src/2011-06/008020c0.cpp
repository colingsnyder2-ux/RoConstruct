// from server: 100% by auto
// roc 2011-06 008020c0  unit: boost::iostreams::zlib_error  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008020c0
//
// 008020c0  55                   push ebp
// 008020c1  8bec                 mov ebp, esp
// 008020c3  83ec08               sub esp, 8
// 008020c6  894df8               mov dword ptr [ebp - 8], ecx
// 008020c9  8b45f8               mov eax, dword ptr [ebp - 8]
// 008020cc  8b08                 mov ecx, dword ptr [eax]
// 008020ce  894dfc               mov dword ptr [ebp - 4], ecx
// 008020d1  8b55fc               mov edx, dword ptr [ebp - 4]
// 008020d4  52                   push edx
// 008020d5  e87e7f0000           call 0x80a058
// 008020da  83c404               add esp, 4
// 008020dd  8be5                 mov esp, ebp
// 008020df  5d                   pop ebp
// 008020e0  c3                   ret 
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ??1?$_Container_base_aux_alloc_real@V?$allocator@U?$pair@HH@std@@@std@@@std@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
