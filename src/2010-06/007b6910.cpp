// from server: 100% by auto
// roc 2010-06 007b6910  unit: CXTPControlEditCtrl  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b6910
//
// 007b6910  56                   push esi
// 007b6911  8b742408             mov esi, dword ptr [esp + 8]
// 007b6915  57                   push edi
// 007b6916  8bf9                 mov edi, ecx
// 007b6918  397708               cmp dword ptr [edi + 8], esi
// 007b691b  7443                 je 0x7b6960
// 007b691d  68e0a57a00           push 0x7aa5e0
// 007b6922  b90062c200           mov ecx, 0xc26200
// 007b6927  e84c641c00           call 0x97cd78
// 007b692c  85f6                 test esi, esi
// 007b692e  7419                 je 0x7b6949
// 007b6930  85c0                 test eax, eax
// 007b6932  7505                 jne 0x7b6939
// 007b6934  e81313ffff           call 0x7a7c4c
// 007b6939  56                   push esi
// 007b693a  8bc8                 mov ecx, eax
// 007b693c  e88fcd0600           call 0x8236d0
// 007b6941  897708               mov dword ptr [edi + 8], esi
// 007b6944  5f                   pop edi
// 007b6945  5e                   pop esi
// 007b6946  c20400               ret 4
// 007b6949  85c0                 test eax, eax
// 007b694b  7505                 jne 0x7b6952
// 007b694d  e8fa12ffff           call 0x7a7c4c
// 007b6952  8b4f08               mov ecx, dword ptr [edi + 8]
// 007b6955  51                   push ecx
// 007b6956  8bc8                 mov ecx, eax
// 007b6958  e8f3c70600           call 0x823150
// 007b695d  897708               mov dword ptr [edi + 8], esi
// 007b6960  5f                   pop edi
// 007b6961  5e                   pop esi
// 007b6962  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?SetAutoCompeteHandle@CXTPControlComboBoxAutoCompleteWnd@@AAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
