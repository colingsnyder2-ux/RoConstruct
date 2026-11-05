// from server: 100% by auto
// roc 2009-06 007f35c0  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f35c0
//
// 007f35c0  56                   push esi
// 007f35c1  8bf1                 mov esi, ecx
// 007f35c3  8b06                 mov eax, dword ptr [esi]
// 007f35c5  85c0                 test eax, eax
// 007f35c7  740f                 je 0x7f35d8
// 007f35c9  50                   push eax
// 007f35ca  e80f57f2ff           call 0x718cde
// 007f35cf  83c404               add esp, 4
// 007f35d2  c70600000000         mov dword ptr [esi], 0
// 007f35d8  5e                   pop esi
// 007f35d9  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp2.cpp
