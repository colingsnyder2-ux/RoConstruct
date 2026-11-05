// from server: 100% by auto
// roc 2010-06 007adc70  unit: CXTPPaintManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007adc70
//
// 007adc70  8b442414             mov eax, dword ptr [esp + 0x14]
// 007adc74  85c0                 test eax, eax
// 007adc76  7403                 je 0x7adc7b
// 007adc78  8b4004               mov eax, dword ptr [eax + 4]
// 007adc7b  8b542428             mov edx, dword ptr [esp + 0x28]
// 007adc7f  52                   push edx
// 007adc80  8b542428             mov edx, dword ptr [esp + 0x28]
// 007adc84  52                   push edx
// 007adc85  8b542428             mov edx, dword ptr [esp + 0x28]
// 007adc89  52                   push edx
// 007adc8a  8b542428             mov edx, dword ptr [esp + 0x28]
// 007adc8e  52                   push edx
// 007adc8f  8b542428             mov edx, dword ptr [esp + 0x28]
// 007adc93  52                   push edx
// 007adc94  8b542420             mov edx, dword ptr [esp + 0x20]
// 007adc98  50                   push eax
// 007adc99  8b442428             mov eax, dword ptr [esp + 0x28]
// 007adc9d  50                   push eax
// 007adc9e  8b442424             mov eax, dword ptr [esp + 0x24]
// 007adca2  52                   push edx
// 007adca3  8b542424             mov edx, dword ptr [esp + 0x24]
// 007adca7  50                   push eax
// 007adca8  8b4104               mov eax, dword ptr [ecx + 4]
// 007adcab  52                   push edx
// 007adcac  50                   push eax
// 007adcad  ff1564a19e00         call dword ptr [0x9ea164]
// 007adcb3  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
