// from server: 100% by auto
// roc 2010-06 0089f860  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089f860
//
// 0089f860  8b442404             mov eax, dword ptr [esp + 4]
// 0089f864  8b5108               mov edx, dword ptr [ecx + 8]
// 0089f867  50                   push eax
// 0089f868  52                   push edx
// 0089f869  e8421cf4ff           call 0x7e14b0
// 0089f86e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp1.cpp
