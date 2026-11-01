// from server: 100% by auto
// roc 2011-06 008eecb0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008eecb0
//
// 008eecb0  56                   push esi
// 008eecb1  8bf1                 mov esi, ecx
// 008eecb3  8d86b8000000         lea eax, [esi + 0xb8]
// 008eecb9  57                   push edi
// 008eecba  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008eecbe  85c0                 test eax, eax
// 008eecc0  741b                 je 0x8eecdd
// 008eecc2  83782000             cmp dword ptr [eax + 0x20], 0
// 008eecc6  7415                 je 0x8eecdd
// 008eecc8  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 008eecce  57                   push edi
// 008eeccf  6a00                 push 0
// 008eecd1  6807040000           push 0x407
// 008eecd6  50                   push eax
// 008eecd7  ff15c019a400         call dword ptr [0xa419c0]
// 008eecdd  57                   push edi
// 008eecde  8bce                 mov ecx, esi
// 008eece0  e879b9f1ff           call 0x80a65e
// 008eece5  5f                   pop edi
// 008eece6  5e                   pop esi
// 008eece7  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?PreTranslateMessage@CXTColorSelectorCtrl@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
