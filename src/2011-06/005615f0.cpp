// from server: 100% by auto
// roc 2011-06 005615f0  unit: seg_00560000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005615f0
//
// 005615f0  8b442404             mov eax, dword ptr [esp + 4]
// 005615f4  85c0                 test eax, eax
// 005615f6  741e                 je 0x561616
// 005615f8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005615fc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00561600  898844020000         mov dword ptr [eax + 0x244], ecx
// 00561606  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056160a  899048020000         mov dword ptr [eax + 0x248], edx
// 00561610  89884c020000         mov dword ptr [eax + 0x24c], ecx
// 00561616  c3                   ret 
// library libpng-1.2.22/pngmem.c (function _png_set_mem_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngmem.c
