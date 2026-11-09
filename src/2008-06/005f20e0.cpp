// from server: 100% by auto
// roc 2008-06 005f20e0  unit: RBX::FaceInstance  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f20e0
//
// 005f20e0  8b01                 mov eax, dword ptr [ecx]
// 005f20e2  50                   push eax
// 005f20e3  ff156c2e8000         call dword ptr [0x802e6c]
// 005f20e9  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
