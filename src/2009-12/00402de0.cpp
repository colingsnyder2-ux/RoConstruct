// from server: 100% by auto
// roc 2009-12 00402de0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402de0
//
// 00402de0  803d4495b70000       cmp byte ptr [0xb79544], 0
// 00402de7  56                   push esi
// 00402de8  8bf1                 mov esi, ecx
// 00402dea  7527                 jne 0x402e13
// 00402dec  68dcf69900           push 0x99f6dc
// 00402df1  ff151cb29800         call dword ptr [0x98b21c]
// 00402df7  85c0                 test eax, eax
// 00402df9  7411                 je 0x402e0c
// 00402dfb  68ccf69900           push 0x99f6cc
// 00402e00  50                   push eax
// 00402e01  ff1520b29800         call dword ptr [0x98b220]
// 00402e07  a34095b700           mov dword ptr [0xb79540], eax
// 00402e0c  c6054495b70001       mov byte ptr [0xb79544], 1
// 00402e13  a14095b700           mov eax, dword ptr [0xb79540]
// 00402e18  8b542408             mov edx, dword ptr [esp + 8]
// 00402e1c  85c0                 test eax, eax
// 00402e1e  7410                 je 0x402e30
// 00402e20  8b4e04               mov ecx, dword ptr [esi + 4]
// 00402e23  6a00                 push 0
// 00402e25  51                   push ecx
// 00402e26  8b0e                 mov ecx, dword ptr [esi]
// 00402e28  52                   push edx
// 00402e29  51                   push ecx
// 00402e2a  ffd0                 call eax
// 00402e2c  5e                   pop esi
// 00402e2d  c20400               ret 4
// 00402e30  8b06                 mov eax, dword ptr [esi]
// 00402e32  52                   push edx
// 00402e33  50                   push eax
// 00402e34  ff1500b09800         call dword ptr [0x98b000]
// 00402e3a  5e                   pop esi
// 00402e3b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteSubKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
