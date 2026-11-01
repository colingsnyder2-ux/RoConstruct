// from server: 100% by auto
// roc 2009-12 007fbc80  unit: CXTPControlEditCtrl  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fbc80
//
// 007fbc80  56                   push esi
// 007fbc81  8b742408             mov esi, dword ptr [esp + 8]
// 007fbc85  57                   push edi
// 007fbc86  8bf9                 mov edi, ecx
// 007fbc88  397708               cmp dword ptr [edi + 8], esi
// 007fbc8b  7443                 je 0x7fbcd0
// 007fbc8d  68b0647f00           push 0x7f64b0
// 007fbc92  b9d0bab900           mov ecx, 0xb9bad0
// 007fbc97  e8a0a71200           call 0x92643c
// 007fbc9c  85f6                 test esi, esi
// 007fbc9e  7419                 je 0x7fbcb9
// 007fbca0  85c0                 test eax, eax
// 007fbca2  7505                 jne 0x7fbca9
// 007fbca4  e8637effff           call 0x7f3b0c
// 007fbca9  56                   push esi
// 007fbcaa  8bc8                 mov ecx, eax
// 007fbcac  e80f3a0700           call 0x86f6c0
// 007fbcb1  897708               mov dword ptr [edi + 8], esi
// 007fbcb4  5f                   pop edi
// 007fbcb5  5e                   pop esi
// 007fbcb6  c20400               ret 4
// 007fbcb9  85c0                 test eax, eax
// 007fbcbb  7505                 jne 0x7fbcc2
// 007fbcbd  e84a7effff           call 0x7f3b0c
// 007fbcc2  8b4f08               mov ecx, dword ptr [edi + 8]
// 007fbcc5  51                   push ecx
// 007fbcc6  8bc8                 mov ecx, eax
// 007fbcc8  e873340700           call 0x86f140
// 007fbccd  897708               mov dword ptr [edi + 8], esi
// 007fbcd0  5f                   pop edi
// 007fbcd1  5e                   pop esi
// 007fbcd2  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?SetAutoCompeteHandle@CXTPControlComboBoxAutoCompleteWnd@@AAEXPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
