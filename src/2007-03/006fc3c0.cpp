// from server: 100% by auto
// roc 2007-03 006fc3c0  unit: seg_006f0000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006fc3c0
//
// 006fc3c0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 006fc3c3  8b442404             mov eax, dword ptr [esp + 4]
// 006fc3c7  895008               mov dword ptr [eax + 8], edx
// 006fc3ca  83410cff             add dword ptr [ecx + 0xc], -1
// 006fc3ce  894110               mov dword ptr [ecx + 0x10], eax
// 006fc3d1  7505                 jne 0x6fc3d8
// 006fc3d3  e8e8f5f2ff           call 0x62b9c0
// 006fc3d8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
