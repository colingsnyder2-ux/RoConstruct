// from server: 100% by auto
// roc 2008-06 0071c2c0  unit: CXTPDockBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071c2c0
//
// 0071c2c0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0071c2c3  8b442404             mov eax, dword ptr [esp + 4]
// 0071c2c7  895008               mov dword ptr [eax + 8], edx
// 0071c2ca  83410cff             add dword ptr [ecx + 0xc], -1
// 0071c2ce  894110               mov dword ptr [ecx + 0x10], eax
// 0071c2d1  7505                 jne 0x71c2d8
// 0071c2d3  e8586ef8ff           call 0x6a3130
// 0071c2d8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
