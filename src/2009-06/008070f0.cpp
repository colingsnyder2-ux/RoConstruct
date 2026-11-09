// from server: 100% by auto
// roc 2009-06 008070f0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008070f0
//
// 008070f0  8b442404             mov eax, dword ptr [esp + 4]
// 008070f4  85c0                 test eax, eax
// 008070f6  7517                 jne 0x80710f
// 008070f8  83c8ff               or eax, 0xffffffff
// 008070fb  6a00                 push 0
// 008070fd  894170               mov dword ptr [ecx + 0x70], eax
// 00807100  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00807103  6a00                 push 0
// 00807105  50                   push eax
// 00807106  ff157cee8900         call dword ptr [0x89ee7c]
// 0080710c  c20400               ret 4
// 0080710f  8b4004               mov eax, dword ptr [eax + 4]
// 00807112  6a00                 push 0
// 00807114  894170               mov dword ptr [ecx + 0x70], eax
// 00807117  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0080711a  6a00                 push 0
// 0080711c  50                   push eax
// 0080711d  ff157cee8900         call dword ptr [0x89ee7c]
// 00807123  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?SelectColorCell@CXTColorSelectorCtrl@@UAEXPAUCOLOR_CELL@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
