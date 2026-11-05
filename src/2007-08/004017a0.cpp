// from server: 100% by auto
// roc 2007-08 004017a0  unit: CAboutRobloxDialog  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004017a0
//
// 004017a0  8b442408             mov eax, dword ptr [esp + 8]
// 004017a4  f764240c             mul dword ptr [esp + 0xc]
// 004017a8  85d2                 test edx, edx
// 004017aa  7705                 ja 0x4017b1
// 004017ac  83f8ff               cmp eax, -1
// 004017af  7606                 jbe 0x4017b7
// 004017b1  b857000780           mov eax, 0x80070057
// 004017b6  c3                   ret 
// 004017b7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004017bb  8901                 mov dword ptr [ecx], eax
// 004017bd  33c0                 xor eax, eax
// 004017bf  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
