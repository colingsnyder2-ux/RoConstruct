// from server: 100% by auto
// roc 2009-06 00785700  unit: CXTPToolTipContextToolTip  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00785700
//
// 00785700  83ec18               sub esp, 0x18
// 00785703  56                   push esi
// 00785704  8d44240c             lea eax, [esp + 0xc]
// 00785708  57                   push edi
// 00785709  50                   push eax
// 0078570a  e891c2fdff           call 0x7619a0
// 0078570f  8bc8                 mov ecx, eax
// 00785711  e85abefdff           call 0x761570
// 00785716  8b742424             mov esi, dword ptr [esp + 0x24]
// 0078571a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0078571e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00785721  8b3df8ed8900         mov edi, dword ptr [0x89edf8]
// 00785727  8d50fc               lea edx, [eax - 4]
// 0078572a  3bd1                 cmp edx, ecx
// 0078572c  7d0b                 jge 0x785739
// 0078572e  2bc1                 sub eax, ecx
// 00785730  6a00                 push 0
// 00785732  83e804               sub eax, 4
// 00785735  50                   push eax
// 00785736  56                   push esi
// 00785737  ffd7                 call edi
// 00785739  8b0e                 mov ecx, dword ptr [esi]
// 0078573b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0078573f  3bc1                 cmp eax, ecx
// 00785741  7e08                 jle 0x78574b
// 00785743  6a00                 push 0
// 00785745  2bc1                 sub eax, ecx
// 00785747  50                   push eax
// 00785748  56                   push esi
// 00785749  ffd7                 call edi
// 0078574b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0078574f  83c0fc               add eax, -4
// 00785752  3b460c               cmp eax, dword ptr [esi + 0xc]
// 00785755  7d1b                 jge 0x785772
// 00785757  8d4c2408             lea ecx, [esp + 8]
// 0078575b  51                   push ecx
// 0078575c  ff152cee8900         call dword ptr [0x89ee2c]
// 00785762  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00785766  2b560c               sub edx, dword ptr [esi + 0xc]
// 00785769  83ea03               sub edx, 3
// 0078576c  52                   push edx
// 0078576d  6a00                 push 0
// 0078576f  56                   push esi
// 00785770  ffd7                 call edi
// 00785772  5f                   pop edi
// 00785773  5e                   pop esi
// 00785774  83c418               add esp, 0x18
// 00785777  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?EnsureVisible@CXTPToolTipContextToolTip@@IAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
