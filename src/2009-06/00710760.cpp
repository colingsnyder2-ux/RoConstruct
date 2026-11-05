// from server: 100% by auto
// roc 2009-06 00710760  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00710760
//
// 00710760  e87b83ffff           call 0x708ae0
// 00710765  33c0                 xor eax, eax
// 00710767  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlppg.cpp (function ?OnInitDialog@COlePropertyPage@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlppg.cpp
