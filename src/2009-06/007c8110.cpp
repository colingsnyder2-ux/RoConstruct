// from server: 100% by auto
// roc 2009-06 007c8110  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c8110
//
// 007c8110  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007c8114  85d2                 test edx, edx
// 007c8116  7428                 je 0x7c8140
// 007c8118  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c811c  85c9                 test ecx, ecx
// 007c811e  7408                 je 0x7c8128
// 007c8120  8b442408             mov eax, dword ptr [esp + 8]
// 007c8124  85c0                 test eax, eax
// 007c8126  7505                 jne 0x7c812d
// 007c8128  e8b70bf5ff           call 0x718ce4
// 007c812d  56                   push esi
// 007c812e  8bff                 mov edi, edi
// 007c8130  8b30                 mov esi, dword ptr [eax]
// 007c8132  4a                   dec edx
// 007c8133  8931                 mov dword ptr [ecx], esi
// 007c8135  83c104               add ecx, 4
// 007c8138  83c004               add eax, 4
// 007c813b  85d2                 test edx, edx
// 007c813d  75f1                 jne 0x7c8130
// 007c813f  5e                   pop esi
// 007c8140  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ??$CopyElements@H@@YGXPAHPBHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
