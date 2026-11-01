// from server: 100% by auto
// roc 2009-12 0084b230  unit: CXTPPrintingDialog  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084b230
//
// 0084b230  56                   push esi
// 0084b231  8bf1                 mov esi, ecx
// 0084b233  56                   push esi
// 0084b234  ff159cca9800         call dword ptr [0x98ca9c]
// 0084b23a  8bc6                 mov eax, esi
// 0084b23c  5e                   pop esi
// 0084b23d  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??0CComVariant@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
