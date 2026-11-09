// from server: 100% by auto
// roc 2008-06 00401c80  unit: VCWorkspace::?$CComObject  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401c80
//
// 00401c80  51                   push ecx
// 00401c81  8b542408             mov edx, dword ptr [esp + 8]
// 00401c85  56                   push esi
// 00401c86  57                   push edi
// 00401c87  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00401c8b  8d442408             lea eax, [esp + 8]
// 00401c8f  50                   push eax
// 00401c90  57                   push edi
// 00401c91  8bf1                 mov esi, ecx
// 00401c93  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00401c97  6a00                 push 0
// 00401c99  51                   push ecx
// 00401c9a  52                   push edx
// 00401c9b  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00401ca3  ff1510208000         call dword ptr [0x802010]
// 00401ca9  85c0                 test eax, eax
// 00401cab  7522                 jne 0x401ccf
// 00401cad  8b0e                 mov ecx, dword ptr [esi]
// 00401caf  85c9                 test ecx, ecx
// 00401cb1  740d                 je 0x401cc0
// 00401cb3  51                   push ecx
// 00401cb4  ff1508208000         call dword ptr [0x802008]
// 00401cba  c70600000000         mov dword ptr [esi], 0
// 00401cc0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401cc4  81e700030000         and edi, 0x300
// 00401cca  890e                 mov dword ptr [esi], ecx
// 00401ccc  897e04               mov dword ptr [esi + 4], edi
// 00401ccf  5f                   pop edi
// 00401cd0  5e                   pop esi
// 00401cd1  59                   pop ecx
// 00401cd2  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?Open@CRegKey@ATL@@QAEJPAUHKEY__@@PBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
