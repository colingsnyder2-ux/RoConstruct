// from server: 100% by auto
// roc 2009-12 00797330  unit: lua_exception  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797330
//
// 00797330  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00797334  8b412c               mov eax, dword ptr [ecx + 0x2c]
// 00797337  8b542408             mov edx, dword ptr [esp + 8]
// 0079733b  3bd0                 cmp edx, eax
// 0079733d  894c2404             mov dword ptr [esp + 4], ecx
// 00797341  7f0b                 jg 0x79734e
// 00797343  03c0                 add eax, eax
// 00797345  89442408             mov dword ptr [esp + 8], eax
// 00797349  e902ffffff           jmp 0x797250
// 0079734e  03c2                 add eax, edx
// 00797350  89442408             mov dword ptr [esp + 8], eax
// 00797354  e9f7feffff           jmp 0x797250
// library lua-5.1/ldo.c (function _luaD_growstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldo.c
