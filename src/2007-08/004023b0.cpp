// from server: 100% by auto
// roc 2007-08 004023b0  unit: VCWorkspace::?$CComObject  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004023b0
//
// 004023b0  8b01                 mov eax, dword ptr [ecx]
// 004023b2  50                   push eax
// 004023b3  ff15b0e97700         call dword ptr [0x77e9b0]
// 004023b9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
