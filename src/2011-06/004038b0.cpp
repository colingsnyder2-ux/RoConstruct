// from server: 100% by auto
// roc 2011-06 004038b0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004038b0
//
// 004038b0  51                   push ecx
// 004038b1  8b542408             mov edx, dword ptr [esp + 8]
// 004038b5  56                   push esi
// 004038b6  57                   push edi
// 004038b7  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004038bb  8d442408             lea eax, [esp + 8]
// 004038bf  50                   push eax
// 004038c0  57                   push edi
// 004038c1  8bf1                 mov esi, ecx
// 004038c3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004038c7  6a00                 push 0
// 004038c9  51                   push ecx
// 004038ca  52                   push edx
// 004038cb  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004038d3  ff154000a400         call dword ptr [0xa40040]
// 004038d9  85c0                 test eax, eax
// 004038db  7522                 jne 0x4038ff
// 004038dd  8b0e                 mov ecx, dword ptr [esi]
// 004038df  85c9                 test ecx, ecx
// 004038e1  740d                 je 0x4038f0
// 004038e3  51                   push ecx
// 004038e4  ff150400a400         call dword ptr [0xa40004]
// 004038ea  c70600000000         mov dword ptr [esi], 0
// 004038f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004038f4  81e700030000         and edi, 0x300
// 004038fa  890e                 mov dword ptr [esi], ecx
// 004038fc  897e04               mov dword ptr [esi + 4], edi
// 004038ff  5f                   pop edi
// 00403900  5e                   pop esi
// 00403901  59                   pop ecx
// 00403902  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
