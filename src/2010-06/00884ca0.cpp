// from server: 100% by auto
// roc 2010-06 00884ca0  unit: CXTPTabPaintManager::CAppearanceSetVisualStudio2005  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884ca0
//
// 00884ca0  53                   push ebx
// 00884ca1  56                   push esi
// 00884ca2  57                   push edi
// 00884ca3  8bf1                 mov esi, ecx
// 00884ca5  e8e6390000           call 0x888690
// 00884caa  8b1dc0bb9e00         mov ebx, dword ptr [0x9ebbc0]
// 00884cb0  6a00                 push 0
// 00884cb2  6a04                 push 4
// 00884cb4  6a02                 push 2
// 00884cb6  6a02                 push 2
// 00884cb8  8d7e04               lea edi, [esi + 4]
// 00884cbb  57                   push edi
// 00884cbc  c7060459a600         mov dword ptr [esi], 0xa65904
// 00884cc2  ffd3                 call ebx
// 00884cc4  6a00                 push 0
// 00884cc6  6a02                 push 2
// 00884cc8  6a03                 push 3
// 00884cca  6a02                 push 2
// 00884ccc  57                   push edi
// 00884ccd  c7063ceda600         mov dword ptr [esi], 0xa6ed3c
// 00884cd3  ffd3                 call ebx
// 00884cd5  5f                   pop edi
// 00884cd6  8bc6                 mov eax, esi
// 00884cd8  5e                   pop esi
// 00884cd9  5b                   pop ebx
// 00884cda  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetExcel@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
