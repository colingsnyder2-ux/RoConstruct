// from server: 100% by auto
// roc 2008-06 0042e3e0  unit: VCLuaFunction::?$CComObject  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042e3e0
//
// 0042e3e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042e3e4  8b542408             mov edx, dword ptr [esp + 8]
// 0042e3e8  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0042e3eb  50                   push eax
// 0042e3ec  8b442408             mov eax, dword ptr [esp + 8]
// 0042e3f0  52                   push edx
// 0042e3f1  50                   push eax
// 0042e3f2  51                   push ecx
// 0042e3f3  ff15142e8000         call dword ptr [0x802e14]
// 0042e3f9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
