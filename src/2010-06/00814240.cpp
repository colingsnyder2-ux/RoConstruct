// from server: 100% by auto
// roc 2010-06 00814240  unit: CXTPToolTipContext::CHTMLToolTip  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00814240
//
// 00814240  8b442414             mov eax, dword ptr [esp + 0x14]
// 00814244  56                   push esi
// 00814245  85c0                 test eax, eax
// 00814247  7504                 jne 0x81424d
// 00814249  33f6                 xor esi, esi
// 0081424b  eb03                 jmp 0x814250
// 0081424d  8b7004               mov esi, dword ptr [eax + 4]
// 00814250  8b442420             mov eax, dword ptr [esp + 0x20]
// 00814254  85c0                 test eax, eax
// 00814256  7504                 jne 0x81425c
// 00814258  33d2                 xor edx, edx
// 0081425a  eb03                 jmp 0x81425f
// 0081425c  8b5004               mov edx, dword ptr [eax + 4]
// 0081425f  8b4104               mov eax, dword ptr [ecx + 4]
// 00814262  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00814266  83c904               or ecx, 4
// 00814269  51                   push ecx
// 0081426a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0081426e  51                   push ecx
// 0081426f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00814273  51                   push ecx
// 00814274  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00814278  51                   push ecx
// 00814279  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0081427d  51                   push ecx
// 0081427e  6a00                 push 0
// 00814280  56                   push esi
// 00814281  6a00                 push 0
// 00814283  52                   push edx
// 00814284  50                   push eax
// 00814285  ff15a8ba9e00         call dword ptr [0x9ebaa8]
// 0081428b  5e                   pop esi
// 0081428c  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAVCBitmap@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
