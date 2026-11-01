// from server: 100% by auto
// roc 2009-12 0081ebb0  unit: CXTPReportControl  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081ebb0
//
// 0081ebb0  57                   push edi
// 0081ebb1  8bf9                 mov edi, ecx
// 0081ebb3  837f0400             cmp dword ptr [edi + 4], 0
// 0081ebb7  c707044f9f00         mov dword ptr [edi], 0x9f4f04
// 0081ebbd  742a                 je 0x81ebe9
// 0081ebbf  56                   push esi
// 0081ebc0  33f6                 xor esi, esi
// 0081ebc2  397708               cmp dword ptr [edi + 8], esi
// 0081ebc5  7e15                 jle 0x81ebdc
// 0081ebc7  8b4704               mov eax, dword ptr [edi + 4]
// 0081ebca  8b14f0               mov edx, dword ptr [eax + esi*8]
// 0081ebcd  8d0cf0               lea ecx, [eax + esi*8]
// 0081ebd0  8b02                 mov eax, dword ptr [edx]
// 0081ebd2  6a00                 push 0
// 0081ebd4  ffd0                 call eax
// 0081ebd6  46                   inc esi
// 0081ebd7  3b7708               cmp esi, dword ptr [edi + 8]
// 0081ebda  7ceb                 jl 0x81ebc7
// 0081ebdc  8b4f04               mov ecx, dword ptr [edi + 4]
// 0081ebdf  51                   push ecx
// 0081ebe0  e8214ffdff           call 0x7f3b06
// 0081ebe5  83c404               add esp, 4
// 0081ebe8  5e                   pop esi
// 0081ebe9  5f                   pop edi
// 0081ebea  c3                   ret 
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??1?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
