// from server: 100% by auto
// roc 2009-12 007cdc10  unit: RBX::PartDropTool  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdc10
//
// 007cdc10  53                   push ebx
// 007cdc11  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007cdc15  56                   push esi
// 007cdc16  8b7310               mov esi, dword ptr [ebx + 0x10]
// 007cdc19  8b4654               mov eax, dword ptr [esi + 0x54]
// 007cdc1c  57                   push edi
// 007cdc1d  8d3c80               lea edi, [eax + eax*4]
// 007cdc20  03ff                 add edi, edi
// 007cdc22  7505                 jne 0x7cdc29
// 007cdc24  bffeffff7f           mov edi, 0x7ffffffe
// 007cdc29  8b4644               mov eax, dword ptr [esi + 0x44]
// 007cdc2c  2b4640               sub eax, dword ptr [esi + 0x40]
// 007cdc2f  01464c               add dword ptr [esi + 0x4c], eax
// 007cdc32  8bc3                 mov eax, ebx
// 007cdc34  e8d7feffff           call 0x7cdb10
// 007cdc39  2bf8                 sub edi, eax
// 007cdc3b  807e1500             cmp byte ptr [esi + 0x15], 0
// 007cdc3f  7436                 je 0x7cdc77
// 007cdc41  85ff                 test edi, edi
// 007cdc43  7fed                 jg 0x7cdc32
// 007cdc45  807e1500             cmp byte ptr [esi + 0x15], 0
// 007cdc49  742c                 je 0x7cdc77
// 007cdc4b  8b464c               mov eax, dword ptr [esi + 0x4c]
// 007cdc4e  3d00040000           cmp eax, 0x400
// 007cdc53  7310                 jae 0x7cdc65
// 007cdc55  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 007cdc58  81c100040000         add ecx, 0x400
// 007cdc5e  5f                   pop edi
// 007cdc5f  894e40               mov dword ptr [esi + 0x40], ecx
// 007cdc62  5e                   pop esi
// 007cdc63  5b                   pop ebx
// 007cdc64  c3                   ret 
// 007cdc65  8b5644               mov edx, dword ptr [esi + 0x44]
// 007cdc68  0500fcffff           add eax, 0xfffffc00
// 007cdc6d  5f                   pop edi
// 007cdc6e  89464c               mov dword ptr [esi + 0x4c], eax
// 007cdc71  895640               mov dword ptr [esi + 0x40], edx
// 007cdc74  5e                   pop esi
// 007cdc75  5b                   pop ebx
// 007cdc76  c3                   ret 
// 007cdc77  b81f85eb51           mov eax, 0x51eb851f
// 007cdc7c  f76648               mul dword ptr [esi + 0x48]
// 007cdc7f  c1ea05               shr edx, 5
// 007cdc82  0faf5650             imul edx, dword ptr [esi + 0x50]
// 007cdc86  5f                   pop edi
// 007cdc87  895640               mov dword ptr [esi + 0x40], edx
// 007cdc8a  5e                   pop esi
// 007cdc8b  5b                   pop ebx
// 007cdc8c  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_step)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
