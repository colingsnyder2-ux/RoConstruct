// from server: 100% by auto
// roc 2010-06 008570a0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008570a0
//
// 008570a0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008570a4  85d2                 test edx, edx
// 008570a6  7428                 je 0x8570d0
// 008570a8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008570ac  85c9                 test ecx, ecx
// 008570ae  7408                 je 0x8570b8
// 008570b0  8b442408             mov eax, dword ptr [esp + 8]
// 008570b4  85c0                 test eax, eax
// 008570b6  7505                 jne 0x8570bd
// 008570b8  e88f0bf5ff           call 0x7a7c4c
// 008570bd  56                   push esi
// 008570be  8bff                 mov edi, edi
// 008570c0  8b30                 mov esi, dword ptr [eax]
// 008570c2  4a                   dec edx
// 008570c3  8931                 mov dword ptr [ecx], esi
// 008570c5  83c104               add ecx, 4
// 008570c8  83c004               add eax, 4
// 008570cb  85d2                 test edx, edx
// 008570cd  75f1                 jne 0x8570c0
// 008570cf  5e                   pop esi
// 008570d0  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribboncategory.cpp (function ??$CopyElements@H@@YGXPAHPBHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribboncategory.cpp
