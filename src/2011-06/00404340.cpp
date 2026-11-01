// from server: 100% by auto
// roc 2011-06 00404340  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00404340
//
// 00404340  8b442404             mov eax, dword ptr [esp + 4]
// 00404344  56                   push esi
// 00404345  50                   push eax
// 00404346  8bf1                 mov esi, ecx
// 00404348  ff15400aa400         call dword ptr [0xa40a40]
// 0040434e  83c404               add esp, 4
// 00404351  85c0                 test eax, eax
// 00404353  750a                 jne 0x40435f
// 00404355  680e000780           push 0x8007000e
// 0040435a  e841f2ffff           call 0x4035a0
// 0040435f  8906                 mov dword ptr [esi], eax
// 00404361  5e                   pop esi
// 00404362  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarThemeOffice2007.cpp (function ?AllocateHeap@?$CTempBuffer@D$0IA@VCCRTAllocator@ATL@@@ATL@@AAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarThemeOffice2007.cpp
