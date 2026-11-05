// from server: 100% by auto
// roc 2010-06 00402ec0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402ec0
//
// 00402ec0  51                   push ecx
// 00402ec1  8b542408             mov edx, dword ptr [esp + 8]
// 00402ec5  56                   push esi
// 00402ec6  57                   push edi
// 00402ec7  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00402ecb  8d442408             lea eax, [esp + 8]
// 00402ecf  50                   push eax
// 00402ed0  57                   push edi
// 00402ed1  8bf1                 mov esi, ecx
// 00402ed3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00402ed7  6a00                 push 0
// 00402ed9  51                   push ecx
// 00402eda  52                   push edx
// 00402edb  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00402ee3  ff1518a09e00         call dword ptr [0x9ea018]
// 00402ee9  85c0                 test eax, eax
// 00402eeb  7522                 jne 0x402f0f
// 00402eed  8b0e                 mov ecx, dword ptr [esi]
// 00402eef  85c9                 test ecx, ecx
// 00402ef1  740d                 je 0x402f00
// 00402ef3  51                   push ecx
// 00402ef4  ff1510a09e00         call dword ptr [0x9ea010]
// 00402efa  c70600000000         mov dword ptr [esi], 0
// 00402f00  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00402f04  81e700030000         and edi, 0x300
// 00402f0a  890e                 mov dword ptr [esi], ecx
// 00402f0c  897e04               mov dword ptr [esi + 4], edi
// 00402f0f  5f                   pop edi
// 00402f10  5e                   pop esi
// 00402f11  59                   pop ecx
// 00402f12  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
