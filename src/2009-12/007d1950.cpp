// from server: 100% by auto
// roc 2009-12 007d1950  unit: seg_007d0000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1950
//
// 007d1950  8b5130               mov edx, dword ptr [ecx + 0x30]
// 007d1953  50                   push eax
// 007d1954  52                   push edx
// 007d1955  e846a90000           call 0x7dc2a0
// 007d195a  83c9ff               or ecx, 0xffffffff
// 007d195d  83c408               add esp, 8
// 007d1960  894e10               mov dword ptr [esi + 0x10], ecx
// 007d1963  894e14               mov dword ptr [esi + 0x14], ecx
// 007d1966  c70604000000         mov dword ptr [esi], 4
// 007d196c  894608               mov dword ptr [esi + 8], eax
// 007d196f  c3                   ret 
// library lua-5.1/lparser.c (function _codestring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
