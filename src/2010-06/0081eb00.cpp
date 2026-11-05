// from server: 100% by auto
// roc 2010-06 0081eb00  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081eb00
//
// 0081eb00  83ec10               sub esp, 0x10
// 0081eb03  56                   push esi
// 0081eb04  8bf1                 mov esi, ecx
// 0081eb06  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0081eb09  8d442404             lea eax, [esp + 4]
// 0081eb0d  50                   push eax
// 0081eb0e  51                   push ecx
// 0081eb0f  ff155cbc9e00         call dword ptr [0x9ebc5c]
// 0081eb15  8b542420             mov edx, dword ptr [esp + 0x20]
// 0081eb19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0081eb1d  52                   push edx
// 0081eb1e  50                   push eax
// 0081eb1f  8d4c240c             lea ecx, [esp + 0xc]
// 0081eb23  51                   push ecx
// 0081eb24  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 0081eb2a  85c0                 test eax, eax
// 0081eb2c  7520                 jne 0x81eb4e
// 0081eb2e  8bce                 mov ecx, esi
// 0081eb30  e8fb6f0700           call 0x895b30
// 0081eb35  84c0                 test al, al
// 0081eb37  7515                 jne 0x81eb4e
// 0081eb39  8b16                 mov edx, dword ptr [esi]
// 0081eb3b  8b8248010000         mov eax, dword ptr [edx + 0x148]
// 0081eb41  6aff                 push -1
// 0081eb43  8bce                 mov ecx, esi
// 0081eb45  ffd0                 call eax
// 0081eb47  5e                   pop esi
// 0081eb48  83c410               add esp, 0x10
// 0081eb4b  c20c00               ret 0xc
// 0081eb4e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0081eb52  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0081eb56  8b442418             mov eax, dword ptr [esp + 0x18]
// 0081eb5a  51                   push ecx
// 0081eb5b  52                   push edx
// 0081eb5c  50                   push eax
// 0081eb5d  8bce                 mov ecx, esi
// 0081eb5f  e81c730700           call 0x895e80
// 0081eb64  5e                   pop esi
// 0081eb65  83c410               add esp, 0x10
// 0081eb68  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPopup.cpp (function ?OnLButtonDown@CXTColorPopup@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPopup.cpp
