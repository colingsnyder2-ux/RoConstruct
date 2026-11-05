// from server: 100% by auto
// roc 2009-06 007232f0  unit: RBX::Network::Players::Plugin  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007232f0
//
// 007232f0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007232f4  85c0                 test eax, eax
// 007232f6  7403                 je 0x7232fb
// 007232f8  8b4004               mov eax, dword ptr [eax + 4]
// 007232fb  8b542428             mov edx, dword ptr [esp + 0x28]
// 007232ff  52                   push edx
// 00723300  8b542428             mov edx, dword ptr [esp + 0x28]
// 00723304  52                   push edx
// 00723305  8b542428             mov edx, dword ptr [esp + 0x28]
// 00723309  52                   push edx
// 0072330a  8b542428             mov edx, dword ptr [esp + 0x28]
// 0072330e  52                   push edx
// 0072330f  8b542428             mov edx, dword ptr [esp + 0x28]
// 00723313  52                   push edx
// 00723314  8b542420             mov edx, dword ptr [esp + 0x20]
// 00723318  50                   push eax
// 00723319  8b442428             mov eax, dword ptr [esp + 0x28]
// 0072331d  50                   push eax
// 0072331e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00723322  52                   push edx
// 00723323  8b542424             mov edx, dword ptr [esp + 0x24]
// 00723327  50                   push eax
// 00723328  8b4104               mov eax, dword ptr [ecx + 4]
// 0072332b  52                   push edx
// 0072332c  50                   push eax
// 0072332d  ff15dce08900         call dword ptr [0x89e0dc]
// 00723333  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
