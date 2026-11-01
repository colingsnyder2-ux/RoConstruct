// from server: 100% by auto
// roc 2007-03 00620280  unit: seg_00620000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00620280
//
// 00620280  53                   push ebx
// 00620281  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00620285  56                   push esi
// 00620286  57                   push edi
// 00620287  683c267c00           push 0x7c263c
// 0062028c  89590c               mov dword ptr [ecx + 0xc], ebx
// 0062028f  bf05400080           mov edi, 0x80004005
// 00620294  ff1548d27700         call dword ptr [0x77d248]
// 0062029a  8bf0                 mov esi, eax
// 0062029c  85f6                 test esi, esi
// 0062029e  7421                 je 0x6202c1
// 006202a0  682c267c00           push 0x7c262c
// 006202a5  56                   push esi
// 006202a6  ff1544d27700         call dword ptr [0x77d244]
// 006202ac  85c0                 test eax, eax
// 006202ae  740a                 je 0x6202ba
// 006202b0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006202b4  51                   push ecx
// 006202b5  53                   push ebx
// 006202b6  ffd0                 call eax
// 006202b8  8bf8                 mov edi, eax
// 006202ba  56                   push esi
// 006202bb  ff159cd27700         call dword ptr [0x77d29c]
// 006202c1  8bc7                 mov eax, edi
// 006202c3  5f                   pop edi
// 006202c4  5e                   pop esi
// 006202c5  5b                   pop ebx
// 006202c6  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?ShellAutoComplete@CXTPControlComboBoxAutoCompleteWnd@@QAEJPAUHWND__@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
