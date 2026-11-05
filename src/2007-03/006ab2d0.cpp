// from server: 100% by auto
// roc 2007-03 006ab2d0  unit: seg_006a0000  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006ab2d0
//
// 006ab2d0  56                   push esi
// 006ab2d1  57                   push edi
// 006ab2d2  8bf9                 mov edi, ecx
// 006ab2d4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006ab2d8  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006ab2db  83f8ff               cmp eax, -1
// 006ab2de  7505                 jne 0x6ab2e5
// 006ab2e0  8b5114               mov edx, dword ptr [ecx + 0x14]
// 006ab2e3  eb02                 jmp 0x6ab2e7
// 006ab2e5  8bd0                 mov edx, eax
// 006ab2e7  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006ab2ea  83f8ff               cmp eax, -1
// 006ab2ed  7503                 jne 0x6ab2f2
// 006ab2ef  8b4108               mov eax, dword ptr [ecx + 8]
// 006ab2f2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006ab2f6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006ab2fa  6a00                 push 0
// 006ab2fc  51                   push ecx
// 006ab2fd  52                   push edx
// 006ab2fe  50                   push eax
// 006ab2ff  8d542420             lea edx, [esp + 0x20]
// 006ab303  52                   push edx
// 006ab304  56                   push esi
// 006ab305  8bcf                 mov ecx, edi
// 006ab307  e8d476f8ff           call 0x6329e0
// 006ab30c  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ab310  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ab314  8b542414             mov edx, dword ptr [esp + 0x14]
// 006ab318  50                   push eax
// 006ab319  50                   push eax
// 006ab31a  83ec10               sub esp, 0x10
// 006ab31d  8bc4                 mov eax, esp
// 006ab31f  8908                 mov dword ptr [eax], ecx
// 006ab321  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006ab325  895004               mov dword ptr [eax + 4], edx
// 006ab328  8b542434             mov edx, dword ptr [esp + 0x34]
// 006ab32c  894808               mov dword ptr [eax + 8], ecx
// 006ab32f  56                   push esi
// 006ab330  8bcf                 mov ecx, edi
// 006ab332  89500c               mov dword ptr [eax + 0xc], edx
// 006ab335  e85670f8ff           call 0x632390
// 006ab33a  5f                   pop edi
// 006ab33b  5e                   pop esi
// 006ab33c  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?RectangleEx@CXTPOffice2003Theme@@IAEXPAVCDC@@VCRect@@HHAAVCXTPPaintManagerColorGradient@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
