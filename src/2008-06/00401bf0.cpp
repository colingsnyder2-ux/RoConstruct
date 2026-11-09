// from server: 100% by auto
// roc 2008-06 00401bf0  unit: VCWorkspace::?$CComObject  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401bf0
//
// 00401bf0  803d88c2960000       cmp byte ptr [0x96c288], 0
// 00401bf7  56                   push esi
// 00401bf8  8bf1                 mov esi, ecx
// 00401bfa  7527                 jne 0x401c23
// 00401bfc  68c8af8000           push 0x80afc8
// 00401c01  ff15bc218000         call dword ptr [0x8021bc]
// 00401c07  85c0                 test eax, eax
// 00401c09  7411                 je 0x401c1c
// 00401c0b  68b8af8000           push 0x80afb8
// 00401c10  50                   push eax
// 00401c11  ff15c0218000         call dword ptr [0x8021c0]
// 00401c17  a384c29600           mov dword ptr [0x96c284], eax
// 00401c1c  c60588c2960001       mov byte ptr [0x96c288], 1
// 00401c23  a184c29600           mov eax, dword ptr [0x96c284]
// 00401c28  8b542408             mov edx, dword ptr [esp + 8]
// 00401c2c  85c0                 test eax, eax
// 00401c2e  7410                 je 0x401c40
// 00401c30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00401c33  6a00                 push 0
// 00401c35  51                   push ecx
// 00401c36  8b0e                 mov ecx, dword ptr [esi]
// 00401c38  52                   push edx
// 00401c39  51                   push ecx
// 00401c3a  ffd0                 call eax
// 00401c3c  5e                   pop esi
// 00401c3d  c20400               ret 4
// 00401c40  8b06                 mov eax, dword ptr [esi]
// 00401c42  52                   push edx
// 00401c43  50                   push eax
// 00401c44  ff1534208000         call dword ptr [0x802034]
// 00401c4a  5e                   pop esi
// 00401c4b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteSubKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
