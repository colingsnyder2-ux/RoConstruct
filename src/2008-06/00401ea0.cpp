// from server: 100% by auto
// roc 2008-06 00401ea0  unit: VCWorkspace::?$CComObject  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401ea0
//
// 00401ea0  f605acc2960001       test byte ptr [0x96c2ac], 1
// 00401ea7  755d                 jne 0x401f06
// 00401ea9  830dacc2960001       or dword ptr [0x96c2ac], 1
// 00401eb0  b808000000           mov eax, 8
// 00401eb5  66a390c29600         mov word ptr [0x96c290], ax
// 00401ebb  b908400000           mov ecx, 0x4008
// 00401ec0  ba13000000           mov edx, 0x13
// 00401ec5  b811000000           mov eax, 0x11
// 00401eca  c7058cc2960098ad8000 mov dword ptr [0x96c28c], 0x80ad98
// 00401ed4  c70594c2960094ad8000 mov dword ptr [0x96c294], 0x80ad94
// 00401ede  66890d98c29600       mov word ptr [0x96c298], cx
// 00401ee5  c7059cc2960090ad8000 mov dword ptr [0x96c29c], 0x80ad90
// 00401eef  668915a0c29600       mov word ptr [0x96c2a0], dx
// 00401ef6  c705a4c296008cad8000 mov dword ptr [0x96c2a4], 0x80ad8c
// 00401f00  66a3a8c29600         mov word ptr [0x96c2a8], ax
// 00401f06  53                   push ebx
// 00401f07  8b1db4218000         mov ebx, dword ptr [0x8021b4]
// 00401f0d  56                   push esi
// 00401f0e  57                   push edi
// 00401f0f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00401f13  33f6                 xor esi, esi
// 00401f15  8b0cf58cc29600       mov ecx, dword ptr [esi*8 + 0x96c28c]
// 00401f1c  51                   push ecx
// 00401f1d  57                   push edi
// 00401f1e  ffd3                 call ebx
// 00401f20  85c0                 test eax, eax
// 00401f22  740c                 je 0x401f30
// 00401f24  46                   inc esi
// 00401f25  83fe04               cmp esi, 4
// 00401f28  72eb                 jb 0x401f15
// 00401f2a  5f                   pop edi
// 00401f2b  5e                   pop esi
// 00401f2c  33c0                 xor eax, eax
// 00401f2e  5b                   pop ebx
// 00401f2f  c3                   ret 
// 00401f30  668b14f590c29600     mov dx, word ptr [esi*8 + 0x96c290]
// 00401f38  8b442414             mov eax, dword ptr [esp + 0x14]
// 00401f3c  5f                   pop edi
// 00401f3d  5e                   pop esi
// 00401f3e  668910               mov word ptr [eax], dx
// 00401f41  b801000000           mov eax, 1
// 00401f46  5b                   pop ebx
// 00401f47  c3                   ret 
// library atl-9.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
