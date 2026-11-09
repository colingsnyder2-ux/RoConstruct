// from server: 100% by auto
// roc 2010-06 0081a310  unit: CXTPPropertyGridItem  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081a310
//
// 0081a310  56                   push esi
// 0081a311  8bf1                 mov esi, ecx
// 0081a313  e8662a1600           call 0x97cd7e
// 0081a318  8d4e20               lea ecx, [esi + 0x20]
// 0081a31b  c706d42ca600         mov dword ptr [esi], 0xa62cd4
// 0081a321  e8fafaffff           call 0x819e20
// 0081a326  8bc6                 mov eax, esi
// 0081a328  5e                   pop esi
// 0081a329  c3                   ret 
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??0?$CXTPCalendarPtrCollectionT@VCXTPCalendarCaptionBarThemePart@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
