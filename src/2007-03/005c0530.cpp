// from server: 100% by auto
// roc 2007-03 005c0530  unit: seg_005c0000  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c0530
//
// 005c0530  56                   push esi
// 005c0531  8b742408             mov esi, dword ptr [esp + 8]
// 005c0535  807e0600             cmp byte ptr [esi + 6], 0
// 005c0539  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c053c  7519                 jne 0x5c0557
// 005c053e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c0542  6aff                 push -1
// 005c0544  83c0f0               add eax, -0x10
// 005c0547  50                   push eax
// 005c0548  56                   push esi
// 005c0549  e8a2fdffff           call 0x5c02f0
// 005c054e  83c40c               add esp, 0xc
// 005c0551  85c0                 test eax, eax
// 005c0553  7554                 jne 0x5c05a9
// 005c0555  eb31                 jmp 0x5c0588
// 005c0557  c6460600             mov byte ptr [esi + 6], 0
// 005c055b  8b4804               mov ecx, dword ptr [eax + 4]
// 005c055e  8b11                 mov edx, dword ptr [ecx]
// 005c0560  807a0600             cmp byte ptr [edx + 6], 0
// 005c0564  741d                 je 0x5c0583
// 005c0566  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005c056a  50                   push eax
// 005c056b  56                   push esi
// 005c056c  e8eff9ffff           call 0x5bff60
// 005c0571  83c408               add esp, 8
// 005c0574  85c0                 test eax, eax
// 005c0576  7410                 je 0x5c0588
// 005c0578  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c057b  8b5108               mov edx, dword ptr [ecx + 8]
// 005c057e  895608               mov dword ptr [esi + 8], edx
// 005c0581  eb05                 jmp 0x5c0588
// 005c0583  8b00                 mov eax, dword ptr [eax]
// 005c0585  89460c               mov dword ptr [esi + 0xc], eax
// 005c0588  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c058b  2b4e28               sub ecx, dword ptr [esi + 0x28]
// 005c058e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c0593  f7e9                 imul ecx
// 005c0595  c1fa02               sar edx, 2
// 005c0598  8bca                 mov ecx, edx
// 005c059a  c1e91f               shr ecx, 0x1f
// 005c059d  03ca                 add ecx, edx
// 005c059f  51                   push ecx
// 005c05a0  56                   push esi
// 005c05a1  e81aa10300           call 0x5fa6c0
// 005c05a6  83c408               add esp, 8
// 005c05a9  5e                   pop esi
// 005c05aa  c3                   ret 
// library lua-5.1.1/ldo.c (function _resume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
