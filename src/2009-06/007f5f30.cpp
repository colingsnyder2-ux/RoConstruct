// from server: 100% by auto
// roc 2009-06 007f5f30  unit: CXTPTabPaintManager::CAppearanceSetVisualStudio2005  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5f30
//
// 007f5f30  53                   push ebx
// 007f5f31  56                   push esi
// 007f5f32  57                   push edi
// 007f5f33  8bf1                 mov esi, ecx
// 007f5f35  e8063a0000           call 0x7f9940
// 007f5f3a  8b1da4ed8900         mov ebx, dword ptr [0x89eda4]
// 007f5f40  6a00                 push 0
// 007f5f42  6a04                 push 4
// 007f5f44  6a02                 push 2
// 007f5f46  6a02                 push 2
// 007f5f48  8d7e04               lea edi, [esi + 4]
// 007f5f4b  57                   push edi
// 007f5f4c  c706e4039000         mov dword ptr [esi], 0x9003e4
// 007f5f52  ffd3                 call ebx
// 007f5f54  6a00                 push 0
// 007f5f56  6a02                 push 2
// 007f5f58  6a03                 push 3
// 007f5f5a  6a02                 push 2
// 007f5f5c  57                   push edi
// 007f5f5d  c706d4a59000         mov dword ptr [esi], 0x90a5d4
// 007f5f63  ffd3                 call ebx
// 007f5f65  5f                   pop edi
// 007f5f66  8bc6                 mov eax, esi
// 007f5f68  5e                   pop esi
// 007f5f69  5b                   pop ebx
// 007f5f6a  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetExcel@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
