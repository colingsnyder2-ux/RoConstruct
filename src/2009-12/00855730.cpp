// from server: 100% by auto
// roc 2009-12 00855730  unit: PAUHWND__::?$CArray  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00855730
//
// 00855730  56                   push esi
// 00855731  57                   push edi
// 00855732  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00855736  8bf1                 mov esi, ecx
// 00855738  85ff                 test edi, edi
// 0085573a  7d05                 jge 0x855741
// 0085573c  e8cbe3f9ff           call 0x7f3b0c
// 00855741  3b7e08               cmp edi, dword ptr [esi + 8]
// 00855744  7c0b                 jl 0x855751
// 00855746  6aff                 push -1
// 00855748  8d4701               lea eax, [edi + 1]
// 0085574b  50                   push eax
// 0085574c  e84ffcffff           call 0x8553a0
// 00855751  8b542410             mov edx, dword ptr [esp + 0x10]
// 00855755  8b4e04               mov ecx, dword ptr [esi + 4]
// 00855758  8b02                 mov eax, dword ptr [edx]
// 0085575a  8904b9               mov dword ptr [ecx + edi*4], eax
// 0085575d  5f                   pop edi
// 0085575e  5e                   pop esi
// 0085575f  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarTheme.cpp (function ?SetAtGrow@?$CArray@PAVCXTPCalendarDayViewEvent@@AAPAV1@@@QAEXHAAPAVCXTPCalendarDayViewEvent@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarTheme.cpp
