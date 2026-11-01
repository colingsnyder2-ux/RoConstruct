// from server: 100% by auto
// roc 2009-12 00428410  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00428410
//
// 00428410  8b442404             mov eax, dword ptr [esp + 4]
// 00428414  398164010000         cmp dword ptr [ecx + 0x164], eax
// 0042841a  740b                 je 0x428427
// 0042841c  898164010000         mov dword ptr [ecx + 0x164], eax
// 00428422  e899d83c00           call 0x7f5cc0
// 00428427  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
