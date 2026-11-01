// from server: 100% by auto
// roc 2009-12 00855810  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00855810
//
// 00855810  83ec20               sub esp, 0x20
// 00855813  8b442428             mov eax, dword ptr [esp + 0x28]
// 00855817  53                   push ebx
// 00855818  55                   push ebp
// 00855819  8be9                 mov ebp, ecx
// 0085581b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0085581f  03c1                 add eax, ecx
// 00855821  99                   cdq 
// 00855822  2bc2                 sub eax, edx
// 00855824  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00855828  56                   push esi
// 00855829  8bf0                 mov esi, eax
// 0085582b  8b442438             mov eax, dword ptr [esp + 0x38]
// 0085582f  03c2                 add eax, edx
// 00855831  99                   cdq 
// 00855832  57                   push edi
// 00855833  2bc2                 sub eax, edx
// 00855835  8bf8                 mov edi, eax
// 00855837  d1fe                 sar esi, 1
// 00855839  d1ff                 sar edi, 1
// 0085583b  8d4eff               lea ecx, [esi - 1]
// 0085583e  47                   inc edi
// 0085583f  894c2418             mov dword ptr [esp + 0x18], ecx
// 00855843  8d47ff               lea eax, [edi - 1]
// 00855846  8d4f02               lea ecx, [edi + 2]
// 00855849  89442414             mov dword ptr [esp + 0x14], eax
// 0085584d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00855851  894c2424             mov dword ptr [esp + 0x24], ecx
// 00855855  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00855859  8d5603               lea edx, [esi + 3]
// 0085585c  8944242c             mov dword ptr [esp + 0x2c], eax
// 00855860  6a04                 push 4
// 00855862  8d442414             lea eax, [esp + 0x14]
// 00855866  8954242c             mov dword ptr [esp + 0x2c], edx
// 0085586a  8b5104               mov edx, dword ptr [ecx + 4]
// 0085586d  50                   push eax
// 0085586e  8d5efc               lea ebx, [esi - 4]
// 00855871  52                   push edx
// 00855872  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00855876  8974242c             mov dword ptr [esp + 0x2c], esi
// 0085587a  ff1520b19800         call dword ptr [0x98b120]
// 00855880  837d3000             cmp dword ptr [ebp + 0x30], 0
// 00855884  741b                 je 0x8558a1
// 00855886  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0085588a  8b5104               mov edx, dword ptr [ecx + 4]
// 0085588d  8d47fd               lea eax, [edi - 3]
// 00855890  50                   push eax
// 00855891  83c604               add esi, 4
// 00855894  56                   push esi
// 00855895  83c7fb               add edi, -5
// 00855898  57                   push edi
// 00855899  53                   push ebx
// 0085589a  52                   push edx
// 0085589b  ff15c0b09800         call dword ptr [0x98b0c0]
// 008558a1  5f                   pop edi
// 008558a2  5e                   pop esi
// 008558a3  5d                   pop ebp
// 008558a4  5b                   pop ebx
// 008558a5  83c420               add esp, 0x20
// 008558a8  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawEntry@CNavigateButtonActiveFiles@CXTPTabClientWnd@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
