// from server: 100% by auto
// roc 2011-06 00403720  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403720
//
// 00403720  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403724  8b542408             mov edx, dword ptr [esp + 8]
// 00403728  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040372b  50                   push eax
// 0040372c  8b442408             mov eax, dword ptr [esp + 8]
// 00403730  52                   push edx
// 00403731  50                   push eax
// 00403732  51                   push ecx
// 00403733  ff15b419a400         call dword ptr [0xa419b4]
// 00403739  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
