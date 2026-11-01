// from server: 100% by auto
// roc 2009-12 00832b70  unit: CRobloxTreeCtrl  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832b70
//
// 00832b70  83ec10               sub esp, 0x10
// 00832b73  55                   push ebp
// 00832b74  56                   push esi
// 00832b75  6a00                 push 0
// 00832b77  8be9                 mov ebp, ecx
// 00832b79  8b4534               mov eax, dword ptr [ebp + 0x34]
// 00832b7c  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832b7f  6a00                 push 0
// 00832b81  680a110000           push 0x110a
// 00832b86  50                   push eax
// 00832b87  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832b8d  8bf0                 mov esi, eax
// 00832b8f  85f6                 test esi, esi
// 00832b91  0f84bf000000         je 0x832c56
// 00832b97  53                   push ebx
// 00832b98  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00832b9c  57                   push edi
// 00832b9d  8d4900               lea ecx, [ecx]
// 00832ba0  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00832ba3  6a02                 push 2
// 00832ba5  56                   push esi
// 00832ba6  e85b3b0f00           call 0x926706
// 00832bab  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00832bae  51                   push ecx
// 00832baf  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00832bb2  8d542414             lea edx, [esp + 0x14]
// 00832bb6  8bf8                 mov edi, eax
// 00832bb8  52                   push edx
// 00832bb9  d1ef                 shr edi, 1
// 00832bbb  56                   push esi
// 00832bbc  83e701               and edi, 1
// 00832bbf  e83216fcff           call 0x7f41f6
// 00832bc4  8b442424             mov eax, dword ptr [esp + 0x24]
// 00832bc8  50                   push eax
// 00832bc9  8d4c2414             lea ecx, [esp + 0x14]
// 00832bcd  51                   push ecx
// 00832bce  8bd1                 mov edx, ecx
// 00832bd0  52                   push edx
// 00832bd1  ff15dcca9800         call dword ptr [0x98cadc]
// 00832bd7  6a00                 push 0
// 00832bd9  8bcb                 mov ecx, ebx
// 00832bdb  56                   push esi
// 00832bdc  85c0                 test eax, eax
// 00832bde  7433                 je 0x832c13
// 00832be0  e8513b0f00           call 0x926736
// 00832be5  85ff                 test edi, edi
// 00832be7  7504                 jne 0x832bed
// 00832be9  85c0                 test eax, eax
// 00832beb  743c                 je 0x832c29
// 00832bed  8a4c2428             mov cl, byte ptr [esp + 0x28]
// 00832bf1  f6c108               test cl, 8
// 00832bf4  740a                 je 0x832c00
// 00832bf6  85c0                 test eax, eax
// 00832bf8  7406                 je 0x832c00
// 00832bfa  6a02                 push 2
// 00832bfc  6a00                 push 0
// 00832bfe  eb2d                 jmp 0x832c2d
// 00832c00  f6c104               test cl, 4
// 00832c03  7430                 je 0x832c35
// 00832c05  85c0                 test eax, eax
// 00832c07  742c                 je 0x832c35
// 00832c09  50                   push eax
// 00832c0a  8bcb                 mov ecx, ebx
// 00832c0c  e81f3b0f00           call 0x926730
// 00832c11  eb22                 jmp 0x832c35
// 00832c13  e81e3b0f00           call 0x926736
// 00832c18  85ff                 test edi, edi
// 00832c1a  7409                 je 0x832c25
// 00832c1c  85c0                 test eax, eax
// 00832c1e  7509                 jne 0x832c29
// 00832c20  6a02                 push 2
// 00832c22  50                   push eax
// 00832c23  eb08                 jmp 0x832c2d
// 00832c25  85c0                 test eax, eax
// 00832c27  740c                 je 0x832c35
// 00832c29  6a02                 push 2
// 00832c2b  6a02                 push 2
// 00832c2d  56                   push esi
// 00832c2e  8bcd                 mov ecx, ebp
// 00832c30  e81bf5ffff           call 0x832150
// 00832c35  8b4534               mov eax, dword ptr [ebp + 0x34]
// 00832c38  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832c3b  56                   push esi
// 00832c3c  6a06                 push 6
// 00832c3e  680a110000           push 0x110a
// 00832c43  50                   push eax
// 00832c44  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832c4a  8bf0                 mov esi, eax
// 00832c4c  85f6                 test esi, esi
// 00832c4e  0f854cffffff         jne 0x832ba0
// 00832c54  5f                   pop edi
// 00832c55  5b                   pop ebx
// 00832c56  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 00832c59  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00832c5c  52                   push edx
// 00832c5d  ff15a4ca9800         call dword ptr [0x98caa4]
// 00832c63  5e                   pop esi
// 00832c64  5d                   pop ebp
// 00832c65  83c410               add esp, 0x10
// 00832c68  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?UpdateSelectionForRect@CXTPTreeBase@@MAEXPBUtagRECT@@IAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
