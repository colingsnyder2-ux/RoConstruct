// from server: 100% by auto
// roc 2007-08 00401970  unit: CAboutRobloxDialog  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401970
//
// 00401970  8b442404             mov eax, dword ptr [esp + 4]
// 00401974  85c0                 test eax, eax
// 00401976  7e0a                 jle 0x401982
// 00401978  25ffff0000           and eax, 0xffff
// 0040197d  0d00000780           or eax, 0x80070000
// 00401982  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function _HRESULT_FROM_WIN32)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
