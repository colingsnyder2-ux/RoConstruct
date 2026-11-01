// from server: 100% by auto
// roc 2009-12 008a34a0  unit: CXTPReportHyperlinks  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a34a0
//
// 008a34a0  56                   push esi
// 008a34a1  8bf1                 mov esi, ecx
// 008a34a3  e8f8fcffff           call 0x8a31a0
// 008a34a8  c7063c5aa000         mov dword ptr [esi], 0xa05a3c
// 008a34ae  8bc6                 mov eax, esi
// 008a34b0  5e                   pop esi
// 008a34b1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
