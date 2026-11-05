// from server: 100% by auto
// roc 2010-06 0081e8c0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081e8c0
//
// 0081e8c0  56                   push esi
// 0081e8c1  8bf1                 mov esi, ecx
// 0081e8c3  e8a896f8ff           call 0x7a7f70
// 0081e8c8  837c240800           cmp dword ptr [esp + 8], 0
// 0081e8cd  751b                 jne 0x81e8ea
// 0081e8cf  8bce                 mov ecx, esi
// 0081e8d1  e85a720700           call 0x895b30
// 0081e8d6  84c0                 test al, al
// 0081e8d8  7510                 jne 0x81e8ea
// 0081e8da  8b4620               mov eax, dword ptr [esi + 0x20]
// 0081e8dd  6a00                 push 0
// 0081e8df  6a00                 push 0
// 0081e8e1  6a10                 push 0x10
// 0081e8e3  50                   push eax
// 0081e8e4  ff1548ba9e00         call dword ptr [0x9eba48]
// 0081e8ea  5e                   pop esi
// 0081e8eb  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTColorPopup.cpp (function ?OnActivate@CXTColorPopup@@IAEXIPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPopup.cpp
