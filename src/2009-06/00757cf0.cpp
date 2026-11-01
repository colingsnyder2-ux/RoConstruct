// from server: 100% by auto
// roc 2009-06 00757cf0  unit: CRobloxTreeCtrl  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757cf0
//
// 00757cf0  83ec10               sub esp, 0x10
// 00757cf3  55                   push ebp
// 00757cf4  56                   push esi
// 00757cf5  6a00                 push 0
// 00757cf7  8be9                 mov ebp, ecx
// 00757cf9  8b4534               mov eax, dword ptr [ebp + 0x34]
// 00757cfc  8b4020               mov eax, dword ptr [eax + 0x20]
// 00757cff  6a00                 push 0
// 00757d01  680a110000           push 0x110a
// 00757d06  50                   push eax
// 00757d07  ff1590ee8900         call dword ptr [0x89ee90]
// 00757d0d  8bf0                 mov esi, eax
// 00757d0f  85f6                 test esi, esi
// 00757d11  0f84bf000000         je 0x757dd6
// 00757d17  53                   push ebx
// 00757d18  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00757d1c  57                   push edi
// 00757d1d  8d4900               lea ecx, [ecx]
// 00757d20  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00757d23  6a02                 push 2
// 00757d25  56                   push esi
// 00757d26  e86f440f00           call 0x84c19a
// 00757d2b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00757d2e  51                   push ecx
// 00757d2f  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00757d32  8d542414             lea edx, [esp + 0x14]
// 00757d36  8bf8                 mov edi, eax
// 00757d38  52                   push edx
// 00757d39  d1ef                 shr edi, 1
// 00757d3b  56                   push esi
// 00757d3c  83e701               and edi, 1
// 00757d3f  e88a16fcff           call 0x7193ce
// 00757d44  8b442424             mov eax, dword ptr [esp + 0x24]
// 00757d48  50                   push eax
// 00757d49  8d4c2414             lea ecx, [esp + 0x14]
// 00757d4d  51                   push ecx
// 00757d4e  8bd1                 mov edx, ecx
// 00757d50  52                   push edx
// 00757d51  ff15f0ee8900         call dword ptr [0x89eef0]
// 00757d57  6a00                 push 0
// 00757d59  8bcb                 mov ecx, ebx
// 00757d5b  56                   push esi
// 00757d5c  85c0                 test eax, eax
// 00757d5e  7433                 je 0x757d93
// 00757d60  e865440f00           call 0x84c1ca
// 00757d65  85ff                 test edi, edi
// 00757d67  7504                 jne 0x757d6d
// 00757d69  85c0                 test eax, eax
// 00757d6b  743c                 je 0x757da9
// 00757d6d  8a4c2428             mov cl, byte ptr [esp + 0x28]
// 00757d71  f6c108               test cl, 8
// 00757d74  740a                 je 0x757d80
// 00757d76  85c0                 test eax, eax
// 00757d78  7406                 je 0x757d80
// 00757d7a  6a02                 push 2
// 00757d7c  6a00                 push 0
// 00757d7e  eb2d                 jmp 0x757dad
// 00757d80  f6c104               test cl, 4
// 00757d83  7430                 je 0x757db5
// 00757d85  85c0                 test eax, eax
// 00757d87  742c                 je 0x757db5
// 00757d89  50                   push eax
// 00757d8a  8bcb                 mov ecx, ebx
// 00757d8c  e833440f00           call 0x84c1c4
// 00757d91  eb22                 jmp 0x757db5
// 00757d93  e832440f00           call 0x84c1ca
// 00757d98  85ff                 test edi, edi
// 00757d9a  7409                 je 0x757da5
// 00757d9c  85c0                 test eax, eax
// 00757d9e  7509                 jne 0x757da9
// 00757da0  6a02                 push 2
// 00757da2  50                   push eax
// 00757da3  eb08                 jmp 0x757dad
// 00757da5  85c0                 test eax, eax
// 00757da7  740c                 je 0x757db5
// 00757da9  6a02                 push 2
// 00757dab  6a02                 push 2
// 00757dad  56                   push esi
// 00757dae  8bcd                 mov ecx, ebp
// 00757db0  e81bf5ffff           call 0x7572d0
// 00757db5  8b4534               mov eax, dword ptr [ebp + 0x34]
// 00757db8  8b4020               mov eax, dword ptr [eax + 0x20]
// 00757dbb  56                   push esi
// 00757dbc  6a06                 push 6
// 00757dbe  680a110000           push 0x110a
// 00757dc3  50                   push eax
// 00757dc4  ff1590ee8900         call dword ptr [0x89ee90]
// 00757dca  8bf0                 mov esi, eax
// 00757dcc  85f6                 test esi, esi
// 00757dce  0f854cffffff         jne 0x757d20
// 00757dd4  5f                   pop edi
// 00757dd5  5b                   pop ebx
// 00757dd6  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00757dd9  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00757ddc  52                   push edx
// 00757ddd  ff15b4ee8900         call dword ptr [0x89eeb4]
// 00757de3  5e                   pop esi
// 00757de4  5d                   pop ebp
// 00757de5  83c410               add esp, 0x10
// 00757de8  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?UpdateSelectionForRect@CXTPTreeBase@@MAEXPBUtagRECT@@IAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
