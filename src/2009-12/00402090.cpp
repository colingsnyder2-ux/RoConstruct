// from server: 100% by auto
// roc 2009-12 00402090  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402090
//
// 00402090  8b01                 mov eax, dword ptr [ecx]
// 00402092  50                   push eax
// 00402093  ff1590ba9800         call dword ptr [0x98ba90]
// 00402099  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
