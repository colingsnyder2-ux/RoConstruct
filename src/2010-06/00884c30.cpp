// from server: 100% by auto
// roc 2010-06 00884c30  unit: RBX::GroundStage  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884c30
//
// 00884c30  56                   push esi
// 00884c31  8bf1                 mov esi, ecx
// 00884c33  e8583a0000           call 0x888690
// 00884c38  6a00                 push 0
// 00884c3a  6a06                 push 6
// 00884c3c  6a03                 push 3
// 00884c3e  6a02                 push 2
// 00884c40  8d4604               lea eax, [esi + 4]
// 00884c43  50                   push eax
// 00884c44  c706d4eba600         mov dword ptr [esi], 0xa6ebd4
// 00884c4a  ff15c0bb9e00         call dword ptr [0x9ebbc0]
// 00884c50  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00884c57  c706f4eca600         mov dword ptr [esi], 0xa6ecf4
// 00884c5d  c7462001000000       mov dword ptr [esi + 0x20], 1
// 00884c64  8bc6                 mov eax, esi
// 00884c66  5e                   pop esi
// 00884c67  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
