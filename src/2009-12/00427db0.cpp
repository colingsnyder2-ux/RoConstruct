// from server: 100% by auto
// roc 2009-12 00427db0  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00427db0
//
// 00427db0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00427db4  8b542408             mov edx, dword ptr [esp + 8]
// 00427db8  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00427dbb  50                   push eax
// 00427dbc  8b442408             mov eax, dword ptr [esp + 8]
// 00427dc0  52                   push edx
// 00427dc1  50                   push eax
// 00427dc2  51                   push ecx
// 00427dc3  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00427dc9  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?PostMessageA@CWnd@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
