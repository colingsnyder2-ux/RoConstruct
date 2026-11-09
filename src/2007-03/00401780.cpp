// from server: 100% by auto
// roc 2007-03 00401780  unit: seg_00400000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401780
//
// 00401780  8b442408             mov eax, dword ptr [esp + 8]
// 00401784  f76c240c             imul dword ptr [esp + 0xc]
// 00401788  8bc8                 mov ecx, eax
// 0040178a  81c100000080         add ecx, 0x80000000
// 00401790  83d200               adc edx, 0
// 00401793  85d2                 test edx, edx
// 00401795  7710                 ja 0x4017a7
// 00401797  7205                 jb 0x40179e
// 00401799  83f9ff               cmp ecx, -1
// 0040179c  7709                 ja 0x4017a7
// 0040179e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004017a2  8901                 mov dword ptr [ecx], eax
// 004017a4  33c0                 xor eax, eax
// 004017a6  c3                   ret 
// 004017a7  b857000780           mov eax, 0x80070057
// 004017ac  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
