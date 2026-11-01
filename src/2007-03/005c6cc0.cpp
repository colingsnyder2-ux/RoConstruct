// from server: 100% by auto
// roc 2007-03 005c6cc0  unit: seg_005c0000  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6cc0
//
// 005c6cc0  56                   push esi
// 005c6cc1  8b742408             mov esi, dword ptr [esp + 8]
// 005c6cc5  68b0a47b00           push 0x7ba4b0
// 005c6cca  6a02                 push 2
// 005c6ccc  56                   push esi
// 005c6ccd  e80e2fffff           call 0x5b9be0
// 005c6cd2  6a01                 push 1
// 005c6cd4  56                   push esi
// 005c6cd5  e8361fffff           call 0x5b8c10
// 005c6cda  6a01                 push 1
// 005c6cdc  6a00                 push 0
// 005c6cde  56                   push esi
// 005c6cdf  e87c2affff           call 0x5b9760
// 005c6ce4  6aff                 push -1
// 005c6ce6  56                   push esi
// 005c6ce7  e8541fffff           call 0x5b8c40
// 005c6cec  83c428               add esp, 0x28
// 005c6cef  85c0                 test eax, eax
// 005c6cf1  750e                 jne 0x5c6d01
// 005c6cf3  8b442410             mov eax, dword ptr [esp + 0x10]
// 005c6cf7  c70000000000         mov dword ptr [eax], 0
// 005c6cfd  33c0                 xor eax, eax
// 005c6cff  5e                   pop esi
// 005c6d00  c3                   ret 
// 005c6d01  6aff                 push -1
// 005c6d03  56                   push esi
// 005c6d04  e8e71fffff           call 0x5b8cf0
// 005c6d09  83c408               add esp, 8
// 005c6d0c  85c0                 test eax, eax
// 005c6d0e  741a                 je 0x5c6d2a
// 005c6d10  6a03                 push 3
// 005c6d12  56                   push esi
// 005c6d13  e8381effff           call 0x5b8b50
// 005c6d18  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005c6d1c  51                   push ecx
// 005c6d1d  6a03                 push 3
// 005c6d1f  56                   push esi
// 005c6d20  e82b21ffff           call 0x5b8e50
// 005c6d25  83c414               add esp, 0x14
// 005c6d28  5e                   pop esi
// 005c6d29  c3                   ret 
// 005c6d2a  6888a47b00           push 0x7ba488
// 005c6d2f  56                   push esi
// 005c6d30  e81b2effff           call 0x5b9b50
// 005c6d35  83c408               add esp, 8
// 005c6d38  33c0                 xor eax, eax
// 005c6d3a  5e                   pop esi
// 005c6d3b  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _generic_reader)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
