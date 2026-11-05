// from server: 100% by auto
// roc 2008-06 0077ae70  unit: CXTPTabClientWnd::CNavigateButtonActiveFiles  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0077ae70
//
// 0077ae70  56                   push esi
// 0077ae71  8bf1                 mov esi, ecx
// 0077ae73  8b06                 mov eax, dword ptr [esi]
// 0077ae75  85c0                 test eax, eax
// 0077ae77  740f                 je 0x77ae88
// 0077ae79  50                   push eax
// 0077ae7a  e8cb5af2ff           call 0x6a094a
// 0077ae7f  83c404               add esp, 4
// 0077ae82  c70600000000         mov dword ptr [esi], 0
// 0077ae88  5e                   pop esi
// 0077ae89  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oledisp2.cpp (function ??1COleDispParams@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp2.cpp
