// from server: 100% by auto
// roc 2011-06 008bd8b0  unit: CXTPDockingPaneWindowSelect  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bd8b0
//
// 008bd8b0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 008bd8b3  8b442404             mov eax, dword ptr [esp + 4]
// 008bd8b7  895008               mov dword ptr [eax + 8], edx
// 008bd8ba  83410cff             add dword ptr [ecx + 0xc], -1
// 008bd8be  894110               mov dword ptr [ecx + 0x10], eax
// 008bd8c1  7505                 jne 0x8bd8c8
// 008bd8c3  e8e8b9ffff           call 0x8b92b0
// 008bd8c8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
