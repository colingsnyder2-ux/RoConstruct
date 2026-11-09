// from server: 100% by auto
// roc 2011-06 008d3260  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d3260
//
// 008d3260  56                   push esi
// 008d3261  8bf1                 mov esi, ecx
// 008d3263  8b06                 mov eax, dword ptr [esi]
// 008d3265  85c0                 test eax, eax
// 008d3267  740f                 je 0x8d3278
// 008d3269  50                   push eax
// 008d326a  e89570f3ff           call 0x80a304
// 008d326f  83c404               add esp, 4
// 008d3272  c70600000000         mov dword ptr [esi], 0
// 008d3278  5e                   pop esi
// 008d3279  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp2.cpp
