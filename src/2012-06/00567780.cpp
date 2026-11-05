// roc 2012-06 00567780  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567780
//
// 00567780  53                   push ebx
// 00567781  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00567785  56                   push esi
// 00567786  8bf1                 mov esi, ecx
// 00567788  85db                 test ebx, ebx
// 0056778a  7707                 ja 0x567793
// 0056778c  5e                   pop esi
// 0056778d  32c0                 xor al, al
// 0056778f  5b                   pop ebx
// 00567790  c20c00               ret 0xc
// 00567793  8b4608               mov eax, dword ptr [esi + 8]
// 00567796  8d0c18               lea ecx, [eax + ebx]
// 00567799  3b0e                 cmp ecx, dword ptr [esi]
// 0056779b  77ef                 ja 0x56778c
// 0056779d  8bc8                 mov ecx, eax
// 0056779f  83e107               and ecx, 7
// 005677a2  894c2410             mov dword ptr [esp + 0x10], ecx
// 005677a6  7529                 jne 0x5677d1
// 005677a8  f6c307               test bl, 7
// 005677ab  7524                 jne 0x5677d1
// 005677ad  c1e803               shr eax, 3
// 005677b0  03460c               add eax, dword ptr [esi + 0xc]
// 005677b3  8bd3                 mov edx, ebx
// 005677b5  c1ea03               shr edx, 3
// 005677b8  52                   push edx
// 005677b9  50                   push eax
// 005677ba  8b442414             mov eax, dword ptr [esp + 0x14]
// 005677be  50                   push eax
// 005677bf  e898be4100           call 0x98365c
// 005677c4  83c40c               add esp, 0xc
// 005677c7  015e08               add dword ptr [esi + 8], ebx
// 005677ca  5e                   pop esi
// 005677cb  b001                 mov al, 1
// 005677cd  5b                   pop ebx
// 005677ce  c20c00               ret 0xc
// 005677d1  55                   push ebp
// 005677d2  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005677d6  57                   push edi
// 005677d7  8d4b07               lea ecx, [ebx + 7]
// 005677da  c1e903               shr ecx, 3
// 005677dd  51                   push ecx
// 005677de  33ff                 xor edi, edi
// 005677e0  57                   push edi
// 005677e1  55                   push ebp
// 005677e2  e88dbb4100           call 0x983374
// 005677e7  83c40c               add esp, 0xc
// 005677ea  8d9b00000000         lea ebx, [ebx]
// 005677f0  8b5608               mov edx, dword ptr [esi + 8]
// 005677f3  8b460c               mov eax, dword ptr [esi + 0xc]
// 005677f6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005677fa  c1ea03               shr edx, 3
// 005677fd  8a1402               mov dl, byte ptr [edx + eax]
// 00567800  d2e2                 shl dl, cl
// 00567802  08142f               or byte ptr [edi + ebp], dl
// 00567805  85c9                 test ecx, ecx
// 00567807  7622                 jbe 0x56782b
// 00567809  b808000000           mov eax, 8
// 0056780e  2bc1                 sub eax, ecx
// 00567810  3bd8                 cmp ebx, eax
// 00567812  7617                 jbe 0x56782b
// 00567814  8b4e08               mov ecx, dword ptr [esi + 8]
// 00567817  8b560c               mov edx, dword ptr [esi + 0xc]
// 0056781a  c1e903               shr ecx, 3
// 0056781d  8a541101             mov dl, byte ptr [ecx + edx + 1]
// 00567821  8ac8                 mov cl, al
// 00567823  d2ea                 shr dl, cl
// 00567825  0a142f               or dl, byte ptr [edi + ebp]
// 00567828  88142f               mov byte ptr [edi + ebp], dl
// 0056782b  b808000000           mov eax, 8
// 00567830  3bd8                 cmp ebx, eax
// 00567832  7213                 jb 0x567847
// 00567834  014608               add dword ptr [esi + 8], eax
// 00567837  2bd8                 sub ebx, eax
// 00567839  47                   inc edi
// 0056783a  85db                 test ebx, ebx
// 0056783c  77b2                 ja 0x5677f0
// 0056783e  5f                   pop edi
// 0056783f  5d                   pop ebp
// 00567840  5e                   pop esi
// 00567841  b001                 mov al, 1
// 00567843  5b                   pop ebx
// 00567844  c20c00               ret 0xc
// 00567847  83c3f8               add ebx, -8
// 0056784a  791c                 jns 0x567868
// 0056784c  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 00567851  7407                 je 0x56785a
// 00567853  8acb                 mov cl, bl
// 00567855  f6d9                 neg cl
// 00567857  d22c2f               shr byte ptr [edi + ebp], cl
// 0056785a  5f                   pop edi
// 0056785b  03d8                 add ebx, eax
// 0056785d  015e08               add dword ptr [esi + 8], ebx
// 00567860  5d                   pop ebp
// 00567861  5e                   pop esi
// 00567862  b001                 mov al, 1
// 00567864  5b                   pop ebx
// 00567865  c20c00               ret 0xc
// 00567868  014608               add dword ptr [esi + 8], eax
// 0056786b  5f                   pop edi
// 0056786c  5d                   pop ebp
// 0056786d  5e                   pop esi
// 0056786e  b001                 mov al, 1
// 00567870  5b                   pop ebx
// 00567871  c20c00               ret 0xc
// copied from an identical function in another client (function ?ReadBits@BitStream@RakNet@@QAE_NPAEI_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp