// from server: 100% by auto
// roc 2007-03 006efec0  unit: seg_006e0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006efec0
//
// 006efec0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006efec4  8b542404             mov edx, dword ptr [esp + 4]
// 006efec8  56                   push esi
// 006efec9  8bf1                 mov esi, ecx
// 006efecb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006efecf  50                   push eax
// 006efed0  51                   push ecx
// 006efed1  52                   push edx
// 006efed2  8bce                 mov ecx, esi
// 006efed4  e847ffffff           call 0x6efe20
// 006efed9  8b4620               mov eax, dword ptr [esi + 0x20]
// 006efedc  6a00                 push 0
// 006efede  6a00                 push 0
// 006efee0  50                   push eax
// 006efee1  ff1554ee7700         call dword ptr [0x77ee54]
// 006efee7  5e                   pop esi
// 006efee8  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSidePanel.cpp (function ?OnSize@CXTPDockingPaneSidePanel@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSidePanel.cpp
