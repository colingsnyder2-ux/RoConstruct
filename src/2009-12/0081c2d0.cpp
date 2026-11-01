// from server: 100% by auto
// roc 2009-12 0081c2d0  unit: CXTPReportRecordItemEditOptions  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081c2d0
//
// 0081c2d0  833dbcaeb90000       cmp dword ptr [0xb9aebc], 0
// 0081c2d7  b800040000           mov eax, 0x400
// 0081c2dc  7411                 je 0x81c2ef
// 0081c2de  e8bd250500           call 0x86e8a0
// 0081c2e3  8b10                 mov edx, dword ptr [eax]
// 0081c2e5  8bc8                 mov ecx, eax
// 0081c2e7  8b4238               mov eax, dword ptr [edx + 0x38]
// 0081c2ea  ffd0                 call eax
// 0081c2ec  0fb7c0               movzx eax, ax
// 0081c2ef  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?GetActiveLCID@CXTPCalendarUtils@@SAKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarUtils.cpp
