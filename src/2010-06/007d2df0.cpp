// from server: 100% by auto
// roc 2010-06 007d2df0  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d2df0
//
// 007d2df0  56                   push esi
// 007d2df1  8b742408             mov esi, dword ptr [esp + 8]
// 007d2df5  57                   push edi
// 007d2df6  8bf9                 mov edi, ecx
// 007d2df8  85f6                 test esi, esi
// 007d2dfa  7d05                 jge 0x7d2e01
// 007d2dfc  e84b4efdff           call 0x7a7c4c
// 007d2e01  3b7708               cmp esi, dword ptr [edi + 8]
// 007d2e04  7c0b                 jl 0x7d2e11
// 007d2e06  6aff                 push -1
// 007d2e08  8d4601               lea eax, [esi + 1]
// 007d2e0b  50                   push eax
// 007d2e0c  e87ffeffff           call 0x7d2c90
// 007d2e11  8b5704               mov edx, dword ptr [edi + 4]
// 007d2e14  8d0c76               lea ecx, [esi + esi*2]
// 007d2e17  8d048a               lea eax, [edx + ecx*4]
// 007d2e1a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007d2e1e  8b11                 mov edx, dword ptr [ecx]
// 007d2e20  8910                 mov dword ptr [eax], edx
// 007d2e22  8b5104               mov edx, dword ptr [ecx + 4]
// 007d2e25  895004               mov dword ptr [eax + 4], edx
// 007d2e28  8b4908               mov ecx, dword ptr [ecx + 8]
// 007d2e2b  5f                   pop edi
// 007d2e2c  894808               mov dword ptr [eax + 8], ecx
// 007d2e2f  5e                   pop esi
// 007d2e30  c20800               ret 8
// library xtp-13.2.1/Source\Calendar\XTPCalendarRecurrencePattern.cpp (function ?SetAtGrow@?$CArray@VCOleDateTime@ATL@@AAV12@@@QAEXHAAVCOleDateTime@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarRecurrencePattern.cpp
