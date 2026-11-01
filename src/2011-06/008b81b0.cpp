// from server: 100% by auto
// roc 2011-06 008b81b0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b81b0
//
// 008b81b0  53                   push ebx
// 008b81b1  55                   push ebp
// 008b81b2  56                   push esi
// 008b81b3  57                   push edi
// 008b81b4  8bf9                 mov edi, ecx
// 008b81b6  8b07                 mov eax, dword ptr [edi]
// 008b81b8  8b5058               mov edx, dword ptr [eax + 0x58]
// 008b81bb  ffd2                 call edx
// 008b81bd  8bd8                 mov ebx, eax
// 008b81bf  33f6                 xor esi, esi
// 008b81c1  85db                 test ebx, ebx
// 008b81c3  7e1e                 jle 0x8b81e3
// 008b81c5  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 008b81c9  8da42400000000       lea esp, [esp]
// 008b81d0  8b07                 mov eax, dword ptr [edi]
// 008b81d2  8b5060               mov edx, dword ptr [eax + 0x60]
// 008b81d5  56                   push esi
// 008b81d6  8bcf                 mov ecx, edi
// 008b81d8  ffd2                 call edx
// 008b81da  3bc5                 cmp eax, ebp
// 008b81dc  740f                 je 0x8b81ed
// 008b81de  46                   inc esi
// 008b81df  3bf3                 cmp esi, ebx
// 008b81e1  7ced                 jl 0x8b81d0
// 008b81e3  5f                   pop edi
// 008b81e4  5e                   pop esi
// 008b81e5  5d                   pop ebp
// 008b81e6  83c8ff               or eax, 0xffffffff
// 008b81e9  5b                   pop ebx
// 008b81ea  c20400               ret 4
// 008b81ed  5f                   pop edi
// 008b81ee  8bc6                 mov eax, esi
// 008b81f0  5e                   pop esi
// 008b81f1  5d                   pop ebp
// 008b81f2  5b                   pop ebx
// 008b81f3  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?FindElement@?$CXTPArrayT@IIJ@@UBEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
