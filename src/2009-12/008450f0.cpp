// from server: 100% by auto
// roc 2009-12 008450f0  unit: CXTPOriginalControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008450f0
//
// 008450f0  8bc1                 mov eax, ecx
// 008450f2  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008450f5  85c9                 test ecx, ecx
// 008450f7  7405                 je 0x8450fe
// 008450f9  e9d2f3fbff           jmp 0x8044d0
// 008450fe  8b4038               mov eax, dword ptr [eax + 0x38]
// 00845101  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?GetCommandBars@CXTPControls@@QBEPAVCXTPCommandBars@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
