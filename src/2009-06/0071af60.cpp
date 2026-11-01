// from server: 100% by auto
// roc 2009-06 0071af60  unit: CXTPEdit  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071af60
//
// 0071af60  53                   push ebx
// 0071af61  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0071af65  56                   push esi
// 0071af66  57                   push edi
// 0071af67  6868138f00           push 0x8f1368
// 0071af6c  89590c               mov dword ptr [ecx + 0xc], ebx
// 0071af6f  bf05400080           mov edi, 0x80004005
// 0071af74  ff15d4e18900         call dword ptr [0x89e1d4]
// 0071af7a  8bf0                 mov esi, eax
// 0071af7c  85f6                 test esi, esi
// 0071af7e  7421                 je 0x71afa1
// 0071af80  6858138f00           push 0x8f1358
// 0071af85  56                   push esi
// 0071af86  ff15e8e18900         call dword ptr [0x89e1e8]
// 0071af8c  85c0                 test eax, eax
// 0071af8e  740a                 je 0x71af9a
// 0071af90  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0071af94  51                   push ecx
// 0071af95  53                   push ebx
// 0071af96  ffd0                 call eax
// 0071af98  8bf8                 mov edi, eax
// 0071af9a  56                   push esi
// 0071af9b  ff15b4e18900         call dword ptr [0x89e1b4]
// 0071afa1  8bc7                 mov eax, edi
// 0071afa3  5f                   pop edi
// 0071afa4  5e                   pop esi
// 0071afa5  5b                   pop ebx
// 0071afa6  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?ShellAutoComplete@CXTPControlComboBoxAutoCompleteWnd@@QAEJPAUHWND__@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
