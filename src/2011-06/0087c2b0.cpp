// from server: 100% by auto
// roc 2011-06 0087c2b0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087c2b0
//
// 0087c2b0  83ec10               sub esp, 0x10
// 0087c2b3  56                   push esi
// 0087c2b4  8bf1                 mov esi, ecx
// 0087c2b6  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0087c2b9  8d442404             lea eax, [esp + 4]
// 0087c2bd  50                   push eax
// 0087c2be  51                   push ecx
// 0087c2bf  ff157c1ca400         call dword ptr [0xa41c7c]
// 0087c2c5  8b542420             mov edx, dword ptr [esp + 0x20]
// 0087c2c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0087c2cd  52                   push edx
// 0087c2ce  50                   push eax
// 0087c2cf  8d4c240c             lea ecx, [esp + 0xc]
// 0087c2d3  51                   push ecx
// 0087c2d4  ff15101ca400         call dword ptr [0xa41c10]
// 0087c2da  85c0                 test eax, eax
// 0087c2dc  7520                 jne 0x87c2fe
// 0087c2de  8bce                 mov ecx, esi
// 0087c2e0  e82b240700           call 0x8ee710
// 0087c2e5  84c0                 test al, al
// 0087c2e7  7515                 jne 0x87c2fe
// 0087c2e9  8b16                 mov edx, dword ptr [esi]
// 0087c2eb  8b8248010000         mov eax, dword ptr [edx + 0x148]
// 0087c2f1  6aff                 push -1
// 0087c2f3  8bce                 mov ecx, esi
// 0087c2f5  ffd0                 call eax
// 0087c2f7  5e                   pop esi
// 0087c2f8  83c410               add esp, 0x10
// 0087c2fb  c20c00               ret 0xc
// 0087c2fe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0087c302  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0087c306  8b442418             mov eax, dword ptr [esp + 0x18]
// 0087c30a  51                   push ecx
// 0087c30b  52                   push edx
// 0087c30c  50                   push eax
// 0087c30d  8bce                 mov ecx, esi
// 0087c30f  e81c270700           call 0x8eea30
// 0087c314  5e                   pop esi
// 0087c315  83c410               add esp, 0x10
// 0087c318  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Controls\Popup\XTPColorPopup.cpp (function ?OnLButtonDown@CXTPColorPopup@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Popup/XTPColorPopup.cpp
