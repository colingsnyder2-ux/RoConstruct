// from server: 100% by auto
// roc 2010-06 0087aae0  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087aae0
//
// 0087aae0  8b442404             mov eax, dword ptr [esp + 4]
// 0087aae4  56                   push esi
// 0087aae5  50                   push eax
// 0087aae6  8bf1                 mov esi, ecx
// 0087aae8  e8d3fbffff           call 0x87a6c0
// 0087aaed  50                   push eax
// 0087aaee  8bce                 mov ecx, esi
// 0087aaf0  e8abffffff           call 0x87aaa0
// 0087aaf5  5e                   pop esi
// 0087aaf6  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?Remove@CXTPPropertyGridInplaceButtons@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
