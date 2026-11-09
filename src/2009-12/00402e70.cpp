// from server: 100% by auto
// roc 2009-12 00402e70  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402e70
//
// 00402e70  51                   push ecx
// 00402e71  8b542408             mov edx, dword ptr [esp + 8]
// 00402e75  56                   push esi
// 00402e76  57                   push edi
// 00402e77  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00402e7b  8d442408             lea eax, [esp + 8]
// 00402e7f  50                   push eax
// 00402e80  57                   push edi
// 00402e81  8bf1                 mov esi, ecx
// 00402e83  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00402e87  6a00                 push 0
// 00402e89  51                   push ecx
// 00402e8a  52                   push edx
// 00402e8b  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00402e93  ff1510b09800         call dword ptr [0x98b010]
// 00402e99  85c0                 test eax, eax
// 00402e9b  7522                 jne 0x402ebf
// 00402e9d  8b0e                 mov ecx, dword ptr [esi]
// 00402e9f  85c9                 test ecx, ecx
// 00402ea1  740d                 je 0x402eb0
// 00402ea3  51                   push ecx
// 00402ea4  ff1508b09800         call dword ptr [0x98b008]
// 00402eaa  c70600000000         mov dword ptr [esi], 0
// 00402eb0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00402eb4  81e700030000         and edi, 0x300
// 00402eba  890e                 mov dword ptr [esi], ecx
// 00402ebc  897e04               mov dword ptr [esi + 4], edi
// 00402ebf  5f                   pop edi
// 00402ec0  5e                   pop esi
// 00402ec1  59                   pop ecx
// 00402ec2  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
