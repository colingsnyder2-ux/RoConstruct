// from server: 100% by auto
// roc 2009-06 0076a320  unit: CXTPOriginalControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076a320
//
// 0076a320  8bc1                 mov eax, ecx
// 0076a322  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0076a325  85c9                 test ecx, ecx
// 0076a327  7405                 je 0x76a32e
// 0076a329  e96230fcff           jmp 0x72d390
// 0076a32e  8b4038               mov eax, dword ptr [eax + 0x38]
// 0076a331  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?GetCommandBars@CXTPControls@@QBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
