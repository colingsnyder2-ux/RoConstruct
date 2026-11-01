// from server: 100% by auto
// roc 2009-06 0071aed0  unit: CXTPEdit  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071aed0
//
// 0071aed0  83ec1c               sub esp, 0x1c
// 0071aed3  57                   push edi
// 0071aed4  8bf9                 mov edi, ecx
// 0071aed6  837f0800             cmp dword ptr [edi + 8], 0
// 0071aeda  7509                 jne 0x71aee5
// 0071aedc  33c0                 xor eax, eax
// 0071aede  5f                   pop edi
// 0071aedf  83c41c               add esp, 0x1c
// 0071aee2  c20800               ret 8
// 0071aee5  53                   push ebx
// 0071aee6  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0071aeea  83fb26               cmp ebx, 0x26
// 0071aeed  740f                 je 0x71aefe
// 0071aeef  83fb28               cmp ebx, 0x28
// 0071aef2  740a                 je 0x71aefe
// 0071aef4  83fb22               cmp ebx, 0x22
// 0071aef7  7405                 je 0x71aefe
// 0071aef9  83fb21               cmp ebx, 0x21
// 0071aefc  750d                 jne 0x71af0b
// 0071aefe  6a12                 push 0x12
// 0071af00  ff1534ee8900         call dword ptr [0x89ee34]
// 0071af06  6685c0               test ax, ax
// 0071af09  7d0a                 jge 0x71af15
// 0071af0b  5b                   pop ebx
// 0071af0c  33c0                 xor eax, eax
// 0071af0e  5f                   pop edi
// 0071af0f  83c41c               add esp, 0x1c
// 0071af12  c20800               ret 8
// 0071af15  8b4708               mov eax, dword ptr [edi + 8]
// 0071af18  56                   push esi
// 0071af19  8b3568ee8900         mov esi, dword ptr [0x89ee68]
// 0071af1f  6a05                 push 5
// 0071af21  50                   push eax
// 0071af22  ffd6                 call esi
// 0071af24  6a01                 push 1
// 0071af26  50                   push eax
// 0071af27  ffd6                 call esi
// 0071af29  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0071af2d  8d54240c             lea edx, [esp + 0xc]
// 0071af31  8944240c             mov dword ptr [esp + 0xc], eax
// 0071af35  8b4708               mov eax, dword ptr [edi + 8]
// 0071af38  52                   push edx
// 0071af39  50                   push eax
// 0071af3a  c744241800010000     mov dword ptr [esp + 0x18], 0x100
// 0071af42  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0071af46  894c2420             mov dword ptr [esp + 0x20], ecx
// 0071af4a  ff15a8ee8900         call dword ptr [0x89eea8]
// 0071af50  f7d8                 neg eax
// 0071af52  5e                   pop esi
// 0071af53  1bc0                 sbb eax, eax
// 0071af55  5b                   pop ebx
// 0071af56  f7d8                 neg eax
// 0071af58  5f                   pop edi
// 0071af59  83c41c               add esp, 0x1c
// 0071af5c  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?IsDialogCode@CXTPControlComboBoxAutoCompleteWnd@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
