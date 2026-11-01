// from server: 100% by auto
// roc 2009-12 0081ed90  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081ed90
//
// 0081ed90  56                   push esi
// 0081ed91  8b742408             mov esi, dword ptr [esp + 8]
// 0081ed95  57                   push edi
// 0081ed96  8bf9                 mov edi, ecx
// 0081ed98  85f6                 test esi, esi
// 0081ed9a  7d05                 jge 0x81eda1
// 0081ed9c  e86b4dfdff           call 0x7f3b0c
// 0081eda1  3b7708               cmp esi, dword ptr [edi + 8]
// 0081eda4  7c0b                 jl 0x81edb1
// 0081eda6  6aff                 push -1
// 0081eda8  8d4601               lea eax, [esi + 1]
// 0081edab  50                   push eax
// 0081edac  e87ffeffff           call 0x81ec30
// 0081edb1  8b5704               mov edx, dword ptr [edi + 4]
// 0081edb4  8d0c76               lea ecx, [esi + esi*2]
// 0081edb7  8d048a               lea eax, [edx + ecx*4]
// 0081edba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0081edbe  8b11                 mov edx, dword ptr [ecx]
// 0081edc0  8910                 mov dword ptr [eax], edx
// 0081edc2  8b5104               mov edx, dword ptr [ecx + 4]
// 0081edc5  895004               mov dword ptr [eax + 4], edx
// 0081edc8  8b4908               mov ecx, dword ptr [ecx + 8]
// 0081edcb  5f                   pop edi
// 0081edcc  894808               mov dword ptr [eax + 8], ecx
// 0081edcf  5e                   pop esi
// 0081edd0  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarRecurrencePattern.cpp (function ?SetAtGrow@?$CArray@VCOleDateTime@ATL@@AAV12@@@QAEXHAAVCOleDateTime@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarRecurrencePattern.cpp
