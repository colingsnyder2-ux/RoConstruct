// from server: 100% by auto
// roc 2007-03 005099b0  unit: seg_00500000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005099b0
//
// 005099b0  837c240400           cmp dword ptr [esp + 4], 0
// 005099b5  7424                 je 0x5099db
// 005099b7  8b442408             mov eax, dword ptr [esp + 8]
// 005099bb  85c0                 test eax, eax
// 005099bd  741c                 je 0x5099db
// 005099bf  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005099c3  8b542410             mov edx, dword ptr [esp + 0x10]
// 005099c7  81480800010000       or dword ptr [eax + 8], 0x100
// 005099ce  894864               mov dword ptr [eax + 0x64], ecx
// 005099d1  8a4c2414             mov cl, byte ptr [esp + 0x14]
// 005099d5  895068               mov dword ptr [eax + 0x68], edx
// 005099d8  88486c               mov byte ptr [eax + 0x6c], cl
// 005099db  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_oFFs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
