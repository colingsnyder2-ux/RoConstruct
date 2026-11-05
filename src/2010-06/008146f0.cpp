// from server: 100% by auto
// roc 2010-06 008146f0  unit: CXTPToolTipContextToolTip  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008146f0
//
// 008146f0  83ec18               sub esp, 0x18
// 008146f3  56                   push esi
// 008146f4  8d44240c             lea eax, [esp + 0xc]
// 008146f8  57                   push edi
// 008146f9  50                   push eax
// 008146fa  e8d1c1fdff           call 0x7f08d0
// 008146ff  8bc8                 mov ecx, eax
// 00814701  e89abdfdff           call 0x7f04a0
// 00814706  8b742424             mov esi, dword ptr [esp + 0x24]
// 0081470a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0081470e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00814711  8b3d40bc9e00         mov edi, dword ptr [0x9ebc40]
// 00814717  8d50fc               lea edx, [eax - 4]
// 0081471a  3bd1                 cmp edx, ecx
// 0081471c  7d0b                 jge 0x814729
// 0081471e  2bc1                 sub eax, ecx
// 00814720  6a00                 push 0
// 00814722  83e804               sub eax, 4
// 00814725  50                   push eax
// 00814726  56                   push esi
// 00814727  ffd7                 call edi
// 00814729  8b0e                 mov ecx, dword ptr [esi]
// 0081472b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081472f  3bc1                 cmp eax, ecx
// 00814731  7e08                 jle 0x81473b
// 00814733  6a00                 push 0
// 00814735  2bc1                 sub eax, ecx
// 00814737  50                   push eax
// 00814738  56                   push esi
// 00814739  ffd7                 call edi
// 0081473b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0081473f  83c0fc               add eax, -4
// 00814742  3b460c               cmp eax, dword ptr [esi + 0xc]
// 00814745  7d1b                 jge 0x814762
// 00814747  8d4c2408             lea ecx, [esp + 8]
// 0081474b  51                   push ecx
// 0081474c  ff1574bc9e00         call dword ptr [0x9ebc74]
// 00814752  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00814756  2b560c               sub edx, dword ptr [esi + 0xc]
// 00814759  83ea03               sub edx, 3
// 0081475c  52                   push edx
// 0081475d  6a00                 push 0
// 0081475f  56                   push esi
// 00814760  ffd7                 call edi
// 00814762  5f                   pop edi
// 00814763  5e                   pop esi
// 00814764  83c418               add esp, 0x18
// 00814767  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPToolTipContext.cpp (function ?EnsureVisible@CXTPToolTipContextToolTip@@IAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPToolTipContext.cpp
