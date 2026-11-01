// from server: 100% by auto
// roc 2007-03 005f97b0  unit: seg_005f0000  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f97b0
//
// 005f97b0  53                   push ebx
// 005f97b1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005f97b5  56                   push esi
// 005f97b6  8b7310               mov esi, dword ptr [ebx + 0x10]
// 005f97b9  8b4654               mov eax, dword ptr [esi + 0x54]
// 005f97bc  57                   push edi
// 005f97bd  8d3c80               lea edi, [eax + eax*4]
// 005f97c0  03ff                 add edi, edi
// 005f97c2  7505                 jne 0x5f97c9
// 005f97c4  bffeffff7f           mov edi, 0x7ffffffe
// 005f97c9  8b4644               mov eax, dword ptr [esi + 0x44]
// 005f97cc  2b4640               sub eax, dword ptr [esi + 0x40]
// 005f97cf  01464c               add dword ptr [esi + 0x4c], eax
// 005f97d2  8bc3                 mov eax, ebx
// 005f97d4  e8d7feffff           call 0x5f96b0
// 005f97d9  2bf8                 sub edi, eax
// 005f97db  807e1500             cmp byte ptr [esi + 0x15], 0
// 005f97df  7436                 je 0x5f9817
// 005f97e1  85ff                 test edi, edi
// 005f97e3  7fed                 jg 0x5f97d2
// 005f97e5  807e1500             cmp byte ptr [esi + 0x15], 0
// 005f97e9  742c                 je 0x5f9817
// 005f97eb  8b464c               mov eax, dword ptr [esi + 0x4c]
// 005f97ee  3d00040000           cmp eax, 0x400
// 005f97f3  7310                 jae 0x5f9805
// 005f97f5  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 005f97f8  81c100040000         add ecx, 0x400
// 005f97fe  5f                   pop edi
// 005f97ff  894e40               mov dword ptr [esi + 0x40], ecx
// 005f9802  5e                   pop esi
// 005f9803  5b                   pop ebx
// 005f9804  c3                   ret 
// 005f9805  8b5644               mov edx, dword ptr [esi + 0x44]
// 005f9808  0500fcffff           add eax, 0xfffffc00
// 005f980d  5f                   pop edi
// 005f980e  89464c               mov dword ptr [esi + 0x4c], eax
// 005f9811  895640               mov dword ptr [esi + 0x40], edx
// 005f9814  5e                   pop esi
// 005f9815  5b                   pop ebx
// 005f9816  c3                   ret 
// 005f9817  b81f85eb51           mov eax, 0x51eb851f
// 005f981c  f76648               mul dword ptr [esi + 0x48]
// 005f981f  c1ea05               shr edx, 5
// 005f9822  0faf5650             imul edx, dword ptr [esi + 0x50]
// 005f9826  5f                   pop edi
// 005f9827  895640               mov dword ptr [esi + 0x40], edx
// 005f982a  5e                   pop esi
// 005f982b  5b                   pop ebx
// 005f982c  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_step)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
