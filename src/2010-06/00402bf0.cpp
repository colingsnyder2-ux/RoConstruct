// from server: 100% by auto
// roc 2010-06 00402bf0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402bf0
//
// 00402bf0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00402bf4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402bf8  8b542408             mov edx, dword ptr [esp + 8]
// 00402bfc  50                   push eax
// 00402bfd  8b442408             mov eax, dword ptr [esp + 8]
// 00402c01  51                   push ecx
// 00402c02  52                   push edx
// 00402c03  50                   push eax
// 00402c04  ff15c4a89e00         call dword ptr [0x9ea8c4]
// 00402c0a  50                   push eax
// 00402c0b  e830feffff           call 0x402a40
// 00402c10  83c414               add esp, 0x14
// 00402c13  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarDayViewDay.cpp (function ?memcpy_s@Checked@ATL@@YAXPAXIPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarDayViewDay.cpp
