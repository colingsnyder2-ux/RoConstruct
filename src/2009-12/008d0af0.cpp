// from server: 100% by auto
// roc 2009-12 008d0af0  unit: CXTPTabPaintManager::CAppearanceSetVisualStudio2005  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0af0
//
// 008d0af0  53                   push ebx
// 008d0af1  56                   push esi
// 008d0af2  57                   push edi
// 008d0af3  8bf1                 mov esi, ecx
// 008d0af5  e8e6390000           call 0x8d44e0
// 008d0afa  8b1d38ca9800         mov ebx, dword ptr [0x98ca38]
// 008d0b00  6a00                 push 0
// 008d0b02  6a04                 push 4
// 008d0b04  6a02                 push 2
// 008d0b06  6a02                 push 2
// 008d0b08  8d7e04               lea edi, [esi + 4]
// 008d0b0b  57                   push edi
// 008d0b0c  c706c40fa000         mov dword ptr [esi], 0xa00fc4
// 008d0b12  ffd3                 call ebx
// 008d0b14  6a00                 push 0
// 008d0b16  6a02                 push 2
// 008d0b18  6a03                 push 3
// 008d0b1a  6a02                 push 2
// 008d0b1c  57                   push edi
// 008d0b1d  c70644aaa000         mov dword ptr [esi], 0xa0aa44
// 008d0b23  ffd3                 call ebx
// 008d0b25  5f                   pop edi
// 008d0b26  8bc6                 mov eax, esi
// 008d0b28  5e                   pop esi
// 008d0b29  5b                   pop ebx
// 008d0b2a  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetExcel@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
