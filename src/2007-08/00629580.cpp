// from server: 100% by auto
// roc 2007-08 00629580  unit: RBX::AssemblyStage  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00629580
//
// 00629580  53                   push ebx
// 00629581  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00629585  56                   push esi
// 00629586  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0062958a  57                   push edi
// 0062958b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0062958f  8b07                 mov eax, dword ptr [edi]
// 00629591  83c0fa               add eax, -6
// 00629594  83f803               cmp eax, 3
// 00629597  0f87a0000000         ja 0x62963d
// 0062959d  ff248560966200       jmp dword ptr [eax*4 + 0x629660]
// 006295a4  8bc3                 mov eax, ebx
// 006295a6  83380c               cmp dword ptr [eax], 0xc
// 006295a9  8bce                 mov ecx, esi
// 006295ab  7517                 jne 0x6295c4
// 006295ad  8b5008               mov edx, dword ptr [eax + 8]
// 006295b0  f7c200010000         test edx, 0x100
// 006295b6  750c                 jne 0x6295c4
// 006295b8  0fb67132             movzx esi, byte ptr [ecx + 0x32]
// 006295bc  3bd6                 cmp edx, esi
// 006295be  7c04                 jl 0x6295c4
// 006295c0  834124ff             add dword ptr [ecx + 0x24], -1
// 006295c4  8b5708               mov edx, dword ptr [edi + 8]
// 006295c7  52                   push edx
// 006295c8  e8a3fcffff           call 0x629270
// 006295cd  83c404               add esp, 4
// 006295d0  5f                   pop edi
// 006295d1  5e                   pop esi
// 006295d2  5b                   pop ebx
// 006295d3  c3                   ret 
// 006295d4  53                   push ebx
// 006295d5  56                   push esi
// 006295d6  e835feffff           call 0x629410
// 006295db  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006295de  8b5108               mov edx, dword ptr [ecx + 8]
// 006295e1  8b4f08               mov ecx, dword ptr [edi + 8]
// 006295e4  c1e111               shl ecx, 0x11
// 006295e7  0bc8                 or ecx, eax
// 006295e9  c1e106               shl ecx, 6
// 006295ec  52                   push edx
// 006295ed  83c908               or ecx, 8
// 006295f0  51                   push ecx
// 006295f1  e8eaf6ffff           call 0x628ce0
// 006295f6  83c410               add esp, 0x10
// 006295f9  eb42                 jmp 0x62963d
// 006295fb  53                   push ebx
// 006295fc  56                   push esi
// 006295fd  e80efeffff           call 0x629410
// 00629602  8b560c               mov edx, dword ptr [esi + 0xc]
// 00629605  8b4a08               mov ecx, dword ptr [edx + 8]
// 00629608  8b5708               mov edx, dword ptr [edi + 8]
// 0062960b  c1e208               shl edx, 8
// 0062960e  0bd0                 or edx, eax
// 00629610  c1e206               shl edx, 6
// 00629613  51                   push ecx
// 00629614  83ca07               or edx, 7
// 00629617  52                   push edx
// 00629618  e8c3f6ffff           call 0x628ce0
// 0062961d  83c410               add esp, 0x10
// 00629620  eb1b                 jmp 0x62963d
// 00629622  53                   push ebx
// 00629623  56                   push esi
// 00629624  e857feffff           call 0x629480
// 00629629  8b4f08               mov ecx, dword ptr [edi + 8]
// 0062962c  50                   push eax
// 0062962d  8b470c               mov eax, dword ptr [edi + 0xc]
// 00629630  50                   push eax
// 00629631  51                   push ecx
// 00629632  6a09                 push 9
// 00629634  56                   push esi
// 00629635  e846f7ffff           call 0x628d80
// 0062963a  83c41c               add esp, 0x1c
// 0062963d  833b0c               cmp dword ptr [ebx], 0xc
// 00629640  7517                 jne 0x629659
// 00629642  8b5b08               mov ebx, dword ptr [ebx + 8]
// 00629645  f7c300010000         test ebx, 0x100
// 0062964b  750c                 jne 0x629659
// 0062964d  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 00629651  3bda                 cmp ebx, edx
// 00629653  7c04                 jl 0x629659
// 00629655  834624ff             add dword ptr [esi + 0x24], -1
// 00629659  5f                   pop edi
// 0062965a  5e                   pop esi
// 0062965b  5b                   pop ebx
// 0062965c  c3                   ret 
// 0062965d  8d4900               lea ecx, [ecx]
// 00629660  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 00629661  95                   xchg ebp, eax
// 00629662  6200                 bound eax, qword ptr [eax]
// 00629664  d495                 aam 0x95
// 00629666  6200                 bound eax, qword ptr [eax]
// 00629668  fb                   sti 
// 00629669  95                   xchg ebp, eax
// 0062966a  6200                 bound eax, qword ptr [eax]
// library lua-5.1/lcode.c (function _luaK_storevar)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
