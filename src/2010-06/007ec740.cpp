// from server: 100% by auto
// roc 2010-06 007ec740  unit: CXTPControls  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec740
//
// 007ec740  83ec14               sub esp, 0x14
// 007ec743  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ec747  8b542420             mov edx, dword ptr [esp + 0x20]
// 007ec74b  56                   push esi
// 007ec74c  8bf1                 mov esi, ecx
// 007ec74e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ec752  89442404             mov dword ptr [esp + 4], eax
// 007ec756  8b442428             mov eax, dword ptr [esp + 0x28]
// 007ec75a  c744240800000000     mov dword ptr [esp + 8], 0
// 007ec762  894c240c             mov dword ptr [esp + 0xc], ecx
// 007ec766  89542410             mov dword ptr [esp + 0x10], edx
// 007ec76a  89442414             mov dword ptr [esp + 0x14], eax
// 007ec76e  e87d1befff           call 0x6de2f0
// 007ec773  a802                 test al, 2
// 007ec775  7508                 jne 0x7ec77f
// 007ec777  c744240801000000     mov dword ptr [esp + 8], 1
// 007ec77f  8b16                 mov edx, dword ptr [esi]
// 007ec781  8b9248010000         mov edx, dword ptr [edx + 0x148]
// 007ec787  8d442404             lea eax, [esp + 4]
// 007ec78b  50                   push eax
// 007ec78c  6a04                 push 4
// 007ec78e  8bce                 mov ecx, esi
// 007ec790  ffd2                 call edx
// 007ec792  8b442408             mov eax, dword ptr [esp + 8]
// 007ec796  5e                   pop esi
// 007ec797  83c414               add esp, 0x14
// 007ec79a  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneManager.cpp (function ?NotifyAction@CXTPDockingPaneManager@@QAEHW4XTPDockingPaneAction@@PAVCXTPDockingPane@@PAVCXTPDockingPaneBase@@W4XTPDockingPaneDirection@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneManager.cpp
