// from server: 100% by auto
// roc 2009-12 008a42c0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a42c0
//
// 008a42c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008a42c4  8b542410             mov edx, dword ptr [esp + 0x10]
// 008a42c8  56                   push esi
// 008a42c9  8b742408             mov esi, dword ptr [esp + 8]
// 008a42cd  57                   push edi
// 008a42ce  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008a42d2  897154               mov dword ptr [ecx + 0x54], esi
// 008a42d5  897958               mov dword ptr [ecx + 0x58], edi
// 008a42d8  89415c               mov dword ptr [ecx + 0x5c], eax
// 008a42db  6a01                 push 1
// 008a42dd  895160               mov dword ptr [ecx + 0x60], edx
// 008a42e0  2bd7                 sub edx, edi
// 008a42e2  52                   push edx
// 008a42e3  2bc6                 sub eax, esi
// 008a42e5  50                   push eax
// 008a42e6  57                   push edi
// 008a42e7  56                   push esi
// 008a42e8  e845f9f4ff           call 0x7f3c32
// 008a42ed  5f                   pop edi
// 008a42ee  5e                   pop esi
// 008a42ef  c21000               ret 0x10
// library xtp-15.2.1/Source\Calendar\XTPCalendarControl.cpp (function ?SetHoverRect@CXTPCalendarTip@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControl.cpp
