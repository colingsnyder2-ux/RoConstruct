// roc 2012-06 005be860  unit: RakNet::RakPeer  size: 595 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005be860
//
// 005be860  6aff                 push -1
// 005be862  68d72aab00           push 0xab2ad7
// 005be867  64a100000000         mov eax, dword ptr fs:[0]
// 005be86d  50                   push eax
// 005be86e  64892500000000       mov dword ptr fs:[0], esp
// 005be875  81ec2c010000         sub esp, 0x12c
// 005be87b  53                   push ebx
// 005be87c  55                   push ebp
// 005be87d  56                   push esi
// 005be87e  8bd9                 mov ebx, ecx
// 005be880  57                   push edi
// 005be881  8d4c2428             lea ecx, [esp + 0x28]
// 005be885  e8168dfaff           call 0x5675a0
// 005be88a  6a01                 push 1
// 005be88c  6a08                 push 8
// 005be88e  8d442418             lea eax, [esp + 0x18]
// 005be892  50                   push eax
// 005be893  8d4c2434             lea ecx, [esp + 0x34]
// 005be897  c784245001000000000000 mov dword ptr [esp + 0x150], 0
// 005be8a2  c644241c10           mov byte ptr [esp + 0x1c], 0x10
// 005be8a7  e8e494faff           call 0x567d90
// 005be8ac  8bb4244c010000       mov esi, dword ptr [esp + 0x14c]
// 005be8b3  83c604               add esi, 4
// 005be8b6  56                   push esi
// 005be8b7  8d4c242c             lea ecx, [esp + 0x2c]
// 005be8bb  e860e7ffff           call 0x5bd020
// 005be8c0  8b0e                 mov ecx, dword ptr [esi]
// 005be8c2  8b5604               mov edx, dword ptr [esi + 4]
// 005be8c5  6a01                 push 1
// 005be8c7  83ec14               sub esp, 0x14
// 005be8ca  8bc4                 mov eax, esp
// 005be8cc  8908                 mov dword ptr [eax], ecx
// 005be8ce  8b4e08               mov ecx, dword ptr [esi + 8]
// 005be8d1  895004               mov dword ptr [eax + 4], edx
// 005be8d4  8b560c               mov edx, dword ptr [esi + 0xc]
// 005be8d7  894808               mov dword ptr [eax + 8], ecx
// 005be8da  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005be8dd  89500c               mov dword ptr [eax + 0xc], edx
// 005be8e0  894810               mov dword ptr [eax + 0x10], ecx
// 005be8e3  8bcb                 mov ecx, ebx
// 005be8e5  e8f6d4ffff           call 0x5bbde0
// 005be8ea  0fb7d0               movzx edx, ax
// 005be8ed  8954241c             mov dword ptr [esp + 0x1c], edx
// 005be8f1  e8da92faff           call 0x567bd0
// 005be8f6  84c0                 test al, al
// 005be8f8  751f                 jne 0x5be919
// 005be8fa  6a02                 push 2
// 005be8fc  8d442414             lea eax, [esp + 0x14]
// 005be900  50                   push eax
// 005be901  8d4c2424             lea ecx, [esp + 0x24]
// 005be905  51                   push ecx
// 005be906  e83592faff           call 0x567b40
// 005be90b  83c40c               add esp, 0xc
// 005be90e  6a01                 push 1
// 005be910  6a10                 push 0x10
// 005be912  8d542418             lea edx, [esp + 0x18]
// 005be916  52                   push edx
// 005be917  eb09                 jmp 0x5be922
// 005be919  6a01                 push 1
// 005be91b  6a10                 push 0x10
// 005be91d  8d442424             lea eax, [esp + 0x24]
// 005be921  50                   push eax
// 005be922  8d4c2434             lea ecx, [esp + 0x34]
// 005be926  e86594faff           call 0x567d90
// 005be92b  8dbb98040000         lea edi, [ebx + 0x498]
// 005be931  bd0a000000           mov ebp, 0xa
// 005be936  57                   push edi
// 005be937  8d4c242c             lea ecx, [esp + 0x2c]
// 005be93b  e8e0e6ffff           call 0x5bd020
// 005be940  83c714               add edi, 0x14
// 005be943  83ed01               sub ebp, 1
// 005be946  75ee                 jne 0x5be936
// 005be948  f6058c45e20001       test byte ptr [0xe2458c], 1
// 005be94f  7521                 jne 0x5be972
// 005be951  830d8c45e20001       or dword ptr [0xe2458c], 1
// 005be958  c684244401000001     mov byte ptr [esp + 0x144], 1
// 005be960  e89b91faff           call 0x567b00
// 005be965  a28845e200           mov byte ptr [0xe24588], al
// 005be96a  c684244401000000     mov byte ptr [esp + 0x144], 0
// 005be972  803d8845e20000       cmp byte ptr [0xe24588], 0
// 005be979  7522                 jne 0x5be99d
// 005be97b  6a08                 push 8
// 005be97d  8d4c2418             lea ecx, [esp + 0x18]
// 005be981  51                   push ecx
// 005be982  8d942458010000       lea edx, [esp + 0x158]
// 005be989  52                   push edx
// 005be98a  e8b191faff           call 0x567b40
// 005be98f  83c40c               add esp, 0xc
// 005be992  6a01                 push 1
// 005be994  6a40                 push 0x40
// 005be996  8d44241c             lea eax, [esp + 0x1c]
// 005be99a  50                   push eax
// 005be99b  eb0c                 jmp 0x5be9a9
// 005be99d  6a01                 push 1
// 005be99f  6a40                 push 0x40
// 005be9a1  8d8c2458010000       lea ecx, [esp + 0x158]
// 005be9a8  51                   push ecx
// 005be9a9  8d4c2434             lea ecx, [esp + 0x34]
// 005be9ad  e8de93faff           call 0x567d90
// 005be9b2  e819a0ffff           call 0x5b89d0
// 005be9b7  f6058c45e20001       test byte ptr [0xe2458c], 1
// 005be9be  89442414             mov dword ptr [esp + 0x14], eax
// 005be9c2  89542418             mov dword ptr [esp + 0x18], edx
// 005be9c6  7521                 jne 0x5be9e9
// 005be9c8  830d8c45e20001       or dword ptr [0xe2458c], 1
// 005be9cf  c684244401000002     mov byte ptr [esp + 0x144], 2
// 005be9d7  e82491faff           call 0x567b00
// 005be9dc  a28845e200           mov byte ptr [0xe24588], al
// 005be9e1  c684244401000000     mov byte ptr [esp + 0x144], 0
// 005be9e9  803d8845e20000       cmp byte ptr [0xe24588], 0
// 005be9f0  751f                 jne 0x5bea11
// 005be9f2  6a08                 push 8
// 005be9f4  8d542424             lea edx, [esp + 0x24]
// 005be9f8  52                   push edx
// 005be9f9  8d44241c             lea eax, [esp + 0x1c]
// 005be9fd  50                   push eax
// 005be9fe  e83d91faff           call 0x567b40
// 005bea03  83c40c               add esp, 0xc
// 005bea06  6a01                 push 1
// 005bea08  6a40                 push 0x40
// 005bea0a  8d4c2428             lea ecx, [esp + 0x28]
// 005bea0e  51                   push ecx
// 005bea0f  eb09                 jmp 0x5bea1a
// 005bea11  6a01                 push 1
// 005bea13  6a40                 push 0x40
// 005bea15  8d54241c             lea edx, [esp + 0x1c]
// 005bea19  52                   push edx
// 005bea1a  8d4c2434             lea ecx, [esp + 0x34]
// 005bea1e  e86d93faff           call 0x567d90
// 005bea23  6a00                 push 0
// 005bea25  e8969fffff           call 0x5b89c0
// 005bea2a  52                   push edx
// 005bea2b  50                   push eax
// 005bea2c  6a00                 push 0
// 005bea2e  6a00                 push 0
// 005bea30  83ec28               sub esp, 0x28
// 005bea33  8bfc                 mov edi, esp
// 005bea35  8bcf                 mov ecx, edi
// 005bea37  8964244c             mov dword ptr [esp + 0x4c], esp
// 005bea3b  e8a032faff           call 0x561ce0
// 005bea40  8d6f10               lea ebp, [edi + 0x10]
// 005bea43  8bcd                 mov ecx, ebp
// 005bea45  e8e62ffaff           call 0x561a30
// 005bea4a  a1f815d900           mov eax, dword ptr [0xd915f8]
// 005bea4f  8907                 mov dword ptr [edi], eax
// 005bea51  8b0dfc15d900         mov ecx, dword ptr [0xd915fc]
// 005bea57  894f04               mov dword ptr [edi + 4], ecx
// 005bea5a  668b150016d900       mov dx, word ptr [0xd91600]
// 005bea61  56                   push esi
// 005bea62  8bcd                 mov ecx, ebp
// 005bea64  66895708             mov word ptr [edi + 8], dx
// 005bea68  e8a32dfaff           call 0x561810
// 005bea6d  8b442464             mov eax, dword ptr [esp + 0x64]
// 005bea71  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 005bea75  6a00                 push 0
// 005bea77  6a03                 push 3
// 005bea79  6a00                 push 0
// 005bea7b  50                   push eax
// 005bea7c  51                   push ecx
// 005bea7d  8bcb                 mov ecx, ebx
// 005bea7f  e83cd6ffff           call 0x5bc0c0
// 005bea84  8d4c2428             lea ecx, [esp + 0x28]
// 005bea88  c7842444010000ffffffff mov dword ptr [esp + 0x144], 0xffffffff
// 005bea93  e8188cfaff           call 0x5676b0
// 005bea98  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005bea9f  5f                   pop edi
// 005beaa0  5e                   pop esi
// 005beaa1  5d                   pop ebp
// 005beaa2  64890d00000000       mov dword ptr fs:[0], ecx
// 005beaa9  5b                   pop ebx
// 005beaaa  81c438010000         add esp, 0x138
// 005beab0  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnConnectionRequest@RakPeer@RakNet@@IAEXPAURemoteSystemStruct@12@_K@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp