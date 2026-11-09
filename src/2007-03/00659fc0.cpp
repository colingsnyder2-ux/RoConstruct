// from server: 100% by auto
// roc 2007-03 00659fc0  unit: seg_00650000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00659fc0
//
// 00659fc0  83ec14               sub esp, 0x14
// 00659fc3  8b442418             mov eax, dword ptr [esp + 0x18]
// 00659fc7  8b542420             mov edx, dword ptr [esp + 0x20]
// 00659fcb  56                   push esi
// 00659fcc  8bf1                 mov esi, ecx
// 00659fce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00659fd2  89442404             mov dword ptr [esp + 4], eax
// 00659fd6  8b442428             mov eax, dword ptr [esp + 0x28]
// 00659fda  c744240800000000     mov dword ptr [esp + 8], 0
// 00659fe2  894c240c             mov dword ptr [esp + 0xc], ecx
// 00659fe6  89542410             mov dword ptr [esp + 0x10], edx
// 00659fea  89442414             mov dword ptr [esp + 0x14], eax
// 00659fee  e8ddec0100           call 0x678cd0
// 00659ff3  a802                 test al, 2
// 00659ff5  7508                 jne 0x659fff
// 00659ff7  c744240801000000     mov dword ptr [esp + 8], 1
// 00659fff  8b16                 mov edx, dword ptr [esi]
// 0065a001  8b9240010000         mov edx, dword ptr [edx + 0x140]
// 0065a007  8d442404             lea eax, [esp + 4]
// 0065a00b  50                   push eax
// 0065a00c  6a04                 push 4
// 0065a00e  8bce                 mov ecx, esi
// 0065a010  ffd2                 call edx
// 0065a012  8b442408             mov eax, dword ptr [esp + 8]
// 0065a016  5e                   pop esi
// 0065a017  83c414               add esp, 0x14
// 0065a01a  c21000               ret 0x10
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?NotifyAction@CXTPDockingPaneManager@@QAEHW4XTPDockingPaneAction@@PAVCXTPDockingPane@@PAVCXTPDockingPaneBase@@W4XTPDockingPaneDirection@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
