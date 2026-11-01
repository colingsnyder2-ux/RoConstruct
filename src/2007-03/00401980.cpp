// from server: 100% by auto
// roc 2007-03 00401980  unit: seg_00400000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401980
//
// 00401980  8b442404             mov eax, dword ptr [esp + 4]
// 00401984  85c0                 test eax, eax
// 00401986  7e0a                 jle 0x401992
// 00401988  25ffff0000           and eax, 0xffff
// 0040198d  0d00000780           or eax, 0x80070000
// 00401992  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function _HRESULT_FROM_WIN32)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
