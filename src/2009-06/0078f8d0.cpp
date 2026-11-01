// from server: 100% by auto
// roc 2009-06 0078f8d0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078f8d0
//
// 0078f8d0  56                   push esi
// 0078f8d1  8bf1                 mov esi, ecx
// 0078f8d3  e83097f8ff           call 0x719008
// 0078f8d8  837c240800           cmp dword ptr [esp + 8], 0
// 0078f8dd  751b                 jne 0x78f8fa
// 0078f8df  8bce                 mov ecx, esi
// 0078f8e1  e8da740700           call 0x806dc0
// 0078f8e6  84c0                 test al, al
// 0078f8e8  7510                 jne 0x78f8fa
// 0078f8ea  8b4620               mov eax, dword ptr [esi + 0x20]
// 0078f8ed  6a00                 push 0
// 0078f8ef  6a00                 push 0
// 0078f8f1  6a10                 push 0x10
// 0078f8f3  50                   push eax
// 0078f8f4  ff159cee8900         call dword ptr [0x89ee9c]
// 0078f8fa  5e                   pop esi
// 0078f8fb  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Popup\XTPColorPopup.cpp (function ?OnActivate@CXTPColorPopup@@IAEXIPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Popup/XTPColorPopup.cpp
