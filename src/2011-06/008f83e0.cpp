// from server: 100% by auto
// roc 2011-06 008f83e0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f83e0
//
// 008f83e0  8b442404             mov eax, dword ptr [esp + 4]
// 008f83e4  8b5108               mov edx, dword ptr [ecx + 8]
// 008f83e7  50                   push eax
// 008f83e8  52                   push edx
// 008f83e9  e8a268f4ff           call 0x83ec90
// 008f83ee  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp1.cpp
