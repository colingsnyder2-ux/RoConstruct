// from server: 100% by auto
// roc 2009-06 00403220  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403220
//
// 00403220  56                   push esi
// 00403221  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00403225  57                   push edi
// 00403226  8bf9                 mov edi, ecx
// 00403228  85f6                 test esi, esi
// 0040322a  7508                 jne 0x403234
// 0040322c  5f                   pop edi
// 0040322d  8d460d               lea eax, [esi + 0xd]
// 00403230  5e                   pop esi
// 00403231  c20c00               ret 0xc
// 00403234  56                   push esi
// 00403235  ff15e0e18900         call dword ptr [0x89e1e0]
// 0040323b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040323f  8b17                 mov edx, dword ptr [edi]
// 00403241  40                   inc eax
// 00403242  50                   push eax
// 00403243  8b442418             mov eax, dword ptr [esp + 0x18]
// 00403247  56                   push esi
// 00403248  50                   push eax
// 00403249  6a00                 push 0
// 0040324b  51                   push ecx
// 0040324c  52                   push edx
// 0040324d  ff1514e08900         call dword ptr [0x89e014]
// 00403253  5f                   pop edi
// 00403254  5e                   pop esi
// 00403255  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
