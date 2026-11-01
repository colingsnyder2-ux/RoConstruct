// from server: 100% by auto
// roc 2011-06 00856ca0  unit: CXTPControls  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00856ca0
//
// 00856ca0  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 00856ca4  8b442404             mov eax, dword ptr [esp + 4]
// 00856ca8  894120               mov dword ptr [ecx + 0x20], eax
// 00856cab  7e07                 jle 0x856cb4
// 00856cad  8b11                 mov edx, dword ptr [ecx]
// 00856caf  8b4274               mov eax, dword ptr [edx + 0x74]
// 00856cb2  ffd0                 call eax
// 00856cb4  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?SetParent@CXTPControls@@QAEXPAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
