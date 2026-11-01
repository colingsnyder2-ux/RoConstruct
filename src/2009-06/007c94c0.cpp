// from server: 100% by auto
// roc 2009-06 007c94c0  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c94c0
//
// 007c94c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c94c4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007c94c8  56                   push esi
// 007c94c9  8b742408             mov esi, dword ptr [esp + 8]
// 007c94cd  57                   push edi
// 007c94ce  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007c94d2  897154               mov dword ptr [ecx + 0x54], esi
// 007c94d5  897958               mov dword ptr [ecx + 0x58], edi
// 007c94d8  89415c               mov dword ptr [ecx + 0x5c], eax
// 007c94db  6a01                 push 1
// 007c94dd  895160               mov dword ptr [ecx + 0x60], edx
// 007c94e0  2bd7                 sub edx, edi
// 007c94e2  52                   push edx
// 007c94e3  2bc6                 sub eax, esi
// 007c94e5  50                   push eax
// 007c94e6  57                   push edi
// 007c94e7  56                   push esi
// 007c94e8  e81df9f4ff           call 0x718e0a
// 007c94ed  5f                   pop edi
// 007c94ee  5e                   pop esi
// 007c94ef  c21000               ret 0x10
// library xtp-15.2.1/Source\Calendar\XTPCalendarControl.cpp (function ?SetHoverRect@CXTPCalendarTip@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControl.cpp
