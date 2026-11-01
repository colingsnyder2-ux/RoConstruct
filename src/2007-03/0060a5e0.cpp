// from server: 100% by auto
// roc 2007-03 0060a5e0  unit: seg_00600000  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0060a5e0
//
// 0060a5e0  83ec0c               sub esp, 0xc
// 0060a5e3  55                   push ebp
// 0060a5e4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0060a5e8  56                   push esi
// 0060a5e9  57                   push edi
// 0060a5ea  8bf9                 mov edi, ecx
// 0060a5ec  8b7704               mov esi, dword ptr [edi + 4]
// 0060a5ef  8b4604               mov eax, dword ptr [esi + 4]
// 0060a5f2  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060a5f6  b101                 mov cl, 1
// 0060a5f8  884c240c             mov byte ptr [esp + 0xc], cl
// 0060a5fc  7520                 jne 0x60a61e
// 0060a5fe  8b5500               mov edx, dword ptr [ebp]
// 0060a601  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0060a604  8bf0                 mov esi, eax
// 0060a606  0f92c1               setb cl
// 0060a609  84c9                 test cl, cl
// 0060a60b  884c240c             mov byte ptr [esp + 0xc], cl
// 0060a60f  7404                 je 0x60a615
// 0060a611  8b00                 mov eax, dword ptr [eax]
// 0060a613  eb03                 jmp 0x60a618
// 0060a615  8b4008               mov eax, dword ptr [eax + 8]
// 0060a618  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0060a61c  74e3                 je 0x60a601
// 0060a61e  84c9                 test cl, cl
// 0060a620  8bd6                 mov edx, esi
// 0060a622  89542414             mov dword ptr [esp + 0x14], edx
// 0060a626  897c2410             mov dword ptr [esp + 0x10], edi
// 0060a62a  743d                 je 0x60a669
// 0060a62c  8b4704               mov eax, dword ptr [edi + 4]
// 0060a62f  3b30                 cmp esi, dword ptr [eax]
// 0060a631  8d4c2410             lea ecx, [esp + 0x10]
// 0060a635  7529                 jne 0x60a660
// 0060a637  55                   push ebp
// 0060a638  56                   push esi
// 0060a639  6a01                 push 1
// 0060a63b  51                   push ecx
// 0060a63c  8bcf                 mov ecx, edi
// 0060a63e  e8bdf7ffff           call 0x609e00
// 0060a643  8bc8                 mov ecx, eax
// 0060a645  8b11                 mov edx, dword ptr [ecx]
// 0060a647  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060a64b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0060a64e  5f                   pop edi
// 0060a64f  5e                   pop esi
// 0060a650  8910                 mov dword ptr [eax], edx
// 0060a652  894804               mov dword ptr [eax + 4], ecx
// 0060a655  c6400801             mov byte ptr [eax + 8], 1
// 0060a659  5d                   pop ebp
// 0060a65a  83c40c               add esp, 0xc
// 0060a65d  c20800               ret 8
// 0060a660  e80bb2feff           call 0x5f5870
// 0060a665  8b542414             mov edx, dword ptr [esp + 0x14]
// 0060a669  8b420c               mov eax, dword ptr [edx + 0xc]
// 0060a66c  3b4500               cmp eax, dword ptr [ebp]
// 0060a66f  730e                 jae 0x60a67f
// 0060a671  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0060a675  55                   push ebp
// 0060a676  56                   push esi
// 0060a677  51                   push ecx
// 0060a678  8d54241c             lea edx, [esp + 0x1c]
// 0060a67c  52                   push edx
// 0060a67d  ebbd                 jmp 0x60a63c
// 0060a67f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060a683  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060a687  5f                   pop edi
// 0060a688  5e                   pop esi
// 0060a689  8908                 mov dword ptr [eax], ecx
// 0060a68b  895004               mov dword ptr [eax + 4], edx
// 0060a68e  c6400800             mov byte ptr [eax + 8], 0
// 0060a692  5d                   pop ebp
// 0060a693  83c40c               add esp, 0xc
// 0060a696  c20800               ret 8
// library templates-boost-1_34_1/map_ptr_pod12.cpp (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_ptr_pod12.cpp
