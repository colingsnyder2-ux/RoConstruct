// from server: 100% by auto
// roc 2012-06 0064e470  unit: seg_00640000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064e470
//
// 0064e470  8b442404             mov eax, dword ptr [esp + 4]
// 0064e474  85c0                 test eax, eax
// 0064e476  741e                 je 0x64e496
// 0064e478  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064e47c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0064e480  898844020000         mov dword ptr [eax + 0x244], ecx
// 0064e486  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064e48a  899048020000         mov dword ptr [eax + 0x248], edx
// 0064e490  89884c020000         mov dword ptr [eax + 0x24c], ecx
// 0064e496  c3                   ret 
// library libpng-1.2.22/pngmem.c (function _png_set_mem_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngmem.c
