// from server: 100% by auto
// roc 2011-06 00459510  unit: CRobloxApp  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00459510
//
// 00459510  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00459514  33c9                 xor ecx, ecx
// 00459516  83ec10               sub esp, 0x10
// 00459519  3bd1                 cmp edx, ecx
// 0045951b  7509                 jne 0x459526
// 0045951d  b803400080           mov eax, 0x80004003
// 00459522  83c410               add esp, 0x10
// 00459525  c3                   ret 
// 00459526  8b442414             mov eax, dword ptr [esp + 0x14]
// 0045952a  3bc1                 cmp eax, ecx
// 0045952c  7509                 jne 0x459537
// 0045952e  b857000780           mov eax, 0x80070057
// 00459533  83c410               add esp, 0x10
// 00459536  c3                   ret 
// 00459537  56                   push esi
// 00459538  8b30                 mov esi, dword ptr [eax]
// 0045953a  51                   push ecx
// 0045953b  51                   push ecx
// 0045953c  52                   push edx
// 0045953d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00459541  894c2410             mov dword ptr [esp + 0x10], ecx
// 00459545  894c2414             mov dword ptr [esp + 0x14], ecx
// 00459549  894c2418             mov dword ptr [esp + 0x18], ecx
// 0045954d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00459551  8d4c2410             lea ecx, [esp + 0x10]
// 00459555  51                   push ecx
// 00459556  6a02                 push 2
// 00459558  6800040000           push 0x400
// 0045955d  688816ac00           push 0xac1688
// 00459562  52                   push edx
// 00459563  50                   push eax
// 00459564  8b4618               mov eax, dword ptr [esi + 0x18]
// 00459567  ffd0                 call eax
// 00459569  5e                   pop esi
// 0045956a  83c410               add esp, 0x10
// 0045956d  c3                   ret 
// library atl-8.0/atl.cpp (function ?GetProperty@?$CComPtr@UIDispatch@@@ATL@@SAJPAUIDispatch@@JPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
