// from server: 100% by auto
// roc 2012-06 00a706f0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a706f0
//
// 00a706f0  8b442404             mov eax, dword ptr [esp + 4]
// 00a706f4  8b5108               mov edx, dword ptr [ecx + 8]
// 00a706f7  50                   push eax
// 00a706f8  52                   push edx
// 00a706f9  e8d2170000           call 0xa71ed0
// 00a706fe  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oledisp1.cpp
