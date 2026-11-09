// from server: 100% by auto
// roc 2007-08 004028b0  unit: std::bad_alloc  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004028b0
//
// 004028b0  8b442408             mov eax, dword ptr [esp + 8]
// 004028b4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004028b8  83caff               or edx, 0xffffffff
// 004028bb  2bd0                 sub edx, eax
// 004028bd  3bd1                 cmp edx, ecx
// 004028bf  7306                 jae 0x4028c7
// 004028c1  b857000780           mov eax, 0x80070057
// 004028c6  c3                   ret 
// 004028c7  03c1                 add eax, ecx
// 004028c9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004028cd  8901                 mov dword ptr [ecx], eax
// 004028cf  33c0                 xor eax, eax
// 004028d1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
