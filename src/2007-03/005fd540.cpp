// from server: 100% by auto
// roc 2007-03 005fd540  unit: seg_005f0000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd540
//
// 005fd540  8b5130               mov edx, dword ptr [ecx + 0x30]
// 005fd543  50                   push eax
// 005fd544  52                   push edx
// 005fd545  e8d6720100           call 0x614820
// 005fd54a  83c9ff               or ecx, 0xffffffff
// 005fd54d  83c408               add esp, 8
// 005fd550  894e10               mov dword ptr [esi + 0x10], ecx
// 005fd553  894e14               mov dword ptr [esi + 0x14], ecx
// 005fd556  c70604000000         mov dword ptr [esi], 4
// 005fd55c  894608               mov dword ptr [esi + 8], eax
// 005fd55f  c3                   ret 
// library lua-5.1.1/lparser.c (function _codestring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
