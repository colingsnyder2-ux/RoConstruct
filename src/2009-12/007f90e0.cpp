// from server: 100% by auto
// roc 2009-12 007f90e0  unit: CXTPEdit  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f90e0
//
// 007f90e0  83ec1c               sub esp, 0x1c
// 007f90e3  57                   push edi
// 007f90e4  8bf9                 mov edi, ecx
// 007f90e6  837f0800             cmp dword ptr [edi + 8], 0
// 007f90ea  7509                 jne 0x7f90f5
// 007f90ec  33c0                 xor eax, eax
// 007f90ee  5f                   pop edi
// 007f90ef  83c41c               add esp, 0x1c
// 007f90f2  c20800               ret 8
// 007f90f5  53                   push ebx
// 007f90f6  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 007f90fa  83fb26               cmp ebx, 0x26
// 007f90fd  740f                 je 0x7f910e
// 007f90ff  83fb28               cmp ebx, 0x28
// 007f9102  740a                 je 0x7f910e
// 007f9104  83fb22               cmp ebx, 0x22
// 007f9107  7405                 je 0x7f910e
// 007f9109  83fb21               cmp ebx, 0x21
// 007f910c  750d                 jne 0x7f911b
// 007f910e  6a12                 push 0x12
// 007f9110  ff1530cc9800         call dword ptr [0x98cc30]
// 007f9116  6685c0               test ax, ax
// 007f9119  7d0a                 jge 0x7f9125
// 007f911b  5b                   pop ebx
// 007f911c  33c0                 xor eax, eax
// 007f911e  5f                   pop edi
// 007f911f  83c41c               add esp, 0x1c
// 007f9122  c20800               ret 8
// 007f9125  8b4708               mov eax, dword ptr [edi + 8]
// 007f9128  56                   push esi
// 007f9129  8b35fccb9800         mov esi, dword ptr [0x98cbfc]
// 007f912f  6a05                 push 5
// 007f9131  50                   push eax
// 007f9132  ffd6                 call esi
// 007f9134  6a01                 push 1
// 007f9136  50                   push eax
// 007f9137  ffd6                 call esi
// 007f9139  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007f913d  8d54240c             lea edx, [esp + 0xc]
// 007f9141  8944240c             mov dword ptr [esp + 0xc], eax
// 007f9145  8b4708               mov eax, dword ptr [edi + 8]
// 007f9148  52                   push edx
// 007f9149  50                   push eax
// 007f914a  c744241800010000     mov dword ptr [esp + 0x18], 0x100
// 007f9152  895c241c             mov dword ptr [esp + 0x1c], ebx
// 007f9156  894c2420             mov dword ptr [esp + 0x20], ecx
// 007f915a  ff15b8ca9800         call dword ptr [0x98cab8]
// 007f9160  f7d8                 neg eax
// 007f9162  5e                   pop esi
// 007f9163  1bc0                 sbb eax, eax
// 007f9165  5b                   pop ebx
// 007f9166  f7d8                 neg eax
// 007f9168  5f                   pop edi
// 007f9169  83c41c               add esp, 0x1c
// 007f916c  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?IsDialogCode@CXTPControlComboBoxAutoCompleteWnd@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
