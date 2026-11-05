// from server: 100% by auto
// roc 2010-06 00819be0  unit: CPropertyGridItemBrickColor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00819be0
//
// 00819be0  8b442404             mov eax, dword ptr [esp + 4]
// 00819be4  85c0                 test eax, eax
// 00819be6  7c0e                 jl 0x819bf6
// 00819be8  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 00819beb  7d09                 jge 0x819bf6
// 00819bed  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00819bf0  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00819bf3  c20400               ret 4
// 00819bf6  33c0                 xor eax, eax
// 00819bf8  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?GetAt@CXTPPropertyGridInplaceButtons@@QBEPAVCXTPPropertyGridInplaceButton@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
