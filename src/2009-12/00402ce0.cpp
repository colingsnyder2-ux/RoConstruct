// from server: 100% by auto
// roc 2009-12 00402ce0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402ce0
//
// 00402ce0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402ce4  8b542408             mov edx, dword ptr [esp + 8]
// 00402ce8  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00402ceb  50                   push eax
// 00402cec  8b442408             mov eax, dword ptr [esp + 8]
// 00402cf0  52                   push edx
// 00402cf1  50                   push eax
// 00402cf2  51                   push ecx
// 00402cf3  ff15b8cb9800         call dword ptr [0x98cbb8]
// 00402cf9  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?PostMessageA@CWnd@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
