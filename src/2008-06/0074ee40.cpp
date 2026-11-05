// from server: 100% by auto
// roc 2008-06 0074ee40  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0074ee40
//
// 0074ee40  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0074ee44  85d2                 test edx, edx
// 0074ee46  7428                 je 0x74ee70
// 0074ee48  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0074ee4c  85c9                 test ecx, ecx
// 0074ee4e  7408                 je 0x74ee58
// 0074ee50  8b442408             mov eax, dword ptr [esp + 8]
// 0074ee54  85c0                 test eax, eax
// 0074ee56  7505                 jne 0x74ee5d
// 0074ee58  e8e71af5ff           call 0x6a0944
// 0074ee5d  56                   push esi
// 0074ee5e  8bff                 mov edi, edi
// 0074ee60  8b30                 mov esi, dword ptr [eax]
// 0074ee62  4a                   dec edx
// 0074ee63  8931                 mov dword ptr [ecx], esi
// 0074ee65  83c104               add ecx, 4
// 0074ee68  83c004               add eax, 4
// 0074ee6b  85d2                 test edx, edx
// 0074ee6d  75f1                 jne 0x74ee60
// 0074ee6f  5e                   pop esi
// 0074ee70  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ??$CopyElements@H@@YGXPAHPBHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
