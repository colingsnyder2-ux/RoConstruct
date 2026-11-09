// from server: 100% by auto
// roc 2007-08 0063d800  unit: CXTPPaintManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063d800
//
// 0063d800  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063d804  85c0                 test eax, eax
// 0063d806  7403                 je 0x63d80b
// 0063d808  8b4004               mov eax, dword ptr [eax + 4]
// 0063d80b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0063d80f  52                   push edx
// 0063d810  8b542428             mov edx, dword ptr [esp + 0x28]
// 0063d814  52                   push edx
// 0063d815  8b542428             mov edx, dword ptr [esp + 0x28]
// 0063d819  52                   push edx
// 0063d81a  8b542428             mov edx, dword ptr [esp + 0x28]
// 0063d81e  52                   push edx
// 0063d81f  8b542428             mov edx, dword ptr [esp + 0x28]
// 0063d823  52                   push edx
// 0063d824  8b542420             mov edx, dword ptr [esp + 0x20]
// 0063d828  50                   push eax
// 0063d829  8b442428             mov eax, dword ptr [esp + 0x28]
// 0063d82d  50                   push eax
// 0063d82e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0063d832  52                   push edx
// 0063d833  8b542424             mov edx, dword ptr [esp + 0x24]
// 0063d837  50                   push eax
// 0063d838  8b4104               mov eax, dword ptr [ecx + 4]
// 0063d83b  52                   push edx
// 0063d83c  50                   push eax
// 0063d83d  ff1538d17700         call dword ptr [0x77d138]
// 0063d843  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
