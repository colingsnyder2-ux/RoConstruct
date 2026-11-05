// from server: 100% by auto
// roc 2010-06 00402d30  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402d30
//
// 00402d30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402d34  8b542408             mov edx, dword ptr [esp + 8]
// 00402d38  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00402d3b  50                   push eax
// 00402d3c  8b442408             mov eax, dword ptr [esp + 8]
// 00402d40  52                   push edx
// 00402d41  50                   push eax
// 00402d42  51                   push ecx
// 00402d43  ff1548ba9e00         call dword ptr [0x9eba48]
// 00402d49  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
