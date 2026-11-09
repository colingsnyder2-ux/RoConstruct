// from server: 100% by auto
// roc 2007-08 005c5fb0  unit: lua_exception  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5fb0
//
// 005c5fb0  8b4628               mov eax, dword ptr [esi + 0x28]
// 005c5fb3  894614               mov dword ptr [esi + 0x14], eax
// 005c5fb6  8b00                 mov eax, dword ptr [eax]
// 005c5fb8  57                   push edi
// 005c5fb9  50                   push eax
// 005c5fba  56                   push esi
// 005c5fbb  89460c               mov dword ptr [esi + 0xc], eax
// 005c5fbe  e8fdd00400           call 0x6130c0
// 005c5fc3  8b460c               mov eax, dword ptr [esi + 0xc]
// 005c5fc6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c5fca  50                   push eax
// 005c5fcb  51                   push ecx
// 005c5fcc  56                   push esi
// 005c5fcd  e8cef7ffff           call 0x5c57a0
// 005c5fd2  33ff                 xor edi, edi
// 005c5fd4  83c414               add esp, 0x14
// 005c5fd7  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 005c5fde  66897e34             mov word ptr [esi + 0x34], di
// 005c5fe2  c6463701             mov byte ptr [esi + 0x37], 1
// 005c5fe6  7e2f                 jle 0x5c6017
// 005c5fe8  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c5feb  2b4e28               sub ecx, dword ptr [esi + 0x28]
// 005c5fee  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c5ff3  f7e9                 imul ecx
// 005c5ff5  c1fa02               sar edx, 2
// 005c5ff8  8bc2                 mov eax, edx
// 005c5ffa  c1e81f               shr eax, 0x1f
// 005c5ffd  8d4c0201             lea ecx, [edx + eax + 1]
// 005c6001  81f9204e0000         cmp ecx, 0x4e20
// 005c6007  7d0e                 jge 0x5c6017
// 005c6009  68204e0000           push 0x4e20
// 005c600e  56                   push esi
// 005c600f  e87cfaffff           call 0x5c5a90
// 005c6014  83c408               add esp, 8
// 005c6017  897e74               mov dword ptr [esi + 0x74], edi
// 005c601a  897e70               mov dword ptr [esi + 0x70], edi
// 005c601d  5f                   pop edi
// 005c601e  c3                   ret 
// library lua-5.1.2/ldo.c (function _resetstack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
