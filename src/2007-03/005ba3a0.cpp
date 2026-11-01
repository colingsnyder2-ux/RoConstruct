// from server: 100% by auto
// roc 2007-03 005ba3a0  unit: seg_005b0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba3a0
//
// 005ba3a0  8b442408             mov eax, dword ptr [esp + 8]
// 005ba3a4  8b4804               mov ecx, dword ptr [eax + 4]
// 005ba3a7  85c9                 test ecx, ecx
// 005ba3a9  7503                 jne 0x5ba3ae
// 005ba3ab  33c0                 xor eax, eax
// 005ba3ad  c3                   ret 
// 005ba3ae  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005ba3b2  890a                 mov dword ptr [edx], ecx
// 005ba3b4  c7400400000000       mov dword ptr [eax + 4], 0
// 005ba3bb  8b00                 mov eax, dword ptr [eax]
// 005ba3bd  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _getS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
