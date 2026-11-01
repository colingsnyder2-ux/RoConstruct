// from server: 100% by auto
// roc 2007-08 00689c30  unit: CXTPTabClientWnd  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689c30
//
// 00689c30  53                   push ebx
// 00689c31  57                   push edi
// 00689c32  8bf9                 mov edi, ecx
// 00689c34  e80566faff           call 0x63023e
// 00689c39  8bd8                 mov ebx, eax
// 00689c3b  85db                 test ebx, ebx
// 00689c3d  7448                 je 0x689c87
// 00689c3f  83bfb400000000       cmp dword ptr [edi + 0xb4], 0
// 00689c46  743f                 je 0x689c87
// 00689c48  56                   push esi
// 00689c49  53                   push ebx
// 00689c4a  e87165faff           call 0x6301c0
// 00689c4f  8bf0                 mov esi, eax
// 00689c51  85f6                 test esi, esi
// 00689c53  7431                 je 0x689c86
// 00689c55  6a00                 push 0
// 00689c57  6a00                 push 0
// 00689c59  680000c700           push 0xc70000
// 00689c5e  8bce                 mov ecx, esi
// 00689c60  e85367faff           call 0x6303b8
// 00689c65  6a00                 push 0
// 00689c67  6a00                 push 0
// 00689c69  6800020000           push 0x200
// 00689c6e  8bce                 mov ecx, esi
// 00689c70  e89f65faff           call 0x630214
// 00689c75  6a01                 push 1
// 00689c77  6a00                 push 0
// 00689c79  6a00                 push 0
// 00689c7b  6a00                 push 0
// 00689c7d  6a00                 push 0
// 00689c7f  8bce                 mov ecx, esi
// 00689c81  e8ae63faff           call 0x630034
// 00689c86  5e                   pop esi
// 00689c87  8b07                 mov eax, dword ptr [edi]
// 00689c89  8b903c010000         mov edx, dword ptr [eax + 0x13c]
// 00689c8f  8bcf                 mov ecx, edi
// 00689c91  ffd2                 call edx
// 00689c93  5f                   pop edi
// 00689c94  8bc3                 mov eax, ebx
// 00689c96  5b                   pop ebx
// 00689c97  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDICreate@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
