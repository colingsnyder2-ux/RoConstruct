// from server: 100% by auto
// roc 2010-06 007adbf0  unit: CXTPPaintManager  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007adbf0
//
// 007adbf0  8b442404             mov eax, dword ptr [esp + 4]
// 007adbf4  56                   push esi
// 007adbf5  8bf1                 mov esi, ecx
// 007adbf7  85c0                 test eax, eax
// 007adbf9  7513                 jne 0x7adc0e
// 007adbfb  50                   push eax
// 007adbfc  ff15aca09e00         call dword ptr [0x9ea0ac]
// 007adc02  50                   push eax
// 007adc03  8bce                 mov ecx, esi
// 007adc05  e886f11c00           call 0x97cd90
// 007adc0a  5e                   pop esi
// 007adc0b  c20400               ret 4
// 007adc0e  8b4004               mov eax, dword ptr [eax + 4]
// 007adc11  50                   push eax
// 007adc12  ff15aca09e00         call dword ptr [0x9ea0ac]
// 007adc18  50                   push eax
// 007adc19  8bce                 mov ecx, esi
// 007adc1b  e870f11c00           call 0x97cd90
// 007adc20  5e                   pop esi
// 007adc21  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?CreateCompatibleDC@CDC@@QAEHPAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
