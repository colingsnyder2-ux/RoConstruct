// from server: 100% by auto
// roc 2010-06 005a0a40  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a0a40
//
// 005a0a40  53                   push ebx
// 005a0a41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005a0a45  57                   push edi
// 005a0a46  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005a0a4a  57                   push edi
// 005a0a4b  53                   push ebx
// 005a0a4c  ff1560a39e00         call dword ptr [0x9ea360]
// 005a0a52  85c0                 test eax, eax
// 005a0a54  7503                 jne 0x5a0a59
// 005a0a56  5f                   pop edi
// 005a0a57  5b                   pop ebx
// 005a0a58  c3                   ret 
// 005a0a59  56                   push esi
// 005a0a5a  50                   push eax
// 005a0a5b  ff15eca29e00         call dword ptr [0x9ea2ec]
// 005a0a61  8bf0                 mov esi, eax
// 005a0a63  85f6                 test esi, esi
// 005a0a65  742d                 je 0x5a0a94
// 005a0a67  57                   push edi
// 005a0a68  53                   push ebx
// 005a0a69  ff1564a39e00         call dword ptr [0x9ea364]
// 005a0a6f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005a0a73  03c6                 add eax, esi
// 005a0a75  83e10f               and ecx, 0xf
// 005a0a78  7616                 jbe 0x5a0a90
// 005a0a7a  8d9b00000000         lea ebx, [ebx]
// 005a0a80  3bf0                 cmp esi, eax
// 005a0a82  7310                 jae 0x5a0a94
// 005a0a84  83e901               sub ecx, 1
// 005a0a87  0fb716               movzx edx, word ptr [esi]
// 005a0a8a  8d745602             lea esi, [esi + edx*2 + 2]
// 005a0a8e  75f0                 jne 0x5a0a80
// 005a0a90  3bf0                 cmp esi, eax
// 005a0a92  7206                 jb 0x5a0a9a
// 005a0a94  5e                   pop esi
// 005a0a95  5f                   pop edi
// 005a0a96  33c0                 xor eax, eax
// 005a0a98  5b                   pop ebx
// 005a0a99  c3                   ret 
// 005a0a9a  0fb706               movzx eax, word ptr [esi]
// 005a0a9d  f7d8                 neg eax
// 005a0a9f  1bc0                 sbb eax, eax
// 005a0aa1  23c6                 and eax, esi
// 005a0aa3  5e                   pop esi
// 005a0aa4  5f                   pop edi
// 005a0aa5  5b                   pop ebx
// 005a0aa6  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
