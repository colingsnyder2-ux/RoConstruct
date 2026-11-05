// from server: 100% by auto
// roc 2007-08 006fc8b0  unit: CXTPPropertyGridInplaceList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fc8b0
//
// 006fc8b0  56                   push esi
// 006fc8b1  8bf1                 mov esi, ecx
// 006fc8b3  e8223df3ff           call 0x6305da
// 006fc8b8  c7067ccb7d00         mov dword ptr [esi], 0x7dcb7c
// 006fc8be  c7465400000000       mov dword ptr [esi + 0x54], 0
// 006fc8c5  8bc6                 mov eax, esi
// 006fc8c7  5e                   pop esi
// 006fc8c8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
