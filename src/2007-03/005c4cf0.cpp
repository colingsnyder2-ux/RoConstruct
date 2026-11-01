// from server: 100% by auto
// roc 2007-03 005c4cf0  unit: seg_005c0000  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4cf0
//
// 005c4cf0  81ec0c020000         sub esp, 0x20c
// 005c4cf6  55                   push ebp
// 005c4cf7  56                   push esi
// 005c4cf8  57                   push edi
// 005c4cf9  8bbc241c020000       mov edi, dword ptr [esp + 0x21c]
// 005c4d00  57                   push edi
// 005c4d01  e84a3dffff           call 0x5b8a50
// 005c4d06  8be8                 mov ebp, eax
// 005c4d08  8d442410             lea eax, [esp + 0x10]
// 005c4d0c  50                   push eax
// 005c4d0d  57                   push edi
// 005c4d0e  e89d52ffff           call 0x5b9fb0
// 005c4d13  be01000000           mov esi, 1
// 005c4d18  83c40c               add esp, 0xc
// 005c4d1b  3bee                 cmp ebp, esi
// 005c4d1d  7c50                 jl 0x5c4d6f
// 005c4d1f  53                   push ebx
// 005c4d20  56                   push esi
// 005c4d21  57                   push edi
// 005c4d22  e8d959ffff           call 0x5ba700
// 005c4d27  8bd8                 mov ebx, eax
// 005c4d29  0fb6cb               movzx ecx, bl
// 005c4d2c  83c408               add esp, 8
// 005c4d2f  3bcb                 cmp ecx, ebx
// 005c4d31  740f                 je 0x5c4d42
// 005c4d33  68389f7b00           push 0x7b9f38
// 005c4d38  56                   push esi
// 005c4d39  57                   push edi
// 005c4d3a  e8b156ffff           call 0x5ba3f0
// 005c4d3f  83c40c               add esp, 0xc
// 005c4d42  8d94241c020000       lea edx, [esp + 0x21c]
// 005c4d49  39542410             cmp dword ptr [esp + 0x10], edx
// 005c4d4d  720d                 jb 0x5c4d5c
// 005c4d4f  8d442410             lea eax, [esp + 0x10]
// 005c4d53  50                   push eax
// 005c4d54  e8e750ffff           call 0x5b9e40
// 005c4d59  83c404               add esp, 4
// 005c4d5c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c4d60  8819                 mov byte ptr [ecx], bl
// 005c4d62  8344241001           add dword ptr [esp + 0x10], 1
// 005c4d67  83c601               add esi, 1
// 005c4d6a  3bf5                 cmp esi, ebp
// 005c4d6c  7eb2                 jle 0x5c4d20
// 005c4d6e  5b                   pop ebx
// 005c4d6f  8d54240c             lea edx, [esp + 0xc]
// 005c4d73  52                   push edx
// 005c4d74  e86751ffff           call 0x5b9ee0
// 005c4d79  83c404               add esp, 4
// 005c4d7c  5f                   pop edi
// 005c4d7d  5e                   pop esi
// 005c4d7e  b801000000           mov eax, 1
// 005c4d83  5d                   pop ebp
// 005c4d84  81c40c020000         add esp, 0x20c
// 005c4d8a  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_char)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
