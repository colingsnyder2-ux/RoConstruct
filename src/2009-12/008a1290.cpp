// from server: 100% by auto
// roc 2009-12 008a1290  unit: CXTPReportPaintManager  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a1290
//
// 008a1290  56                   push esi
// 008a1291  8bf1                 mov esi, ecx
// 008a1293  e8c893f7ff           call 0x81a660
// 008a1298  c706f853a000         mov dword ptr [esi], 0xa053f8
// 008a129e  8bc6                 mov eax, esi
// 008a12a0  5e                   pop esi
// 008a12a1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
