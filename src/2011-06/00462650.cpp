// from server: 100% by auto
// roc 2011-06 00462650  unit: CRobloxApp  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00462650
//
// 00462650  8b442414             mov eax, dword ptr [esp + 0x14]
// 00462654  85c0                 test eax, eax
// 00462656  7403                 je 0x46265b
// 00462658  8b4004               mov eax, dword ptr [eax + 4]
// 0046265b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0046265f  52                   push edx
// 00462660  8b542420             mov edx, dword ptr [esp + 0x20]
// 00462664  52                   push edx
// 00462665  8b542420             mov edx, dword ptr [esp + 0x20]
// 00462669  52                   push edx
// 0046266a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0046266e  50                   push eax
// 0046266f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00462673  50                   push eax
// 00462674  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00462678  52                   push edx
// 00462679  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0046267d  50                   push eax
// 0046267e  8b4104               mov eax, dword ptr [ecx + 4]
// 00462681  52                   push edx
// 00462682  50                   push eax
// 00462683  ff159001a400         call dword ptr [0xa40190]
// 00462689  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
