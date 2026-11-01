// from server: 100% by auto
// roc 2012-06 004041d0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004041d0
//
// 004041d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004041d4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004041d8  8b542408             mov edx, dword ptr [esp + 8]
// 004041dc  50                   push eax
// 004041dd  8b442408             mov eax, dword ptr [esp + 8]
// 004041e1  51                   push ecx
// 004041e2  52                   push edx
// 004041e3  50                   push eax
// 004041e4  ff15fc29b200         call dword ptr [0xb229fc]
// 004041ea  50                   push eax
// 004041eb  e830feffff           call 0x404020
// 004041f0  83c414               add esp, 0x14
// 004041f3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?memcpy_s@Checked@ATL@@YAXPAXIPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarCaptionBarControl.cpp
