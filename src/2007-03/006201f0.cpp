// from server: 100% by auto
// roc 2007-03 006201f0  unit: seg_00620000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006201f0
//
// 006201f0  83ec1c               sub esp, 0x1c
// 006201f3  57                   push edi
// 006201f4  8bf9                 mov edi, ecx
// 006201f6  837f0800             cmp dword ptr [edi + 8], 0
// 006201fa  7509                 jne 0x620205
// 006201fc  33c0                 xor eax, eax
// 006201fe  5f                   pop edi
// 006201ff  83c41c               add esp, 0x1c
// 00620202  c20800               ret 8
// 00620205  53                   push ebx
// 00620206  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0062020a  83fb26               cmp ebx, 0x26
// 0062020d  740f                 je 0x62021e
// 0062020f  83fb28               cmp ebx, 0x28
// 00620212  740a                 je 0x62021e
// 00620214  83fb22               cmp ebx, 0x22
// 00620217  7405                 je 0x62021e
// 00620219  83fb21               cmp ebx, 0x21
// 0062021c  750d                 jne 0x62022b
// 0062021e  6a12                 push 0x12
// 00620220  ff151ced7700         call dword ptr [0x77ed1c]
// 00620226  6685c0               test ax, ax
// 00620229  7d0a                 jge 0x620235
// 0062022b  5b                   pop ebx
// 0062022c  33c0                 xor eax, eax
// 0062022e  5f                   pop edi
// 0062022f  83c41c               add esp, 0x1c
// 00620232  c20800               ret 8
// 00620235  8b4708               mov eax, dword ptr [edi + 8]
// 00620238  56                   push esi
// 00620239  8b3588ed7700         mov esi, dword ptr [0x77ed88]
// 0062023f  6a05                 push 5
// 00620241  50                   push eax
// 00620242  ffd6                 call esi
// 00620244  6a01                 push 1
// 00620246  50                   push eax
// 00620247  ffd6                 call esi
// 00620249  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0062024d  8d54240c             lea edx, [esp + 0xc]
// 00620251  8944240c             mov dword ptr [esp + 0xc], eax
// 00620255  8b4708               mov eax, dword ptr [edi + 8]
// 00620258  52                   push edx
// 00620259  50                   push eax
// 0062025a  c744241800010000     mov dword ptr [esp + 0x18], 0x100
// 00620262  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00620266  894c2420             mov dword ptr [esp + 0x20], ecx
// 0062026a  ff15d4ee7700         call dword ptr [0x77eed4]
// 00620270  f7d8                 neg eax
// 00620272  5e                   pop esi
// 00620273  1bc0                 sbb eax, eax
// 00620275  5b                   pop ebx
// 00620276  f7d8                 neg eax
// 00620278  5f                   pop edi
// 00620279  83c41c               add esp, 0x1c
// 0062027c  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?IsDialogCode@CXTPControlComboBoxAutoCompleteWnd@@QAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
