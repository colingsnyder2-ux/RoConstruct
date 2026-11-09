// from server: 100% by auto
// roc 2007-03 004028a0  unit: seg_00400000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004028a0
//
// 004028a0  8b442408             mov eax, dword ptr [esp + 8]
// 004028a4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004028a8  83caff               or edx, 0xffffffff
// 004028ab  2bd0                 sub edx, eax
// 004028ad  3bd1                 cmp edx, ecx
// 004028af  7306                 jae 0x4028b7
// 004028b1  b857000780           mov eax, 0x80070057
// 004028b6  c3                   ret 
// 004028b7  03c1                 add eax, ecx
// 004028b9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004028bd  8901                 mov dword ptr [ecx], eax
// 004028bf  33c0                 xor eax, eax
// 004028c1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlAdd@K@ATL@@YAJPAKKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
