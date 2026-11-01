// from server: 100% by auto
// roc 2009-06 007ebda0  unit: PAVCXTPPropertyGridInplaceButton::?$CArray  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ebda0
//
// 007ebda0  8b442404             mov eax, dword ptr [esp + 4]
// 007ebda4  56                   push esi
// 007ebda5  50                   push eax
// 007ebda6  8bf1                 mov esi, ecx
// 007ebda8  e8d3fbffff           call 0x7eb980
// 007ebdad  50                   push eax
// 007ebdae  8bce                 mov ecx, esi
// 007ebdb0  e8abffffff           call 0x7ebd60
// 007ebdb5  5e                   pop esi
// 007ebdb6  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ?Remove@CXTPPropertyGridInplaceButtons@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
