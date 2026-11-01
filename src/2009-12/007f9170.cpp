// from server: 100% by auto
// roc 2009-12 007f9170  unit: CXTPEdit  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9170
//
// 007f9170  53                   push ebx
// 007f9171  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007f9175  56                   push esi
// 007f9176  57                   push edi
// 007f9177  68581b9f00           push 0x9f1b58
// 007f917c  89590c               mov dword ptr [ecx + 0xc], ebx
// 007f917f  bf05400080           mov edi, 0x80004005
// 007f9184  ff15d8b19800         call dword ptr [0x98b1d8]
// 007f918a  8bf0                 mov esi, eax
// 007f918c  85f6                 test esi, esi
// 007f918e  7421                 je 0x7f91b1
// 007f9190  68481b9f00           push 0x9f1b48
// 007f9195  56                   push esi
// 007f9196  ff1520b29800         call dword ptr [0x98b220]
// 007f919c  85c0                 test eax, eax
// 007f919e  740a                 je 0x7f91aa
// 007f91a0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007f91a4  51                   push ecx
// 007f91a5  53                   push ebx
// 007f91a6  ffd0                 call eax
// 007f91a8  8bf8                 mov edi, eax
// 007f91aa  56                   push esi
// 007f91ab  ff15f8b19800         call dword ptr [0x98b1f8]
// 007f91b1  8bc7                 mov eax, edi
// 007f91b3  5f                   pop edi
// 007f91b4  5e                   pop esi
// 007f91b5  5b                   pop ebx
// 007f91b6  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?ShellAutoComplete@CXTPControlComboBoxAutoCompleteWnd@@QAEJPAUHWND__@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
