// from server: 100% by auto
// roc 2009-12 008f3370  unit: CXTColorSelectorCtrlTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f3370
//
// 008f3370  56                   push esi
// 008f3371  8bf1                 mov esi, ecx
// 008f3373  e858ffffff           call 0x8f32d0
// 008f3378  c70698f9a000         mov dword ptr [esi], 0xa0f998
// 008f337e  8bc6                 mov eax, esi
// 008f3380  5e                   pop esi
// 008f3381  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
