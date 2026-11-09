// from server: 100% by auto
// roc 2009-06 00427140  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427140
//
// 00427140  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00427144  8b542408             mov edx, dword ptr [esp + 8]
// 00427148  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0042714b  50                   push eax
// 0042714c  8b442408             mov eax, dword ptr [esp + 8]
// 00427150  52                   push edx
// 00427151  50                   push eax
// 00427152  51                   push ecx
// 00427153  ff1590ee8900         call dword ptr [0x89ee90]
// 00427159  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
