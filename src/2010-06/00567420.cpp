// from server: 100% by auto
// roc 2010-06 00567420  unit: seg_00560000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00567420
//
// 00567420  8b442404             mov eax, dword ptr [esp + 4]
// 00567424  85c0                 test eax, eax
// 00567426  7413                 je 0x56743b
// 00567428  80b82301000000       cmp byte ptr [eax + 0x123], 0
// 0056742f  740a                 je 0x56743b
// 00567431  83487002             or dword ptr [eax + 0x70], 2
// 00567435  b807000000           mov eax, 7
// 0056743a  c3                   ret 
// 0056743b  b801000000           mov eax, 1
// 00567440  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_interlace_handling)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
