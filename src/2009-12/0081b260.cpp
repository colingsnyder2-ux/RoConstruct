// from server: 100% by auto
// roc 2009-12 0081b260  unit: PAVCXTPReportInplaceButton::?$CArray  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081b260
//
// 0081b260  56                   push esi
// 0081b261  8bf1                 mov esi, ecx
// 0081b263  e878ffffff           call 0x81b1e0
// 0081b268  c706d0499f00         mov dword ptr [esi], 0x9f49d0
// 0081b26e  8bc6                 mov eax, esi
// 0081b270  5e                   pop esi
// 0081b271  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
