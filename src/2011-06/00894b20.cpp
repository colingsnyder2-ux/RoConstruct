// from server: 100% by auto
// roc 2011-06 00894b20  unit: XTPPaintThemes::CXTPOffice2003Theme  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00894b20
//
// 00894b20  56                   push esi
// 00894b21  57                   push edi
// 00894b22  8bf9                 mov edi, ecx
// 00894b24  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00894b28  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00894b2b  83f8ff               cmp eax, -1
// 00894b2e  7505                 jne 0x894b35
// 00894b30  8b5114               mov edx, dword ptr [ecx + 0x14]
// 00894b33  eb02                 jmp 0x894b37
// 00894b35  8bd0                 mov edx, eax
// 00894b37  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00894b3a  83f8ff               cmp eax, -1
// 00894b3d  7503                 jne 0x894b42
// 00894b3f  8b4108               mov eax, dword ptr [ecx + 8]
// 00894b42  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00894b46  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00894b4a  6a00                 push 0
// 00894b4c  51                   push ecx
// 00894b4d  52                   push edx
// 00894b4e  50                   push eax
// 00894b4f  8d542420             lea edx, [esp + 0x20]
// 00894b53  52                   push edx
// 00894b54  56                   push esi
// 00894b55  8bcf                 mov ecx, edi
// 00894b57  e884b3f7ff           call 0x80fee0
// 00894b5c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00894b60  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00894b64  8b542414             mov edx, dword ptr [esp + 0x14]
// 00894b68  50                   push eax
// 00894b69  50                   push eax
// 00894b6a  83ec10               sub esp, 0x10
// 00894b6d  8bc4                 mov eax, esp
// 00894b6f  8908                 mov dword ptr [eax], ecx
// 00894b71  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00894b75  895004               mov dword ptr [eax + 4], edx
// 00894b78  8b542434             mov edx, dword ptr [esp + 0x34]
// 00894b7c  894808               mov dword ptr [eax + 8], ecx
// 00894b7f  56                   push esi
// 00894b80  8bcf                 mov ecx, edi
// 00894b82  89500c               mov dword ptr [eax + 0xc], edx
// 00894b85  e826acf7ff           call 0x80f7b0
// 00894b8a  5f                   pop edi
// 00894b8b  5e                   pop esi
// 00894b8c  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?RectangleEx@CXTPOffice2003Theme@@IAEXPAVCDC@@VCRect@@HHAAVCXTPPaintManagerColorGradient@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
