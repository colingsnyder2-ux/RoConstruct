// from server: 100% by auto
// roc 2008-06 006aebd0  unit: CXTPPaintManager  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006aebd0
//
// 006aebd0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006aebd4  85c0                 test eax, eax
// 006aebd6  7403                 je 0x6aebdb
// 006aebd8  8b4004               mov eax, dword ptr [eax + 4]
// 006aebdb  8b542428             mov edx, dword ptr [esp + 0x28]
// 006aebdf  52                   push edx
// 006aebe0  8b542428             mov edx, dword ptr [esp + 0x28]
// 006aebe4  52                   push edx
// 006aebe5  8b542428             mov edx, dword ptr [esp + 0x28]
// 006aebe9  52                   push edx
// 006aebea  8b542428             mov edx, dword ptr [esp + 0x28]
// 006aebee  52                   push edx
// 006aebef  8b542428             mov edx, dword ptr [esp + 0x28]
// 006aebf3  52                   push edx
// 006aebf4  8b542420             mov edx, dword ptr [esp + 0x20]
// 006aebf8  50                   push eax
// 006aebf9  8b442428             mov eax, dword ptr [esp + 0x28]
// 006aebfd  50                   push eax
// 006aebfe  8b442424             mov eax, dword ptr [esp + 0x24]
// 006aec02  52                   push edx
// 006aec03  8b542424             mov edx, dword ptr [esp + 0x24]
// 006aec07  50                   push eax
// 006aec08  8b4104               mov eax, dword ptr [ecx + 4]
// 006aec0b  52                   push edx
// 006aec0c  50                   push eax
// 006aec0d  ff15c0208000         call dword ptr [0x8020c0]
// 006aec13  c22800               ret 0x28
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?AlphaBlend@CDC@@QAEHHHHHPAV1@HHHHU_BLENDFUNCTION@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
