// from server: 100% by auto
// roc 2007-03 006d8dc0  unit: seg_006d0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d8dc0
//
// 006d8dc0  8b442404             mov eax, dword ptr [esp + 4]
// 006d8dc4  56                   push esi
// 006d8dc5  50                   push eax
// 006d8dc6  8bf1                 mov esi, ecx
// 006d8dc8  e8a3fdffff           call 0x6d8b70
// 006d8dcd  50                   push eax
// 006d8dce  8bce                 mov ecx, esi
// 006d8dd0  e88bffffff           call 0x6d8d60
// 006d8dd5  5e                   pop esi
// 006d8dd6  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?Remove@CXTPPropertyGridInplaceButtons@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
