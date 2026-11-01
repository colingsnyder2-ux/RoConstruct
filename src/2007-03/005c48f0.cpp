// from server: 100% by auto
// roc 2007-03 005c48f0  unit: seg_005c0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c48f0
//
// 005c48f0  51                   push ecx
// 005c48f1  56                   push esi
// 005c48f2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c48f6  8d442404             lea eax, [esp + 4]
// 005c48fa  50                   push eax
// 005c48fb  6a01                 push 1
// 005c48fd  56                   push esi
// 005c48fe  e8bd5cffff           call 0x5ba5c0
// 005c4903  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c4907  51                   push ecx
// 005c4908  56                   push esi
// 005c4909  e85247ffff           call 0x5b9060
// 005c490e  83c414               add esp, 0x14
// 005c4911  b801000000           mov eax, 1
// 005c4916  5e                   pop esi
// 005c4917  59                   pop ecx
// 005c4918  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_len)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
