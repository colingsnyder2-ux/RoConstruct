// from server: 100% by auto
// roc 2010-06 00803b50  unit: CXTPPropertyGrid  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803b50
//
// 00803b50  8b542408             mov edx, dword ptr [esp + 8]
// 00803b54  56                   push esi
// 00803b55  8b742408             mov esi, dword ptr [esp + 8]
// 00803b59  57                   push edi
// 00803b5a  6a00                 push 0
// 00803b5c  8bf9                 mov edi, ecx
// 00803b5e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00803b62  8b07                 mov eax, dword ptr [edi]
// 00803b64  8b4060               mov eax, dword ptr [eax + 0x60]
// 00803b67  51                   push ecx
// 00803b68  52                   push edx
// 00803b69  56                   push esi
// 00803b6a  6800000346           push 0x46030000
// 00803b6f  68fe08a000           push 0xa008fe
// 00803b74  6838ffa500           push 0xa5ff38
// 00803b79  6a00                 push 0
// 00803b7b  8bcf                 mov ecx, edi
// 00803b7d  ffd0                 call eax
// 00803b7f  85c0                 test eax, eax
// 00803b81  7507                 jne 0x803b8a
// 00803b83  5f                   pop edi
// 00803b84  33c0                 xor eax, eax
// 00803b86  5e                   pop esi
// 00803b87  c21000               ret 0x10
// 00803b8a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00803b8e  51                   push ecx
// 00803b8f  8bcf                 mov ecx, edi
// 00803b91  e81affffff           call 0x803ab0
// 00803b96  85c0                 test eax, eax
// 00803b98  74e9                 je 0x803b83
// 00803b9a  8b460c               mov eax, dword ptr [esi + 0xc]
// 00803b9d  2b4604               sub eax, dword ptr [esi + 4]
// 00803ba0  8b4e08               mov ecx, dword ptr [esi + 8]
// 00803ba3  2b0e                 sub ecx, dword ptr [esi]
// 00803ba5  8b17                 mov edx, dword ptr [edi]
// 00803ba7  8b9258010000         mov edx, dword ptr [edx + 0x158]
// 00803bad  50                   push eax
// 00803bae  51                   push ecx
// 00803baf  8bcf                 mov ecx, edi
// 00803bb1  ffd2                 call edx
// 00803bb3  8b4604               mov eax, dword ptr [esi + 4]
// 00803bb6  8b560c               mov edx, dword ptr [esi + 0xc]
// 00803bb9  8b0e                 mov ecx, dword ptr [esi]
// 00803bbb  6a44                 push 0x44
// 00803bbd  2bd0                 sub edx, eax
// 00803bbf  52                   push edx
// 00803bc0  8b5608               mov edx, dword ptr [esi + 8]
// 00803bc3  2bd1                 sub edx, ecx
// 00803bc5  52                   push edx
// 00803bc6  50                   push eax
// 00803bc7  51                   push ecx
// 00803bc8  6a00                 push 0
// 00803bca  8bcf                 mov ecx, edi
// 00803bcc  e89b41faff           call 0x7a7d6c
// 00803bd1  5f                   pop edi
// 00803bd2  b801000000           mov eax, 1
// 00803bd7  5e                   pop esi
// 00803bd8  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?Create@CXTPPropertyGrid@@UAEHABUtagRECT@@PAVCWnd@@IK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
