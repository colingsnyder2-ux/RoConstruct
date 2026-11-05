// from server: 100% by auto
// roc 2012-06 00648e00  unit: seg_00640000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00648e00
//
// 00648e00  8b442404             mov eax, dword ptr [esp + 4]
// 00648e04  85c0                 test eax, eax
// 00648e06  7413                 je 0x648e1b
// 00648e08  80b82301000000       cmp byte ptr [eax + 0x123], 0
// 00648e0f  740a                 je 0x648e1b
// 00648e11  83487002             or dword ptr [eax + 0x70], 2
// 00648e15  b807000000           mov eax, 7
// 00648e1a  c3                   ret 
// 00648e1b  b801000000           mov eax, 1
// 00648e20  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_interlace_handling)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
