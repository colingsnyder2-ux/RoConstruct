// from server: 100% by auto
// roc 2009-12 008f5940  unit: CXTButtonThemeOffice2003  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f5940
//
// 008f5940  8bc1                 mov eax, ecx
// 008f5942  c700d4fca000         mov dword ptr [eax], 0xa0fcd4
// 008f5948  c7400400000000       mov dword ptr [eax + 4], 0
// 008f594f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ??0CGdiObject@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
