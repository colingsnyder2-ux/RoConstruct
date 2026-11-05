// from server: 100% by auto
// roc 2011-06 00430650  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00430650
//
// 00430650  8b442404             mov eax, dword ptr [esp + 4]
// 00430654  398160010000         cmp dword ptr [ecx + 0x160], eax
// 0043065a  740b                 je 0x430667
// 0043065c  898160010000         mov dword ptr [ecx + 0x160], eax
// 00430662  e889be3d00           call 0x80c4f0
// 00430667  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
