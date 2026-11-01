// from server: 100% by auto
// roc 2011-06 00462430  unit: CRobloxApp  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00462430
//
// 00462430  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00462434  83ec10               sub esp, 0x10
// 00462437  85c0                 test eax, eax
// 00462439  7509                 jne 0x462444
// 0046243b  b803400080           mov eax, 0x80004003
// 00462440  83c410               add esp, 0x10
// 00462443  c3                   ret 
// 00462444  56                   push esi
// 00462445  8b742418             mov esi, dword ptr [esp + 0x18]
// 00462449  85f6                 test esi, esi
// 0046244b  750a                 jne 0x462457
// 0046244d  b857000780           mov eax, 0x80070057
// 00462452  5e                   pop esi
// 00462453  83c410               add esp, 0x10
// 00462456  c3                   ret 
// 00462457  b901000000           mov ecx, 1
// 0046245c  89442404             mov dword ptr [esp + 4], eax
// 00462460  0fb700               movzx eax, word ptr [eax]
// 00462463  894c240c             mov dword ptr [esp + 0xc], ecx
// 00462467  894c2410             mov dword ptr [esp + 0x10], ecx
// 0046246b  8d4c2420             lea ecx, [esp + 0x20]
// 0046246f  57                   push edi
// 00462470  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00462474  c7442424fdffffff     mov dword ptr [esp + 0x24], 0xfffffffd
// 0046247c  894c240c             mov dword ptr [esp + 0xc], ecx
// 00462480  6683f80d             cmp ax, 0xd
// 00462484  740d                 je 0x462493
// 00462486  6683f809             cmp ax, 9
// 0046248a  7407                 je 0x462493
// 0046248c  a900600000           test eax, 0x6000
// 00462491  7424                 je 0x4624b7
// 00462493  8b16                 mov edx, dword ptr [esi]
// 00462495  8b4a18               mov ecx, dword ptr [edx + 0x18]
// 00462498  6a00                 push 0
// 0046249a  6a00                 push 0
// 0046249c  6a00                 push 0
// 0046249e  8d442414             lea eax, [esp + 0x14]
// 004624a2  50                   push eax
// 004624a3  6a08                 push 8
// 004624a5  6800040000           push 0x400
// 004624aa  688816ac00           push 0xac1688
// 004624af  57                   push edi
// 004624b0  56                   push esi
// 004624b1  ffd1                 call ecx
// 004624b3  85c0                 test eax, eax
// 004624b5  7d20                 jge 0x4624d7
// 004624b7  8b16                 mov edx, dword ptr [esi]
// 004624b9  8b4a18               mov ecx, dword ptr [edx + 0x18]
// 004624bc  6a00                 push 0
// 004624be  6a00                 push 0
// 004624c0  6a00                 push 0
// 004624c2  8d442414             lea eax, [esp + 0x14]
// 004624c6  50                   push eax
// 004624c7  6a04                 push 4
// 004624c9  6800040000           push 0x400
// 004624ce  688816ac00           push 0xac1688
// 004624d3  57                   push edi
// 004624d4  56                   push esi
// 004624d5  ffd1                 call ecx
// 004624d7  5f                   pop edi
// 004624d8  5e                   pop esi
// 004624d9  83c410               add esp, 0x10
// 004624dc  c3                   ret 
// library atl-9.0/atl.cpp (function ?PutProperty@?$CComPtr@UIDispatch@@@ATL@@SAJPAUIDispatch@@JPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
