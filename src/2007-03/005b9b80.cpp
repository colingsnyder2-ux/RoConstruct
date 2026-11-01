// from server: 100% by auto
// roc 2007-03 005b9b80  unit: seg_005b0000  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9b80
//
// 005b9b80  56                   push esi
// 005b9b81  8b742408             mov esi, dword ptr [esp + 8]
// 005b9b85  57                   push edi
// 005b9b86  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b9b8a  57                   push edi
// 005b9b8b  68f0d8ffff           push 0xffffd8f0
// 005b9b90  56                   push esi
// 005b9b91  e83af7ffff           call 0x5b92d0
// 005b9b96  6aff                 push -1
// 005b9b98  56                   push esi
// 005b9b99  e8a2f0ffff           call 0x5b8c40
// 005b9b9e  83c414               add esp, 0x14
// 005b9ba1  85c0                 test eax, eax
// 005b9ba3  7405                 je 0x5b9baa
// 005b9ba5  5f                   pop edi
// 005b9ba6  33c0                 xor eax, eax
// 005b9ba8  5e                   pop esi
// 005b9ba9  c3                   ret 
// 005b9baa  6afe                 push -2
// 005b9bac  56                   push esi
// 005b9bad  e8aeeeffff           call 0x5b8a60
// 005b9bb2  6a00                 push 0
// 005b9bb4  6a00                 push 0
// 005b9bb6  56                   push esi
// 005b9bb7  e8f4f7ffff           call 0x5b93b0
// 005b9bbc  6aff                 push -1
// 005b9bbe  56                   push esi
// 005b9bbf  e84cf0ffff           call 0x5b8c10
// 005b9bc4  57                   push edi
// 005b9bc5  68f0d8ffff           push 0xffffd8f0
// 005b9bca  56                   push esi
// 005b9bcb  e820f9ffff           call 0x5b94f0
// 005b9bd0  83c428               add esp, 0x28
// 005b9bd3  5f                   pop edi
// 005b9bd4  b801000000           mov eax, 1
// 005b9bd9  5e                   pop esi
// 005b9bda  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_newmetatable)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
