// from server: 100% by auto
// roc 2010-06 00896100  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00896100
//
// 00896100  56                   push esi
// 00896101  8bf1                 mov esi, ecx
// 00896103  8d86b8000000         lea eax, [esi + 0xb8]
// 00896109  57                   push edi
// 0089610a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089610e  85c0                 test eax, eax
// 00896110  741b                 je 0x89612d
// 00896112  83782000             cmp dword ptr [eax + 0x20], 0
// 00896116  7415                 je 0x89612d
// 00896118  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 0089611e  57                   push edi
// 0089611f  6a00                 push 0
// 00896121  6807040000           push 0x407
// 00896126  50                   push eax
// 00896127  ff1554ba9e00         call dword ptr [0x9eba54]
// 0089612d  57                   push edi
// 0089612e  8bce                 mov ecx, esi
// 00896130  e86b1ef1ff           call 0x7a7fa0
// 00896135  5f                   pop edi
// 00896136  5e                   pop esi
// 00896137  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?PreTranslateMessage@CXTColorSelectorCtrl@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
