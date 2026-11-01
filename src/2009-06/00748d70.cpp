// from server: 100% by auto
// roc 2009-06 00748d70  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748d70
//
// 00748d70  56                   push esi
// 00748d71  57                   push edi
// 00748d72  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00748d76  8bf1                 mov esi, ecx
// 00748d78  85ff                 test edi, edi
// 00748d7a  7d05                 jge 0x748d81
// 00748d7c  e863fffcff           call 0x718ce4
// 00748d81  3b7e08               cmp edi, dword ptr [esi + 8]
// 00748d84  7c0b                 jl 0x748d91
// 00748d86  6aff                 push -1
// 00748d88  8d4701               lea eax, [edi + 1]
// 00748d8b  50                   push eax
// 00748d8c  e83fefffff           call 0x747cd0
// 00748d91  8b4e04               mov ecx, dword ptr [esi + 4]
// 00748d94  8b542410             mov edx, dword ptr [esp + 0x10]
// 00748d98  8b4204               mov eax, dword ptr [edx + 4]
// 00748d9b  8b74f904             mov esi, dword ptr [ecx + edi*8 + 4]
// 00748d9f  8d0cf9               lea ecx, [ecx + edi*8]
// 00748da2  894104               mov dword ptr [ecx + 4], eax
// 00748da5  85c0                 test eax, eax
// 00748da7  740a                 je 0x748db3
// 00748da9  83c004               add eax, 4
// 00748dac  50                   push eax
// 00748dad  ff15d0e18900         call dword ptr [0x89e1d0]
// 00748db3  85f6                 test esi, esi
// 00748db5  7407                 je 0x748dbe
// 00748db7  8bce                 mov ecx, esi
// 00748db9  e8ea01fdff           call 0x718fa8
// 00748dbe  5f                   pop edi
// 00748dbf  5e                   pop esi
// 00748dc0  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?SetAtGrow@?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@QAEXHAAV?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
