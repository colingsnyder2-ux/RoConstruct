// from server: 100% by auto
// roc 2009-06 00818000  unit: CXTPDialogBar  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00818000
//
// 00818000  53                   push ebx
// 00818001  56                   push esi
// 00818002  57                   push edi
// 00818003  8bf1                 mov esi, ecx
// 00818005  e8fe0ff0ff           call 0x719008
// 0081800a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0081800e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00818012  83ec10               sub esp, 0x10
// 00818015  8bc4                 mov eax, esp
// 00818017  33c9                 xor ecx, ecx
// 00818019  8908                 mov dword ptr [eax], ecx
// 0081801b  33d2                 xor edx, edx
// 0081801d  895004               mov dword ptr [eax + 4], edx
// 00818020  897808               mov dword ptr [eax + 8], edi
// 00818023  8bce                 mov ecx, esi
// 00818025  89580c               mov dword ptr [eax + 0xc], ebx
// 00818028  e863ffffff           call 0x817f90
// 0081802d  5f                   pop edi
// 0081802e  5e                   pop esi
// 0081802f  5b                   pop ebx
// 00818030  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPDialogBar.cpp (function ?OnSize@CXTPDialogBar@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDialogBar.cpp
