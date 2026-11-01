// from server: 100% by auto
// roc 2011-06 004035c0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004035c0
//
// 004035c0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004035c4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004035c8  8b542408             mov edx, dword ptr [esp + 8]
// 004035cc  50                   push eax
// 004035cd  8b442408             mov eax, dword ptr [esp + 8]
// 004035d1  51                   push ecx
// 004035d2  52                   push edx
// 004035d3  50                   push eax
// 004035d4  ff153c0aa400         call dword ptr [0xa40a3c]
// 004035da  50                   push eax
// 004035db  e830feffff           call 0x403410
// 004035e0  83c414               add esp, 0x14
// 004035e3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?memcpy_s@Checked@ATL@@YAXPAXIPBXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarCaptionBarControl.cpp
