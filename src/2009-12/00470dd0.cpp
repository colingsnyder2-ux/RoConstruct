// from server: 100% by auto
// roc 2009-12 00470dd0  unit: CSettingsDialog  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00470dd0
//
// 00470dd0  8b01                 mov eax, dword ptr [ecx]
// 00470dd2  50                   push eax
// 00470dd3  ff150ccd9800         call dword ptr [0x98cd0c]
// 00470dd9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
