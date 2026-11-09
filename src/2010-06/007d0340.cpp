// from server: 100% by auto
// roc 2010-06 007d0340  unit: CXTPReportRecordItemEditOptions  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d0340
//
// 007d0340  833dec55c20000       cmp dword ptr [0xc255ec], 0
// 007d0347  b800040000           mov eax, 0x400
// 007d034c  7411                 je 0x7d035f
// 007d034e  e85d250500           call 0x8228b0
// 007d0353  8b10                 mov edx, dword ptr [eax]
// 007d0355  8bc8                 mov ecx, eax
// 007d0357  8b4238               mov eax, dword ptr [edx + 0x38]
// 007d035a  ffd0                 call eax
// 007d035c  0fb7c0               movzx eax, ax
// 007d035f  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarUtils.cpp (function ?GetActiveLCID@CXTPCalendarUtils@@SAKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarUtils.cpp
