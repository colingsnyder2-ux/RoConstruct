// from server: 100% by auto
// roc 2010-06 00858400  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00858400
//
// 00858400  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00858404  8b542410             mov edx, dword ptr [esp + 0x10]
// 00858408  56                   push esi
// 00858409  8b742408             mov esi, dword ptr [esp + 8]
// 0085840d  57                   push edi
// 0085840e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00858412  897154               mov dword ptr [ecx + 0x54], esi
// 00858415  897958               mov dword ptr [ecx + 0x58], edi
// 00858418  89415c               mov dword ptr [ecx + 0x5c], eax
// 0085841b  6a01                 push 1
// 0085841d  895160               mov dword ptr [ecx + 0x60], edx
// 00858420  2bd7                 sub edx, edi
// 00858422  52                   push edx
// 00858423  2bc6                 sub eax, esi
// 00858425  50                   push eax
// 00858426  57                   push edi
// 00858427  56                   push esi
// 00858428  e845f9f4ff           call 0x7a7d72
// 0085842d  5f                   pop edi
// 0085842e  5e                   pop esi
// 0085842f  c21000               ret 0x10
// library xtp-13.2.1/Source\Calendar\XTPCalendarControl.cpp (function ?SetHoverRect@CXTPCalendarTip@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarControl.cpp
