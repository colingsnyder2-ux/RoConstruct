// from server: 100% by auto
// roc 2009-12 00789d20  unit: RBX::UniversalTool  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789d20
//
// 00789d20  56                   push esi
// 00789d21  8b742408             mov esi, dword ptr [esp + 8]
// 00789d25  57                   push edi
// 00789d26  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00789d2a  57                   push edi
// 00789d2b  68f0d8ffff           push 0xffffd8f0
// 00789d30  56                   push esi
// 00789d31  e8baf2ffff           call 0x788ff0
// 00789d36  6aff                 push -1
// 00789d38  56                   push esi
// 00789d39  e852ecffff           call 0x788990
// 00789d3e  83c414               add esp, 0x14
// 00789d41  85c0                 test eax, eax
// 00789d43  7405                 je 0x789d4a
// 00789d45  5f                   pop edi
// 00789d46  33c0                 xor eax, eax
// 00789d48  5e                   pop esi
// 00789d49  c3                   ret 
// 00789d4a  6afe                 push -2
// 00789d4c  56                   push esi
// 00789d4d  e85eeaffff           call 0x7887b0
// 00789d52  6a00                 push 0
// 00789d54  6a00                 push 0
// 00789d56  56                   push esi
// 00789d57  e874f3ffff           call 0x7890d0
// 00789d5c  6aff                 push -1
// 00789d5e  56                   push esi
// 00789d5f  e8fcebffff           call 0x788960
// 00789d64  57                   push edi
// 00789d65  68f0d8ffff           push 0xffffd8f0
// 00789d6a  56                   push esi
// 00789d6b  e8c0f4ffff           call 0x789230
// 00789d70  83c428               add esp, 0x28
// 00789d73  5f                   pop edi
// 00789d74  b801000000           mov eax, 1
// 00789d79  5e                   pop esi
// 00789d7a  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_newmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
