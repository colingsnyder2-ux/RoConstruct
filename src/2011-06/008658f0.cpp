// from server: 100% by auto
// roc 2011-06 008658f0  unit: CXTPTabClientWnd  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008658f0
//
// 008658f0  56                   push esi
// 008658f1  8bf1                 mov esi, ecx
// 008658f3  8b06                 mov eax, dword ptr [esi]
// 008658f5  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 008658fb  ffd2                 call edx
// 008658fd  85c0                 test eax, eax
// 008658ff  7448                 je 0x865949
// 00865901  83beb000000000       cmp dword ptr [esi + 0xb0], 0
// 00865908  751c                 jne 0x865926
// 0086590a  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0086590e  8b5104               mov edx, dword ptr [ecx + 4]
// 00865911  8b06                 mov eax, dword ptr [esi]
// 00865913  8b8020010000         mov eax, dword ptr [eax + 0x120]
// 00865919  6a00                 push 0
// 0086591b  52                   push edx
// 0086591c  6a0f                 push 0xf
// 0086591e  8bce                 mov ecx, esi
// 00865920  ffd0                 call eax
// 00865922  5e                   pop esi
// 00865923  c21400               ret 0x14
// 00865926  6a0c                 push 0xc
// 00865928  8bc8                 mov ecx, eax
// 0086592a  e80149fcff           call 0x82a230
// 0086592f  8bc8                 mov ecx, eax
// 00865931  e87a9cfaff           call 0x80f5b0
// 00865936  50                   push eax
// 00865937  8d4c2410             lea ecx, [esp + 0x10]
// 0086593b  51                   push ecx
// 0086593c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00865940  e8db54faff           call 0x80ae20
// 00865945  5e                   pop esi
// 00865946  c21400               ret 0x14
// 00865949  6a0c                 push 0xc
// 0086594b  ff15181ba400         call dword ptr [0xa41b18]
// 00865951  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00865955  50                   push eax
// 00865956  8d542410             lea edx, [esp + 0x10]
// 0086595a  52                   push edx
// 0086595b  e8c054faff           call 0x80ae20
// 00865960  5e                   pop esi
// 00865961  c21400               ret 0x14
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnFillBackground@CXTPTabClientWnd@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
