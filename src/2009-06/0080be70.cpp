// from server: 100% by auto
// roc 2009-06 0080be70  unit: CXTCaptionPopupWnd  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080be70
//
// 0080be70  83ec30               sub esp, 0x30
// 0080be73  53                   push ebx
// 0080be74  55                   push ebp
// 0080be75  56                   push esi
// 0080be76  8bf1                 mov esi, ecx
// 0080be78  57                   push edi
// 0080be79  56                   push esi
// 0080be7a  8d4c2424             lea ecx, [esp + 0x24]
// 0080be7e  e84d46f6ff           call 0x7704d0
// 0080be83  6afe                 push -2
// 0080be85  6afe                 push -2
// 0080be87  8d442428             lea eax, [esp + 0x28]
// 0080be8b  50                   push eax
// 0080be8c  ff15bced8900         call dword ptr [0x89edbc]
// 0080be92  8b442424             mov eax, dword ptr [esp + 0x24]
// 0080be96  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0080be9a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0080be9e  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0080bea2  8bf8                 mov edi, eax
// 0080bea4  83c013               add eax, 0x13
// 0080bea7  6a01                 push 1
// 0080bea9  89542440             mov dword ptr [esp + 0x40], edx
// 0080bead  894c243c             mov dword ptr [esp + 0x3c], ecx
// 0080beb1  2bd0                 sub edx, eax
// 0080beb3  52                   push edx
// 0080beb4  2bcb                 sub ecx, ebx
// 0080beb6  51                   push ecx
// 0080beb7  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0080beba  50                   push eax
// 0080bebb  53                   push ebx
// 0080bebc  89442438             mov dword ptr [esp + 0x38], eax
// 0080bec0  e845cff0ff           call 0x718e0a
// 0080bec5  8b542438             mov edx, dword ptr [esp + 0x38]
// 0080bec9  8d6f13               lea ebp, [edi + 0x13]
// 0080becc  6a01                 push 1
// 0080bece  8bcd                 mov ecx, ebp
// 0080bed0  2bcf                 sub ecx, edi
// 0080bed2  51                   push ecx
// 0080bed3  2bd3                 sub edx, ebx
// 0080bed5  52                   push edx
// 0080bed6  57                   push edi
// 0080bed7  53                   push ebx
// 0080bed8  8d4e60               lea ecx, [esi + 0x60]
// 0080bedb  e82acff0ff           call 0x718e0a
// 0080bee0  8b442438             mov eax, dword ptr [esp + 0x38]
// 0080bee4  6afe                 push -2
// 0080bee6  6afe                 push -2
// 0080bee8  8d4c2418             lea ecx, [esp + 0x18]
// 0080beec  51                   push ecx
// 0080beed  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0080bef1  897c2420             mov dword ptr [esp + 0x20], edi
// 0080bef5  89442424             mov dword ptr [esp + 0x24], eax
// 0080bef9  896c2428             mov dword ptr [esp + 0x28], ebp
// 0080befd  ff15bced8900         call dword ptr [0x89edbc]
// 0080bf03  8b442418             mov eax, dword ptr [esp + 0x18]
// 0080bf07  8b542414             mov edx, dword ptr [esp + 0x14]
// 0080bf0b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0080bf0f  8d48f0               lea ecx, [eax - 0x10]
// 0080bf12  6a01                 push 1
// 0080bf14  2bfa                 sub edi, edx
// 0080bf16  57                   push edi
// 0080bf17  2bc1                 sub eax, ecx
// 0080bf19  50                   push eax
// 0080bf1a  52                   push edx
// 0080bf1b  894c2420             mov dword ptr [esp + 0x20], ecx
// 0080bf1f  51                   push ecx
// 0080bf20  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 0080bf26  e8dfcef0ff           call 0x718e0a
// 0080bf2b  5f                   pop edi
// 0080bf2c  5e                   pop esi
// 0080bf2d  5d                   pop ebp
// 0080bf2e  5b                   pop ebx
// 0080bf2f  83c430               add esp, 0x30
// 0080bf32  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RecalcLayout@CXTCaptionPopupWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
