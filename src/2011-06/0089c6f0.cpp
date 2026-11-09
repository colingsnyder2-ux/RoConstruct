// from server: 100% by auto
// roc 2011-06 0089c6f0  unit: CXTPControlEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089c6f0
//
// 0089c6f0  56                   push esi
// 0089c6f1  8bf1                 mov esi, ecx
// 0089c6f3  e868a7f7ff           call 0x816e60
// 0089c6f8  c706a41bad00         mov dword ptr [esi], 0xad1ba4
// 0089c6fe  c7466000000000       mov dword ptr [esi + 0x60], 0
// 0089c705  8bc6                 mov eax, esi
// 0089c707  5e                   pop esi
// 0089c708  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPControlEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlEdit.cpp
