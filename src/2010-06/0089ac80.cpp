// from server: 100% by auto
// roc 2010-06 0089ac80  unit: CXTCaptionPopupWnd  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089ac80
//
// 0089ac80  83ec30               sub esp, 0x30
// 0089ac83  53                   push ebx
// 0089ac84  55                   push ebp
// 0089ac85  56                   push esi
// 0089ac86  8bf1                 mov esi, ecx
// 0089ac88  57                   push edi
// 0089ac89  56                   push esi
// 0089ac8a  8d4c2424             lea ecx, [esp + 0x24]
// 0089ac8e  e87d46f6ff           call 0x7ff310
// 0089ac93  6afe                 push -2
// 0089ac95  6afe                 push -2
// 0089ac97  8d442428             lea eax, [esp + 0x28]
// 0089ac9b  50                   push eax
// 0089ac9c  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 0089aca2  8b442424             mov eax, dword ptr [esp + 0x24]
// 0089aca6  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0089acaa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0089acae  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0089acb2  8bf8                 mov edi, eax
// 0089acb4  83c013               add eax, 0x13
// 0089acb7  6a01                 push 1
// 0089acb9  89542440             mov dword ptr [esp + 0x40], edx
// 0089acbd  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0089acc1  2bd0                 sub edx, eax
// 0089acc3  52                   push edx
// 0089acc4  2bcb                 sub ecx, ebx
// 0089acc6  51                   push ecx
// 0089acc7  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0089acca  50                   push eax
// 0089accb  53                   push ebx
// 0089accc  89442438             mov dword ptr [esp + 0x38], eax
// 0089acd0  e89dd0f0ff           call 0x7a7d72
// 0089acd5  8b542438             mov edx, dword ptr [esp + 0x38]
// 0089acd9  8d6f13               lea ebp, [edi + 0x13]
// 0089acdc  6a01                 push 1
// 0089acde  8bcd                 mov ecx, ebp
// 0089ace0  2bcf                 sub ecx, edi
// 0089ace2  51                   push ecx
// 0089ace3  2bd3                 sub edx, ebx
// 0089ace5  52                   push edx
// 0089ace6  57                   push edi
// 0089ace7  53                   push ebx
// 0089ace8  8d4e60               lea ecx, [esi + 0x60]
// 0089aceb  e882d0f0ff           call 0x7a7d72
// 0089acf0  8b442438             mov eax, dword ptr [esp + 0x38]
// 0089acf4  6afe                 push -2
// 0089acf6  6afe                 push -2
// 0089acf8  8d4c2418             lea ecx, [esp + 0x18]
// 0089acfc  51                   push ecx
// 0089acfd  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0089ad01  897c2420             mov dword ptr [esp + 0x20], edi
// 0089ad05  89442424             mov dword ptr [esp + 0x24], eax
// 0089ad09  896c2428             mov dword ptr [esp + 0x28], ebp
// 0089ad0d  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 0089ad13  8b442418             mov eax, dword ptr [esp + 0x18]
// 0089ad17  8b542414             mov edx, dword ptr [esp + 0x14]
// 0089ad1b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0089ad1f  8d48f0               lea ecx, [eax - 0x10]
// 0089ad22  6a01                 push 1
// 0089ad24  2bfa                 sub edi, edx
// 0089ad26  57                   push edi
// 0089ad27  2bc1                 sub eax, ecx
// 0089ad29  50                   push eax
// 0089ad2a  52                   push edx
// 0089ad2b  894c2420             mov dword ptr [esp + 0x20], ecx
// 0089ad2f  51                   push ecx
// 0089ad30  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 0089ad36  e837d0f0ff           call 0x7a7d72
// 0089ad3b  5f                   pop edi
// 0089ad3c  5e                   pop esi
// 0089ad3d  5d                   pop ebp
// 0089ad3e  5b                   pop ebx
// 0089ad3f  83c430               add esp, 0x30
// 0089ad42  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RecalcLayout@CXTCaptionPopupWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
