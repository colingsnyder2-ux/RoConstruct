// from server: 100% by auto
// roc 2009-12 0086a8c0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086a8c0
//
// 0086a8c0  56                   push esi
// 0086a8c1  8bf1                 mov esi, ecx
// 0086a8c3  e86895f8ff           call 0x7f3e30
// 0086a8c8  837c240800           cmp dword ptr [esp + 8], 0
// 0086a8cd  751b                 jne 0x86a8ea
// 0086a8cf  8bce                 mov ecx, esi
// 0086a8d1  e8fa6f0700           call 0x8e18d0
// 0086a8d6  84c0                 test al, al
// 0086a8d8  7510                 jne 0x86a8ea
// 0086a8da  8b4620               mov eax, dword ptr [esi + 0x20]
// 0086a8dd  6a00                 push 0
// 0086a8df  6a00                 push 0
// 0086a8e1  6a10                 push 0x10
// 0086a8e3  50                   push eax
// 0086a8e4  ff15b8cb9800         call dword ptr [0x98cbb8]
// 0086a8ea  5e                   pop esi
// 0086a8eb  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Popup\XTPColorPopup.cpp (function ?OnActivate@CXTPColorPopup@@IAEXIPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Popup/XTPColorPopup.cpp
