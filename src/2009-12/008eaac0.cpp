// from server: 100% by auto
// roc 2009-12 008eaac0  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eaac0
//
// 008eaac0  8b442404             mov eax, dword ptr [esp + 4]
// 008eaac4  8b5108               mov edx, dword ptr [ecx + 8]
// 008eaac7  50                   push eax
// 008eaac8  52                   push edx
// 008eaac9  e8a201f8ff           call 0x86ac70
// 008eaace  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledisp1.cpp
