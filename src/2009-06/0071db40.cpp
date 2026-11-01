// from server: 100% by auto
// roc 2009-06 0071db40  unit: CXTPControlEditCtrl  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071db40
//
// 0071db40  56                   push esi
// 0071db41  8b742408             mov esi, dword ptr [esp + 8]
// 0071db45  57                   push edi
// 0071db46  8bf9                 mov edi, ecx
// 0071db48  397708               cmp dword ptr [edi + 8], esi
// 0071db4b  7443                 je 0x71db90
// 0071db4d  68f0b87100           push 0x71b8f0
// 0071db52  b99426a500           mov ecx, 0xa52694
// 0071db57  e8a4e31200           call 0x84bf00
// 0071db5c  85f6                 test esi, esi
// 0071db5e  7419                 je 0x71db79
// 0071db60  85c0                 test eax, eax
// 0071db62  7505                 jne 0x71db69
// 0071db64  e87bb1ffff           call 0x718ce4
// 0071db69  56                   push esi
// 0071db6a  8bc8                 mov ecx, eax
// 0071db6c  e8ef690700           call 0x794560
// 0071db71  897708               mov dword ptr [edi + 8], esi
// 0071db74  5f                   pop edi
// 0071db75  5e                   pop esi
// 0071db76  c20400               ret 4
// 0071db79  85c0                 test eax, eax
// 0071db7b  7505                 jne 0x71db82
// 0071db7d  e862b1ffff           call 0x718ce4
// 0071db82  8b4f08               mov ecx, dword ptr [edi + 8]
// 0071db85  51                   push ecx
// 0071db86  8bc8                 mov ecx, eax
// 0071db88  e853640700           call 0x793fe0
// 0071db8d  897708               mov dword ptr [edi + 8], esi
// 0071db90  5f                   pop edi
// 0071db91  5e                   pop esi
// 0071db92  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?SetAutoCompeteHandle@CXTPControlComboBoxAutoCompleteWnd@@AAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
