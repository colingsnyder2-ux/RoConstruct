// from server: 100% by auto
// roc 2010-06 007adc30  unit: CXTPPaintManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007adc30
//
// 007adc30  8b442414             mov eax, dword ptr [esp + 0x14]
// 007adc34  85c0                 test eax, eax
// 007adc36  7403                 je 0x7adc3b
// 007adc38  8b4004               mov eax, dword ptr [eax + 4]
// 007adc3b  8b542420             mov edx, dword ptr [esp + 0x20]
// 007adc3f  52                   push edx
// 007adc40  8b542420             mov edx, dword ptr [esp + 0x20]
// 007adc44  52                   push edx
// 007adc45  8b542420             mov edx, dword ptr [esp + 0x20]
// 007adc49  52                   push edx
// 007adc4a  8b542418             mov edx, dword ptr [esp + 0x18]
// 007adc4e  50                   push eax
// 007adc4f  8b442420             mov eax, dword ptr [esp + 0x20]
// 007adc53  50                   push eax
// 007adc54  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007adc58  52                   push edx
// 007adc59  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007adc5d  50                   push eax
// 007adc5e  8b4104               mov eax, dword ptr [ecx + 4]
// 007adc61  52                   push edx
// 007adc62  50                   push eax
// 007adc63  ff15c0a09e00         call dword ptr [0x9ea0c0]
// 007adc69  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
