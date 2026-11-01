// from server: 100% by auto
// roc 2009-12 008e5530  unit: CXTCaptionButton  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5530
//
// 008e5530  8b442404             mov eax, dword ptr [esp + 4]
// 008e5534  56                   push esi
// 008e5535  50                   push eax
// 008e5536  8bf1                 mov esi, ecx
// 008e5538  e8a7e3f0ff           call 0x7f38e4
// 008e553d  85c0                 test eax, eax
// 008e553f  7504                 jne 0x8e5545
// 008e5541  5e                   pop esi
// 008e5542  c20400               ret 4
// 008e5545  c6467400             mov byte ptr [esi + 0x74], 0
// 008e5549  b801000000           mov eax, 1
// 008e554e  5e                   pop esi
// 008e554f  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?PreCreateWindow@CXTButton@@MAEHAAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
