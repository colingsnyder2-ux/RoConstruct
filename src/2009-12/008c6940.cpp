// from server: 100% by auto
// roc 2009-12 008c6940  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6940
//
// 008c6940  8b442404             mov eax, dword ptr [esp + 4]
// 008c6944  56                   push esi
// 008c6945  50                   push eax
// 008c6946  8bf1                 mov esi, ecx
// 008c6948  e8d3fbffff           call 0x8c6520
// 008c694d  50                   push eax
// 008c694e  8bce                 mov ecx, esi
// 008c6950  e8abffffff           call 0x8c6900
// 008c6955  5e                   pop esi
// 008c6956  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?Remove@CXTPPropertyGridInplaceButtons@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
