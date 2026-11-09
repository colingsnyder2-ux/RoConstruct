// from server: 100% by auto
// roc 2008-06 00401710  unit: CAboutRobloxDialog  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401710
//
// 00401710  8b442408             mov eax, dword ptr [esp + 8]
// 00401714  f76c240c             imul dword ptr [esp + 0xc]
// 00401718  8bc8                 mov ecx, eax
// 0040171a  81c100000080         add ecx, 0x80000000
// 00401720  83d200               adc edx, 0
// 00401723  85d2                 test edx, edx
// 00401725  7710                 ja 0x401737
// 00401727  7205                 jb 0x40172e
// 00401729  83f9ff               cmp ecx, -1
// 0040172c  7709                 ja 0x401737
// 0040172e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00401732  8901                 mov dword ptr [ecx], eax
// 00401734  33c0                 xor eax, eax
// 00401736  c3                   ret 
// 00401737  b857000780           mov eax, 0x80070057
// 0040173c  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??$AtlMultiply@H@ATL@@YAJPAHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgdhtml.cpp
