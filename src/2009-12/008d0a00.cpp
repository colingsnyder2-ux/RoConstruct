// from server: 100% by auto
// roc 2009-12 008d0a00  unit: CXTPTabPaintManager::CAppearanceSetPropertyPage2003  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0a00
//
// 008d0a00  56                   push esi
// 008d0a01  8bf1                 mov esi, ecx
// 008d0a03  e8d83a0000           call 0x8d44e0
// 008d0a08  6a00                 push 0
// 008d0a0a  6a00                 push 0
// 008d0a0c  6a01                 push 1
// 008d0a0e  6a04                 push 4
// 008d0a10  8d4604               lea eax, [esi + 4]
// 008d0a13  50                   push eax
// 008d0a14  c70624a9a000         mov dword ptr [esi], 0xa0a924
// 008d0a1a  ff1538ca9800         call dword ptr [0x98ca38]
// 008d0a20  8bc6                 mov eax, esi
// 008d0a22  5e                   pop esi
// 008d0a23  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ??0CAppearanceSetPropertyPage2007@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
