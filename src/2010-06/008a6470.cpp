// from server: 100% by auto
// roc 2010-06 008a6470  unit: CXTPRibbonControlSystemPopupBarButton  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a6470
//
// 008a6470  8b442404             mov eax, dword ptr [esp + 4]
// 008a6474  c70016000000         mov dword ptr [eax], 0x16
// 008a647a  c7400416000000       mov dword ptr [eax + 4], 0x16
// 008a6481  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonSystemButton.cpp (function ?GetButtonSize@CXTPRibbonControlSystemPopupBarButton@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonSystemButton.cpp
