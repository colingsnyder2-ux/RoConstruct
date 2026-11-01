// from server: 100% by auto
// roc 2007-03 006be110  unit: seg_006b0000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006be110
//
// 006be110  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006be114  8b542410             mov edx, dword ptr [esp + 0x10]
// 006be118  56                   push esi
// 006be119  8b742408             mov esi, dword ptr [esp + 8]
// 006be11d  57                   push edi
// 006be11e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006be122  897154               mov dword ptr [ecx + 0x54], esi
// 006be125  897958               mov dword ptr [ecx + 0x58], edi
// 006be128  89415c               mov dword ptr [ecx + 0x5c], eax
// 006be12b  6a01                 push 1
// 006be12d  895160               mov dword ptr [ecx + 0x60], edx
// 006be130  2bd7                 sub edx, edi
// 006be132  52                   push edx
// 006be133  2bc6                 sub eax, esi
// 006be135  50                   push eax
// 006be136  57                   push edi
// 006be137  56                   push esi
// 006be138  e87f03f6ff           call 0x61e4bc
// 006be13d  5f                   pop edi
// 006be13e  5e                   pop esi
// 006be13f  c21000               ret 0x10
// library xtp-15.2.1/Source\Calendar\XTPCalendarControl.cpp (function ?SetHoverRect@CXTPCalendarTip@@QAEXVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControl.cpp
