// from server: 100% by auto
// roc 2009-06 00403110  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403110
//
// 00403110  803d5c97a30000       cmp byte ptr [0xa3975c], 0
// 00403117  56                   push esi
// 00403118  8bf1                 mov esi, ecx
// 0040311a  7527                 jne 0x403143
// 0040311c  689ccb8a00           push 0x8acb9c
// 00403121  ff15e4e18900         call dword ptr [0x89e1e4]
// 00403127  85c0                 test eax, eax
// 00403129  7411                 je 0x40313c
// 0040312b  688ccb8a00           push 0x8acb8c
// 00403130  50                   push eax
// 00403131  ff15e8e18900         call dword ptr [0x89e1e8]
// 00403137  a35897a300           mov dword ptr [0xa39758], eax
// 0040313c  c6055c97a30001       mov byte ptr [0xa3975c], 1
// 00403143  a15897a300           mov eax, dword ptr [0xa39758]
// 00403148  8b542408             mov edx, dword ptr [esp + 8]
// 0040314c  85c0                 test eax, eax
// 0040314e  7410                 je 0x403160
// 00403150  8b4e04               mov ecx, dword ptr [esi + 4]
// 00403153  6a00                 push 0
// 00403155  51                   push ecx
// 00403156  8b0e                 mov ecx, dword ptr [esi]
// 00403158  52                   push edx
// 00403159  51                   push ecx
// 0040315a  ffd0                 call eax
// 0040315c  5e                   pop esi
// 0040315d  c20400               ret 4
// 00403160  8b06                 mov eax, dword ptr [esi]
// 00403162  52                   push edx
// 00403163  50                   push eax
// 00403164  ff1538e08900         call dword ptr [0x89e038]
// 0040316a  5e                   pop esi
// 0040316b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteSubKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
