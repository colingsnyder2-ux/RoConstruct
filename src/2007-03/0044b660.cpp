// from server: 100% by auto
// roc 2007-03 0044b660  unit: seg_00440000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044b660
//
// 0044b660  8b442404             mov eax, dword ptr [esp + 4]
// 0044b664  398160010000         cmp dword ptr [ecx + 0x160], eax
// 0044b66a  740b                 je 0x44b677
// 0044b66c  898160010000         mov dword ptr [ecx + 0x160], eax
// 0044b672  e8793c1e00           call 0x62f2f0
// 0044b677  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?SetVariableItemsHeight@CXTPPropertyGrid@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
