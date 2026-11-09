// from server: 100% by auto
// roc 2010-06 007e6d30  unit: CRobloxTreeCtrl  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6d30
//
// 007e6d30  83ec10               sub esp, 0x10
// 007e6d33  55                   push ebp
// 007e6d34  56                   push esi
// 007e6d35  6a00                 push 0
// 007e6d37  8be9                 mov ebp, ecx
// 007e6d39  8b4534               mov eax, dword ptr [ebp + 0x34]
// 007e6d3c  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e6d3f  6a00                 push 0
// 007e6d41  680a110000           push 0x110a
// 007e6d46  50                   push eax
// 007e6d47  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6d4d  8bf0                 mov esi, eax
// 007e6d4f  85f6                 test esi, esi
// 007e6d51  0f84bf000000         je 0x7e6e16
// 007e6d57  53                   push ebx
// 007e6d58  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 007e6d5c  57                   push edi
// 007e6d5d  8d4900               lea ecx, [ecx]
// 007e6d60  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 007e6d63  6a02                 push 2
// 007e6d65  56                   push esi
// 007e6d66  e8d7621900           call 0x97d042
// 007e6d6b  8b4d08               mov ecx, dword ptr [ebp + 8]
// 007e6d6e  51                   push ecx
// 007e6d6f  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 007e6d72  8d542414             lea edx, [esp + 0x14]
// 007e6d76  8bf8                 mov edi, eax
// 007e6d78  52                   push edx
// 007e6d79  d1ef                 shr edi, 1
// 007e6d7b  56                   push esi
// 007e6d7c  83e701               and edi, 1
// 007e6d7f  e8b215fcff           call 0x7a8336
// 007e6d84  8b442424             mov eax, dword ptr [esp + 0x24]
// 007e6d88  50                   push eax
// 007e6d89  8d4c2414             lea ecx, [esp + 0x14]
// 007e6d8d  51                   push ecx
// 007e6d8e  8bd1                 mov edx, ecx
// 007e6d90  52                   push edx
// 007e6d91  ff15a4ba9e00         call dword ptr [0x9ebaa4]
// 007e6d97  6a00                 push 0
// 007e6d99  8bcb                 mov ecx, ebx
// 007e6d9b  56                   push esi
// 007e6d9c  85c0                 test eax, eax
// 007e6d9e  7433                 je 0x7e6dd3
// 007e6da0  e8cd621900           call 0x97d072
// 007e6da5  85ff                 test edi, edi
// 007e6da7  7504                 jne 0x7e6dad
// 007e6da9  85c0                 test eax, eax
// 007e6dab  743c                 je 0x7e6de9
// 007e6dad  8a4c2428             mov cl, byte ptr [esp + 0x28]
// 007e6db1  f6c108               test cl, 8
// 007e6db4  740a                 je 0x7e6dc0
// 007e6db6  85c0                 test eax, eax
// 007e6db8  7406                 je 0x7e6dc0
// 007e6dba  6a02                 push 2
// 007e6dbc  6a00                 push 0
// 007e6dbe  eb2d                 jmp 0x7e6ded
// 007e6dc0  f6c104               test cl, 4
// 007e6dc3  7430                 je 0x7e6df5
// 007e6dc5  85c0                 test eax, eax
// 007e6dc7  742c                 je 0x7e6df5
// 007e6dc9  50                   push eax
// 007e6dca  8bcb                 mov ecx, ebx
// 007e6dcc  e89b621900           call 0x97d06c
// 007e6dd1  eb22                 jmp 0x7e6df5
// 007e6dd3  e89a621900           call 0x97d072
// 007e6dd8  85ff                 test edi, edi
// 007e6dda  7409                 je 0x7e6de5
// 007e6ddc  85c0                 test eax, eax
// 007e6dde  7509                 jne 0x7e6de9
// 007e6de0  6a02                 push 2
// 007e6de2  50                   push eax
// 007e6de3  eb08                 jmp 0x7e6ded
// 007e6de5  85c0                 test eax, eax
// 007e6de7  740c                 je 0x7e6df5
// 007e6de9  6a02                 push 2
// 007e6deb  6a02                 push 2
// 007e6ded  56                   push esi
// 007e6dee  8bcd                 mov ecx, ebp
// 007e6df0  e81bf5ffff           call 0x7e6310
// 007e6df5  8b4534               mov eax, dword ptr [ebp + 0x34]
// 007e6df8  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e6dfb  56                   push esi
// 007e6dfc  6a06                 push 6
// 007e6dfe  680a110000           push 0x110a
// 007e6e03  50                   push eax
// 007e6e04  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6e0a  8bf0                 mov esi, eax
// 007e6e0c  85f6                 test esi, esi
// 007e6e0e  0f854cffffff         jne 0x7e6d60
// 007e6e14  5f                   pop edi
// 007e6e15  5b                   pop ebx
// 007e6e16  8b4d34               mov ecx, dword ptr [ebp + 0x34]
// 007e6e19  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007e6e1c  52                   push edx
// 007e6e1d  ff15d8ba9e00         call dword ptr [0x9ebad8]
// 007e6e23  5e                   pop esi
// 007e6e24  5d                   pop ebp
// 007e6e25  83c410               add esp, 0x10
// 007e6e28  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?UpdateSelectionForRect@CXTTreeBase@@MAEXPBUtagRECT@@IAAV?$CTypedPtrList@VCPtrList@@PAU_TREEITEM@@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
