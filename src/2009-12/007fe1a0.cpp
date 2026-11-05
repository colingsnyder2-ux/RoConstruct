// from server: 100% by auto
// roc 2009-12 007fe1a0  unit: CXTPPaintManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe1a0
//
// 007fe1a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fe1a4  85c0                 test eax, eax
// 007fe1a6  7403                 je 0x7fe1ab
// 007fe1a8  8b4004               mov eax, dword ptr [eax + 4]
// 007fe1ab  8b542428             mov edx, dword ptr [esp + 0x28]
// 007fe1af  52                   push edx
// 007fe1b0  8b542428             mov edx, dword ptr [esp + 0x28]
// 007fe1b4  52                   push edx
// 007fe1b5  8b542428             mov edx, dword ptr [esp + 0x28]
// 007fe1b9  52                   push edx
// 007fe1ba  8b542428             mov edx, dword ptr [esp + 0x28]
// 007fe1be  52                   push edx
// 007fe1bf  8b542428             mov edx, dword ptr [esp + 0x28]
// 007fe1c3  52                   push edx
// 007fe1c4  8b542420             mov edx, dword ptr [esp + 0x20]
// 007fe1c8  50                   push eax
// 007fe1c9  8b442428             mov eax, dword ptr [esp + 0x28]
// 007fe1cd  50                   push eax
// 007fe1ce  8b442424             mov eax, dword ptr [esp + 0x24]
// 007fe1d2  52                   push edx
// 007fe1d3  8b542424             mov edx, dword ptr [esp + 0x24]
// 007fe1d7  50                   push eax
// 007fe1d8  8b4104               mov eax, dword ptr [ecx + 4]
// 007fe1db  52                   push edx
// 007fe1dc  50                   push eax
// 007fe1dd  ff151cb19800         call dword ptr [0x98b11c]
// 007fe1e3  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
