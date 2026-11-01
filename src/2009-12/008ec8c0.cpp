// from server: 100% by auto
// roc 2009-12 008ec8c0  unit: CXTPDialogBar  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ec8c0
//
// 008ec8c0  53                   push ebx
// 008ec8c1  56                   push esi
// 008ec8c2  57                   push edi
// 008ec8c3  8bf1                 mov esi, ecx
// 008ec8c5  e86675f0ff           call 0x7f3e30
// 008ec8ca  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008ec8ce  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008ec8d2  83ec10               sub esp, 0x10
// 008ec8d5  8bc4                 mov eax, esp
// 008ec8d7  33c9                 xor ecx, ecx
// 008ec8d9  8908                 mov dword ptr [eax], ecx
// 008ec8db  33d2                 xor edx, edx
// 008ec8dd  895004               mov dword ptr [eax + 4], edx
// 008ec8e0  897808               mov dword ptr [eax + 8], edi
// 008ec8e3  8bce                 mov ecx, esi
// 008ec8e5  89580c               mov dword ptr [eax + 0xc], ebx
// 008ec8e8  e863ffffff           call 0x8ec850
// 008ec8ed  5f                   pop edi
// 008ec8ee  5e                   pop esi
// 008ec8ef  5b                   pop ebx
// 008ec8f0  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPDialogBar.cpp (function ?OnSize@CXTPDialogBar@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDialogBar.cpp
