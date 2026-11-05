// from server: 100% by auto
// roc 2007-08 00716640  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00716640
//
// 00716640  8b442404             mov eax, dword ptr [esp + 4]
// 00716644  8b5108               mov edx, dword ptr [ecx + 8]
// 00716647  50                   push eax
// 00716648  52                   push edx
// 00716649  e8c2c2fbff           call 0x6d2910
// 0071664e  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledisp1.cpp
