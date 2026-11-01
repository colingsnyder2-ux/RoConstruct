// from server: 100% by auto
// roc 2009-06 004277c0  unit: CRobloxControlColorSelector  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004277c0
//
// 004277c0  8b442404             mov eax, dword ptr [esp + 4]
// 004277c4  398160010000         cmp dword ptr [ecx + 0x160], eax
// 004277ca  740b                 je 0x4277d7
// 004277cc  898160010000         mov dword ptr [ecx + 0x160], eax
// 004277d2  e8c97e2f00           call 0x71f6a0
// 004277d7  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
