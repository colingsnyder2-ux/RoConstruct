// from server: 100% by auto
// roc 2008-06 004018f0  unit: CAboutRobloxDialog  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004018f0
//
// 004018f0  8b442404             mov eax, dword ptr [esp + 4]
// 004018f4  85c0                 test eax, eax
// 004018f6  7e0a                 jle 0x401902
// 004018f8  25ffff0000           and eax, 0xffff
// 004018fd  0d00000780           or eax, 0x80070000
// 00401902  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function _HRESULT_FROM_WIN32)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
