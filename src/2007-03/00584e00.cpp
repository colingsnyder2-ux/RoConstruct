// from server: 100% by auto
// roc 2007-03 00584e00  unit: seg_00580000  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00584e00
//
// 00584e00  83ec0c               sub esp, 0xc
// 00584e03  55                   push ebp
// 00584e04  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00584e08  56                   push esi
// 00584e09  57                   push edi
// 00584e0a  8bf9                 mov edi, ecx
// 00584e0c  8b7704               mov esi, dword ptr [edi + 4]
// 00584e0f  8b4604               mov eax, dword ptr [esi + 4]
// 00584e12  80781900             cmp byte ptr [eax + 0x19], 0
// 00584e16  b101                 mov cl, 1
// 00584e18  884c240c             mov byte ptr [esp + 0xc], cl
// 00584e1c  7520                 jne 0x584e3e
// 00584e1e  8b5500               mov edx, dword ptr [ebp]
// 00584e21  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00584e24  8bf0                 mov esi, eax
// 00584e26  0f9cc1               setl cl
// 00584e29  84c9                 test cl, cl
// 00584e2b  884c240c             mov byte ptr [esp + 0xc], cl
// 00584e2f  7404                 je 0x584e35
// 00584e31  8b00                 mov eax, dword ptr [eax]
// 00584e33  eb03                 jmp 0x584e38
// 00584e35  8b4008               mov eax, dword ptr [eax + 8]
// 00584e38  80781900             cmp byte ptr [eax + 0x19], 0
// 00584e3c  74e3                 je 0x584e21
// 00584e3e  84c9                 test cl, cl
// 00584e40  8bd6                 mov edx, esi
// 00584e42  89542414             mov dword ptr [esp + 0x14], edx
// 00584e46  897c2410             mov dword ptr [esp + 0x10], edi
// 00584e4a  743d                 je 0x584e89
// 00584e4c  8b4704               mov eax, dword ptr [edi + 4]
// 00584e4f  3b30                 cmp esi, dword ptr [eax]
// 00584e51  8d4c2410             lea ecx, [esp + 0x10]
// 00584e55  7529                 jne 0x584e80
// 00584e57  55                   push ebp
// 00584e58  56                   push esi
// 00584e59  6a01                 push 1
// 00584e5b  51                   push ecx
// 00584e5c  8bcf                 mov ecx, edi
// 00584e5e  e8bdadfeff           call 0x56fc20
// 00584e63  8bc8                 mov ecx, eax
// 00584e65  8b11                 mov edx, dword ptr [ecx]
// 00584e67  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584e6b  8b4904               mov ecx, dword ptr [ecx + 4]
// 00584e6e  5f                   pop edi
// 00584e6f  5e                   pop esi
// 00584e70  8910                 mov dword ptr [eax], edx
// 00584e72  894804               mov dword ptr [eax + 4], ecx
// 00584e75  c6400801             mov byte ptr [eax + 8], 1
// 00584e79  5d                   pop ebp
// 00584e7a  83c40c               add esp, 0xc
// 00584e7d  c20800               ret 8
// 00584e80  e88bc00600           call 0x5f0f10
// 00584e85  8b542414             mov edx, dword ptr [esp + 0x14]
// 00584e89  8b420c               mov eax, dword ptr [edx + 0xc]
// 00584e8c  3b4500               cmp eax, dword ptr [ebp]
// 00584e8f  7d0e                 jge 0x584e9f
// 00584e91  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00584e95  55                   push ebp
// 00584e96  56                   push esi
// 00584e97  51                   push ecx
// 00584e98  8d54241c             lea edx, [esp + 0x1c]
// 00584e9c  52                   push edx
// 00584e9d  ebbd                 jmp 0x584e5c
// 00584e9f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584ea3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00584ea7  5f                   pop edi
// 00584ea8  5e                   pop esi
// 00584ea9  8908                 mov dword ptr [eax], ecx
// 00584eab  895004               mov dword ptr [eax + 4], edx
// 00584eae  c6400800             mov byte ptr [eax + 8], 0
// 00584eb2  5d                   pop ebp
// 00584eb3  83c40c               add esp, 0xc
// 00584eb6  c20800               ret 8
// library templates-boost-1_34_1/map_int_sp.cpp (function ?insert@?$_Tree@V?$_Tmap_traits@HV?$shared_ptr@UT@@@boost@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HV?$shared_ptr@UT@@@boost@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_int_sp.cpp
