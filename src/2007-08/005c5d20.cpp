// from server: 100% by auto
// roc 2007-08 005c5d20  unit: lua_exception  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5d20
//
// 005c5d20  2b4620               sub eax, dword ptr [esi + 0x20]
// 005c5d23  53                   push ebx
// 005c5d24  6aff                 push -1
// 005c5d26  6a01                 push 1
// 005c5d28  56                   push esi
// 005c5d29  8bd8                 mov ebx, eax
// 005c5d2b  e810feffff           call 0x5c5b40
// 005c5d30  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c5d33  8b4804               mov ecx, dword ptr [eax + 4]
// 005c5d36  8b11                 mov edx, dword ptr [ecx]
// 005c5d38  83c40c               add esp, 0xc
// 005c5d3b  807a0600             cmp byte ptr [edx + 6], 0
// 005c5d3f  752a                 jne 0x5c5d6b
// 005c5d41  83781400             cmp dword ptr [eax + 0x14], 0
// 005c5d45  741d                 je 0x5c5d64
// 005c5d47  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c5d4a  834014ff             add dword ptr [eax + 0x14], -1
// 005c5d4e  6aff                 push -1
// 005c5d50  6a04                 push 4
// 005c5d52  56                   push esi
// 005c5d53  e8e8fdffff           call 0x5c5b40
// 005c5d58  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c5d5b  83c40c               add esp, 0xc
// 005c5d5e  83791400             cmp dword ptr [ecx + 0x14], 0
// 005c5d62  75e3                 jne 0x5c5d47
// 005c5d64  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c5d67  834014ff             add dword ptr [eax + 0x14], -1
// 005c5d6b  8b4620               mov eax, dword ptr [esi + 0x20]
// 005c5d6e  03c3                 add eax, ebx
// 005c5d70  5b                   pop ebx
// 005c5d71  c3                   ret 
// library lua-5.1.2/ldo.c (function _callrethooks)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
