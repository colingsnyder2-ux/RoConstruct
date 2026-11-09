// from server: 100% by auto
// roc 2009-06 0080ff20  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080ff20
//
// 0080ff20  8b442404             mov eax, dword ptr [esp + 4]
// 0080ff24  8b5108               mov edx, dword ptr [ecx + 8]
// 0080ff27  50                   push eax
// 0080ff28  52                   push edx
// 0080ff29  e8f227f4ff           call 0x752720
// 0080ff2e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp1.cpp
