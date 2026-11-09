// from server: 100% by auto
// roc 2010-06 007f4940  unit: CXTPCustomizeCommandsListBox  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f4940
//
// 007f4940  83ec18               sub esp, 0x18
// 007f4943  53                   push ebx
// 007f4944  55                   push ebp
// 007f4945  56                   push esi
// 007f4946  8b742428             mov esi, dword ptr [esp + 0x28]
// 007f494a  8b4618               mov eax, dword ptr [esi + 0x18]
// 007f494d  57                   push edi
// 007f494e  50                   push eax
// 007f494f  8bf9                 mov edi, ecx
// 007f4951  e816841800           call 0x97cd6c
// 007f4956  8d4e1c               lea ecx, [esi + 0x1c]
// 007f4959  51                   push ecx
// 007f495a  8d54241c             lea edx, [esp + 0x1c]
// 007f495e  52                   push edx
// 007f495f  8be8                 mov ebp, eax
// 007f4961  ff1548bc9e00         call dword ptr [0x9ebc48]
// 007f4967  8b5e2c               mov ebx, dword ptr [esi + 0x2c]
// 007f496a  85db                 test ebx, ebx
// 007f496c  7444                 je 0x7f49b2
// 007f496e  8b7f54               mov edi, dword ptr [edi + 0x54]
// 007f4971  8b7610               mov esi, dword ptr [esi + 0x10]
// 007f4974  8bcf                 mov ecx, edi
// 007f4976  83e601               and esi, 1
// 007f4979  e8423efdff           call 0x7c87c0
// 007f497e  57                   push edi
// 007f497f  6a01                 push 1
// 007f4981  56                   push esi
// 007f4982  8b742424             mov esi, dword ptr [esp + 0x24]
// 007f4986  83ec10               sub esp, 0x10
// 007f4989  8bd4                 mov edx, esp
// 007f498b  8932                 mov dword ptr [edx], esi
// 007f498d  8b742438             mov esi, dword ptr [esp + 0x38]
// 007f4991  897204               mov dword ptr [edx + 4], esi
// 007f4994  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 007f4998  897208               mov dword ptr [edx + 8], esi
// 007f499b  8b742440             mov esi, dword ptr [esp + 0x40]
// 007f499f  53                   push ebx
// 007f49a0  8bc8                 mov ecx, eax
// 007f49a2  8b00                 mov eax, dword ptr [eax]
// 007f49a4  8b4070               mov eax, dword ptr [eax + 0x70]
// 007f49a7  89720c               mov dword ptr [edx + 0xc], esi
// 007f49aa  55                   push ebp
// 007f49ab  8d542434             lea edx, [esp + 0x34]
// 007f49af  52                   push edx
// 007f49b0  ffd0                 call eax
// 007f49b2  5f                   pop edi
// 007f49b3  5e                   pop esi
// 007f49b4  5d                   pop ebp
// 007f49b5  5b                   pop ebx
// 007f49b6  83c418               add esp, 0x18
// 007f49b9  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCustomizeCommandsPage.cpp (function ?DrawItem@CXTPCustomizeCommandsListBox@@MAEXPAUtagDRAWITEMSTRUCT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCustomizeCommandsPage.cpp
