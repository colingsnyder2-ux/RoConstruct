// from server: 100% by auto
// roc 2009-06 0077a790  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a790
//
// 0077a790  83ec20               sub esp, 0x20
// 0077a793  8b442428             mov eax, dword ptr [esp + 0x28]
// 0077a797  53                   push ebx
// 0077a798  55                   push ebp
// 0077a799  8be9                 mov ebp, ecx
// 0077a79b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0077a79f  03c1                 add eax, ecx
// 0077a7a1  99                   cdq 
// 0077a7a2  2bc2                 sub eax, edx
// 0077a7a4  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0077a7a8  56                   push esi
// 0077a7a9  8bf0                 mov esi, eax
// 0077a7ab  8b442438             mov eax, dword ptr [esp + 0x38]
// 0077a7af  03c2                 add eax, edx
// 0077a7b1  99                   cdq 
// 0077a7b2  57                   push edi
// 0077a7b3  2bc2                 sub eax, edx
// 0077a7b5  8bf8                 mov edi, eax
// 0077a7b7  d1fe                 sar esi, 1
// 0077a7b9  d1ff                 sar edi, 1
// 0077a7bb  8d4eff               lea ecx, [esi - 1]
// 0077a7be  47                   inc edi
// 0077a7bf  894c2418             mov dword ptr [esp + 0x18], ecx
// 0077a7c3  8d47ff               lea eax, [edi - 1]
// 0077a7c6  8d4f02               lea ecx, [edi + 2]
// 0077a7c9  89442414             mov dword ptr [esp + 0x14], eax
// 0077a7cd  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0077a7d1  894c2424             mov dword ptr [esp + 0x24], ecx
// 0077a7d5  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0077a7d9  8d5603               lea edx, [esi + 3]
// 0077a7dc  8944242c             mov dword ptr [esp + 0x2c], eax
// 0077a7e0  6a04                 push 4
// 0077a7e2  8d442414             lea eax, [esp + 0x14]
// 0077a7e6  8954242c             mov dword ptr [esp + 0x2c], edx
// 0077a7ea  8b5104               mov edx, dword ptr [ecx + 4]
// 0077a7ed  50                   push eax
// 0077a7ee  8d5efc               lea ebx, [esi - 4]
// 0077a7f1  52                   push edx
// 0077a7f2  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0077a7f6  8974242c             mov dword ptr [esp + 0x2c], esi
// 0077a7fa  ff15e4e08900         call dword ptr [0x89e0e4]
// 0077a800  837d3000             cmp dword ptr [ebp + 0x30], 0
// 0077a804  741b                 je 0x77a821
// 0077a806  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0077a80a  8b5104               mov edx, dword ptr [ecx + 4]
// 0077a80d  8d47fd               lea eax, [edi - 3]
// 0077a810  50                   push eax
// 0077a811  83c604               add esi, 4
// 0077a814  56                   push esi
// 0077a815  83c7fb               add edi, -5
// 0077a818  57                   push edi
// 0077a819  53                   push ebx
// 0077a81a  52                   push edx
// 0077a81b  ff156ce18900         call dword ptr [0x89e16c]
// 0077a821  5f                   pop edi
// 0077a822  5e                   pop esi
// 0077a823  5d                   pop ebp
// 0077a824  5b                   pop ebx
// 0077a825  83c420               add esp, 0x20
// 0077a828  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawEntry@CNavigateButtonActiveFiles@CXTPTabClientWnd@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
