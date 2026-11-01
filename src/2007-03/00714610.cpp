// from server: 100% by auto
// roc 2007-03 00714610  unit: seg_00710000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00714610
//
// 00714610  53                   push ebx
// 00714611  56                   push esi
// 00714612  57                   push edi
// 00714613  8bf1                 mov esi, ecx
// 00714615  e8b8a0f0ff           call 0x61e6d2
// 0071461a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0071461e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00714622  83ec10               sub esp, 0x10
// 00714625  8bc4                 mov eax, esp
// 00714627  33c9                 xor ecx, ecx
// 00714629  8908                 mov dword ptr [eax], ecx
// 0071462b  33d2                 xor edx, edx
// 0071462d  895004               mov dword ptr [eax + 4], edx
// 00714630  897808               mov dword ptr [eax + 8], edi
// 00714633  8bce                 mov ecx, esi
// 00714635  89580c               mov dword ptr [eax + 0xc], ebx
// 00714638  e863ffffff           call 0x7145a0
// 0071463d  5f                   pop edi
// 0071463e  5e                   pop esi
// 0071463f  5b                   pop ebx
// 00714640  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPDialogBar.cpp (function ?OnSize@CXTPDialogBar@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDialogBar.cpp
