// from server: 100% by auto
// roc 2007-08 0042e9d0  unit: VCLuaFunction::?$CComObject  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042e9d0
//
// 0042e9d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042e9d4  8b542408             mov edx, dword ptr [esp + 8]
// 0042e9d8  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0042e9db  50                   push eax
// 0042e9dc  8b442408             mov eax, dword ptr [esp + 8]
// 0042e9e0  52                   push edx
// 0042e9e1  50                   push eax
// 0042e9e2  51                   push ecx
// 0042e9e3  ff15d8ec7700         call dword ptr [0x77ecd8]
// 0042e9e9  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?PostMessageA@CWnd@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
