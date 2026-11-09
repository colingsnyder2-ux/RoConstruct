// from server: 100% by auto
// roc 2009-12 00402ef0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402ef0
//
// 00402ef0  56                   push esi
// 00402ef1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00402ef5  57                   push edi
// 00402ef6  8bf9                 mov edi, ecx
// 00402ef8  85f6                 test esi, esi
// 00402efa  7508                 jne 0x402f04
// 00402efc  5f                   pop edi
// 00402efd  8d460d               lea eax, [esi + 0xd]
// 00402f00  5e                   pop esi
// 00402f01  c20c00               ret 0xc
// 00402f04  56                   push esi
// 00402f05  ff1518b29800         call dword ptr [0x98b218]
// 00402f0b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402f0f  8b17                 mov edx, dword ptr [edi]
// 00402f11  40                   inc eax
// 00402f12  50                   push eax
// 00402f13  8b442418             mov eax, dword ptr [esp + 0x18]
// 00402f17  56                   push esi
// 00402f18  50                   push eax
// 00402f19  6a00                 push 0
// 00402f1b  51                   push ecx
// 00402f1c  52                   push edx
// 00402f1d  ff1514b09800         call dword ptr [0x98b014]
// 00402f23  5f                   pop edi
// 00402f24  5e                   pop esi
// 00402f25  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
