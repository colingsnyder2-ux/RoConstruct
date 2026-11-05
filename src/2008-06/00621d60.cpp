// from server: 100% by auto
// roc 2008-06 00621d60  unit: lua_exception  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621d60
//
// 00621d60  2b4620               sub eax, dword ptr [esi + 0x20]
// 00621d63  53                   push ebx
// 00621d64  6aff                 push -1
// 00621d66  6a01                 push 1
// 00621d68  56                   push esi
// 00621d69  8bd8                 mov ebx, eax
// 00621d6b  e810feffff           call 0x621b80
// 00621d70  8b4614               mov eax, dword ptr [esi + 0x14]
// 00621d73  8b4804               mov ecx, dword ptr [eax + 4]
// 00621d76  8b11                 mov edx, dword ptr [ecx]
// 00621d78  83c40c               add esp, 0xc
// 00621d7b  807a0600             cmp byte ptr [edx + 6], 0
// 00621d7f  7528                 jne 0x621da9
// 00621d81  83781400             cmp dword ptr [eax + 0x14], 0
// 00621d85  741c                 je 0x621da3
// 00621d87  8b4614               mov eax, dword ptr [esi + 0x14]
// 00621d8a  ff4814               dec dword ptr [eax + 0x14]
// 00621d8d  6aff                 push -1
// 00621d8f  6a04                 push 4
// 00621d91  56                   push esi
// 00621d92  e8e9fdffff           call 0x621b80
// 00621d97  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00621d9a  83c40c               add esp, 0xc
// 00621d9d  83791400             cmp dword ptr [ecx + 0x14], 0
// 00621da1  75e4                 jne 0x621d87
// 00621da3  8b4614               mov eax, dword ptr [esi + 0x14]
// 00621da6  ff4814               dec dword ptr [eax + 0x14]
// 00621da9  8b4620               mov eax, dword ptr [esi + 0x20]
// 00621dac  03c3                 add eax, ebx
// 00621dae  5b                   pop ebx
// 00621daf  c3                   ret 
// library lua-5.1.2/ldo.c (function _callrethooks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
