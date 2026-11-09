// from server: 100% by auto
// roc 2009-06 007d1800  unit: CXTPDockingPaneWindowSelect  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d1800
//
// 007d1800  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007d1803  8b442404             mov eax, dword ptr [esp + 4]
// 007d1807  895008               mov dword ptr [eax + 8], edx
// 007d180a  83410cff             add dword ptr [ecx + 0xc], -1
// 007d180e  894110               mov dword ptr [ecx + 0x10], eax
// 007d1811  7505                 jne 0x7d1818
// 007d1813  e8680ef6ff           call 0x732680
// 007d1818  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
