// from server: 100% by auto
// roc 2007-03 0068e210  unit: seg_00680000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068e210
//
// 0068e210  56                   push esi
// 0068e211  8bf1                 mov esi, ecx
// 0068e213  e848980700           call 0x707a60
// 0068e218  6a00                 push 0
// 0068e21a  6a04                 push 4
// 0068e21c  6a02                 push 2
// 0068e21e  6a02                 push 2
// 0068e220  8d4604               lea eax, [esi + 4]
// 0068e223  50                   push eax
// 0068e224  c706ec017d00         mov dword ptr [esi], 0x7d01ec
// 0068e22a  ff15b4ed7700         call dword ptr [0x77edb4]
// 0068e230  8bc6                 mov eax, esi
// 0068e232  5e                   pop esi
// 0068e233  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ??0CAppearanceSetFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
