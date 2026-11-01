// from server: 100% by auto
// roc 2011-06 008644e0  unit: CXTPTabClientWnd  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008644e0
//
// 008644e0  53                   push ebx
// 008644e1  57                   push edi
// 008644e2  8bf9                 mov edi, ecx
// 008644e4  e84561faff           call 0x80a62e
// 008644e9  8bd8                 mov ebx, eax
// 008644eb  85db                 test ebx, ebx
// 008644ed  7448                 je 0x864537
// 008644ef  83bfb400000000       cmp dword ptr [edi + 0xb4], 0
// 008644f6  743f                 je 0x864537
// 008644f8  56                   push esi
// 008644f9  53                   push ebx
// 008644fa  e8295efaff           call 0x80a328
// 008644ff  8bf0                 mov esi, eax
// 00864501  85f6                 test esi, esi
// 00864503  7431                 je 0x864536
// 00864505  6a00                 push 0
// 00864507  6a00                 push 0
// 00864509  680000c700           push 0xc70000
// 0086450e  8bce                 mov ecx, esi
// 00864510  e8c362faff           call 0x80a7d8
// 00864515  6a00                 push 0
// 00864517  6a00                 push 0
// 00864519  6800020000           push 0x200
// 0086451e  8bce                 mov ecx, esi
// 00864520  e8df60faff           call 0x80a604
// 00864525  6a01                 push 1
// 00864527  6a00                 push 0
// 00864529  6a00                 push 0
// 0086452b  6a00                 push 0
// 0086452d  6a00                 push 0
// 0086452f  8bce                 mov ecx, esi
// 00864531  e8fa5efaff           call 0x80a430
// 00864536  5e                   pop esi
// 00864537  8b07                 mov eax, dword ptr [edi]
// 00864539  8b9044010000         mov edx, dword ptr [eax + 0x144]
// 0086453f  8bcf                 mov ecx, edi
// 00864541  ffd2                 call edx
// 00864543  5f                   pop edi
// 00864544  8bc3                 mov eax, ebx
// 00864546  5b                   pop ebx
// 00864547  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDICreate@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPTabClientWnd.cpp
