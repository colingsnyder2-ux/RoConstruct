// from server: 100% by auto
// roc 2011-06 00810080  unit: CXTPPaintManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00810080
//
// 00810080  8b442414             mov eax, dword ptr [esp + 0x14]
// 00810084  85c0                 test eax, eax
// 00810086  7403                 je 0x81008b
// 00810088  8b4004               mov eax, dword ptr [eax + 4]
// 0081008b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0081008f  52                   push edx
// 00810090  8b542428             mov edx, dword ptr [esp + 0x28]
// 00810094  52                   push edx
// 00810095  8b542428             mov edx, dword ptr [esp + 0x28]
// 00810099  52                   push edx
// 0081009a  8b542428             mov edx, dword ptr [esp + 0x28]
// 0081009e  52                   push edx
// 0081009f  8b542428             mov edx, dword ptr [esp + 0x28]
// 008100a3  52                   push edx
// 008100a4  8b542420             mov edx, dword ptr [esp + 0x20]
// 008100a8  50                   push eax
// 008100a9  8b442428             mov eax, dword ptr [esp + 0x28]
// 008100ad  50                   push eax
// 008100ae  8b442424             mov eax, dword ptr [esp + 0x24]
// 008100b2  52                   push edx
// 008100b3  8b542424             mov edx, dword ptr [esp + 0x24]
// 008100b7  50                   push eax
// 008100b8  8b4104               mov eax, dword ptr [ecx + 4]
// 008100bb  52                   push edx
// 008100bc  50                   push eax
// 008100bd  ff151401a400         call dword ptr [0xa40114]
// 008100c3  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
