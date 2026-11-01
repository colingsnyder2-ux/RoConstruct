// from server: 100% by auto
// roc 2007-03 007209b0  unit: seg_00720000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007209b0
//
// 007209b0  83ec10               sub esp, 0x10
// 007209b3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007209b7  8b542420             mov edx, dword ptr [esp + 0x20]
// 007209bb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007209bf  890424               mov dword ptr [esp], eax
// 007209c2  03c2                 add eax, edx
// 007209c4  89442408             mov dword ptr [esp + 8], eax
// 007209c8  8b442424             mov eax, dword ptr [esp + 0x24]
// 007209cc  894c2404             mov dword ptr [esp + 4], ecx
// 007209d0  03c8                 add ecx, eax
// 007209d2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007209d6  894c240c             mov dword ptr [esp + 0xc], ecx
// 007209da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007209de  51                   push ecx
// 007209df  8d542404             lea edx, [esp + 4]
// 007209e3  52                   push edx
// 007209e4  50                   push eax
// 007209e5  ff15c8ee7700         call dword ptr [0x77eec8]
// 007209eb  83c410               add esp, 0x10
// 007209ee  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinDrawTools.cpp (function ?XTPFillSolidRect@@YAXPAUHDC__@@HHHHPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinDrawTools.cpp
