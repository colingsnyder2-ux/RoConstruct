// from server: 100% by auto
// roc 2010-06 007f92d0  unit: CXTPControls  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f92d0
//
// 007f92d0  56                   push esi
// 007f92d1  8bf1                 mov esi, ecx
// 007f92d3  e8d8ffffff           call 0x7f92b0
// 007f92d8  8b442408             mov eax, dword ptr [esp + 8]
// 007f92dc  89463c               mov dword ptr [esi + 0x3c], eax
// 007f92df  5e                   pop esi
// 007f92e0  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControls.cpp (function ?SetOriginalControls@CXTPControls@@QAEXPAVCXTPOriginalControls@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControls.cpp
