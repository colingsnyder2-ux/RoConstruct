// from server: 100% by auto
// roc 2007-03 00622d40  unit: seg_00620000  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00622d40
//
// 00622d40  56                   push esi
// 00622d41  8b742408             mov esi, dword ptr [esp + 8]
// 00622d45  57                   push edi
// 00622d46  8bf9                 mov edi, ecx
// 00622d48  397708               cmp dword ptr [edi + 8], esi
// 00622d4b  7443                 je 0x622d90
// 00622d4d  68300c6200           push 0x620c30
// 00622d52  b910238c00           mov ecx, 0x8c2310
// 00622d57  e8487d1100           call 0x73aaa4
// 00622d5c  85f6                 test esi, esi
// 00622d5e  7419                 je 0x622d79
// 00622d60  85c0                 test eax, eax
// 00622d62  7505                 jne 0x622d69
// 00622d64  e845b6ffff           call 0x61e3ae
// 00622d69  56                   push esi
// 00622d6a  8bc8                 mov ecx, eax
// 00622d6c  e88fab0600           call 0x68d900
// 00622d71  897708               mov dword ptr [edi + 8], esi
// 00622d74  5f                   pop edi
// 00622d75  5e                   pop esi
// 00622d76  c20400               ret 4
// 00622d79  85c0                 test eax, eax
// 00622d7b  7505                 jne 0x622d82
// 00622d7d  e82cb6ffff           call 0x61e3ae
// 00622d82  8b4f08               mov ecx, dword ptr [edi + 8]
// 00622d85  51                   push ecx
// 00622d86  8bc8                 mov ecx, eax
// 00622d88  e843a60600           call 0x68d3d0
// 00622d8d  897708               mov dword ptr [edi + 8], esi
// 00622d90  5f                   pop edi
// 00622d91  5e                   pop esi
// 00622d92  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?SetAutoCompeteHandle@CXTPControlComboBoxAutoCompleteWnd@@AAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
