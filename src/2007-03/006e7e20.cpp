// from server: 100% by auto
// roc 2007-03 006e7e20  unit: seg_006e0000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e7e20
//
// 006e7e20  56                   push esi
// 006e7e21  8bf1                 mov esi, ecx
// 006e7e23  e838fc0100           call 0x707a60
// 006e7e28  6a00                 push 0
// 006e7e2a  6a06                 push 6
// 006e7e2c  6a03                 push 3
// 006e7e2e  6a02                 push 2
// 006e7e30  8d4604               lea eax, [esi + 4]
// 006e7e33  50                   push eax
// 006e7e34  c706ac9a7d00         mov dword ptr [esi], 0x7d9aac
// 006e7e3a  ff15b4ed7700         call dword ptr [0x77edb4]
// 006e7e40  c7462400000000       mov dword ptr [esi + 0x24], 0
// 006e7e47  c706849b7d00         mov dword ptr [esi], 0x7d9b84
// 006e7e4d  c7462001000000       mov dword ptr [esi + 0x20], 1
// 006e7e54  8bc6                 mov eax, esi
// 006e7e56  5e                   pop esi
// 006e7e57  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetVisualStudio2005@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
