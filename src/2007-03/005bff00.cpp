// from server: 100% by auto
// roc 2007-03 005bff00  unit: seg_005b0000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bff00
//
// 005bff00  2b4620               sub eax, dword ptr [esi + 0x20]
// 005bff03  53                   push ebx
// 005bff04  6aff                 push -1
// 005bff06  6a01                 push 1
// 005bff08  56                   push esi
// 005bff09  8bd8                 mov ebx, eax
// 005bff0b  e810feffff           call 0x5bfd20
// 005bff10  8b4614               mov eax, dword ptr [esi + 0x14]
// 005bff13  8b4804               mov ecx, dword ptr [eax + 4]
// 005bff16  8b11                 mov edx, dword ptr [ecx]
// 005bff18  83c40c               add esp, 0xc
// 005bff1b  807a0600             cmp byte ptr [edx + 6], 0
// 005bff1f  752a                 jne 0x5bff4b
// 005bff21  83781400             cmp dword ptr [eax + 0x14], 0
// 005bff25  741d                 je 0x5bff44
// 005bff27  8b4614               mov eax, dword ptr [esi + 0x14]
// 005bff2a  834014ff             add dword ptr [eax + 0x14], -1
// 005bff2e  6aff                 push -1
// 005bff30  6a04                 push 4
// 005bff32  56                   push esi
// 005bff33  e8e8fdffff           call 0x5bfd20
// 005bff38  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005bff3b  83c40c               add esp, 0xc
// 005bff3e  83791400             cmp dword ptr [ecx + 0x14], 0
// 005bff42  75e3                 jne 0x5bff27
// 005bff44  8b4614               mov eax, dword ptr [esi + 0x14]
// 005bff47  834014ff             add dword ptr [eax + 0x14], -1
// 005bff4b  8b4620               mov eax, dword ptr [esi + 0x20]
// 005bff4e  03c3                 add eax, ebx
// 005bff50  5b                   pop ebx
// 005bff51  c3                   ret 
// library lua-5.1.1/ldo.c (function _callrethooks)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
