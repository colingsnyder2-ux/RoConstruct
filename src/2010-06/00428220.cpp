// from server: 100% by auto
// roc 2010-06 00428220  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00428220
//
// 00428220  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00428224  8b542408             mov edx, dword ptr [esp + 8]
// 00428228  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0042822b  50                   push eax
// 0042822c  8b442408             mov eax, dword ptr [esp + 8]
// 00428230  52                   push edx
// 00428231  50                   push eax
// 00428232  51                   push ecx
// 00428233  ff1554ba9e00         call dword ptr [0x9eba54]
// 00428239  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
