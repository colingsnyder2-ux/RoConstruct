// roc 2012-06 0097d3e0  unit: boost::iostreams::zlib_error  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097d3e0
//
// 0097d3e0  55                   push ebp
// 0097d3e1  8bec                 mov ebp, esp
// 0097d3e3  83ec08               sub esp, 8
// 0097d3e6  894df8               mov dword ptr [ebp - 8], ecx
// 0097d3e9  8b45f8               mov eax, dword ptr [ebp - 8]
// 0097d3ec  8b08                 mov ecx, dword ptr [eax]
// 0097d3ee  894dfc               mov dword ptr [ebp - 4], ecx
// 0097d3f1  8b55fc               mov edx, dword ptr [ebp - 4]
// 0097d3f4  52                   push edx
// 0097d3f5  e81a4d0000           call 0x982114
// 0097d3fa  83c404               add esp, 4
// 0097d3fd  8be5                 mov esp, ebp
// 0097d3ff  5d                   pop ebp
// 0097d400  c3                   ret 
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ??1?$_Container_base_aux_alloc_real@V?$allocator@U?$pair@HH@std@@@std@@@std@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
