// from server: 100% by auto
// roc 2009-06 007b1230  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b1230
//
// 007b1230  56                   push esi
// 007b1231  8bf1                 mov esi, ecx
// 007b1233  e828a9f6ff           call 0x71bb60
// 007b1238  c7067c2a9000         mov dword ptr [esi], 0x902a7c
// 007b123e  c7466000000000       mov dword ptr [esi + 0x60], 0
// 007b1245  8bc6                 mov eax, esi
// 007b1247  5e                   pop esi
// 007b1248  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPControlEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlEdit.cpp
