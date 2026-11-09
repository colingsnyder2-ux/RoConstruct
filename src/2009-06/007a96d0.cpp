// from server: 100% by auto
// roc 2009-06 007a96d0  unit: XTPPaintThemes::CXTPOffice2003Theme  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a96d0
//
// 007a96d0  56                   push esi
// 007a96d1  57                   push edi
// 007a96d2  8bf9                 mov edi, ecx
// 007a96d4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a96d8  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007a96db  83f8ff               cmp eax, -1
// 007a96de  7505                 jne 0x7a96e5
// 007a96e0  8b5114               mov edx, dword ptr [ecx + 0x14]
// 007a96e3  eb02                 jmp 0x7a96e7
// 007a96e5  8bd0                 mov edx, eax
// 007a96e7  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007a96ea  83f8ff               cmp eax, -1
// 007a96ed  7503                 jne 0x7a96f2
// 007a96ef  8b4108               mov eax, dword ptr [ecx + 8]
// 007a96f2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a96f6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007a96fa  6a00                 push 0
// 007a96fc  51                   push ecx
// 007a96fd  52                   push edx
// 007a96fe  50                   push eax
// 007a96ff  8d542420             lea edx, [esp + 0x20]
// 007a9703  52                   push edx
// 007a9704  56                   push esi
// 007a9705  8bcf                 mov ecx, edi
// 007a9707  e8a499f7ff           call 0x7230b0
// 007a970c  8b442420             mov eax, dword ptr [esp + 0x20]
// 007a9710  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a9714  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a9718  50                   push eax
// 007a9719  50                   push eax
// 007a971a  83ec10               sub esp, 0x10
// 007a971d  8bc4                 mov eax, esp
// 007a971f  8908                 mov dword ptr [eax], ecx
// 007a9721  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007a9725  895004               mov dword ptr [eax + 4], edx
// 007a9728  8b542434             mov edx, dword ptr [esp + 0x34]
// 007a972c  894808               mov dword ptr [eax + 8], ecx
// 007a972f  56                   push esi
// 007a9730  8bcf                 mov ecx, edi
// 007a9732  89500c               mov dword ptr [eax + 0xc], edx
// 007a9735  e84692f7ff           call 0x722980
// 007a973a  5f                   pop edi
// 007a973b  5e                   pop esi
// 007a973c  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?RectangleEx@CXTPOffice2003Theme@@IAEXPAVCDC@@VCRect@@HHAAVCXTPPaintManagerColorGradient@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
