// from server: 100% by auto
// roc 2009-06 00403010  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403010
//
// 00403010  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403014  8b542408             mov edx, dword ptr [esp + 8]
// 00403018  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040301b  50                   push eax
// 0040301c  8b442408             mov eax, dword ptr [esp + 8]
// 00403020  52                   push edx
// 00403021  50                   push eax
// 00403022  51                   push ecx
// 00403023  ff159cee8900         call dword ptr [0x89ee9c]
// 00403029  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
