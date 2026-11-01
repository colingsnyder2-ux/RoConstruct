// from server: 100% by auto
// roc 2007-03 005c0190  unit: seg_005c0000  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c0190
//
// 005c0190  8b4628               mov eax, dword ptr [esi + 0x28]
// 005c0193  894614               mov dword ptr [esi + 0x14], eax
// 005c0196  8b00                 mov eax, dword ptr [eax]
// 005c0198  57                   push edi
// 005c0199  50                   push eax
// 005c019a  56                   push esi
// 005c019b  89460c               mov dword ptr [esi + 0xc], eax
// 005c019e  e8cdc80300           call 0x5fca70
// 005c01a3  8b460c               mov eax, dword ptr [esi + 0xc]
// 005c01a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c01aa  50                   push eax
// 005c01ab  51                   push ecx
// 005c01ac  56                   push esi
// 005c01ad  e8cef7ffff           call 0x5bf980
// 005c01b2  33ff                 xor edi, edi
// 005c01b4  83c414               add esp, 0x14
// 005c01b7  817e30204e0000       cmp dword ptr [esi + 0x30], 0x4e20
// 005c01be  66897e34             mov word ptr [esi + 0x34], di
// 005c01c2  c6463701             mov byte ptr [esi + 0x37], 1
// 005c01c6  7e2f                 jle 0x5c01f7
// 005c01c8  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c01cb  2b4e28               sub ecx, dword ptr [esi + 0x28]
// 005c01ce  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c01d3  f7e9                 imul ecx
// 005c01d5  c1fa02               sar edx, 2
// 005c01d8  8bc2                 mov eax, edx
// 005c01da  c1e81f               shr eax, 0x1f
// 005c01dd  8d4c0201             lea ecx, [edx + eax + 1]
// 005c01e1  81f9204e0000         cmp ecx, 0x4e20
// 005c01e7  7d0e                 jge 0x5c01f7
// 005c01e9  68204e0000           push 0x4e20
// 005c01ee  56                   push esi
// 005c01ef  e87cfaffff           call 0x5bfc70
// 005c01f4  83c408               add esp, 8
// 005c01f7  897e74               mov dword ptr [esi + 0x74], edi
// 005c01fa  897e70               mov dword ptr [esi + 0x70], edi
// 005c01fd  5f                   pop edi
// 005c01fe  c3                   ret 
// library lua-5.1.1/ldo.c (function _resetstack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
