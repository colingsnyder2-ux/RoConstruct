// from server: 100% by auto
// roc 2009-06 00583cf0  unit: seg_00580000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00583cf0
//
// 00583cf0  8b442404             mov eax, dword ptr [esp + 4]
// 00583cf4  85c0                 test eax, eax
// 00583cf6  7413                 je 0x583d0b
// 00583cf8  80b82301000000       cmp byte ptr [eax + 0x123], 0
// 00583cff  740a                 je 0x583d0b
// 00583d01  83487002             or dword ptr [eax + 0x70], 2
// 00583d05  b807000000           mov eax, 7
// 00583d0a  c3                   ret 
// 00583d0b  b801000000           mov eax, 1
// 00583d10  c3                   ret 
// library libpng-1.2.16/pngtrans.c (function _png_set_interlace_handling)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngtrans.c
