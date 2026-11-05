// from server: 100% by auto
// roc 2009-06 00583cb0  unit: seg_00580000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583cb0
//
// 00583cb0  8b442404             mov eax, dword ptr [esp + 4]
// 00583cb4  85c0                 test eax, eax
// 00583cb6  7410                 je 0x583cc8
// 00583cb8  b910000000           mov ecx, 0x10
// 00583cbd  388827010000         cmp byte ptr [eax + 0x127], cl
// 00583cc3  7503                 jne 0x583cc8
// 00583cc5  094870               or dword ptr [eax + 0x70], ecx
// 00583cc8  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_swap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
