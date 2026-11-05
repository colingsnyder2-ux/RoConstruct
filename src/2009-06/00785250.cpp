// from server: 100% by auto
// roc 2009-06 00785250  unit: CInstanceRecord::CNameItem  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00785250
//
// 00785250  8b442414             mov eax, dword ptr [esp + 0x14]
// 00785254  56                   push esi
// 00785255  85c0                 test eax, eax
// 00785257  7504                 jne 0x78525d
// 00785259  33f6                 xor esi, esi
// 0078525b  eb03                 jmp 0x785260
// 0078525d  8b7004               mov esi, dword ptr [eax + 4]
// 00785260  8b442420             mov eax, dword ptr [esp + 0x20]
// 00785264  85c0                 test eax, eax
// 00785266  7504                 jne 0x78526c
// 00785268  33d2                 xor edx, edx
// 0078526a  eb03                 jmp 0x78526f
// 0078526c  8b5004               mov edx, dword ptr [eax + 4]
// 0078526f  8b4104               mov eax, dword ptr [ecx + 4]
// 00785272  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00785276  83c904               or ecx, 4
// 00785279  51                   push ecx
// 0078527a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0078527e  51                   push ecx
// 0078527f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00785283  51                   push ecx
// 00785284  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00785288  51                   push ecx
// 00785289  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0078528d  51                   push ecx
// 0078528e  6a00                 push 0
// 00785290  56                   push esi
// 00785291  6a00                 push 0
// 00785293  52                   push edx
// 00785294  50                   push eax
// 00785295  ff150cef8900         call dword ptr [0x89ef0c]
// 0078529b  5e                   pop esi
// 0078529c  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAVCBitmap@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
