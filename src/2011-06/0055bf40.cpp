// from server: 100% by auto
// roc 2011-06 0055bf40  unit: seg_00550000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055bf40
//
// 0055bf40  8b442404             mov eax, dword ptr [esp + 4]
// 0055bf44  85c0                 test eax, eax
// 0055bf46  7410                 je 0x55bf58
// 0055bf48  b910000000           mov ecx, 0x10
// 0055bf4d  388827010000         cmp byte ptr [eax + 0x127], cl
// 0055bf53  7503                 jne 0x55bf58
// 0055bf55  094870               or dword ptr [eax + 0x70], ecx
// 0055bf58  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_swap)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
