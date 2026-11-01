// from server: 100% by auto
// roc 2009-12 008bc0d0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bc0d0
//
// 008bc0d0  56                   push esi
// 008bc0d1  8bf1                 mov esi, ecx
// 008bc0d3  e87080f3ff           call 0x7f4148
// 008bc0d8  c7061484a000         mov dword ptr [esi], 0xa08414
// 008bc0de  8bc6                 mov eax, esi
// 008bc0e0  5e                   pop esi
// 008bc0e1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
