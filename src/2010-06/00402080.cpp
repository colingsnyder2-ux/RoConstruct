// from server: 100% by auto
// roc 2010-06 00402080  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402080
//
// 00402080  8b01                 mov eax, dword ptr [ecx]
// 00402082  50                   push eax
// 00402083  ff1540aa9e00         call dword ptr [0x9eaa40]
// 00402089  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
