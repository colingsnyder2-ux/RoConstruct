// from server: 100% by auto
// roc 2007-03 00632b40  unit: seg_00630000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632b40
//
// 00632b40  8b442414             mov eax, dword ptr [esp + 0x14]
// 00632b44  85c0                 test eax, eax
// 00632b46  7403                 je 0x632b4b
// 00632b48  8b4004               mov eax, dword ptr [eax + 4]
// 00632b4b  8b542428             mov edx, dword ptr [esp + 0x28]
// 00632b4f  52                   push edx
// 00632b50  8b542428             mov edx, dword ptr [esp + 0x28]
// 00632b54  52                   push edx
// 00632b55  8b542428             mov edx, dword ptr [esp + 0x28]
// 00632b59  52                   push edx
// 00632b5a  8b542428             mov edx, dword ptr [esp + 0x28]
// 00632b5e  52                   push edx
// 00632b5f  8b542428             mov edx, dword ptr [esp + 0x28]
// 00632b63  52                   push edx
// 00632b64  8b542420             mov edx, dword ptr [esp + 0x20]
// 00632b68  50                   push eax
// 00632b69  8b442428             mov eax, dword ptr [esp + 0x28]
// 00632b6d  50                   push eax
// 00632b6e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00632b72  52                   push edx
// 00632b73  8b542424             mov edx, dword ptr [esp + 0x24]
// 00632b77  50                   push eax
// 00632b78  8b4104               mov eax, dword ptr [ecx + 4]
// 00632b7b  52                   push edx
// 00632b7c  50                   push eax
// 00632b7d  ff15e0d07700         call dword ptr [0x77d0e0]
// 00632b83  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
