// from server: 100% by auto
// roc 2007-03 006a4160  unit: seg_006a0000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006a4160
//
// 006a4160  837c241800           cmp dword ptr [esp + 0x18], 0
// 006a4165  56                   push esi
// 006a4166  57                   push edi
// 006a4167  8bf9                 mov edi, ecx
// 006a4169  0f8588000000         jne 0x6a41f7
// 006a416f  6aff                 push -1
// 006a4171  6aff                 push -1
// 006a4173  8d442418             lea eax, [esp + 0x18]
// 006a4177  50                   push eax
// 006a4178  ff159ced7700         call dword ptr [0x77ed9c]
// 006a417e  8b442424             mov eax, dword ptr [esp + 0x24]
// 006a4182  83f802               cmp eax, 2
// 006a4185  7409                 je 0x6a4190
// 006a4187  83f803               cmp eax, 3
// 006a418a  7404                 je 0x6a4190
// 006a418c  33c9                 xor ecx, ecx
// 006a418e  eb05                 jmp 0x6a4195
// 006a4190  b901000000           mov ecx, 1
// 006a4195  83f802               cmp eax, 2
// 006a4198  7409                 je 0x6a41a3
// 006a419a  83f803               cmp eax, 3
// 006a419d  7404                 je 0x6a41a3
// 006a419f  33c0                 xor eax, eax
// 006a41a1  eb05                 jmp 0x6a41a8
// 006a41a3  b801000000           mov eax, 1
// 006a41a8  33d2                 xor edx, edx
// 006a41aa  85c9                 test ecx, ecx
// 006a41ac  0f94c2               sete dl
// 006a41af  33c9                 xor ecx, ecx
// 006a41b1  85c0                 test eax, eax
// 006a41b3  0f94c1               sete cl
// 006a41b6  8d149510000000       lea edx, [edx*4 + 0x10]
// 006a41bd  52                   push edx
// 006a41be  8b542414             mov edx, dword ptr [esp + 0x14]
// 006a41c2  8d0c8d10000000       lea ecx, [ecx*4 + 0x10]
// 006a41c9  51                   push ecx
// 006a41ca  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006a41ce  83ec10               sub esp, 0x10
// 006a41d1  8bc4                 mov eax, esp
// 006a41d3  8910                 mov dword ptr [eax], edx
// 006a41d5  8b542430             mov edx, dword ptr [esp + 0x30]
// 006a41d9  894804               mov dword ptr [eax + 4], ecx
// 006a41dc  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006a41e0  895008               mov dword ptr [eax + 8], edx
// 006a41e3  8b542424             mov edx, dword ptr [esp + 0x24]
// 006a41e7  89480c               mov dword ptr [eax + 0xc], ecx
// 006a41ea  52                   push edx
// 006a41eb  8bcf                 mov ecx, edi
// 006a41ed  e89ee1f8ff           call 0x632390
// 006a41f2  5f                   pop edi
// 006a41f3  5e                   pop esi
// 006a41f4  c21c00               ret 0x1c
// 006a41f7  837c242400           cmp dword ptr [esp + 0x24], 0
// 006a41fc  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006a4200  742c                 je 0x6a422e
// 006a4202  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a4206  8b542414             mov edx, dword ptr [esp + 0x14]
// 006a420a  6a14                 push 0x14
// 006a420c  6a10                 push 0x10
// 006a420e  83ec10               sub esp, 0x10
// 006a4211  8bc4                 mov eax, esp
// 006a4213  8908                 mov dword ptr [eax], ecx
// 006a4215  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006a4219  895004               mov dword ptr [eax + 4], edx
// 006a421c  8b542434             mov edx, dword ptr [esp + 0x34]
// 006a4220  894808               mov dword ptr [eax + 8], ecx
// 006a4223  56                   push esi
// 006a4224  8bcf                 mov ecx, edi
// 006a4226  89500c               mov dword ptr [eax + 0xc], edx
// 006a4229  e862e1f8ff           call 0x632390
// 006a422e  6aff                 push -1
// 006a4230  6aff                 push -1
// 006a4232  8d442418             lea eax, [esp + 0x18]
// 006a4236  50                   push eax
// 006a4237  ff159ced7700         call dword ptr [0x77ed9c]
// 006a423d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a4241  8b542414             mov edx, dword ptr [esp + 0x14]
// 006a4245  6a0f                 push 0xf
// 006a4247  6a0f                 push 0xf
// 006a4249  83ec10               sub esp, 0x10
// 006a424c  8bc4                 mov eax, esp
// 006a424e  8908                 mov dword ptr [eax], ecx
// 006a4250  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006a4254  895004               mov dword ptr [eax + 4], edx
// 006a4257  8b542434             mov edx, dword ptr [esp + 0x34]
// 006a425b  894808               mov dword ptr [eax + 8], ecx
// 006a425e  56                   push esi
// 006a425f  8bcf                 mov ecx, edi
// 006a4261  89500c               mov dword ptr [eax + 0xc], edx
// 006a4264  e827e1f8ff           call 0x632390
// 006a4269  5f                   pop edi
// 006a426a  5e                   pop esi
// 006a426b  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawControlEditFrame@CXTPDefaultTheme@@MAEXPAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
