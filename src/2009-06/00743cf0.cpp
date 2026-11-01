// from server: 100% by auto
// roc 2009-06 00743cf0  unit: CXTPReportControl  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743cf0
//
// 00743cf0  57                   push edi
// 00743cf1  8bf9                 mov edi, ecx
// 00743cf3  837f0400             cmp dword ptr [edi + 4], 0
// 00743cf7  c7075c4a8f00         mov dword ptr [edi], 0x8f4a5c
// 00743cfd  742a                 je 0x743d29
// 00743cff  56                   push esi
// 00743d00  33f6                 xor esi, esi
// 00743d02  397708               cmp dword ptr [edi + 8], esi
// 00743d05  7e15                 jle 0x743d1c
// 00743d07  8b4704               mov eax, dword ptr [edi + 4]
// 00743d0a  8b14f0               mov edx, dword ptr [eax + esi*8]
// 00743d0d  8d0cf0               lea ecx, [eax + esi*8]
// 00743d10  8b02                 mov eax, dword ptr [edx]
// 00743d12  6a00                 push 0
// 00743d14  ffd0                 call eax
// 00743d16  46                   inc esi
// 00743d17  3b7708               cmp esi, dword ptr [edi + 8]
// 00743d1a  7ceb                 jl 0x743d07
// 00743d1c  8b4f04               mov ecx, dword ptr [edi + 4]
// 00743d1f  51                   push ecx
// 00743d20  e8b94ffdff           call 0x718cde
// 00743d25  83c404               add esp, 4
// 00743d28  5e                   pop esi
// 00743d29  5f                   pop edi
// 00743d2a  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??1?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
