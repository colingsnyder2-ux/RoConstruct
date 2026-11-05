// from server: 100% by auto
// roc 2007-08 00401770  unit: CAboutRobloxDialog  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401770
//
// 00401770  8b442408             mov eax, dword ptr [esp + 8]
// 00401774  f76c240c             imul dword ptr [esp + 0xc]
// 00401778  8bc8                 mov ecx, eax
// 0040177a  81c100000080         add ecx, 0x80000000
// 00401780  83d200               adc edx, 0
// 00401783  85d2                 test edx, edx
// 00401785  7710                 ja 0x401797
// 00401787  7205                 jb 0x40178e
// 00401789  83f9ff               cmp ecx, -1
// 0040178c  7709                 ja 0x401797
// 0040178e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00401792  8901                 mov dword ptr [ecx], eax
// 00401794  33c0                 xor eax, eax
// 00401796  c3                   ret 
// 00401797  b857000780           mov eax, 0x80070057
// 0040179c  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
