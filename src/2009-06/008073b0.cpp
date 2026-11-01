// from server: 100% by auto
// roc 2009-06 008073b0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008073b0
//
// 008073b0  56                   push esi
// 008073b1  8bf1                 mov esi, ecx
// 008073b3  8d86b8000000         lea eax, [esi + 0xb8]
// 008073b9  57                   push edi
// 008073ba  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008073be  85c0                 test eax, eax
// 008073c0  741b                 je 0x8073dd
// 008073c2  83782000             cmp dword ptr [eax + 0x20], 0
// 008073c6  7415                 je 0x8073dd
// 008073c8  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 008073ce  57                   push edi
// 008073cf  6a00                 push 0
// 008073d1  6807040000           push 0x407
// 008073d6  50                   push eax
// 008073d7  ff1590ee8900         call dword ptr [0x89ee90]
// 008073dd  57                   push edi
// 008073de  8bce                 mov ecx, esi
// 008073e0  e8531cf1ff           call 0x719038
// 008073e5  5f                   pop edi
// 008073e6  5e                   pop esi
// 008073e7  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?PreTranslateMessage@CXTColorSelectorCtrl@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
