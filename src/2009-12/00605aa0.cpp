// from server: 100% by auto
// roc 2009-12 00605aa0  unit: seg_00600000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605aa0
//
// 00605aa0  8b442404             mov eax, dword ptr [esp + 4]
// 00605aa4  85c0                 test eax, eax
// 00605aa6  7413                 je 0x605abb
// 00605aa8  80b82301000000       cmp byte ptr [eax + 0x123], 0
// 00605aaf  740a                 je 0x605abb
// 00605ab1  83487002             or dword ptr [eax + 0x70], 2
// 00605ab5  b807000000           mov eax, 7
// 00605aba  c3                   ret 
// 00605abb  b801000000           mov eax, 1
// 00605ac0  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_interlace_handling)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
