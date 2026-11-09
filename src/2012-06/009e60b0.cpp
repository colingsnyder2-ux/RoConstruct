// roc 2012-06 009e60b0  unit: CXTSplitterWnd  size: 507 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e60b0
//
// 009e60b0  83ec10               sub esp, 0x10
// 009e60b3  53                   push ebx
// 009e60b4  55                   push ebp
// 009e60b5  56                   push esi
// 009e60b6  57                   push edi
// 009e60b7  8be9                 mov ebp, ecx
// 009e60b9  e882ecffff           call 0x9e4d40
// 009e60be  8b7814               mov edi, dword ptr [eax + 0x14]
// 009e60c1  8bcd                 mov ecx, ebp
// 009e60c3  e878ecffff           call 0x9e4d40
// 009e60c8  8b742424             mov esi, dword ptr [esp + 0x24]
// 009e60cc  8b5818               mov ebx, dword ptr [eax + 0x18]
// 009e60cf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 009e60d3  85f6                 test esi, esi
// 009e60d5  7518                 jne 0x9e60ef
// 009e60d7  8b4d20               mov ecx, dword ptr [ebp + 0x20]
// 009e60da  6a41                 push 0x41
// 009e60dc  56                   push esi
// 009e60dd  50                   push eax
// 009e60de  51                   push ecx
// 009e60df  ff15403db200         call dword ptr [0xb23d40]
// 009e60e5  5f                   pop edi
// 009e60e6  5e                   pop esi
// 009e60e7  5d                   pop ebp
// 009e60e8  5b                   pop ebx
// 009e60e9  83c410               add esp, 0x10
// 009e60ec  c20c00               ret 0xc
// 009e60ef  8b10                 mov edx, dword ptr [eax]
// 009e60f1  8b4804               mov ecx, dword ptr [eax + 4]
// 009e60f4  89542410             mov dword ptr [esp + 0x10], edx
// 009e60f8  8b5008               mov edx, dword ptr [eax + 8]
// 009e60fb  8b400c               mov eax, dword ptr [eax + 0xc]
// 009e60fe  8944241c             mov dword ptr [esp + 0x1c], eax
// 009e6102  8b442428             mov eax, dword ptr [esp + 0x28]
// 009e6106  894c2414             mov dword ptr [esp + 0x14], ecx
// 009e610a  89542418             mov dword ptr [esp + 0x18], edx
// 009e610e  85c0                 test eax, eax
// 009e6110  0f84db000000         je 0x9e61f1
// 009e6116  83f803               cmp eax, 3
// 009e6119  0f8575010000         jne 0x9e6294
// 009e611f  83bd0401000000       cmp dword ptr [ebp + 0x104], 0
// 009e6126  7478                 je 0x9e61a0
// 009e6128  f6850801000004       test byte ptr [ebp + 0x108], 4
// 009e612f  57                   push edi
// 009e6130  8d4c2414             lea ecx, [esp + 0x14]
// 009e6134  57                   push edi
// 009e6135  51                   push ecx
// 009e6136  8bce                 mov ecx, esi
// 009e6138  753a                 jne 0x9e6174
// 009e613a  e867cdf9ff           call 0x982ea6
// 009e613f  6aff                 push -1
// 009e6141  6aff                 push -1
// 009e6143  8d542418             lea edx, [esp + 0x18]
// 009e6147  52                   push edx
// 009e6148  ff154c3bb200         call dword ptr [0xb23b4c]
// 009e614e  e80d77fdff           call 0x9bd860
// 009e6153  6a14                 push 0x14
// 009e6155  8bc8                 mov ecx, eax
// 009e6157  e8846efdff           call 0x9bcfe0
// 009e615c  50                   push eax
// 009e615d  53                   push ebx
// 009e615e  8d442418             lea eax, [esp + 0x18]
// 009e6162  50                   push eax
// 009e6163  8bce                 mov ecx, esi
// 009e6165  e83ccdf9ff           call 0x982ea6
// 009e616a  5f                   pop edi
// 009e616b  5e                   pop esi
// 009e616c  5d                   pop ebp
// 009e616d  5b                   pop ebx
// 009e616e  83c410               add esp, 0x10
// 009e6171  c20c00               ret 0xc
// 009e6174  e82dcdf9ff           call 0x982ea6
// 009e6179  6aff                 push -1
// 009e617b  6aff                 push -1
// 009e617d  8d542418             lea edx, [esp + 0x18]
// 009e6181  52                   push edx
// 009e6182  ff154c3bb200         call dword ptr [0xb23b4c]
// 009e6188  57                   push edi
// 009e6189  57                   push edi
// 009e618a  8d442418             lea eax, [esp + 0x18]
// 009e618e  50                   push eax
// 009e618f  8bce                 mov ecx, esi
// 009e6191  e810cdf9ff           call 0x982ea6
// 009e6196  5f                   pop edi
// 009e6197  5e                   pop esi
// 009e6198  5d                   pop ebp
// 009e6199  5b                   pop ebx
// 009e619a  83c410               add esp, 0x10
// 009e619d  c20c00               ret 0xc
// 009e61a0  e8bb76fdff           call 0x9bd860
// 009e61a5  6a14                 push 0x14
// 009e61a7  8bc8                 mov ecx, eax
// 009e61a9  e8326efdff           call 0x9bcfe0
// 009e61ae  50                   push eax
// 009e61af  53                   push ebx
// 009e61b0  8d4c2418             lea ecx, [esp + 0x18]
// 009e61b4  51                   push ecx
// 009e61b5  8bce                 mov ecx, esi
// 009e61b7  e8eaccf9ff           call 0x982ea6
// 009e61bc  6aff                 push -1
// 009e61be  6aff                 push -1
// 009e61c0  8d542418             lea edx, [esp + 0x18]
// 009e61c4  52                   push edx
// 009e61c5  ff154c3bb200         call dword ptr [0xb23b4c]
// 009e61cb  e89076fdff           call 0x9bd860
// 009e61d0  6a06                 push 6
// 009e61d2  8bc8                 mov ecx, eax
// 009e61d4  e8076efdff           call 0x9bcfe0
// 009e61d9  57                   push edi
// 009e61da  50                   push eax
// 009e61db  8d442418             lea eax, [esp + 0x18]
// 009e61df  50                   push eax
// 009e61e0  8bce                 mov ecx, esi
// 009e61e2  e8bfccf9ff           call 0x982ea6
// 009e61e7  5f                   pop edi
// 009e61e8  5e                   pop esi
// 009e61e9  5d                   pop ebp
// 009e61ea  5b                   pop ebx
// 009e61eb  83c410               add esp, 0x10
// 009e61ee  c20c00               ret 0xc
// 009e61f1  83bd0401000000       cmp dword ptr [ebp + 0x104], 0
// 009e61f8  7446                 je 0x9e6240
// 009e61fa  57                   push edi
// 009e61fb  57                   push edi
// 009e61fc  8d4c2418             lea ecx, [esp + 0x18]
// 009e6200  51                   push ecx
// 009e6201  8bce                 mov ecx, esi
// 009e6203  e89eccf9ff           call 0x982ea6
// 009e6208  8b2d4c3bb200         mov ebp, dword ptr [0xb23b4c]
// 009e620e  6aff                 push -1
// 009e6210  6aff                 push -1
// 009e6212  8d542418             lea edx, [esp + 0x18]
// 009e6216  52                   push edx
// 009e6217  ffd5                 call ebp
// 009e6219  e84276fdff           call 0x9bd860
// 009e621e  6a14                 push 0x14
// 009e6220  8bc8                 mov ecx, eax
// 009e6222  e8b96dfdff           call 0x9bcfe0
// 009e6227  53                   push ebx
// 009e6228  50                   push eax
// 009e6229  8d442418             lea eax, [esp + 0x18]
// 009e622d  50                   push eax
// 009e622e  8bce                 mov ecx, esi
// 009e6230  e871ccf9ff           call 0x982ea6
// 009e6235  6aff                 push -1
// 009e6237  6aff                 push -1
// 009e6239  8d4c2418             lea ecx, [esp + 0x18]
// 009e623d  51                   push ecx
// 009e623e  eb52                 jmp 0x9e6292
// 009e6240  e81b76fdff           call 0x9bd860
// 009e6245  6a06                 push 6
// 009e6247  8bc8                 mov ecx, eax
// 009e6249  e8926dfdff           call 0x9bcfe0
// 009e624e  50                   push eax
// 009e624f  57                   push edi
// 009e6250  8d542418             lea edx, [esp + 0x18]
// 009e6254  52                   push edx
// 009e6255  8bce                 mov ecx, esi
// 009e6257  e84accf9ff           call 0x982ea6
// 009e625c  8b2d4c3bb200         mov ebp, dword ptr [0xb23b4c]
// 009e6262  6aff                 push -1
// 009e6264  6aff                 push -1
// 009e6266  8d442418             lea eax, [esp + 0x18]
// 009e626a  50                   push eax
// 009e626b  ffd5                 call ebp
// 009e626d  e8ee75fdff           call 0x9bd860
// 009e6272  6a14                 push 0x14
// 009e6274  8bc8                 mov ecx, eax
// 009e6276  e8656dfdff           call 0x9bcfe0
// 009e627b  53                   push ebx
// 009e627c  50                   push eax
// 009e627d  8d4c2418             lea ecx, [esp + 0x18]
// 009e6281  51                   push ecx
// 009e6282  8bce                 mov ecx, esi
// 009e6284  e81dccf9ff           call 0x982ea6
// 009e6289  6aff                 push -1
// 009e628b  6aff                 push -1
// 009e628d  8d542418             lea edx, [esp + 0x18]
// 009e6291  52                   push edx
// 009e6292  ffd5                 call ebp
// 009e6294  57                   push edi
// 009e6295  8d442414             lea eax, [esp + 0x14]
// 009e6299  50                   push eax
// 009e629a  8bce                 mov ecx, esi
// 009e629c  e80bccf9ff           call 0x982eac
// 009e62a1  5f                   pop edi
// 009e62a2  5e                   pop esi
// 009e62a3  5d                   pop ebp
// 009e62a4  5b                   pop ebx
// 009e62a5  83c410               add esp, 0x10
// 009e62a8  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnDrawSplitter@CXTSplitterWnd@@MAEXPAVCDC@@W4ESplitType@CSplitterWnd@@ABVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1