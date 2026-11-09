// from server: 100% by auto
// roc 2008-06 0070a150  unit: CXTPToolTipContext::CHTMLToolTip  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070a150
//
// 0070a150  8b442414             mov eax, dword ptr [esp + 0x14]
// 0070a154  56                   push esi
// 0070a155  85c0                 test eax, eax
// 0070a157  7504                 jne 0x70a15d
// 0070a159  33f6                 xor esi, esi
// 0070a15b  eb03                 jmp 0x70a160
// 0070a15d  8b7004               mov esi, dword ptr [eax + 4]
// 0070a160  8b442420             mov eax, dword ptr [esp + 0x20]
// 0070a164  85c0                 test eax, eax
// 0070a166  7504                 jne 0x70a16c
// 0070a168  33d2                 xor edx, edx
// 0070a16a  eb03                 jmp 0x70a16f
// 0070a16c  8b5004               mov edx, dword ptr [eax + 4]
// 0070a16f  8b4104               mov eax, dword ptr [ecx + 4]
// 0070a172  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0070a176  83c904               or ecx, 4
// 0070a179  51                   push ecx
// 0070a17a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070a17e  51                   push ecx
// 0070a17f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070a183  51                   push ecx
// 0070a184  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070a188  51                   push ecx
// 0070a189  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070a18d  51                   push ecx
// 0070a18e  6a00                 push 0
// 0070a190  56                   push esi
// 0070a191  6a00                 push 0
// 0070a193  52                   push edx
// 0070a194  50                   push eax
// 0070a195  ff15782b8000         call dword ptr [0x802b78]
// 0070a19b  5e                   pop esi
// 0070a19c  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAVCBitmap@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
