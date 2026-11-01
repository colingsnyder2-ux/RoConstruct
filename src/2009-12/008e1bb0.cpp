// from server: 100% by auto
// roc 2009-12 008e1bb0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e1bb0
//
// 008e1bb0  8b442404             mov eax, dword ptr [esp + 4]
// 008e1bb4  85c0                 test eax, eax
// 008e1bb6  7517                 jne 0x8e1bcf
// 008e1bb8  83c8ff               or eax, 0xffffffff
// 008e1bbb  6a00                 push 0
// 008e1bbd  894170               mov dword ptr [ecx + 0x70], eax
// 008e1bc0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008e1bc3  6a00                 push 0
// 008e1bc5  50                   push eax
// 008e1bc6  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e1bcc  c20400               ret 4
// 008e1bcf  8b4004               mov eax, dword ptr [eax + 4]
// 008e1bd2  6a00                 push 0
// 008e1bd4  894170               mov dword ptr [ecx + 0x70], eax
// 008e1bd7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008e1bda  6a00                 push 0
// 008e1bdc  50                   push eax
// 008e1bdd  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e1be3  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?SelectColorCell@CXTColorSelectorCtrl@@UAEXPAUCOLOR_CELL@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
