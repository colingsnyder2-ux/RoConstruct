// from server: 100% by auto
// roc 2009-12 008ce170  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce170
//
// 008ce170  56                   push esi
// 008ce171  8bf1                 mov esi, ecx
// 008ce173  8b06                 mov eax, dword ptr [esi]
// 008ce175  85c0                 test eax, eax
// 008ce177  740f                 je 0x8ce188
// 008ce179  50                   push eax
// 008ce17a  e88759f2ff           call 0x7f3b06
// 008ce17f  83c404               add esp, 4
// 008ce182  c70600000000         mov dword ptr [esi], 0
// 008ce188  5e                   pop esi
// 008ce189  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledisp2.cpp
