// from server: 100% by auto
// roc 2010-06 00895e40  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00895e40
//
// 00895e40  8b442404             mov eax, dword ptr [esp + 4]
// 00895e44  85c0                 test eax, eax
// 00895e46  7517                 jne 0x895e5f
// 00895e48  83c8ff               or eax, 0xffffffff
// 00895e4b  6a00                 push 0
// 00895e4d  894170               mov dword ptr [ecx + 0x70], eax
// 00895e50  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00895e53  6a00                 push 0
// 00895e55  50                   push eax
// 00895e56  ff1578ba9e00         call dword ptr [0x9eba78]
// 00895e5c  c20400               ret 4
// 00895e5f  8b4004               mov eax, dword ptr [eax + 4]
// 00895e62  6a00                 push 0
// 00895e64  894170               mov dword ptr [ecx + 0x70], eax
// 00895e67  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00895e6a  6a00                 push 0
// 00895e6c  50                   push eax
// 00895e6d  ff1578ba9e00         call dword ptr [0x9eba78]
// 00895e73  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?SelectColorCell@CXTColorSelectorCtrl@@UAEXPAUCOLOR_CELL@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
