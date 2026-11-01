// from server: 100% by auto
// roc 2007-03 005c1750  unit: seg_005c0000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1750
//
// 005c1750  56                   push esi
// 005c1751  8b742408             mov esi, dword ptr [esp + 8]
// 005c1755  68f4987b00           push 0x7b98f4
// 005c175a  6a01                 push 1
// 005c175c  56                   push esi
// 005c175d  e84e8dffff           call 0x5ba4b0
// 005c1762  8b00                 mov eax, dword ptr [eax]
// 005c1764  83c40c               add esp, 0xc
// 005c1767  85c0                 test eax, eax
// 005c1769  7515                 jne 0x5c1780
// 005c176b  6830997b00           push 0x7b9930
// 005c1770  56                   push esi
// 005c1771  e84a79ffff           call 0x5b90c0
// 005c1776  83c408               add esp, 8
// 005c1779  b801000000           mov eax, 1
// 005c177e  5e                   pop esi
// 005c177f  c3                   ret 
// 005c1780  50                   push eax
// 005c1781  6824997b00           push 0x7b9924
// 005c1786  56                   push esi
// 005c1787  e8d479ffff           call 0x5b9160
// 005c178c  83c40c               add esp, 0xc
// 005c178f  b801000000           mov eax, 1
// 005c1794  5e                   pop esi
// 005c1795  c3                   ret 
// library lua-5.1.1/liolib.c (function _io_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 liolib.c
