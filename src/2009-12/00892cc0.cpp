// from server: 100% by auto
// roc 2009-12 00892cc0  unit: CXTPMenuBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00892cc0
//
// 00892cc0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00892cc3  8b442404             mov eax, dword ptr [esp + 4]
// 00892cc7  895008               mov dword ptr [eax + 8], edx
// 00892cca  83410cff             add dword ptr [ecx + 0xc], -1
// 00892cce  894110               mov dword ptr [ecx + 0x10], eax
// 00892cd1  7505                 jne 0x892cd8
// 00892cd3  e84838f6ff           call 0x7f6520
// 00892cd8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxcommandmanager.cpp (function ?FreeAssoc@?$CMap@IIHH@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcommandmanager.cpp
