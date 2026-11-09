// from server: 100% by auto
// roc 2010-06 00809740  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809740
//
// 00809740  83ec20               sub esp, 0x20
// 00809743  8b442428             mov eax, dword ptr [esp + 0x28]
// 00809747  53                   push ebx
// 00809748  55                   push ebp
// 00809749  8be9                 mov ebp, ecx
// 0080974b  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0080974f  03c1                 add eax, ecx
// 00809751  99                   cdq 
// 00809752  2bc2                 sub eax, edx
// 00809754  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00809758  56                   push esi
// 00809759  8bf0                 mov esi, eax
// 0080975b  8b442438             mov eax, dword ptr [esp + 0x38]
// 0080975f  03c2                 add eax, edx
// 00809761  99                   cdq 
// 00809762  57                   push edi
// 00809763  2bc2                 sub eax, edx
// 00809765  8bf8                 mov edi, eax
// 00809767  d1fe                 sar esi, 1
// 00809769  d1ff                 sar edi, 1
// 0080976b  8d4eff               lea ecx, [esi - 1]
// 0080976e  47                   inc edi
// 0080976f  894c2418             mov dword ptr [esp + 0x18], ecx
// 00809773  8d47ff               lea eax, [edi - 1]
// 00809776  8d4f02               lea ecx, [edi + 2]
// 00809779  89442414             mov dword ptr [esp + 0x14], eax
// 0080977d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00809781  894c2424             mov dword ptr [esp + 0x24], ecx
// 00809785  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00809789  8d5603               lea edx, [esi + 3]
// 0080978c  8944242c             mov dword ptr [esp + 0x2c], eax
// 00809790  6a04                 push 4
// 00809792  8d442414             lea eax, [esp + 0x14]
// 00809796  8954242c             mov dword ptr [esp + 0x2c], edx
// 0080979a  8b5104               mov edx, dword ptr [ecx + 4]
// 0080979d  50                   push eax
// 0080979e  8d5efc               lea ebx, [esi - 4]
// 008097a1  52                   push edx
// 008097a2  895c241c             mov dword ptr [esp + 0x1c], ebx
// 008097a6  8974242c             mov dword ptr [esp + 0x2c], esi
// 008097aa  ff1568a19e00         call dword ptr [0x9ea168]
// 008097b0  837d3000             cmp dword ptr [ebp + 0x30], 0
// 008097b4  741b                 je 0x8097d1
// 008097b6  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 008097ba  8b5104               mov edx, dword ptr [ecx + 4]
// 008097bd  8d47fd               lea eax, [edi - 3]
// 008097c0  50                   push eax
// 008097c1  83c604               add esi, 4
// 008097c4  56                   push esi
// 008097c5  83c7fb               add edi, -5
// 008097c8  57                   push edi
// 008097c9  53                   push ebx
// 008097ca  52                   push edx
// 008097cb  ff1508a19e00         call dword ptr [0x9ea108]
// 008097d1  5f                   pop edi
// 008097d2  5e                   pop esi
// 008097d3  5d                   pop ebp
// 008097d4  5b                   pop ebx
// 008097d5  83c420               add esp, 0x20
// 008097d8  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawEntry@CNavigateButtonActiveFiles@CXTPTabClientWnd@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
