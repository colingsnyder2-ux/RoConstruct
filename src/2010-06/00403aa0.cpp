// from server: 100% by auto
// roc 2010-06 00403aa0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403aa0
//
// 00403aa0  8b442404             mov eax, dword ptr [esp + 4]
// 00403aa4  56                   push esi
// 00403aa5  50                   push eax
// 00403aa6  8bf1                 mov esi, ecx
// 00403aa8  ff15c8a89e00         call dword ptr [0x9ea8c8]
// 00403aae  83c404               add esp, 4
// 00403ab1  85c0                 test eax, eax
// 00403ab3  750a                 jne 0x403abf
// 00403ab5  680e000780           push 0x8007000e
// 00403aba  e811f1ffff           call 0x402bd0
// 00403abf  8906                 mov dword ptr [esi], eax
// 00403ac1  5e                   pop esi
// 00403ac2  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?AllocateHeap@?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@AAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarThemeOffice2007.cpp
