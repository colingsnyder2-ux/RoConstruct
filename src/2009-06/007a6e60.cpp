// from server: 100% by auto
// roc 2009-06 007a6e60  unit: CXTPOffice2007Theme  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a6e60
//
// 007a6e60  83ec10               sub esp, 0x10
// 007a6e63  8b442420             mov eax, dword ptr [esp + 0x20]
// 007a6e67  53                   push ebx
// 007a6e68  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 007a6e6c  55                   push ebp
// 007a6e6d  bd03000000           mov ebp, 3
// 007a6e72  56                   push esi
// 007a6e73  83c0fd               add eax, -3
// 007a6e76  83c3fd               add ebx, -3
// 007a6e79  57                   push edi
// 007a6e7a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007a6e7e  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a6e82  89442418             mov dword ptr [esp + 0x18], eax
// 007a6e86  896c2410             mov dword ptr [esp + 0x10], ebp
// 007a6e8a  85ed                 test ebp, ebp
// 007a6e8c  7e41                 jle 0x7a6ecf
// 007a6e8e  8b742418             mov esi, dword ptr [esp + 0x18]
// 007a6e92  68ffffff00           push 0xffffff
// 007a6e97  6a02                 push 2
// 007a6e99  6a02                 push 2
// 007a6e9b  8d4301               lea eax, [ebx + 1]
// 007a6e9e  50                   push eax
// 007a6e9f  8d4e01               lea ecx, [esi + 1]
// 007a6ea2  51                   push ecx
// 007a6ea3  8bcf                 mov ecx, edi
// 007a6ea5  e886500a00           call 0x84bf30
// 007a6eaa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a6eae  6a27                 push 0x27
// 007a6eb0  e8cbb8f7ff           call 0x722780
// 007a6eb5  50                   push eax
// 007a6eb6  6a02                 push 2
// 007a6eb8  6a02                 push 2
// 007a6eba  53                   push ebx
// 007a6ebb  56                   push esi
// 007a6ebc  8bcf                 mov ecx, edi
// 007a6ebe  e86d500a00           call 0x84bf30
// 007a6ec3  83ee04               sub esi, 4
// 007a6ec6  83ed01               sub ebp, 1
// 007a6ec9  75c7                 jne 0x7a6e92
// 007a6ecb  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007a6ecf  4d                   dec ebp
// 007a6ed0  83eb04               sub ebx, 4
// 007a6ed3  896c2410             mov dword ptr [esp + 0x10], ebp
// 007a6ed7  85ed                 test ebp, ebp
// 007a6ed9  7fb3                 jg 0x7a6e8e
// 007a6edb  5f                   pop edi
// 007a6edc  5e                   pop esi
// 007a6edd  5d                   pop ebp
// 007a6ede  5b                   pop ebx
// 007a6edf  83c410               add esp, 0x10
// 007a6ee2  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ?DrawStatusBarGripper@CXTPResourceTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
