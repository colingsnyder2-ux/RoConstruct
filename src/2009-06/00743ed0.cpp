// from server: 100% by auto
// roc 2009-06 00743ed0  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743ed0
//
// 00743ed0  56                   push esi
// 00743ed1  8b742408             mov esi, dword ptr [esp + 8]
// 00743ed5  57                   push edi
// 00743ed6  8bf9                 mov edi, ecx
// 00743ed8  85f6                 test esi, esi
// 00743eda  7d05                 jge 0x743ee1
// 00743edc  e8034efdff           call 0x718ce4
// 00743ee1  3b7708               cmp esi, dword ptr [edi + 8]
// 00743ee4  7c0b                 jl 0x743ef1
// 00743ee6  6aff                 push -1
// 00743ee8  8d4601               lea eax, [esi + 1]
// 00743eeb  50                   push eax
// 00743eec  e87ffeffff           call 0x743d70
// 00743ef1  8b5704               mov edx, dword ptr [edi + 4]
// 00743ef4  8d0c76               lea ecx, [esi + esi*2]
// 00743ef7  8d048a               lea eax, [edx + ecx*4]
// 00743efa  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00743efe  8b11                 mov edx, dword ptr [ecx]
// 00743f00  8910                 mov dword ptr [eax], edx
// 00743f02  8b5104               mov edx, dword ptr [ecx + 4]
// 00743f05  895004               mov dword ptr [eax + 4], edx
// 00743f08  8b4908               mov ecx, dword ptr [ecx + 8]
// 00743f0b  5f                   pop edi
// 00743f0c  894808               mov dword ptr [eax + 8], ecx
// 00743f0f  5e                   pop esi
// 00743f10  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarRecurrencePattern.cpp (function ?SetAtGrow@?$CArray@VCOleDateTime@ATL@@AAV12@@@QAEXHAAVCOleDateTime@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarRecurrencePattern.cpp
