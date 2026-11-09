// from server: 100% by auto
// roc 2011-06 00403ad0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403ad0
//
// 00403ad0  f6054416cb0001       test byte ptr [0xcb1644], 1
// 00403ad7  755d                 jne 0x403b36
// 00403ad9  830d4416cb0001       or dword ptr [0xcb1644], 1
// 00403ae0  b808000000           mov eax, 8
// 00403ae5  66a32816cb00         mov word ptr [0xcb1628], ax
// 00403aeb  b908400000           mov ecx, 0x4008
// 00403af0  ba13000000           mov edx, 0x13
// 00403af5  b811000000           mov eax, 0x11
// 00403afa  c7052416cb00c8b7a500 mov dword ptr [0xcb1624], 0xa5b7c8
// 00403b04  c7052c16cb00c4b7a500 mov dword ptr [0xcb162c], 0xa5b7c4
// 00403b0e  66890d3016cb00       mov word ptr [0xcb1630], cx
// 00403b15  c7053416cb00c0b7a500 mov dword ptr [0xcb1634], 0xa5b7c0
// 00403b1f  6689153816cb00       mov word ptr [0xcb1638], dx
// 00403b26  c7053c16cb00bcb7a500 mov dword ptr [0xcb163c], 0xa5b7bc
// 00403b30  66a34016cb00         mov word ptr [0xcb1640], ax
// 00403b36  53                   push ebx
// 00403b37  8b1d5403a400         mov ebx, dword ptr [0xa40354]
// 00403b3d  56                   push esi
// 00403b3e  57                   push edi
// 00403b3f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00403b43  33f6                 xor esi, esi
// 00403b45  8b0cf52416cb00       mov ecx, dword ptr [esi*8 + 0xcb1624]
// 00403b4c  51                   push ecx
// 00403b4d  57                   push edi
// 00403b4e  ffd3                 call ebx
// 00403b50  85c0                 test eax, eax
// 00403b52  740c                 je 0x403b60
// 00403b54  46                   inc esi
// 00403b55  83fe04               cmp esi, 4
// 00403b58  72eb                 jb 0x403b45
// 00403b5a  5f                   pop edi
// 00403b5b  5e                   pop esi
// 00403b5c  33c0                 xor eax, eax
// 00403b5e  5b                   pop ebx
// 00403b5f  c3                   ret 
// 00403b60  668b14f52816cb00     mov dx, word ptr [esi*8 + 0xcb1628]
// 00403b68  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403b6c  5f                   pop edi
// 00403b6d  5e                   pop esi
// 00403b6e  668910               mov word ptr [eax], dx
// 00403b71  b801000000           mov eax, 1
// 00403b76  5b                   pop ebx
// 00403b77  c3                   ret 
// library atl-9.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
