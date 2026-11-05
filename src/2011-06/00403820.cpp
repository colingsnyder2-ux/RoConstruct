// from server: 100% by auto
// roc 2011-06 00403820  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403820
//
// 00403820  803d2016cb0000       cmp byte ptr [0xcb1620], 0
// 00403827  56                   push esi
// 00403828  8bf1                 mov esi, ecx
// 0040382a  7527                 jne 0x403853
// 0040382c  6844b8a500           push 0xa5b844
// 00403831  ff156803a400         call dword ptr [0xa40368]
// 00403837  85c0                 test eax, eax
// 00403839  7411                 je 0x40384c
// 0040383b  6834b8a500           push 0xa5b834
// 00403840  50                   push eax
// 00403841  ff156c03a400         call dword ptr [0xa4036c]
// 00403847  a31c16cb00           mov dword ptr [0xcb161c], eax
// 0040384c  c6052016cb0001       mov byte ptr [0xcb1620], 1
// 00403853  a11c16cb00           mov eax, dword ptr [0xcb161c]
// 00403858  8b542408             mov edx, dword ptr [esp + 8]
// 0040385c  85c0                 test eax, eax
// 0040385e  7410                 je 0x403870
// 00403860  8b4e04               mov ecx, dword ptr [esi + 4]
// 00403863  6a00                 push 0
// 00403865  51                   push ecx
// 00403866  8b0e                 mov ecx, dword ptr [esi]
// 00403868  52                   push edx
// 00403869  51                   push ecx
// 0040386a  ffd0                 call eax
// 0040386c  5e                   pop esi
// 0040386d  c20400               ret 4
// 00403870  8b06                 mov eax, dword ptr [esi]
// 00403872  52                   push edx
// 00403873  50                   push eax
// 00403874  ff150000a400         call dword ptr [0xa40000]
// 0040387a  5e                   pop esi
// 0040387b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteSubKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
