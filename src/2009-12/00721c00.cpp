// from server: 100% by auto
// roc 2009-12 00721c00  unit: seg_00720000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00721c00
//
// 00721c00  8b01                 mov eax, dword ptr [ecx]
// 00721c02  50                   push eax
// 00721c03  ff15d8cc9800         call dword ptr [0x98ccd8]
// 00721c09  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
