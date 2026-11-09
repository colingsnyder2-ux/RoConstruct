// from server: 100% by auto
// roc 2009-12 008e1e70  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e1e70
//
// 008e1e70  56                   push esi
// 008e1e71  8bf1                 mov esi, ecx
// 008e1e73  8d86b8000000         lea eax, [esi + 0xb8]
// 008e1e79  57                   push edi
// 008e1e7a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008e1e7e  85c0                 test eax, eax
// 008e1e80  741b                 je 0x8e1e9d
// 008e1e82  83782000             cmp dword ptr [eax + 0x20], 0
// 008e1e86  7415                 je 0x8e1e9d
// 008e1e88  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 008e1e8e  57                   push edi
// 008e1e8f  6a00                 push 0
// 008e1e91  6807040000           push 0x407
// 008e1e96  50                   push eax
// 008e1e97  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008e1e9d  57                   push edi
// 008e1e9e  8bce                 mov ecx, esi
// 008e1ea0  e8bb1ff1ff           call 0x7f3e60
// 008e1ea5  5f                   pop edi
// 008e1ea6  5e                   pop esi
// 008e1ea7  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?PreTranslateMessage@CXTColorSelectorCtrl@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
