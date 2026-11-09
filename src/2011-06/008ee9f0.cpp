// from server: 100% by auto
// roc 2011-06 008ee9f0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ee9f0
//
// 008ee9f0  8b442404             mov eax, dword ptr [esp + 4]
// 008ee9f4  85c0                 test eax, eax
// 008ee9f6  7517                 jne 0x8eea0f
// 008ee9f8  83c8ff               or eax, 0xffffffff
// 008ee9fb  6a00                 push 0
// 008ee9fd  894170               mov dword ptr [ecx + 0x70], eax
// 008eea00  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008eea03  6a00                 push 0
// 008eea05  50                   push eax
// 008eea06  ff15ec19a400         call dword ptr [0xa419ec]
// 008eea0c  c20400               ret 4
// 008eea0f  8b4004               mov eax, dword ptr [eax + 4]
// 008eea12  6a00                 push 0
// 008eea14  894170               mov dword ptr [ecx + 0x70], eax
// 008eea17  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008eea1a  6a00                 push 0
// 008eea1c  50                   push eax
// 008eea1d  ff15ec19a400         call dword ptr [0xa419ec]
// 008eea23  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?SelectColorCell@CXTColorSelectorCtrl@@UAEXPAUCOLOR_CELL@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
