// from server: 100% by auto
// roc 2007-03 0050e090  unit: seg_00500000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e090
//
// 0050e090  8b442404             mov eax, dword ptr [esp + 4]
// 0050e094  80b82301000000       cmp byte ptr [eax + 0x123], 0
// 0050e09b  740a                 je 0x50e0a7
// 0050e09d  83487002             or dword ptr [eax + 0x70], 2
// 0050e0a1  b807000000           mov eax, 7
// 0050e0a6  c3                   ret 
// 0050e0a7  b801000000           mov eax, 1
// 0050e0ac  c3                   ret 
// library libpng-1.2.7/pngtrans.c (function _png_set_interlace_handling)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngtrans.c
