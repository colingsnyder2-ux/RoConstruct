// from server: 100% by auto
// roc 2010-06 007b3f40  unit: CXTPEdit  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3f40
//
// 007b3f40  53                   push ebx
// 007b3f41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007b3f45  56                   push esi
// 007b3f46  57                   push edi
// 007b3f47  68dc5fa500           push 0xa55fdc
// 007b3f4c  89590c               mov dword ptr [ecx + 0xc], ebx
// 007b3f4f  bf05400080           mov edi, 0x80004005
// 007b3f54  ff1548a39e00         call dword ptr [0x9ea348]
// 007b3f5a  8bf0                 mov esi, eax
// 007b3f5c  85f6                 test esi, esi
// 007b3f5e  7421                 je 0x7b3f81
// 007b3f60  68cc5fa500           push 0xa55fcc
// 007b3f65  56                   push esi
// 007b3f66  ff1590a39e00         call dword ptr [0x9ea390]
// 007b3f6c  85c0                 test eax, eax
// 007b3f6e  740a                 je 0x7b3f7a
// 007b3f70  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007b3f74  51                   push ecx
// 007b3f75  53                   push ebx
// 007b3f76  ffd0                 call eax
// 007b3f78  8bf8                 mov edi, eax
// 007b3f7a  56                   push esi
// 007b3f7b  ff1568a39e00         call dword ptr [0x9ea368]
// 007b3f81  8bc7                 mov eax, edi
// 007b3f83  5f                   pop edi
// 007b3f84  5e                   pop esi
// 007b3f85  5b                   pop ebx
// 007b3f86  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?ShellAutoComplete@CXTPControlComboBoxAutoCompleteWnd@@QAEJPAUHWND__@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
