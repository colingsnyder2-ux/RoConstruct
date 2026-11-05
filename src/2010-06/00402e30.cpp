// from server: 100% by auto
// roc 2010-06 00402e30  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402e30
//
// 00402e30  803df4fabf0000       cmp byte ptr [0xbffaf4], 0
// 00402e37  56                   push esi
// 00402e38  8bf1                 mov esi, ecx
// 00402e3a  7527                 jne 0x402e63
// 00402e3c  688002a000           push 0xa00280
// 00402e41  ff158ca39e00         call dword ptr [0x9ea38c]
// 00402e47  85c0                 test eax, eax
// 00402e49  7411                 je 0x402e5c
// 00402e4b  687002a000           push 0xa00270
// 00402e50  50                   push eax
// 00402e51  ff1590a39e00         call dword ptr [0x9ea390]
// 00402e57  a3f0fabf00           mov dword ptr [0xbffaf0], eax
// 00402e5c  c605f4fabf0001       mov byte ptr [0xbffaf4], 1
// 00402e63  a1f0fabf00           mov eax, dword ptr [0xbffaf0]
// 00402e68  8b542408             mov edx, dword ptr [esp + 8]
// 00402e6c  85c0                 test eax, eax
// 00402e6e  7410                 je 0x402e80
// 00402e70  8b4e04               mov ecx, dword ptr [esi + 4]
// 00402e73  6a00                 push 0
// 00402e75  51                   push ecx
// 00402e76  8b0e                 mov ecx, dword ptr [esi]
// 00402e78  52                   push edx
// 00402e79  51                   push ecx
// 00402e7a  ffd0                 call eax
// 00402e7c  5e                   pop esi
// 00402e7d  c20400               ret 4
// 00402e80  8b06                 mov eax, dword ptr [esi]
// 00402e82  52                   push edx
// 00402e83  50                   push eax
// 00402e84  ff1508a09e00         call dword ptr [0x9ea008]
// 00402e8a  5e                   pop esi
// 00402e8b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteSubKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
