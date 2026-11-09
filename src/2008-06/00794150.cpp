// from server: 100% by auto
// roc 2008-06 00794150  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00794150
//
// 00794150  8b442404             mov eax, dword ptr [esp + 4]
// 00794154  8b5108               mov edx, dword ptr [ecx + 8]
// 00794157  50                   push eax
// 00794158  52                   push edx
// 00794159  e8c2a1f7ff           call 0x70e320
// 0079415e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp1.cpp
