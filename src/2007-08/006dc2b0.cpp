// from server: 100% by auto
// roc 2007-08 006dc2b0  unit: CXTPDockingPaneWindowSelect  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006dc2b0
//
// 006dc2b0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 006dc2b3  8b442404             mov eax, dword ptr [esp + 4]
// 006dc2b7  895008               mov dword ptr [eax + 8], edx
// 006dc2ba  83410cff             add dword ptr [ecx + 0xc], -1
// 006dc2be  894110               mov dword ptr [ecx + 0x10], eax
// 006dc2c1  7505                 jne 0x6dc2c8
// 006dc2c3  e828baffff           call 0x6d7cf0
// 006dc2c8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
