// from server: 100% by auto
// roc 2009-12 008e4550  unit: CXTCaptionTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4550
//
// 008e4550  56                   push esi
// 008e4551  8bf1                 mov esi, ecx
// 008e4553  e868ffffff           call 0x8e44c0
// 008e4558  c7060cc4a000         mov dword ptr [esi], 0xa0c40c
// 008e455e  8bc6                 mov eax, esi
// 008e4560  5e                   pop esi
// 008e4561  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
