// from server: 100% by auto
// roc 2007-08 0066e000  unit: CXTPControls  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0066e000
//
// 0066e000  83ec14               sub esp, 0x14
// 0066e003  8b442418             mov eax, dword ptr [esp + 0x18]
// 0066e007  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066e00b  56                   push esi
// 0066e00c  8bf1                 mov esi, ecx
// 0066e00e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0066e012  89442404             mov dword ptr [esp + 4], eax
// 0066e016  8b442428             mov eax, dword ptr [esp + 0x28]
// 0066e01a  c744240800000000     mov dword ptr [esp + 8], 0
// 0066e022  894c240c             mov dword ptr [esp + 0xc], ecx
// 0066e026  89542410             mov dword ptr [esp + 0x10], edx
// 0066e02a  89442414             mov dword ptr [esp + 0x14], eax
// 0066e02e  e87d110200           call 0x68f1b0
// 0066e033  a802                 test al, 2
// 0066e035  7508                 jne 0x66e03f
// 0066e037  c744240801000000     mov dword ptr [esp + 8], 1
// 0066e03f  8b16                 mov edx, dword ptr [esi]
// 0066e041  8b9240010000         mov edx, dword ptr [edx + 0x140]
// 0066e047  8d442404             lea eax, [esp + 4]
// 0066e04b  50                   push eax
// 0066e04c  6a04                 push 4
// 0066e04e  8bce                 mov ecx, esi
// 0066e050  ffd2                 call edx
// 0066e052  8b442408             mov eax, dword ptr [esp + 8]
// 0066e056  5e                   pop esi
// 0066e057  83c414               add esp, 0x14
// 0066e05a  c21000               ret 0x10
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?NotifyAction@CXTPDockingPaneManager@@QAEHW4XTPDockingPaneAction@@PAVCXTPDockingPane@@PAVCXTPDockingPaneBase@@W4XTPDockingPaneDirection@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
