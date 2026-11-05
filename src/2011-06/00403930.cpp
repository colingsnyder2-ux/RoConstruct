// from server: 100% by auto
// roc 2011-06 00403930  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403930
//
// 00403930  56                   push esi
// 00403931  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00403935  57                   push edi
// 00403936  8bf9                 mov edi, ecx
// 00403938  85f6                 test esi, esi
// 0040393a  7508                 jne 0x403944
// 0040393c  5f                   pop edi
// 0040393d  8d460d               lea eax, [esi + 0xd]
// 00403940  5e                   pop esi
// 00403941  c20c00               ret 0xc
// 00403944  56                   push esi
// 00403945  ff156403a400         call dword ptr [0xa40364]
// 0040394b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040394f  8b17                 mov edx, dword ptr [edi]
// 00403951  40                   inc eax
// 00403952  50                   push eax
// 00403953  8b442418             mov eax, dword ptr [esp + 0x18]
// 00403957  56                   push esi
// 00403958  50                   push eax
// 00403959  6a00                 push 0
// 0040395b  51                   push ecx
// 0040395c  52                   push edx
// 0040395d  ff154400a400         call dword ptr [0xa40044]
// 00403963  5f                   pop edi
// 00403964  5e                   pop esi
// 00403965  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetStringValue@CRegKey@ATL@@QAEJPBD0K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
