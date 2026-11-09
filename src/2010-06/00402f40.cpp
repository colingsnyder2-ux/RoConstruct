// from server: 100% by auto
// roc 2010-06 00402f40  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402f40
//
// 00402f40  56                   push esi
// 00402f41  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00402f45  57                   push edi
// 00402f46  8bf9                 mov edi, ecx
// 00402f48  85f6                 test esi, esi
// 00402f4a  7508                 jne 0x402f54
// 00402f4c  5f                   pop edi
// 00402f4d  8d460d               lea eax, [esi + 0xd]
// 00402f50  5e                   pop esi
// 00402f51  c20c00               ret 0xc
// 00402f54  56                   push esi
// 00402f55  ff1588a39e00         call dword ptr [0x9ea388]
// 00402f5b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402f5f  8b17                 mov edx, dword ptr [edi]
// 00402f61  40                   inc eax
// 00402f62  50                   push eax
// 00402f63  8b442418             mov eax, dword ptr [esp + 0x18]
// 00402f67  56                   push esi
// 00402f68  50                   push eax
// 00402f69  6a00                 push 0
// 00402f6b  51                   push ecx
// 00402f6c  52                   push edx
// 00402f6d  ff151ca09e00         call dword ptr [0x9ea01c]
// 00402f73  5f                   pop edi
// 00402f74  5e                   pop esi
// 00402f75  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
