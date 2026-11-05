// from server: 100% by auto
// roc 2008-06 0055be30  unit: RBX::VInstance::?$SignalDesc  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055be30
//
// 0055be30  53                   push ebx
// 0055be31  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0055be35  57                   push edi
// 0055be36  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0055be3a  57                   push edi
// 0055be3b  53                   push ebx
// 0055be3c  ff15a8218000         call dword ptr [0x8021a8]
// 0055be42  85c0                 test eax, eax
// 0055be44  7503                 jne 0x55be49
// 0055be46  5f                   pop edi
// 0055be47  5b                   pop ebx
// 0055be48  c3                   ret 
// 0055be49  56                   push esi
// 0055be4a  50                   push eax
// 0055be4b  ff1510228000         call dword ptr [0x802210]
// 0055be51  8bf0                 mov esi, eax
// 0055be53  85f6                 test esi, esi
// 0055be55  742d                 je 0x55be84
// 0055be57  57                   push edi
// 0055be58  53                   push ebx
// 0055be59  ff15c8218000         call dword ptr [0x8021c8]
// 0055be5f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055be63  03c6                 add eax, esi
// 0055be65  83e10f               and ecx, 0xf
// 0055be68  7616                 jbe 0x55be80
// 0055be6a  8d9b00000000         lea ebx, [ebx]
// 0055be70  3bf0                 cmp esi, eax
// 0055be72  7310                 jae 0x55be84
// 0055be74  83e901               sub ecx, 1
// 0055be77  0fb716               movzx edx, word ptr [esi]
// 0055be7a  8d745602             lea esi, [esi + edx*2 + 2]
// 0055be7e  75f0                 jne 0x55be70
// 0055be80  3bf0                 cmp esi, eax
// 0055be82  7206                 jb 0x55be8a
// 0055be84  5e                   pop esi
// 0055be85  5f                   pop edi
// 0055be86  33c0                 xor eax, eax
// 0055be88  5b                   pop ebx
// 0055be89  c3                   ret 
// 0055be8a  0fb706               movzx eax, word ptr [esi]
// 0055be8d  f7d8                 neg eax
// 0055be8f  1bc0                 sbb eax, eax
// 0055be91  23c6                 and eax, esi
// 0055be93  5e                   pop esi
// 0055be94  5f                   pop edi
// 0055be95  5b                   pop ebx
// 0055be96  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
