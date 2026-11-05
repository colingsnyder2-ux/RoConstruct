// from server: 100% by auto
// roc 2010-06 00882350  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882350
//
// 00882350  56                   push esi
// 00882351  8bf1                 mov esi, ecx
// 00882353  8b06                 mov eax, dword ptr [esi]
// 00882355  85c0                 test eax, eax
// 00882357  740f                 je 0x882368
// 00882359  50                   push eax
// 0088235a  e8e758f2ff           call 0x7a7c46
// 0088235f  83c404               add esp, 4
// 00882362  c70600000000         mov dword ptr [esi], 0
// 00882368  5e                   pop esi
// 00882369  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp2.cpp
