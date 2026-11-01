// from server: 100% by auto
// roc 2007-03 004405b0  unit: seg_00440000  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004405b0
//
// 004405b0  83ec0c               sub esp, 0xc
// 004405b3  55                   push ebp
// 004405b4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004405b8  56                   push esi
// 004405b9  57                   push edi
// 004405ba  8bf9                 mov edi, ecx
// 004405bc  8b7704               mov esi, dword ptr [edi + 4]
// 004405bf  8b4604               mov eax, dword ptr [esi + 4]
// 004405c2  80782100             cmp byte ptr [eax + 0x21], 0
// 004405c6  b101                 mov cl, 1
// 004405c8  884c240c             mov byte ptr [esp + 0xc], cl
// 004405cc  7520                 jne 0x4405ee
// 004405ce  8b5500               mov edx, dword ptr [ebp]
// 004405d1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004405d4  8bf0                 mov esi, eax
// 004405d6  0f92c1               setb cl
// 004405d9  84c9                 test cl, cl
// 004405db  884c240c             mov byte ptr [esp + 0xc], cl
// 004405df  7404                 je 0x4405e5
// 004405e1  8b00                 mov eax, dword ptr [eax]
// 004405e3  eb03                 jmp 0x4405e8
// 004405e5  8b4008               mov eax, dword ptr [eax + 8]
// 004405e8  80782100             cmp byte ptr [eax + 0x21], 0
// 004405ec  74e3                 je 0x4405d1
// 004405ee  84c9                 test cl, cl
// 004405f0  8bd6                 mov edx, esi
// 004405f2  89542414             mov dword ptr [esp + 0x14], edx
// 004405f6  897c2410             mov dword ptr [esp + 0x10], edi
// 004405fa  743d                 je 0x440639
// 004405fc  8b4704               mov eax, dword ptr [edi + 4]
// 004405ff  3b30                 cmp esi, dword ptr [eax]
// 00440601  8d4c2410             lea ecx, [esp + 0x10]
// 00440605  7529                 jne 0x440630
// 00440607  55                   push ebp
// 00440608  56                   push esi
// 00440609  6a01                 push 1
// 0044060b  51                   push ecx
// 0044060c  8bcf                 mov ecx, edi
// 0044060e  e86de8ffff           call 0x43ee80
// 00440613  8bc8                 mov ecx, eax
// 00440615  8b11                 mov edx, dword ptr [ecx]
// 00440617  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044061b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044061e  5f                   pop edi
// 0044061f  5e                   pop esi
// 00440620  8910                 mov dword ptr [eax], edx
// 00440622  894804               mov dword ptr [eax + 4], ecx
// 00440625  c6400801             mov byte ptr [eax + 8], 1
// 00440629  5d                   pop ebp
// 0044062a  83c40c               add esp, 0xc
// 0044062d  c20800               ret 8
// 00440630  e87b460800           call 0x4c4cb0
// 00440635  8b542414             mov edx, dword ptr [esp + 0x14]
// 00440639  8b420c               mov eax, dword ptr [edx + 0xc]
// 0044063c  3b4500               cmp eax, dword ptr [ebp]
// 0044063f  730e                 jae 0x44064f
// 00440641  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00440645  55                   push ebp
// 00440646  56                   push esi
// 00440647  51                   push ecx
// 00440648  8d54241c             lea edx, [esp + 0x1c]
// 0044064c  52                   push edx
// 0044064d  ebbd                 jmp 0x44060c
// 0044064f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00440653  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00440657  5f                   pop edi
// 00440658  5e                   pop esi
// 00440659  8908                 mov dword ptr [eax], ecx
// 0044065b  895004               mov dword ptr [eax + 4], edx
// 0044065e  c6400800             mov byte ptr [eax + 8], 0
// 00440662  5d                   pop ebp
// 00440663  83c40c               add esp, 0xc
// 00440666  c20800               ret 8
// library templates-boost-1_34_1/map_ptr_pod16.cpp (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_ptr_pod16.cpp
