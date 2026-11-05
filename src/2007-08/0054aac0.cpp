// from server: 100% by auto
// roc 2007-08 0054aac0  unit: RBX::ServiceProvider  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054aac0
//
// 0054aac0  8b01                 mov eax, dword ptr [ecx]
// 0054aac2  50                   push eax
// 0054aac3  ff1508ef7700         call dword ptr [0x77ef08]
// 0054aac9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
