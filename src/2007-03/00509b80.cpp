// from server: 100% by auto
// roc 2007-03 00509b80  unit: seg_00500000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509b80
//
// 00509b80  837c240400           cmp dword ptr [esp + 4], 0
// 00509b85  742d                 je 0x509bb4
// 00509b87  8b442408             mov eax, dword ptr [esp + 8]
// 00509b8b  85c0                 test eax, eax
// 00509b8d  7425                 je 0x509bb4
// 00509b8f  dd442410             fld qword ptr [esp + 0x10]
// 00509b93  8a4c240c             mov cl, byte ptr [esp + 0xc]
// 00509b97  81480800400000       or dword ptr [eax + 8], 0x4000
// 00509b9e  dd98e0000000         fstp qword ptr [eax + 0xe0]
// 00509ba4  dd442418             fld qword ptr [esp + 0x18]
// 00509ba8  8888dc000000         mov byte ptr [eax + 0xdc], cl
// 00509bae  dd98e8000000         fstp qword ptr [eax + 0xe8]
// 00509bb4  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_sCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
