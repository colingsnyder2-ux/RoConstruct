// from server: 100% by auto
// roc 2009-12 00512730  unit: boost::detail::thread_data_base  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00512730
//
// 00512730  33c0                 xor eax, eax
// 00512732  3981e4000000         cmp dword ptr [ecx + 0xe4], eax
// 00512738  0f95c0               setne al
// 0051273b  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarDayView.cpp (function ?IsEditingSubject@CXTPCalendarView@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarDayView.cpp
