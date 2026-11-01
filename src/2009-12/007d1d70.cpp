// from server: 100% by auto
// roc 2009-12 007d1d70  unit: seg_007d0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1d70
//
// 007d1d70  56                   push esi
// 007d1d71  57                   push edi
// 007d1d72  8b7830               mov edi, dword ptr [eax + 0x30]
// 007d1d75  8b01                 mov eax, dword ptr [ecx]
// 007d1d77  8bf2                 mov esi, edx
// 007d1d79  2b74240c             sub esi, dword ptr [esp + 0xc]
// 007d1d7d  83f80d               cmp eax, 0xd
// 007d1d80  7431                 je 0x7d1db3
// 007d1d82  83f80e               cmp eax, 0xe
// 007d1d85  742c                 je 0x7d1db3
// 007d1d87  85c0                 test eax, eax
// 007d1d89  740a                 je 0x7d1d95
// 007d1d8b  51                   push ecx
// 007d1d8c  57                   push edi
// 007d1d8d  e87eae0000           call 0x7dcc10
// 007d1d92  83c408               add esp, 8
// 007d1d95  85f6                 test esi, esi
// 007d1d97  7e3c                 jle 0x7d1dd5
// 007d1d99  53                   push ebx
// 007d1d9a  8b5f24               mov ebx, dword ptr [edi + 0x24]
// 007d1d9d  56                   push esi
// 007d1d9e  57                   push edi
// 007d1d9f  e8bca30000           call 0x7dc160
// 007d1da4  56                   push esi
// 007d1da5  53                   push ebx
// 007d1da6  57                   push edi
// 007d1da7  e844a90000           call 0x7dc6f0
// 007d1dac  83c414               add esp, 0x14
// 007d1daf  5b                   pop ebx
// 007d1db0  5f                   pop edi
// 007d1db1  5e                   pop esi
// 007d1db2  c3                   ret 
// 007d1db3  83c601               add esi, 1
// 007d1db6  7902                 jns 0x7d1dba
// 007d1db8  33f6                 xor esi, esi
// 007d1dba  56                   push esi
// 007d1dbb  51                   push ecx
// 007d1dbc  57                   push edi
// 007d1dbd  e83ea50000           call 0x7dc300
// 007d1dc2  83c40c               add esp, 0xc
// 007d1dc5  83fe01               cmp esi, 1
// 007d1dc8  7e0b                 jle 0x7d1dd5
// 007d1dca  4e                   dec esi
// 007d1dcb  56                   push esi
// 007d1dcc  57                   push edi
// 007d1dcd  e88ea30000           call 0x7dc160
// 007d1dd2  83c408               add esp, 8
// 007d1dd5  5f                   pop edi
// 007d1dd6  5e                   pop esi
// 007d1dd7  c3                   ret 
// library lua-5.1/lparser.c (function _adjust_assign)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
