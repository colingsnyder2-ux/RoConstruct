// from server: 100% by auto
// roc 2007-03 0070f030  unit: seg_00700000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070f030
//
// 0070f030  8b442404             mov eax, dword ptr [esp + 4]
// 0070f034  8b5108               mov edx, dword ptr [ecx + 8]
// 0070f037  50                   push eax
// 0070f038  52                   push edx
// 0070f039  e862caf1ff           call 0x62baa0
// 0070f03e  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\oledisp1.cpp (function ?AddPair@CVariantBoolConverter@@QAEXABVCVariantBoolPair@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oledisp1.cpp
