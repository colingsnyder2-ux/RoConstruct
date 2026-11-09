// from server: 100% by auto
// roc 2010-06 007f9190  unit: CXTPOriginalControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f9190
//
// 007f9190  8bc1                 mov eax, ecx
// 007f9192  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007f9195  85c9                 test ecx, ecx
// 007f9197  7405                 je 0x7f919e
// 007f9199  e932f4fbff           jmp 0x7b85d0
// 007f919e  8b4038               mov eax, dword ptr [eax + 0x38]
// 007f91a1  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControls.cpp (function ?GetCommandBars@CXTPControls@@QBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControls.cpp
