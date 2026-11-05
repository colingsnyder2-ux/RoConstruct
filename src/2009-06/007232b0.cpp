// from server: 100% by auto
// roc 2009-06 007232b0  unit: RBX::Network::Players::Plugin  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007232b0
//
// 007232b0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007232b4  85c0                 test eax, eax
// 007232b6  7403                 je 0x7232bb
// 007232b8  8b4004               mov eax, dword ptr [eax + 4]
// 007232bb  8b542420             mov edx, dword ptr [esp + 0x20]
// 007232bf  52                   push edx
// 007232c0  8b542420             mov edx, dword ptr [esp + 0x20]
// 007232c4  52                   push edx
// 007232c5  8b542420             mov edx, dword ptr [esp + 0x20]
// 007232c9  52                   push edx
// 007232ca  8b542418             mov edx, dword ptr [esp + 0x18]
// 007232ce  50                   push eax
// 007232cf  8b442420             mov eax, dword ptr [esp + 0x20]
// 007232d3  50                   push eax
// 007232d4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007232d8  52                   push edx
// 007232d9  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007232dd  50                   push eax
// 007232de  8b4104               mov eax, dword ptr [ecx + 4]
// 007232e1  52                   push edx
// 007232e2  50                   push eax
// 007232e3  ff15e0e08900         call dword ptr [0x89e0e0]
// 007232e9  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?BitBlt@CDC@@QAEHHHHHPAV1@HHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
