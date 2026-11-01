// from server: 100% by auto
// roc 2010-06 00856ef0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00856ef0
//
// 00856ef0  53                   push ebx
// 00856ef1  55                   push ebp
// 00856ef2  56                   push esi
// 00856ef3  57                   push edi
// 00856ef4  8bf9                 mov edi, ecx
// 00856ef6  8b07                 mov eax, dword ptr [edi]
// 00856ef8  8b5058               mov edx, dword ptr [eax + 0x58]
// 00856efb  ffd2                 call edx
// 00856efd  8bd8                 mov ebx, eax
// 00856eff  33f6                 xor esi, esi
// 00856f01  85db                 test ebx, ebx
// 00856f03  7e1e                 jle 0x856f23
// 00856f05  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00856f09  8da42400000000       lea esp, [esp]
// 00856f10  8b07                 mov eax, dword ptr [edi]
// 00856f12  8b5060               mov edx, dword ptr [eax + 0x60]
// 00856f15  56                   push esi
// 00856f16  8bcf                 mov ecx, edi
// 00856f18  ffd2                 call edx
// 00856f1a  3bc5                 cmp eax, ebp
// 00856f1c  740f                 je 0x856f2d
// 00856f1e  46                   inc esi
// 00856f1f  3bf3                 cmp esi, ebx
// 00856f21  7ced                 jl 0x856f10
// 00856f23  5f                   pop edi
// 00856f24  5e                   pop esi
// 00856f25  5d                   pop ebp
// 00856f26  83c8ff               or eax, 0xffffffff
// 00856f29  5b                   pop ebx
// 00856f2a  c20400               ret 4
// 00856f2d  5f                   pop edi
// 00856f2e  8bc6                 mov eax, esi
// 00856f30  5e                   pop esi
// 00856f31  5d                   pop ebp
// 00856f32  5b                   pop ebx
// 00856f33  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarEventLabel.cpp (function ?FindElement@?$CXTPArrayT@IIJ@@UBEHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarEventLabel.cpp
