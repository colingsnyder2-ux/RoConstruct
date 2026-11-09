// from server: 100% by auto
// roc 2010-06 0083f720  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083f720
//
// 0083f720  56                   push esi
// 0083f721  8bf1                 mov esi, ecx
// 0083f723  e8e852f7ff           call 0x7b4a10
// 0083f728  c7068471a600         mov dword ptr [esi], 0xa67184
// 0083f72e  c7466000000000       mov dword ptr [esi + 0x60], 0
// 0083f735  8bc6                 mov eax, esi
// 0083f737  5e                   pop esi
// 0083f738  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPControlEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlEdit.cpp
