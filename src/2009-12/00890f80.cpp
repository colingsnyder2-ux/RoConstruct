// from server: 100% by auto
// roc 2009-12 00890f80  unit: ATL::CRegObject  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00890f80
//
// 00890f80  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00890f84  85d2                 test edx, edx
// 00890f86  7428                 je 0x890fb0
// 00890f88  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00890f8c  85c9                 test ecx, ecx
// 00890f8e  7408                 je 0x890f98
// 00890f90  8b442408             mov eax, dword ptr [esp + 8]
// 00890f94  85c0                 test eax, eax
// 00890f96  7505                 jne 0x890f9d
// 00890f98  e86f2bf6ff           call 0x7f3b0c
// 00890f9d  56                   push esi
// 00890f9e  8bff                 mov edi, edi
// 00890fa0  8b30                 mov esi, dword ptr [eax]
// 00890fa2  4a                   dec edx
// 00890fa3  8931                 mov dword ptr [ecx], esi
// 00890fa5  83c104               add ecx, 4
// 00890fa8  83c004               add eax, 4
// 00890fab  85d2                 test edx, edx
// 00890fad  75f1                 jne 0x890fa0
// 00890faf  5e                   pop esi
// 00890fb0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ??$CopyElements@H@@YGXPAHPBHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
