// from server: 100% by auto
// roc 2010-06 007d2c10  unit: CXTPReportControl  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d2c10
//
// 007d2c10  57                   push edi
// 007d2c11  8bf9                 mov edi, ecx
// 007d2c13  837f0400             cmp dword ptr [edi + 4], 0
// 007d2c17  c707f491a500         mov dword ptr [edi], 0xa591f4
// 007d2c1d  742a                 je 0x7d2c49
// 007d2c1f  56                   push esi
// 007d2c20  33f6                 xor esi, esi
// 007d2c22  397708               cmp dword ptr [edi + 8], esi
// 007d2c25  7e15                 jle 0x7d2c3c
// 007d2c27  8b4704               mov eax, dword ptr [edi + 4]
// 007d2c2a  8b14f0               mov edx, dword ptr [eax + esi*8]
// 007d2c2d  8d0cf0               lea ecx, [eax + esi*8]
// 007d2c30  8b02                 mov eax, dword ptr [edx]
// 007d2c32  6a00                 push 0
// 007d2c34  ffd0                 call eax
// 007d2c36  46                   inc esi
// 007d2c37  3b7708               cmp esi, dword ptr [edi + 8]
// 007d2c3a  7ceb                 jl 0x7d2c27
// 007d2c3c  8b4f04               mov ecx, dword ptr [edi + 4]
// 007d2c3f  51                   push ecx
// 007d2c40  e80150fdff           call 0x7a7c46
// 007d2c45  83c404               add esp, 4
// 007d2c48  5e                   pop esi
// 007d2c49  5f                   pop edi
// 007d2c4a  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??1?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
