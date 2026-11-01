// from server: 100% by auto
// roc 2009-12 00884590  unit: XTPPaintThemes::CXTPOffice2003Theme  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00884590
//
// 00884590  56                   push esi
// 00884591  57                   push edi
// 00884592  8bf9                 mov edi, ecx
// 00884594  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00884598  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0088459b  83f8ff               cmp eax, -1
// 0088459e  7505                 jne 0x8845a5
// 008845a0  8b5114               mov edx, dword ptr [ecx + 0x14]
// 008845a3  eb02                 jmp 0x8845a7
// 008845a5  8bd0                 mov edx, eax
// 008845a7  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008845aa  83f8ff               cmp eax, -1
// 008845ad  7503                 jne 0x8845b2
// 008845af  8b4108               mov eax, dword ptr [ecx + 8]
// 008845b2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008845b6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008845ba  6a00                 push 0
// 008845bc  51                   push ecx
// 008845bd  52                   push edx
// 008845be  50                   push eax
// 008845bf  8d542420             lea edx, [esp + 0x20]
// 008845c3  52                   push edx
// 008845c4  56                   push esi
// 008845c5  8bcf                 mov ecx, edi
// 008845c7  e8a499f7ff           call 0x7fdf70
// 008845cc  8b442420             mov eax, dword ptr [esp + 0x20]
// 008845d0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008845d4  8b542414             mov edx, dword ptr [esp + 0x14]
// 008845d8  50                   push eax
// 008845d9  50                   push eax
// 008845da  83ec10               sub esp, 0x10
// 008845dd  8bc4                 mov eax, esp
// 008845df  8908                 mov dword ptr [eax], ecx
// 008845e1  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008845e5  895004               mov dword ptr [eax + 4], edx
// 008845e8  8b542434             mov edx, dword ptr [esp + 0x34]
// 008845ec  894808               mov dword ptr [eax + 8], ecx
// 008845ef  56                   push esi
// 008845f0  8bcf                 mov ecx, edi
// 008845f2  89500c               mov dword ptr [eax + 0xc], edx
// 008845f5  e84692f7ff           call 0x7fd840
// 008845fa  5f                   pop edi
// 008845fb  5e                   pop esi
// 008845fc  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?RectangleEx@CXTPOffice2003Theme@@IAEXPAVCDC@@VCRect@@HHAAVCXTPPaintManagerColorGradient@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
