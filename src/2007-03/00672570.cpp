// from server: 100% by auto
// roc 2007-03 00672570  unit: seg_00670000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00672570
//
// 00672570  8bc1                 mov eax, ecx
// 00672572  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00672575  85c9                 test ecx, ecx
// 00672577  7405                 je 0x67257e
// 00672579  e99267fcff           jmp 0x638d10
// 0067257e  8b4038               mov eax, dword ptr [eax + 0x38]
// 00672581  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?GetCommandBars@CXTPControls@@QBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
