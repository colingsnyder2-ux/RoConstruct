// from server: 100% by auto
// roc 2009-12 00610c30  unit: seg_00610000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00610c30
//
// 00610c30  8b442404             mov eax, dword ptr [esp + 4]
// 00610c34  85c0                 test eax, eax
// 00610c36  741e                 je 0x610c56
// 00610c38  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00610c3c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00610c40  898844020000         mov dword ptr [eax + 0x244], ecx
// 00610c46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00610c4a  899048020000         mov dword ptr [eax + 0x248], edx
// 00610c50  89884c020000         mov dword ptr [eax + 0x24c], ecx
// 00610c56  c3                   ret 
// library libpng-1.2.22/pngmem.c (function _png_set_mem_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngmem.c
