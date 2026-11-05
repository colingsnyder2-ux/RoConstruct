// from server: 100% by auto
// roc 2009-06 004031a0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004031a0
//
// 004031a0  51                   push ecx
// 004031a1  8b542408             mov edx, dword ptr [esp + 8]
// 004031a5  56                   push esi
// 004031a6  57                   push edi
// 004031a7  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004031ab  8d442408             lea eax, [esp + 8]
// 004031af  50                   push eax
// 004031b0  57                   push edi
// 004031b1  8bf1                 mov esi, ecx
// 004031b3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004031b7  6a00                 push 0
// 004031b9  51                   push ecx
// 004031ba  52                   push edx
// 004031bb  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004031c3  ff1510e08900         call dword ptr [0x89e010]
// 004031c9  85c0                 test eax, eax
// 004031cb  7522                 jne 0x4031ef
// 004031cd  8b0e                 mov ecx, dword ptr [esi]
// 004031cf  85c9                 test ecx, ecx
// 004031d1  740d                 je 0x4031e0
// 004031d3  51                   push ecx
// 004031d4  ff1508e08900         call dword ptr [0x89e008]
// 004031da  c70600000000         mov dword ptr [esi], 0
// 004031e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004031e4  81e700030000         and edi, 0x300
// 004031ea  890e                 mov dword ptr [esi], ecx
// 004031ec  897e04               mov dword ptr [esi + 4], edi
// 004031ef  5f                   pop edi
// 004031f0  5e                   pop esi
// 004031f1  59                   pop ecx
// 004031f2  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
