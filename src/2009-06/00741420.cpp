// from server: 100% by auto
// roc 2009-06 00741420  unit: CXTPReportRecordItemEditOptions  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00741420
//
// 00741420  833d601aa50000       cmp dword ptr [0xa51a60], 0
// 00741427  b800040000           mov eax, 0x400
// 0074142c  7411                 je 0x74143f
// 0074142e  e80d9d0500           call 0x79b140
// 00741433  8b10                 mov edx, dword ptr [eax]
// 00741435  8bc8                 mov ecx, eax
// 00741437  8b4238               mov eax, dword ptr [edx + 0x38]
// 0074143a  ffd0                 call eax
// 0074143c  0fb7c0               movzx eax, ax
// 0074143f  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?GetActiveLCID@CXTPCalendarUtils@@SAKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarUtils.cpp
