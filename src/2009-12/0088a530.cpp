// from server: 100% by auto
// roc 2009-12 0088a530  unit: XTPPaintThemes::CXTPOfficeTheme  size: 337 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088a530
//
// 0088a530  83ec10               sub esp, 0x10
// 0088a533  837c243000           cmp dword ptr [esp + 0x30], 0
// 0088a538  53                   push ebx
// 0088a539  55                   push ebp
// 0088a53a  56                   push esi
// 0088a53b  57                   push edi
// 0088a53c  8bd9                 mov ebx, ecx
// 0088a53e  0f8422010000         je 0x88a666
// 0088a544  8b542438             mov edx, dword ptr [esp + 0x38]
// 0088a548  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0088a54c  2b542430             sub edx, dword ptr [esp + 0x30]
// 0088a550  b801000000           mov eax, 1
// 0088a555  41                   inc ecx
// 0088a556  894c2418             mov dword ptr [esp + 0x18], ecx
// 0088a55a  03d0                 add edx, eax
// 0088a55c  6a29                 push 0x29
// 0088a55e  8bcb                 mov ecx, ebx
// 0088a560  89442414             mov dword ptr [esp + 0x14], eax
// 0088a564  89442418             mov dword ptr [esp + 0x18], eax
// 0088a568  89542420             mov dword ptr [esp + 0x20], edx
// 0088a56c  e8cf30f7ff           call 0x7fd640
// 0088a571  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0088a575  50                   push eax
// 0088a576  8d442414             lea eax, [esp + 0x14]
// 0088a57a  50                   push eax
// 0088a57b  8bcd                 mov ecx, ebp
// 0088a57d  e87ca0f6ff           call 0x7f45fe
// 0088a582  6aff                 push -1
// 0088a584  6aff                 push -1
// 0088a586  8d4c2418             lea ecx, [esp + 0x18]
// 0088a58a  51                   push ecx
// 0088a58b  ff1558ca9800         call dword ptr [0x98ca58]
// 0088a591  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088a595  2b44242c             sub eax, dword ptr [esp + 0x2c]
// 0088a599  b910000000           mov ecx, 0x10
// 0088a59e  99                   cdq 
// 0088a59f  2bc2                 sub eax, edx
// 0088a5a1  d1f8                 sar eax, 1
// 0088a5a3  8d78f6               lea edi, [eax - 0xa]
// 0088a5a6  83ff10               cmp edi, 0x10
// 0088a5a9  7f02                 jg 0x88a5ad
// 0088a5ab  8bcf                 mov ecx, edi
// 0088a5ad  8b542418             mov edx, dword ptr [esp + 0x18]
// 0088a5b1  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088a5b5  03c2                 add eax, edx
// 0088a5b7  99                   cdq 
// 0088a5b8  2bc2                 sub eax, edx
// 0088a5ba  d1f8                 sar eax, 1
// 0088a5bc  8bf0                 mov esi, eax
// 0088a5be  2bf1                 sub esi, ecx
// 0088a5c0  83ff10               cmp edi, 0x10
// 0088a5c3  7e05                 jle 0x88a5ca
// 0088a5c5  bf10000000           mov edi, 0x10
// 0088a5ca  03f8                 add edi, eax
// 0088a5cc  837c243c00           cmp dword ptr [esp + 0x3c], 0
// 0088a5d1  7449                 je 0x88a61c
// 0088a5d3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088a5d7  8b542414             mov edx, dword ptr [esp + 0x14]
// 0088a5db  6a1f                 push 0x1f
// 0088a5dd  6a20                 push 0x20
// 0088a5df  83ec10               sub esp, 0x10
// 0088a5e2  8bc4                 mov eax, esp
// 0088a5e4  8908                 mov dword ptr [eax], ecx
// 0088a5e6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0088a5ea  895004               mov dword ptr [eax + 4], edx
// 0088a5ed  8b542434             mov edx, dword ptr [esp + 0x34]
// 0088a5f1  894808               mov dword ptr [eax + 8], ecx
// 0088a5f4  55                   push ebp
// 0088a5f5  8bcb                 mov ecx, ebx
// 0088a5f7  89500c               mov dword ptr [eax + 0xc], edx
// 0088a5fa  e86141f7ff           call 0x7fe760
// 0088a5ff  3bf7                 cmp esi, edi
// 0088a601  7d63                 jge 0x88a666
// 0088a603  6a2d                 push 0x2d
// 0088a605  6a04                 push 4
// 0088a607  57                   push edi
// 0088a608  6a04                 push 4
// 0088a60a  56                   push esi
// 0088a60b  55                   push ebp
// 0088a60c  8bcb                 mov ecx, ebx
// 0088a60e  e88d45f7ff           call 0x7feba0
// 0088a613  6a2d                 push 0x2d
// 0088a615  6a06                 push 6
// 0088a617  57                   push edi
// 0088a618  6a06                 push 6
// 0088a61a  eb41                 jmp 0x88a65d
// 0088a61c  6a1e                 push 0x1e
// 0088a61e  8bcb                 mov ecx, ebx
// 0088a620  e81b30f7ff           call 0x7fd640
// 0088a625  50                   push eax
// 0088a626  8d442414             lea eax, [esp + 0x14]
// 0088a62a  50                   push eax
// 0088a62b  8bcd                 mov ecx, ebp
// 0088a62d  e8cc9ff6ff           call 0x7f45fe
// 0088a632  3bf7                 cmp esi, edi
// 0088a634  7d30                 jge 0x88a666
// 0088a636  6a26                 push 0x26
// 0088a638  6a03                 push 3
// 0088a63a  57                   push edi
// 0088a63b  6a03                 push 3
// 0088a63d  56                   push esi
// 0088a63e  55                   push ebp
// 0088a63f  8bcb                 mov ecx, ebx
// 0088a641  e85a45f7ff           call 0x7feba0
// 0088a646  6a26                 push 0x26
// 0088a648  6a05                 push 5
// 0088a64a  57                   push edi
// 0088a64b  6a05                 push 5
// 0088a64d  56                   push esi
// 0088a64e  55                   push ebp
// 0088a64f  8bcb                 mov ecx, ebx
// 0088a651  e84a45f7ff           call 0x7feba0
// 0088a656  6a26                 push 0x26
// 0088a658  6a07                 push 7
// 0088a65a  57                   push edi
// 0088a65b  6a07                 push 7
// 0088a65d  56                   push esi
// 0088a65e  55                   push ebp
// 0088a65f  8bcb                 mov ecx, ebx
// 0088a661  e83a45f7ff           call 0x7feba0
// 0088a666  8b442424             mov eax, dword ptr [esp + 0x24]
// 0088a66a  5f                   pop edi
// 0088a66b  5e                   pop esi
// 0088a66c  5d                   pop ebp
// 0088a66d  c70000000000         mov dword ptr [eax], 0
// 0088a673  c7400409000000       mov dword ptr [eax + 4], 9
// 0088a67a  5b                   pop ebx
// 0088a67b  83c410               add esp, 0x10
// 0088a67e  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawTearOffGripper@CXTPOfficeTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
