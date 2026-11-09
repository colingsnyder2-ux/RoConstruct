// from server: 100% by auto
// roc 2007-03 004017b0  unit: seg_00400000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004017b0
//
// 004017b0  8b442408             mov eax, dword ptr [esp + 8]
// 004017b4  f764240c             mul dword ptr [esp + 0xc]
// 004017b8  85d2                 test edx, edx
// 004017ba  7705                 ja 0x4017c1
// 004017bc  83f8ff               cmp eax, -1
// 004017bf  7606                 jbe 0x4017c7
// 004017c1  b857000780           mov eax, 0x80070057
// 004017c6  c3                   ret 
// 004017c7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004017cb  8901                 mov dword ptr [ecx], eax
// 004017cd  33c0                 xor eax, eax
// 004017cf  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
