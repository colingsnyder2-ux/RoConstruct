// from server: 100% by auto
// roc 2007-03 006092d0  unit: seg_00600000  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006092d0
//
// 006092d0  83ec0c               sub esp, 0xc
// 006092d3  55                   push ebp
// 006092d4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006092d8  56                   push esi
// 006092d9  57                   push edi
// 006092da  8bf9                 mov edi, ecx
// 006092dc  8b7704               mov esi, dword ptr [edi + 4]
// 006092df  8b4604               mov eax, dword ptr [esi + 4]
// 006092e2  80782100             cmp byte ptr [eax + 0x21], 0
// 006092e6  b101                 mov cl, 1
// 006092e8  884c240c             mov byte ptr [esp + 0xc], cl
// 006092ec  7520                 jne 0x60930e
// 006092ee  8b5500               mov edx, dword ptr [ebp]
// 006092f1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006092f4  8bf0                 mov esi, eax
// 006092f6  0f92c1               setb cl
// 006092f9  84c9                 test cl, cl
// 006092fb  884c240c             mov byte ptr [esp + 0xc], cl
// 006092ff  7404                 je 0x609305
// 00609301  8b00                 mov eax, dword ptr [eax]
// 00609303  eb03                 jmp 0x609308
// 00609305  8b4008               mov eax, dword ptr [eax + 8]
// 00609308  80782100             cmp byte ptr [eax + 0x21], 0
// 0060930c  74e3                 je 0x6092f1
// 0060930e  84c9                 test cl, cl
// 00609310  8bd6                 mov edx, esi
// 00609312  89542414             mov dword ptr [esp + 0x14], edx
// 00609316  897c2410             mov dword ptr [esp + 0x10], edi
// 0060931a  743d                 je 0x609359
// 0060931c  8b4704               mov eax, dword ptr [edi + 4]
// 0060931f  3b30                 cmp esi, dword ptr [eax]
// 00609321  8d4c2410             lea ecx, [esp + 0x10]
// 00609325  7529                 jne 0x609350
// 00609327  55                   push ebp
// 00609328  56                   push esi
// 00609329  6a01                 push 1
// 0060932b  51                   push ecx
// 0060932c  8bcf                 mov ecx, edi
// 0060932e  e8adfcffff           call 0x608fe0
// 00609333  8bc8                 mov ecx, eax
// 00609335  8b11                 mov edx, dword ptr [ecx]
// 00609337  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060933b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0060933e  5f                   pop edi
// 0060933f  5e                   pop esi
// 00609340  8910                 mov dword ptr [eax], edx
// 00609342  894804               mov dword ptr [eax + 4], ecx
// 00609345  c6400801             mov byte ptr [eax + 8], 1
// 00609349  5d                   pop ebp
// 0060934a  83c40c               add esp, 0xc
// 0060934d  c20800               ret 8
// 00609350  e85bb9ebff           call 0x4c4cb0
// 00609355  8b542414             mov edx, dword ptr [esp + 0x14]
// 00609359  8b420c               mov eax, dword ptr [edx + 0xc]
// 0060935c  3b4500               cmp eax, dword ptr [ebp]
// 0060935f  730e                 jae 0x60936f
// 00609361  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00609365  55                   push ebp
// 00609366  56                   push esi
// 00609367  51                   push ecx
// 00609368  8d54241c             lea edx, [esp + 0x1c]
// 0060936c  52                   push edx
// 0060936d  ebbd                 jmp 0x60932c
// 0060936f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00609373  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00609377  5f                   pop edi
// 00609378  5e                   pop esi
// 00609379  8908                 mov dword ptr [eax], ecx
// 0060937b  895004               mov dword ptr [eax + 4], edx
// 0060937e  c6400800             mov byte ptr [eax + 8], 0
// 00609382  5d                   pop ebp
// 00609383  83c40c               add esp, 0xc
// 00609386  c20800               ret 8
// library templates-boost-1_34_1/map_ptr_pod16.cpp (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_ptr_pod16.cpp
