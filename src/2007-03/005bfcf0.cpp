// from server: 100% by auto
// roc 2007-03 005bfcf0  unit: seg_005b0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfcf0
//
// 005bfcf0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005bfcf4  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 005bfcf7  8b542408             mov edx, dword ptr [esp + 8]
// 005bfcfb  3bd0                 cmp edx, eax
// 005bfcfd  894c2404             mov dword ptr [esp + 4], ecx
// 005bfd01  7f0b                 jg 0x5bfd0e
// 005bfd03  03c0                 add eax, eax
// 005bfd05  89442408             mov dword ptr [esp + 8], eax
// 005bfd09  e902ffffff           jmp 0x5bfc10
// 005bfd0e  03c2                 add eax, edx
// 005bfd10  89442408             mov dword ptr [esp + 8], eax
// 005bfd14  e9f7feffff           jmp 0x5bfc10
// library lua-5.1.1/ldo.c (function _luaD_growstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
