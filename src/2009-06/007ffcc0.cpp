// from server: 100% by auto
// roc 2009-06 007ffcc0  unit: CXTColorHex  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ffcc0
//
// 007ffcc0  51                   push ecx
// 007ffcc1  53                   push ebx
// 007ffcc2  55                   push ebp
// 007ffcc3  894c2408             mov dword ptr [esp + 8], ecx
// 007ffcc7  8b4978               mov ecx, dword ptr [ecx + 0x78]
// 007ffcca  56                   push esi
// 007ffccb  57                   push edi
// 007ffccc  85c9                 test ecx, ecx
// 007ffcce  7440                 je 0x7ffd10
// 007ffcd0  8b6908               mov ebp, dword ptr [ecx + 8]
// 007ffcd3  85ed                 test ebp, ebp
// 007ffcd5  7439                 je 0x7ffd10
// 007ffcd7  8b4510               mov eax, dword ptr [ebp + 0x10]
// 007ffcda  f7d8                 neg eax
// 007ffcdc  1bc0                 sbb eax, eax
// 007ffcde  25f5fdffff           and eax, 0xfffffdf5
// 007ffce3  05b3020000           add eax, 0x2b3
// 007ffce8  33f6                 xor esi, esi
// 007ffcea  85c0                 test eax, eax
// 007ffcec  7e1c                 jle 0x7ffd0a
// 007ffcee  8b5514               mov edx, dword ptr [ebp + 0x14]
// 007ffcf1  8b3a                 mov edi, dword ptr [edx]
// 007ffcf3  8b5a04               mov ebx, dword ptr [edx + 4]
// 007ffcf6  397c2418             cmp dword ptr [esp + 0x18], edi
// 007ffcfa  7506                 jne 0x7ffd02
// 007ffcfc  395c241c             cmp dword ptr [esp + 0x1c], ebx
// 007ffd00  7419                 je 0x7ffd1b
// 007ffd02  46                   inc esi
// 007ffd03  83c208               add edx, 8
// 007ffd06  3bf0                 cmp esi, eax
// 007ffd08  7ce7                 jl 0x7ffcf1
// 007ffd0a  8b09                 mov ecx, dword ptr [ecx]
// 007ffd0c  85c9                 test ecx, ecx
// 007ffd0e  75c0                 jne 0x7ffcd0
// 007ffd10  5f                   pop edi
// 007ffd11  5e                   pop esi
// 007ffd12  5d                   pop ebp
// 007ffd13  83c8ff               or eax, 0xffffffff
// 007ffd16  5b                   pop ebx
// 007ffd17  59                   pop ecx
// 007ffd18  c20800               ret 8
// 007ffd1b  8b4514               mov eax, dword ptr [ebp + 0x14]
// 007ffd1e  8b10                 mov edx, dword ptr [eax]
// 007ffd20  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ffd24  895168               mov dword ptr [ecx + 0x68], edx
// 007ffd27  8b4004               mov eax, dword ptr [eax + 4]
// 007ffd2a  89416c               mov dword ptr [ecx + 0x6c], eax
// 007ffd2d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007ffd30  5f                   pop edi
// 007ffd31  5e                   pop esi
// 007ffd32  895164               mov dword ptr [ecx + 0x64], edx
// 007ffd35  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007ffd38  5d                   pop ebp
// 007ffd39  5b                   pop ebx
// 007ffd3a  59                   pop ecx
// 007ffd3b  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?ColorFromPoint@CXTColorHex@@QAEKVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
