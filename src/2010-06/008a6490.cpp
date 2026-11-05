// from server: 100% by auto
// roc 2010-06 008a6490  unit: CXTPRibbonControlSystemPopupBarButton  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a6490
//
// 008a6490  8b442404             mov eax, dword ptr [esp + 4]
// 008a6494  c70010000000         mov dword ptr [eax], 0x10
// 008a649a  c7400410000000       mov dword ptr [eax + 4], 0x10
// 008a64a1  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonSystemButton.cpp (function ?GetIconSize@CXTPRibbonControlSystemPopupBarButton@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonSystemButton.cpp
