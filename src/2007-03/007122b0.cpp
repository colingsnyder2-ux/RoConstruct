// from server: 100% by auto
// roc 2007-03 007122b0  unit: seg_00710000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007122b0
//
// 007122b0  8b442404             mov eax, dword ptr [esp + 4]
// 007122b4  c70010000000         mov dword ptr [eax], 0x10
// 007122ba  c7400410000000       mov dword ptr [eax + 4], 0x10
// 007122c1  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonSystemButton.cpp (function ?GetIconSize@CXTPRibbonControlSystemPopupBarButton@@UBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonSystemButton.cpp
