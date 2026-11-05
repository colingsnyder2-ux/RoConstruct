// from server: 100% by auto
// roc 2008-06 0041d570  unit: VDHTMLWindow::?$SignalDesc  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041d570
//
// 0041d570  8b542404             mov edx, dword ptr [esp + 4]
// 0041d574  83ec08               sub esp, 8
// 0041d577  53                   push ebx
// 0041d578  8bd9                 mov ebx, ecx
// 0041d57a  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041d57d  b949922409           mov ecx, 0x9249249
// 0041d582  2bc8                 sub ecx, eax
// 0041d584  3bca                 cmp ecx, edx
// 0041d586  7305                 jae 0x41d58d
// 0041d588  e883940f00           call 0x516a10
// 0041d58d  8bc8                 mov ecx, eax
// 0041d58f  d1e9                 shr ecx, 1
// 0041d591  83f908               cmp ecx, 8
// 0041d594  7305                 jae 0x41d59b
// 0041d596  b908000000           mov ecx, 8
// 0041d59b  55                   push ebp
// 0041d59c  56                   push esi
// 0041d59d  57                   push edi
// 0041d59e  3bd1                 cmp edx, ecx
// 0041d5a0  7311                 jae 0x41d5b3
// 0041d5a2  be49922409           mov esi, 0x9249249
// 0041d5a7  2bf1                 sub esi, ecx
// 0041d5a9  3bc6                 cmp eax, esi
// 0041d5ab  7706                 ja 0x41d5b3
// 0041d5ad  8bd1                 mov edx, ecx
// 0041d5af  8954241c             mov dword ptr [esp + 0x1c], edx
// 0041d5b3  8b7318               mov esi, dword ptr [ebx + 0x18]
// 0041d5b6  03c2                 add eax, edx
// 0041d5b8  6a00                 push 0
// 0041d5ba  50                   push eax
// 0041d5bb  89742418             mov dword ptr [esp + 0x18], esi
// 0041d5bf  e88c350000           call 0x420b50
// 0041d5c4  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041d5c7  8944241c             mov dword ptr [esp + 0x1c], eax
// 0041d5cb  03f6                 add esi, esi
// 0041d5cd  03f6                 add esi, esi
// 0041d5cf  8d3c06               lea edi, [esi + eax]
// 0041d5d2  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0041d5d5  03c0                 add eax, eax
// 0041d5d7  03c0                 add eax, eax
// 0041d5d9  8d140e               lea edx, [esi + ecx]
// 0041d5dc  2bc2                 sub eax, edx
// 0041d5de  03c1                 add eax, ecx
// 0041d5e0  c1f802               sar eax, 2
// 0041d5e3  83c408               add esp, 8
// 0041d5e6  8d0c8500000000       lea ecx, [eax*4]
// 0041d5ed  8d2c39               lea ebp, [ecx + edi]
// 0041d5f0  85c0                 test eax, eax
// 0041d5f2  760d                 jbe 0x41d601
// 0041d5f4  51                   push ecx
// 0041d5f5  52                   push edx
// 0041d5f6  51                   push ecx
// 0041d5f7  57                   push edi
// 0041d5f8  ff1550288000         call dword ptr [0x802850]
// 0041d5fe  83c410               add esp, 0x10
// 0041d601  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041d605  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041d609  3bd0                 cmp edx, eax
// 0041d60b  7743                 ja 0x41d650
// 0041d60d  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041d610  c1fe02               sar esi, 2
// 0041d613  8d0cb500000000       lea ecx, [esi*4]
// 0041d61a  8d3c29               lea edi, [ecx + ebp]
// 0041d61d  85f6                 test esi, esi
// 0041d61f  7611                 jbe 0x41d632
// 0041d621  51                   push ecx
// 0041d622  50                   push eax
// 0041d623  51                   push ecx
// 0041d624  55                   push ebp
// 0041d625  ff1550288000         call dword ptr [0x802850]
// 0041d62b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0041d62f  83c410               add esp, 0x10
// 0041d632  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041d636  2bca                 sub ecx, edx
// 0041d638  7408                 je 0x41d642
// 0041d63a  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041d63e  33c0                 xor eax, eax
// 0041d640  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041d642  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041d646  85d2                 test edx, edx
// 0041d648  7662                 jbe 0x41d6ac
// 0041d64a  8bca                 mov ecx, edx
// 0041d64c  8bfd                 mov edi, ebp
// 0041d64e  eb58                 jmp 0x41d6a8
// 0041d650  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0041d653  8d3c8500000000       lea edi, [eax*4]
// 0041d65a  8bc7                 mov eax, edi
// 0041d65c  c1f802               sar eax, 2
// 0041d65f  85c0                 test eax, eax
// 0041d661  7611                 jbe 0x41d674
// 0041d663  03c0                 add eax, eax
// 0041d665  03c0                 add eax, eax
// 0041d667  50                   push eax
// 0041d668  51                   push ecx
// 0041d669  50                   push eax
// 0041d66a  55                   push ebp
// 0041d66b  ff1550288000         call dword ptr [0x802850]
// 0041d671  83c410               add esp, 0x10
// 0041d674  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041d677  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0041d67b  8d0c07               lea ecx, [edi + eax]
// 0041d67e  2bf1                 sub esi, ecx
// 0041d680  03f0                 add esi, eax
// 0041d682  c1fe02               sar esi, 2
// 0041d685  8d04b500000000       lea eax, [esi*4]
// 0041d68c  8d3c28               lea edi, [eax + ebp]
// 0041d68f  85f6                 test esi, esi
// 0041d691  760d                 jbe 0x41d6a0
// 0041d693  50                   push eax
// 0041d694  51                   push ecx
// 0041d695  50                   push eax
// 0041d696  55                   push ebp
// 0041d697  ff1550288000         call dword ptr [0x802850]
// 0041d69d  83c410               add esp, 0x10
// 0041d6a0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0041d6a4  85c9                 test ecx, ecx
// 0041d6a6  7604                 jbe 0x41d6ac
// 0041d6a8  33c0                 xor eax, eax
// 0041d6aa  f3ab                 rep stosd dword ptr es:[edi], eax
// 0041d6ac  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0041d6af  85c0                 test eax, eax
// 0041d6b1  7409                 je 0x41d6bc
// 0041d6b3  50                   push eax
// 0041d6b4  e8c12f2800           call 0x6a067a
// 0041d6b9  83c404               add esp, 4
// 0041d6bc  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041d6c0  015314               add dword ptr [ebx + 0x14], edx
// 0041d6c3  5f                   pop edi
// 0041d6c4  5e                   pop esi
// 0041d6c5  896b10               mov dword ptr [ebx + 0x10], ebp
// 0041d6c8  5d                   pop ebp
// 0041d6c9  5b                   pop ebx
// 0041d6ca  83c408               add esp, 8
// 0041d6cd  c20400               ret 4
// standard library deque<string> (function ?_Growmap@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
