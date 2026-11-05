// from server: 100% by auto
// roc 2009-12 004283f0  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004283f0
//
// 004283f0  8b442404             mov eax, dword ptr [esp + 4]
// 004283f4  398160010000         cmp dword ptr [ecx + 0x160], eax
// 004283fa  740b                 je 0x428407
// 004283fc  898160010000         mov dword ptr [ecx + 0x160], eax
// 00428402  e8b9d83c00           call 0x7f5cc0
// 00428407  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
