// from server: 100% by auto
// roc 2007-03 005b9ae0  unit: seg_005b0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9ae0
//
// 005b9ae0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b9ae4  83ec64               sub esp, 0x64
// 005b9ae7  56                   push esi
// 005b9ae8  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005b9aec  8d442404             lea eax, [esp + 4]
// 005b9af0  50                   push eax
// 005b9af1  51                   push ecx
// 005b9af2  56                   push esi
// 005b9af3  e8c88b0000           call 0x5c26c0
// 005b9af8  83c40c               add esp, 0xc
// 005b9afb  85c0                 test eax, eax
// 005b9afd  7434                 je 0x5b9b33
// 005b9aff  8d542404             lea edx, [esp + 4]
// 005b9b03  52                   push edx
// 005b9b04  6830917b00           push 0x7b9130
// 005b9b09  56                   push esi
// 005b9b0a  e821970000           call 0x5c3230
// 005b9b0f  8b442424             mov eax, dword ptr [esp + 0x24]
// 005b9b13  83c40c               add esp, 0xc
// 005b9b16  85c0                 test eax, eax
// 005b9b18  7e19                 jle 0x5b9b33
// 005b9b1a  50                   push eax
// 005b9b1b  8d44242c             lea eax, [esp + 0x2c]
// 005b9b1f  50                   push eax
// 005b9b20  6828917b00           push 0x7b9128
// 005b9b25  56                   push esi
// 005b9b26  e835f6ffff           call 0x5b9160
// 005b9b2b  83c410               add esp, 0x10
// 005b9b2e  5e                   pop esi
// 005b9b2f  83c464               add esp, 0x64
// 005b9b32  c3                   ret 
// 005b9b33  6a00                 push 0
// 005b9b35  68ac497800           push 0x7849ac
// 005b9b3a  56                   push esi
// 005b9b3b  e840f5ffff           call 0x5b9080
// 005b9b40  83c40c               add esp, 0xc
// 005b9b43  5e                   pop esi
// 005b9b44  83c464               add esp, 0x64
// 005b9b47  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_where)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
