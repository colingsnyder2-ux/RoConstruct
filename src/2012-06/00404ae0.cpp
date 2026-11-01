// from server: 100% by auto
// roc 2012-06 00404ae0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404ae0
//
// 00404ae0  8b442404             mov eax, dword ptr [esp + 4]
// 00404ae4  56                   push esi
// 00404ae5  50                   push eax
// 00404ae6  8bf1                 mov esi, ecx
// 00404ae8  ff15f829b200         call dword ptr [0xb229f8]
// 00404aee  83c404               add esp, 4
// 00404af1  85c0                 test eax, eax
// 00404af3  750a                 jne 0x404aff
// 00404af5  680e000780           push 0x8007000e
// 00404afa  e8b1f6ffff           call 0x4041b0
// 00404aff  8906                 mov dword ptr [esi], eax
// 00404b01  5e                   pop esi
// 00404b02  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?AllocateHeap@?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@AAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarThemeOffice2007.cpp
