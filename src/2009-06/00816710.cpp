// from server: 100% by auto
// roc 2009-06 00816710  unit: CXTPRibbonControlSystemPopupBarButton  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00816710
//
// 00816710  8b442404             mov eax, dword ptr [esp + 4]
// 00816714  c70016000000         mov dword ptr [eax], 0x16
// 0081671a  c7400416000000       mov dword ptr [eax + 4], 0x16
// 00816721  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonSystemButton.cpp (function ?GetButtonSize@CXTPRibbonControlSystemPopupBarButton@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonSystemButton.cpp
