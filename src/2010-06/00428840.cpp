// from server: 100% by auto
// roc 2010-06 00428840  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00428840
//
// 00428840  8b442404             mov eax, dword ptr [esp + 4]
// 00428844  398160010000         cmp dword ptr [ecx + 0x160], eax
// 0042884a  740b                 je 0x428857
// 0042884c  898160010000         mov dword ptr [ecx + 0x160], eax
// 00428852  e8a9153800           call 0x7a9e00
// 00428857  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
