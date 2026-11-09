// from server: 100% by auto
// roc 2009-06 004e3120  unit: RBX::Network::VClient::?$FactoryProduct  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e3120
//
// 004e3120  8b01                 mov eax, dword ptr [ecx]
// 004e3122  50                   push eax
// 004e3123  ff15ace18900         call dword ptr [0x89e1ac]
// 004e3129  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
