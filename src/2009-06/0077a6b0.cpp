// from server: 100% by auto
// roc 2009-06 0077a6b0  unit: PAUHWND__::?$CArray  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a6b0
//
// 0077a6b0  56                   push esi
// 0077a6b1  57                   push edi
// 0077a6b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077a6b6  8bf1                 mov esi, ecx
// 0077a6b8  85ff                 test edi, edi
// 0077a6ba  7d05                 jge 0x77a6c1
// 0077a6bc  e823e6f9ff           call 0x718ce4
// 0077a6c1  3b7e08               cmp edi, dword ptr [esi + 8]
// 0077a6c4  7c0b                 jl 0x77a6d1
// 0077a6c6  6aff                 push -1
// 0077a6c8  8d4701               lea eax, [edi + 1]
// 0077a6cb  50                   push eax
// 0077a6cc  e83f7efdff           call 0x752510
// 0077a6d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0077a6d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0077a6d8  8b02                 mov eax, dword ptr [edx]
// 0077a6da  8904b9               mov dword ptr [ecx + edi*4], eax
// 0077a6dd  5f                   pop edi
// 0077a6de  5e                   pop esi
// 0077a6df  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarTheme.cpp (function ?SetAtGrow@?$CArray@PAVCXTPCalendarDayViewEvent@@AAPAV1@@@QAEXHAAPAVCXTPCalendarDayViewEvent@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarTheme.cpp
