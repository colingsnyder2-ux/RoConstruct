// from server: 100% by auto
// roc 2008-06 00401740  unit: CAboutRobloxDialog  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401740
//
// 00401740  8b442408             mov eax, dword ptr [esp + 8]
// 00401744  f764240c             mul dword ptr [esp + 0xc]
// 00401748  85d2                 test edx, edx
// 0040174a  7705                 ja 0x401751
// 0040174c  83f8ff               cmp eax, -1
// 0040174f  7606                 jbe 0x401757
// 00401751  b857000780           mov eax, 0x80070057
// 00401756  c3                   ret 
// 00401757  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040175b  8901                 mov dword ptr [ecx], eax
// 0040175d  33c0                 xor eax, eax
// 0040175f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??$AtlMultiply@I@ATL@@YAJPAIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
