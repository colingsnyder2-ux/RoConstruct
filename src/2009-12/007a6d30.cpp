// from server: 100% by auto
// roc 2009-12 007a6d30  unit: RBX::RevoluteLink  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a6d30
//
// 007a6d30  56                   push esi
// 007a6d31  8bf1                 mov esi, ecx
// 007a6d33  e8e87d0000           call 0x7aeb20
// 007a6d38  c70604d49e00         mov dword ptr [esi], 0x9ed404
// 007a6d3e  8bc6                 mov eax, esi
// 007a6d40  5e                   pop esi
// 007a6d41  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
