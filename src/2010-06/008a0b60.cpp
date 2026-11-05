// from server: 100% by auto
// roc 2010-06 008a0b60  unit: CXTPDialogBar  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a0b60
//
// 008a0b60  53                   push ebx
// 008a0b61  56                   push esi
// 008a0b62  57                   push edi
// 008a0b63  8bf1                 mov esi, ecx
// 008a0b65  e80674f0ff           call 0x7a7f70
// 008a0b6a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008a0b6e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008a0b72  83ec10               sub esp, 0x10
// 008a0b75  8bc4                 mov eax, esp
// 008a0b77  33c9                 xor ecx, ecx
// 008a0b79  8908                 mov dword ptr [eax], ecx
// 008a0b7b  33d2                 xor edx, edx
// 008a0b7d  895004               mov dword ptr [eax + 4], edx
// 008a0b80  897808               mov dword ptr [eax + 8], edi
// 008a0b83  8bce                 mov ecx, esi
// 008a0b85  89580c               mov dword ptr [eax + 0xc], ebx
// 008a0b88  e863ffffff           call 0x8a0af0
// 008a0b8d  5f                   pop edi
// 008a0b8e  5e                   pop esi
// 008a0b8f  5b                   pop ebx
// 008a0b90  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPDialogBar.cpp (function ?OnSize@CXTPDialogBar@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDialogBar.cpp
