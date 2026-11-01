// from server: 100% by auto
// roc 2009-12 00845230  unit: CXTPControls  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00845230
//
// 00845230  56                   push esi
// 00845231  8bf1                 mov esi, ecx
// 00845233  e8d8ffffff           call 0x845210
// 00845238  8b442408             mov eax, dword ptr [esp + 8]
// 0084523c  89463c               mov dword ptr [esi + 0x3c], eax
// 0084523f  5e                   pop esi
// 00845240  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetOriginalControls@CXTPControls@@QAEXPAVCXTPOriginalControls@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
