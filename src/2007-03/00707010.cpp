// from server: 100% by auto
// roc 2007-03 00707010  unit: seg_00700000  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707010
//
// 00707010  83ec30               sub esp, 0x30
// 00707013  53                   push ebx
// 00707014  55                   push ebp
// 00707015  56                   push esi
// 00707016  8bf1                 mov esi, ecx
// 00707018  57                   push edi
// 00707019  56                   push esi
// 0070701a  8d4c2424             lea ecx, [esp + 0x24]
// 0070701e  e83d48f6ff           call 0x66b860
// 00707023  6afe                 push -2
// 00707025  6afe                 push -2
// 00707027  8d442428             lea eax, [esp + 0x28]
// 0070702b  50                   push eax
// 0070702c  ff159ced7700         call dword ptr [0x77ed9c]
// 00707032  8b442424             mov eax, dword ptr [esp + 0x24]
// 00707036  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0070703a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0070703e  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00707042  8bf8                 mov edi, eax
// 00707044  83c013               add eax, 0x13
// 00707047  6a01                 push 1
// 00707049  89542440             mov dword ptr [esp + 0x40], edx
// 0070704d  894c243c             mov dword ptr [esp + 0x3c], ecx
// 00707051  2bd0                 sub edx, eax
// 00707053  52                   push edx
// 00707054  2bcb                 sub ecx, ebx
// 00707056  51                   push ecx
// 00707057  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0070705a  50                   push eax
// 0070705b  53                   push ebx
// 0070705c  89442438             mov dword ptr [esp + 0x38], eax
// 00707060  e85774f1ff           call 0x61e4bc
// 00707065  8b542438             mov edx, dword ptr [esp + 0x38]
// 00707069  8d6f13               lea ebp, [edi + 0x13]
// 0070706c  6a01                 push 1
// 0070706e  8bcd                 mov ecx, ebp
// 00707070  2bcf                 sub ecx, edi
// 00707072  51                   push ecx
// 00707073  2bd3                 sub edx, ebx
// 00707075  52                   push edx
// 00707076  57                   push edi
// 00707077  53                   push ebx
// 00707078  8d4e60               lea ecx, [esi + 0x60]
// 0070707b  e83c74f1ff           call 0x61e4bc
// 00707080  8b442438             mov eax, dword ptr [esp + 0x38]
// 00707084  6afe                 push -2
// 00707086  6afe                 push -2
// 00707088  8d4c2418             lea ecx, [esp + 0x18]
// 0070708c  51                   push ecx
// 0070708d  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00707091  897c2420             mov dword ptr [esp + 0x20], edi
// 00707095  89442424             mov dword ptr [esp + 0x24], eax
// 00707099  896c2428             mov dword ptr [esp + 0x28], ebp
// 0070709d  ff159ced7700         call dword ptr [0x77ed9c]
// 007070a3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007070a7  8b542414             mov edx, dword ptr [esp + 0x14]
// 007070ab  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007070af  8d48f0               lea ecx, [eax - 0x10]
// 007070b2  6a01                 push 1
// 007070b4  2bfa                 sub edi, edx
// 007070b6  57                   push edi
// 007070b7  2bc1                 sub eax, ecx
// 007070b9  50                   push eax
// 007070ba  52                   push edx
// 007070bb  894c2420             mov dword ptr [esp + 0x20], ecx
// 007070bf  51                   push ecx
// 007070c0  8d8ef0010000         lea ecx, [esi + 0x1f0]
// 007070c6  e8f173f1ff           call 0x61e4bc
// 007070cb  5f                   pop edi
// 007070cc  5e                   pop esi
// 007070cd  5d                   pop ebp
// 007070ce  5b                   pop ebx
// 007070cf  83c430               add esp, 0x30
// 007070d2  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?RecalcLayout@CXTCaptionPopupWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
