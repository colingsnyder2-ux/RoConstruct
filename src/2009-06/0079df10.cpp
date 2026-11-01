// from server: 100% by auto
// roc 2009-06 0079df10  unit: CXTPControlGallery  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079df10
//
// 0079df10  56                   push esi
// 0079df11  8bf1                 mov esi, ecx
// 0079df13  e818d5f7ff           call 0x71b430
// 0079df18  c70624179000         mov dword ptr [esi], 0x901724
// 0079df1e  c7465414179000       mov dword ptr [esi + 0x54], 0x901714
// 0079df25  c7465cb4169000       mov dword ptr [esi + 0x5c], 0x9016b4
// 0079df2c  8bc6                 mov eax, esi
// 0079df2e  5e                   pop esi
// 0079df2f  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ??0CXTPControlFontComboBoxList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
