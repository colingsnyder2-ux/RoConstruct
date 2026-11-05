// from server: 100% by auto
// roc 2007-08 00401950  unit: CAboutRobloxDialog  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401950
//
// 00401950  ff1500d37700         call dword ptr [0x77d300]
// 00401956  85c0                 test eax, eax
// 00401958  7e0a                 jle 0x401964
// 0040195a  25ffff0000           and eax, 0xffff
// 0040195f  0d00000780           or eax, 0x80070000
// 00401964  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl3.cpp
