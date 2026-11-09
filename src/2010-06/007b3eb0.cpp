// from server: 100% by auto
// roc 2010-06 007b3eb0  unit: CXTPEdit  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3eb0
//
// 007b3eb0  83ec1c               sub esp, 0x1c
// 007b3eb3  57                   push edi
// 007b3eb4  8bf9                 mov edi, ecx
// 007b3eb6  837f0800             cmp dword ptr [edi + 8], 0
// 007b3eba  7509                 jne 0x7b3ec5
// 007b3ebc  33c0                 xor eax, eax
// 007b3ebe  5f                   pop edi
// 007b3ebf  83c41c               add esp, 0x1c
// 007b3ec2  c20800               ret 8
// 007b3ec5  53                   push ebx
// 007b3ec6  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 007b3eca  83fb26               cmp ebx, 0x26
// 007b3ecd  740f                 je 0x7b3ede
// 007b3ecf  83fb28               cmp ebx, 0x28
// 007b3ed2  740a                 je 0x7b3ede
// 007b3ed4  83fb22               cmp ebx, 0x22
// 007b3ed7  7405                 je 0x7b3ede
// 007b3ed9  83fb21               cmp ebx, 0x21
// 007b3edc  750d                 jne 0x7b3eeb
// 007b3ede  6a12                 push 0x12
// 007b3ee0  ff157cbc9e00         call dword ptr [0x9ebc7c]
// 007b3ee6  6685c0               test ax, ax
// 007b3ee9  7d0a                 jge 0x7b3ef5
// 007b3eeb  5b                   pop ebx
// 007b3eec  33c0                 xor eax, eax
// 007b3eee  5f                   pop edi
// 007b3eef  83c41c               add esp, 0x1c
// 007b3ef2  c20800               ret 8
// 007b3ef5  8b4708               mov eax, dword ptr [edi + 8]
// 007b3ef8  56                   push esi
// 007b3ef9  8b3590ba9e00         mov esi, dword ptr [0x9eba90]
// 007b3eff  6a05                 push 5
// 007b3f01  50                   push eax
// 007b3f02  ffd6                 call esi
// 007b3f04  6a01                 push 1
// 007b3f06  50                   push eax
// 007b3f07  ffd6                 call esi
// 007b3f09  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007b3f0d  8d54240c             lea edx, [esp + 0xc]
// 007b3f11  8944240c             mov dword ptr [esp + 0xc], eax
// 007b3f15  8b4708               mov eax, dword ptr [edi + 8]
// 007b3f18  52                   push edx
// 007b3f19  50                   push eax
// 007b3f1a  c744241800010000     mov dword ptr [esp + 0x18], 0x100
// 007b3f22  895c241c             mov dword ptr [esp + 0x1c], ebx
// 007b3f26  894c2420             mov dword ptr [esp + 0x20], ecx
// 007b3f2a  ff15acb99e00         call dword ptr [0x9eb9ac]
// 007b3f30  f7d8                 neg eax
// 007b3f32  5e                   pop esi
// 007b3f33  1bc0                 sbb eax, eax
// 007b3f35  5b                   pop ebx
// 007b3f36  f7d8                 neg eax
// 007b3f38  5f                   pop edi
// 007b3f39  83c41c               add esp, 0x1c
// 007b3f3c  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?IsDialogCode@CXTPControlComboBoxAutoCompleteWnd@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
