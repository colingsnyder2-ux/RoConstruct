// from server: 100% by auto
// roc 2011-06 0055bf80  unit: seg_00550000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055bf80
//
// 0055bf80  8b442404             mov eax, dword ptr [esp + 4]
// 0055bf84  85c0                 test eax, eax
// 0055bf86  7413                 je 0x55bf9b
// 0055bf88  80b82301000000       cmp byte ptr [eax + 0x123], 0
// 0055bf8f  740a                 je 0x55bf9b
// 0055bf91  83487002             or dword ptr [eax + 0x70], 2
// 0055bf95  b807000000           mov eax, 7
// 0055bf9a  c3                   ret 
// 0055bf9b  b801000000           mov eax, 1
// 0055bfa0  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_interlace_handling)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
