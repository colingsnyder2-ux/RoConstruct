// from server: 100% by auto
// roc 2011-06 008f2270  unit: CXTCaptionButton  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f2270
//
// 008f2270  f644240804           test byte ptr [esp + 8], 4
// 008f2275  56                   push esi
// 008f2276  8bf1                 mov esi, ecx
// 008f2278  7509                 jne 0x8f2283
// 008f227a  e8af83f1ff           call 0x80a62e
// 008f227f  5e                   pop esi
// 008f2280  c20800               ret 8
// 008f2283  8b442408             mov eax, dword ptr [esp + 8]
// 008f2287  50                   push eax
// 008f2288  e82ba30d00           call 0x9cc5b8
// 008f228d  85c0                 test eax, eax
// 008f228f  740d                 je 0x8f229e
// 008f2291  8b16                 mov edx, dword ptr [esi]
// 008f2293  50                   push eax
// 008f2294  8b82a0010000         mov eax, dword ptr [edx + 0x1a0]
// 008f229a  8bce                 mov ecx, esi
// 008f229c  ffd0                 call eax
// 008f229e  b801000000           mov eax, 1
// 008f22a3  5e                   pop esi
// 008f22a4  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButton.cpp (function ?OnPrintClient@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButton.cpp
