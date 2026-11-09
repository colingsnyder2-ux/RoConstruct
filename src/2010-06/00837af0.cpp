// from server: 100% by auto
// roc 2010-06 00837af0  unit: XTPPaintThemes::CXTPOffice2003Theme  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00837af0
//
// 00837af0  56                   push esi
// 00837af1  57                   push edi
// 00837af2  8bf9                 mov edi, ecx
// 00837af4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00837af8  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00837afb  83f8ff               cmp eax, -1
// 00837afe  7505                 jne 0x837b05
// 00837b00  8b5114               mov edx, dword ptr [ecx + 0x14]
// 00837b03  eb02                 jmp 0x837b07
// 00837b05  8bd0                 mov edx, eax
// 00837b07  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00837b0a  83f8ff               cmp eax, -1
// 00837b0d  7503                 jne 0x837b12
// 00837b0f  8b4108               mov eax, dword ptr [ecx + 8]
// 00837b12  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00837b16  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00837b1a  6a00                 push 0
// 00837b1c  51                   push ecx
// 00837b1d  52                   push edx
// 00837b1e  50                   push eax
// 00837b1f  8d542420             lea edx, [esp + 0x20]
// 00837b23  52                   push edx
// 00837b24  56                   push esi
// 00837b25  8bcf                 mov ecx, edi
// 00837b27  e8145ff7ff           call 0x7ada40
// 00837b2c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00837b30  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00837b34  8b542414             mov edx, dword ptr [esp + 0x14]
// 00837b38  50                   push eax
// 00837b39  50                   push eax
// 00837b3a  83ec10               sub esp, 0x10
// 00837b3d  8bc4                 mov eax, esp
// 00837b3f  8908                 mov dword ptr [eax], ecx
// 00837b41  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00837b45  895004               mov dword ptr [eax + 4], edx
// 00837b48  8b542434             mov edx, dword ptr [esp + 0x34]
// 00837b4c  894808               mov dword ptr [eax + 8], ecx
// 00837b4f  56                   push esi
// 00837b50  8bcf                 mov ecx, edi
// 00837b52  89500c               mov dword ptr [eax + 0xc], edx
// 00837b55  e8b657f7ff           call 0x7ad310
// 00837b5a  5f                   pop edi
// 00837b5b  5e                   pop esi
// 00837b5c  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?RectangleEx@CXTPOffice2003Theme@@IAEXPAVCDC@@VCRect@@HHAAVCXTPPaintManagerColorGradient@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
