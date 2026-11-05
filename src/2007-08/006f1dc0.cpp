// from server: 100% by auto
// roc 2007-08 006f1dc0  unit: CStatic  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f1dc0
//
// 006f1dc0  56                   push esi
// 006f1dc1  8bf1                 mov esi, ecx
// 006f1dc3  e812e8f3ff           call 0x6305da
// 006f1dc8  c70654b57d00         mov dword ptr [esi], 0x7db554
// 006f1dce  c7465400000000       mov dword ptr [esi + 0x54], 0
// 006f1dd5  8bc6                 mov eax, esi
// 006f1dd7  5e                   pop esi
// 006f1dd8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
