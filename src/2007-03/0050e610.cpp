// from server: 100% by auto
// roc 2007-03 0050e610  unit: seg_00500000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e610
//
// 0050e610  dd442408             fld qword ptr [esp + 8]
// 0050e614  d9c0                 fld st(0)
// 0050e616  dd442410             fld qword ptr [esp + 0x10]
// 0050e61a  dcc9                 fmul st(1), st(0)
// 0050e61c  d9c9                 fxch st(1)
// 0050e61e  dc25a81f7900         fsub qword ptr [0x791fa8]
// 0050e624  d9e1                 fabs 
// 0050e626  dc1d18fe7900         fcomp qword ptr [0x79fe18]
// 0050e62c  dfe0                 fnstsw ax
// 0050e62e  f6c441               test ah, 0x41
// 0050e631  8b442404             mov eax, dword ptr [esp + 4]
// 0050e635  7410                 je 0x50e647
// 0050e637  8a8826010000         mov cl, byte ptr [eax + 0x126]
// 0050e63d  f6c104               test cl, 4
// 0050e640  7505                 jne 0x50e647
// 0050e642  80f903               cmp cl, 3
// 0050e645  7507                 jne 0x50e64e
// 0050e647  81487000200000       or dword ptr [eax + 0x70], 0x2000
// 0050e64e  d9985c010000         fstp dword ptr [eax + 0x15c]
// 0050e654  d99860010000         fstp dword ptr [eax + 0x160]
// 0050e65a  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_set_gamma)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
