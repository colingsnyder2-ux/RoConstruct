// from server: 100% by auto
// roc 2009-06 00816010  unit: CXTPRibbonSystemPopupBarPage  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00816010
//
// 00816010  56                   push esi
// 00816011  8bf1                 mov esi, ecx
// 00816013  e8b83ff5ff           call 0x769fd0
// 00816018  c706ece59000         mov dword ptr [esi], 0x90e5ec
// 0081601e  c74654dce59000       mov dword ptr [esi + 0x54], 0x90e5dc
// 00816025  c7465c7ce59000       mov dword ptr [esi + 0x5c], 0x90e57c
// 0081602c  8bc6                 mov eax, esi
// 0081602e  5e                   pop esi
// 0081602f  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ??0CXTPControlFontComboBoxList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
