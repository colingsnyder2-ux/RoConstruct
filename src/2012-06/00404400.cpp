// from server: 100% by auto
// roc 2012-06 00404400  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404400
//
// 00404400  51                   push ecx
// 00404401  8b542408             mov edx, dword ptr [esp + 8]
// 00404405  56                   push esi
// 00404406  57                   push edi
// 00404407  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0040440b  8d442408             lea eax, [esp + 8]
// 0040440f  50                   push eax
// 00404410  57                   push edi
// 00404411  8bf1                 mov esi, ecx
// 00404413  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00404417  6a00                 push 0
// 00404419  51                   push ecx
// 0040441a  52                   push edx
// 0040441b  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00404423  ff150c20b200         call dword ptr [0xb2200c]
// 00404429  85c0                 test eax, eax
// 0040442b  7522                 jne 0x40444f
// 0040442d  8b0e                 mov ecx, dword ptr [esi]
// 0040442f  85c9                 test ecx, ecx
// 00404431  740d                 je 0x404440
// 00404433  51                   push ecx
// 00404434  ff150420b200         call dword ptr [0xb22004]
// 0040443a  c70600000000         mov dword ptr [esi], 0
// 00404440  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00404444  81e700030000         and edi, 0x300
// 0040444a  890e                 mov dword ptr [esi], ecx
// 0040444c  897e04               mov dword ptr [esi + 4], edi
// 0040444f  5f                   pop edi
// 00404450  5e                   pop esi
// 00404451  59                   pop ecx
// 00404452  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
