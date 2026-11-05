// from server: 100% by auto
// roc 2011-06 00402390  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00402390
//
// 00402390  8b01                 mov eax, dword ptr [ecx]
// 00402392  50                   push eax
// 00402393  ff15000ba400         call dword ptr [0xa40b00]
// 00402399  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
