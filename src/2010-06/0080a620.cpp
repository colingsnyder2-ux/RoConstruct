// from server: 100% by auto
// roc 2010-06 0080a620  unit: CXTPTabClientWnd  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080a620
//
// 0080a620  56                   push esi
// 0080a621  8bf1                 mov esi, ecx
// 0080a623  8b06                 mov eax, dword ptr [esi]
// 0080a625  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 0080a62b  ffd2                 call edx
// 0080a62d  85c0                 test eax, eax
// 0080a62f  7448                 je 0x80a679
// 0080a631  83beb000000000       cmp dword ptr [esi + 0xb0], 0
// 0080a638  751c                 jne 0x80a656
// 0080a63a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080a63e  8b5104               mov edx, dword ptr [ecx + 4]
// 0080a641  8b06                 mov eax, dword ptr [esi]
// 0080a643  8b8020010000         mov eax, dword ptr [eax + 0x120]
// 0080a649  6a00                 push 0
// 0080a64b  52                   push edx
// 0080a64c  6a0f                 push 0xf
// 0080a64e  8bce                 mov ecx, esi
// 0080a650  ffd0                 call eax
// 0080a652  5e                   pop esi
// 0080a653  c21400               ret 0x14
// 0080a656  6a0c                 push 0xc
// 0080a658  8bc8                 mov ecx, eax
// 0080a65a  e861e1fbff           call 0x7c87c0
// 0080a65f  8bc8                 mov ecx, eax
// 0080a661  e8aa2afaff           call 0x7ad110
// 0080a666  50                   push eax
// 0080a667  8d4c2410             lea ecx, [esp + 0x10]
// 0080a66b  51                   push ecx
// 0080a66c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080a670  e8c9e0f9ff           call 0x7a873e
// 0080a675  5e                   pop esi
// 0080a676  c21400               ret 0x14
// 0080a679  6a0c                 push 0xc
// 0080a67b  ff1504ba9e00         call dword ptr [0x9eba04]
// 0080a681  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080a685  50                   push eax
// 0080a686  8d542410             lea edx, [esp + 0x10]
// 0080a68a  52                   push edx
// 0080a68b  e8aee0f9ff           call 0x7a873e
// 0080a690  5e                   pop esi
// 0080a691  c21400               ret 0x14
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnFillBackground@CXTPTabClientWnd@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
