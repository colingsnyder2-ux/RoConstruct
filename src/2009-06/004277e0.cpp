// from server: 100% by auto
// roc 2009-06 004277e0  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004277e0
//
// 004277e0  8b442404             mov eax, dword ptr [esp + 4]
// 004277e4  398164010000         cmp dword ptr [ecx + 0x164], eax
// 004277ea  740b                 je 0x4277f7
// 004277ec  898164010000         mov dword ptr [ecx + 0x164], eax
// 004277f2  e8a97e2f00           call 0x71f6a0
// 004277f7  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
