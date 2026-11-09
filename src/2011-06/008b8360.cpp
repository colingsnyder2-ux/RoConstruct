// from server: 100% by auto
// roc 2011-06 008b8360  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b8360
//
// 008b8360  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008b8364  85d2                 test edx, edx
// 008b8366  7428                 je 0x8b8390
// 008b8368  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008b836c  85c9                 test ecx, ecx
// 008b836e  7408                 je 0x8b8378
// 008b8370  8b442408             mov eax, dword ptr [esp + 8]
// 008b8374  85c0                 test eax, eax
// 008b8376  7505                 jne 0x8b837d
// 008b8378  e88d1ff5ff           call 0x80a30a
// 008b837d  56                   push esi
// 008b837e  8bff                 mov edi, edi
// 008b8380  8b30                 mov esi, dword ptr [eax]
// 008b8382  4a                   dec edx
// 008b8383  8931                 mov dword ptr [ecx], esi
// 008b8385  83c104               add ecx, 4
// 008b8388  83c004               add eax, 4
// 008b838b  85d2                 test edx, edx
// 008b838d  75f1                 jne 0x8b8380
// 008b838f  5e                   pop esi
// 008b8390  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ??$CopyElements@H@@YGXPAHPBHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
