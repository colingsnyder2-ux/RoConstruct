// from server: 100% by auto
// roc 2009-06 00401040  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401040
//
// 00401040  8b01                 mov eax, dword ptr [ecx]
// 00401042  50                   push eax
// 00401043  ff154ce38900         call dword ptr [0x89e34c]
// 00401049  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
