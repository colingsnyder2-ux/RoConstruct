// from server: 100% by auto
// roc 2007-08 006fd2d0  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006fd2d0
//
// 006fd2d0  56                   push esi
// 006fd2d1  8bf1                 mov esi, ecx
// 006fd2d3  8b06                 mov eax, dword ptr [esi]
// 006fd2d5  85c0                 test eax, eax
// 006fd2d7  740f                 je 0x6fd2e8
// 006fd2d9  50                   push eax
// 006fd2da  e8472cf3ff           call 0x62ff26
// 006fd2df  83c404               add esp, 4
// 006fd2e2  c70600000000         mov dword ptr [esi], 0
// 006fd2e8  5e                   pop esi
// 006fd2e9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledisp2.cpp
