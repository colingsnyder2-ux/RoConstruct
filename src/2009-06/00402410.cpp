// from server: 100% by auto
// roc 2009-06 00402410  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402410
//
// 00402410  8b01                 mov eax, dword ptr [ecx]
// 00402412  50                   push eax
// 00402413  ff153cea8900         call dword ptr [0x89ea3c]
// 00402419  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
