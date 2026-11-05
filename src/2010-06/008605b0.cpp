// from server: 100% by auto
// roc 2010-06 008605b0  unit: CXTPDockingPaneWindowSelect  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008605b0
//
// 008605b0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 008605b3  8b442404             mov eax, dword ptr [esp + 4]
// 008605b7  895008               mov dword ptr [eax + 8], edx
// 008605ba  83410cff             add dword ptr [ecx + 0xc], -1
// 008605be  894110               mov dword ptr [ecx + 0x10], eax
// 008605c1  7505                 jne 0x8605c8
// 008605c3  e8f8d3f5ff           call 0x7bd9c0
// 008605c8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
