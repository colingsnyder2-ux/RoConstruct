// from server: 100% by auto
// roc 2009-12 00860260  unit: CXTPToolTipContext::CHTMLToolTip  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00860260
//
// 00860260  8b442414             mov eax, dword ptr [esp + 0x14]
// 00860264  56                   push esi
// 00860265  85c0                 test eax, eax
// 00860267  7504                 jne 0x86026d
// 00860269  33f6                 xor esi, esi
// 0086026b  eb03                 jmp 0x860270
// 0086026d  8b7004               mov esi, dword ptr [eax + 4]
// 00860270  8b442420             mov eax, dword ptr [esp + 0x20]
// 00860274  85c0                 test eax, eax
// 00860276  7504                 jne 0x86027c
// 00860278  33d2                 xor edx, edx
// 0086027a  eb03                 jmp 0x86027f
// 0086027c  8b5004               mov edx, dword ptr [eax + 4]
// 0086027f  8b4104               mov eax, dword ptr [ecx + 4]
// 00860282  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00860286  83c904               or ecx, 4
// 00860289  51                   push ecx
// 0086028a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0086028e  51                   push ecx
// 0086028f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00860293  51                   push ecx
// 00860294  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00860298  51                   push ecx
// 00860299  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0086029d  51                   push ecx
// 0086029e  6a00                 push 0
// 008602a0  56                   push esi
// 008602a1  6a00                 push 0
// 008602a3  52                   push edx
// 008602a4  50                   push eax
// 008602a5  ff15f8ca9800         call dword ptr [0x98caf8]
// 008602ab  5e                   pop esi
// 008602ac  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAVCBitmap@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
