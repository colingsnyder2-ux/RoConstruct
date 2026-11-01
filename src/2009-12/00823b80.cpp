// from server: 100% by auto
// roc 2009-12 00823b80  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823b80
//
// 00823b80  56                   push esi
// 00823b81  57                   push edi
// 00823b82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00823b86  8bf1                 mov esi, ecx
// 00823b88  85ff                 test edi, edi
// 00823b8a  7d05                 jge 0x823b91
// 00823b8c  e87bfffcff           call 0x7f3b0c
// 00823b91  3b7e08               cmp edi, dword ptr [esi + 8]
// 00823b94  7c0b                 jl 0x823ba1
// 00823b96  6aff                 push -1
// 00823b98  8d4701               lea eax, [edi + 1]
// 00823b9b  50                   push eax
// 00823b9c  e88fefffff           call 0x822b30
// 00823ba1  8b4e04               mov ecx, dword ptr [esi + 4]
// 00823ba4  8b542410             mov edx, dword ptr [esp + 0x10]
// 00823ba8  8b4204               mov eax, dword ptr [edx + 4]
// 00823bab  8b74f904             mov esi, dword ptr [ecx + edi*8 + 4]
// 00823baf  8d0cf9               lea ecx, [ecx + edi*8]
// 00823bb2  894104               mov dword ptr [ecx + 4], eax
// 00823bb5  85c0                 test eax, eax
// 00823bb7  740a                 je 0x823bc3
// 00823bb9  83c004               add eax, 4
// 00823bbc  50                   push eax
// 00823bbd  ff150cb29800         call dword ptr [0x98b20c]
// 00823bc3  85f6                 test esi, esi
// 00823bc5  7407                 je 0x823bce
// 00823bc7  8bce                 mov ecx, esi
// 00823bc9  e80e02fdff           call 0x7f3ddc
// 00823bce  5f                   pop edi
// 00823bcf  5e                   pop esi
// 00823bd0  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?SetAtGrow@?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@QAEXHAAV?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
