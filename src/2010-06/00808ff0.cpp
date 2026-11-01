// from server: 100% by auto
// roc 2010-06 00808ff0  unit: CXTPTabClientWnd  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808ff0
//
// 00808ff0  53                   push ebx
// 00808ff1  57                   push edi
// 00808ff2  8bf9                 mov edi, ecx
// 00808ff4  e877eff9ff           call 0x7a7f70
// 00808ff9  8bd8                 mov ebx, eax
// 00808ffb  85db                 test ebx, ebx
// 00808ffd  7448                 je 0x809047
// 00808fff  83bfb400000000       cmp dword ptr [edi + 0xb4], 0
// 00809006  743f                 je 0x809047
// 00809008  56                   push esi
// 00809009  53                   push ebx
// 0080900a  e85becf9ff           call 0x7a7c6a
// 0080900f  8bf0                 mov esi, eax
// 00809011  85f6                 test esi, esi
// 00809013  7431                 je 0x809046
// 00809015  6a00                 push 0
// 00809017  6a00                 push 0
// 00809019  680000c700           push 0xc70000
// 0080901e  8bce                 mov ecx, esi
// 00809020  e8f5f0f9ff           call 0x7a811a
// 00809025  6a00                 push 0
// 00809027  6a00                 push 0
// 00809029  6800020000           push 0x200
// 0080902e  8bce                 mov ecx, esi
// 00809030  e811eff9ff           call 0x7a7f46
// 00809035  6a01                 push 1
// 00809037  6a00                 push 0
// 00809039  6a00                 push 0
// 0080903b  6a00                 push 0
// 0080903d  6a00                 push 0
// 0080903f  8bce                 mov ecx, esi
// 00809041  e82cedf9ff           call 0x7a7d72
// 00809046  5e                   pop esi
// 00809047  8b07                 mov eax, dword ptr [edi]
// 00809049  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 0080904f  8bcf                 mov ecx, edi
// 00809051  ffd2                 call edx
// 00809053  5f                   pop edi
// 00809054  8bc3                 mov eax, ebx
// 00809056  5b                   pop ebx
// 00809057  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDICreate@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
