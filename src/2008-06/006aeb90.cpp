// from server: 100% by auto
// roc 2008-06 006aeb90  unit: CXTPPaintManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006aeb90
//
// 006aeb90  8b442414             mov eax, dword ptr [esp + 0x14]
// 006aeb94  85c0                 test eax, eax
// 006aeb96  7403                 je 0x6aeb9b
// 006aeb98  8b4004               mov eax, dword ptr [eax + 4]
// 006aeb9b  8b542420             mov edx, dword ptr [esp + 0x20]
// 006aeb9f  52                   push edx
// 006aeba0  8b542420             mov edx, dword ptr [esp + 0x20]
// 006aeba4  52                   push edx
// 006aeba5  8b542420             mov edx, dword ptr [esp + 0x20]
// 006aeba9  52                   push edx
// 006aebaa  8b542418             mov edx, dword ptr [esp + 0x18]
// 006aebae  50                   push eax
// 006aebaf  8b442420             mov eax, dword ptr [esp + 0x20]
// 006aebb3  50                   push eax
// 006aebb4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006aebb8  52                   push edx
// 006aebb9  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006aebbd  50                   push eax
// 006aebbe  8b4104               mov eax, dword ptr [ecx + 4]
// 006aebc1  52                   push edx
// 006aebc2  50                   push eax
// 006aebc3  ff15c4208000         call dword ptr [0x8020c4]
// 006aebc9  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
