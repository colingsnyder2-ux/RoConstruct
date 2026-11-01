// from server: 100% by auto
// roc 2009-12 00443100  unit: RBX::MergeBinder  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00443100
//
// 00443100  8b01                 mov eax, dword ptr [ecx]
// 00443102  8b4010               mov eax, dword ptr [eax + 0x10]
// 00443105  ffe0                 jmp eax
// library mfc-8.0/atlmfc\src\mfc\except.cpp (function ?GetErrorMessage@CException@@UAEHPADIPAI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/except.cpp
