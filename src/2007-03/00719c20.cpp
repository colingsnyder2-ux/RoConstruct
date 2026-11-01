// from server: 100% by auto
// roc 2007-03 00719c20  unit: seg_00710000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00719c20
//
// 00719c20  837c241800           cmp dword ptr [esp + 0x18], 0
// 00719c25  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00719c29  741f                 je 0x719c4a
// 00719c2b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00719c2f  8b542414             mov edx, dword ptr [esp + 0x14]
// 00719c33  50                   push eax
// 00719c34  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00719c38  51                   push ecx
// 00719c39  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00719c3d  52                   push edx
// 00719c3e  50                   push eax
// 00719c3f  51                   push ecx
// 00719c40  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00719c44  e8a30e0200           call 0x73aaec
// 00719c49  c3                   ret 
// 00719c4a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00719c4e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00719c52  52                   push edx
// 00719c53  8b542410             mov edx, dword ptr [esp + 0x10]
// 00719c57  50                   push eax
// 00719c58  8b442410             mov eax, dword ptr [esp + 0x10]
// 00719c5c  51                   push ecx
// 00719c5d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00719c61  52                   push edx
// 00719c62  50                   push eax
// 00719c63  e8840e0200           call 0x73aaec
// 00719c68  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectTrackBar.cpp (function ?PatRect@@YAXPAVCDC@@HHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectTrackBar.cpp
