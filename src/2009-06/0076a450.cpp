// from server: 100% by auto
// roc 2009-06 0076a450  unit: CXTPControls  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076a450
//
// 0076a450  56                   push esi
// 0076a451  8bf1                 mov esi, ecx
// 0076a453  e8d8ffffff           call 0x76a430
// 0076a458  8b442408             mov eax, dword ptr [esp + 8]
// 0076a45c  89463c               mov dword ptr [esi + 0x3c], eax
// 0076a45f  5e                   pop esi
// 0076a460  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetOriginalControls@CXTPControls@@QAEXPAVCXTPOriginalControls@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
