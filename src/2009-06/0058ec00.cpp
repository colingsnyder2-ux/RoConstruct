// from server: 100% by auto
// roc 2009-06 0058ec00  unit: seg_00580000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ec00
//
// 0058ec00  8b442404             mov eax, dword ptr [esp + 4]
// 0058ec04  85c0                 test eax, eax
// 0058ec06  741e                 je 0x58ec26
// 0058ec08  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0058ec0c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0058ec10  898844020000         mov dword ptr [eax + 0x244], ecx
// 0058ec16  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058ec1a  899048020000         mov dword ptr [eax + 0x248], edx
// 0058ec20  89884c020000         mov dword ptr [eax + 0x24c], ecx
// 0058ec26  c3                   ret 
// library libpng-1.2.22/pngmem.c (function _png_set_mem_fn)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngmem.c
