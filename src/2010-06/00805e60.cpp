// from server: 100% by auto
// roc 2010-06 00805e60  unit: CXTPPropExchangeArchive  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00805e60
//
// 00805e60  53                   push ebx
// 00805e61  55                   push ebp
// 00805e62  56                   push esi
// 00805e63  57                   push edi
// 00805e64  e8f51dfaff           call 0x7a7c5e
// 00805e69  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00805e6d  8b2d28a39e00         mov ebp, dword ptr [0x9ea328]
// 00805e73  8bf8                 mov edi, eax
// 00805e75  8b7720               mov esi, dword ptr [edi + 0x20]
// 00805e78  85f6                 test esi, esi
// 00805e7a  7415                 je 0x805e91
// 00805e7c  8d642400             lea esp, [esp]
// 00805e80  8b06                 mov eax, dword ptr [esi]
// 00805e82  50                   push eax
// 00805e83  53                   push ebx
// 00805e84  ffd5                 call ebp
// 00805e86  85c0                 test eax, eax
// 00805e88  7435                 je 0x805ebf
// 00805e8a  8b7614               mov esi, dword ptr [esi + 0x14]
// 00805e8d  85f6                 test esi, esi
// 00805e8f  75ef                 jne 0x805e80
// 00805e91  8b7f4c               mov edi, dword ptr [edi + 0x4c]
// 00805e94  85ff                 test edi, edi
// 00805e96  7420                 je 0x805eb8
// 00805e98  8b7728               mov esi, dword ptr [edi + 0x28]
// 00805e9b  85f6                 test esi, esi
// 00805e9d  7412                 je 0x805eb1
// 00805e9f  90                   nop 
// 00805ea0  8b0e                 mov ecx, dword ptr [esi]
// 00805ea2  51                   push ecx
// 00805ea3  53                   push ebx
// 00805ea4  ffd5                 call ebp
// 00805ea6  85c0                 test eax, eax
// 00805ea8  7415                 je 0x805ebf
// 00805eaa  8b7614               mov esi, dword ptr [esi + 0x14]
// 00805ead  85f6                 test esi, esi
// 00805eaf  75ef                 jne 0x805ea0
// 00805eb1  8b7f3c               mov edi, dword ptr [edi + 0x3c]
// 00805eb4  85ff                 test edi, edi
// 00805eb6  75e0                 jne 0x805e98
// 00805eb8  5f                   pop edi
// 00805eb9  5e                   pop esi
// 00805eba  5d                   pop ebp
// 00805ebb  33c0                 xor eax, eax
// 00805ebd  5b                   pop ebx
// 00805ebe  c3                   ret 
// 00805ebf  5f                   pop edi
// 00805ec0  8bc6                 mov eax, esi
// 00805ec2  5e                   pop esi
// 00805ec3  5d                   pop ebp
// 00805ec4  5b                   pop ebx
// 00805ec5  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?FindRuntimeClass@CXTPPropExchange@@SAPAUCRuntimeClass@@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
