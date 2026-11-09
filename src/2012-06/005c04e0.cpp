// roc 2012-06 005c04e0  unit: RakNet::RakPeer  size: 285 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c04e0
//
// 005c04e0  83ec08               sub esp, 8
// 005c04e3  837c240c00           cmp dword ptr [esp + 0xc], 0
// 005c04e8  53                   push ebx
// 005c04e9  55                   push ebp
// 005c04ea  56                   push esi
// 005c04eb  57                   push edi
// 005c04ec  8bf1                 mov esi, ecx
// 005c04ee  0f84fd000000         je 0x5c05f1
// 005c04f4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005c04f8  85ed                 test ebp, ebp
// 005c04fa  0f8cf1000000         jl 0x5c05f1
// 005c0500  83be2c02000000       cmp dword ptr [esi + 0x22c], 0
// 005c0507  0f84e4000000         je 0x5c05f1
// 005c050d  8a4604               mov al, byte ptr [esi + 4]
// 005c0510  3c01                 cmp al, 1
// 005c0512  0f84d9000000         je 0x5c05f1
// 005c0518  8b5c2458             mov ebx, dword ptr [esp + 0x58]
// 005c051c  84db                 test bl, bl
// 005c051e  7511                 jne 0x5c0531
// 005c0520  8d4c2430             lea ecx, [esp + 0x30]
// 005c0524  e867a0ffff           call 0x5ba590
// 005c0529  84c0                 test al, al
// 005c052b  0f85c0000000         jne 0x5c05f1
// 005c0531  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 005c0535  85ff                 test edi, edi
// 005c0537  750b                 jne 0x5c0544
// 005c0539  8b16                 mov edx, dword ptr [esi]
// 005c053b  8b4248               mov eax, dword ptr [edx + 0x48]
// 005c053e  8bce                 mov ecx, esi
// 005c0540  ffd0                 call eax
// 005c0542  8bf8                 mov edi, eax
// 005c0544  84db                 test bl, bl
// 005c0546  7567                 jne 0x5c05af
// 005c0548  6a01                 push 1
// 005c054a  8d4c2434             lea ecx, [esp + 0x34]
// 005c054e  51                   push ecx
// 005c054f  8bce                 mov ecx, esi
// 005c0551  e81aafffff           call 0x5bb470
// 005c0556  84c0                 test al, al
// 005c0558  7455                 je 0x5c05af
// 005c055a  8b16                 mov edx, dword ptr [esi]
// 005c055c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c0560  8b5254               mov edx, dword ptr [edx + 0x54]
// 005c0563  55                   push ebp
// 005c0564  50                   push eax
// 005c0565  8bce                 mov ecx, esi
// 005c0567  ffd2                 call edx
// 005c0569  837c242805           cmp dword ptr [esp + 0x28], 5
// 005c056e  7c33                 jl 0x5c05a3
// 005c0570  8d9ec8050000         lea ebx, [esi + 0x5c8]
// 005c0576  8bcb                 mov ecx, ebx
// 005c0578  c64424100e           mov byte ptr [esp + 0x10], 0xe
// 005c057d  e8de89e5ff           call 0x418f60
// 005c0582  8b86e0050000         mov eax, dword ptr [esi + 0x5e0]
// 005c0588  8bcb                 mov ecx, ebx
// 005c058a  89442411             mov dword ptr [esp + 0x11], eax
// 005c058e  e8dd89e5ff           call 0x418f70
// 005c0593  8b16                 mov edx, dword ptr [esi]
// 005c0595  8b5254               mov edx, dword ptr [edx + 0x54]
// 005c0598  6a05                 push 5
// 005c059a  8d442414             lea eax, [esp + 0x14]
// 005c059e  50                   push eax
// 005c059f  8bce                 mov ecx, esi
// 005c05a1  ffd2                 call edx
// 005c05a3  8bc7                 mov eax, edi
// 005c05a5  5f                   pop edi
// 005c05a6  5e                   pop esi
// 005c05a7  5d                   pop ebp
// 005c05a8  5b                   pop ebx
// 005c05a9  83c408               add esp, 8
// 005c05ac  c24400               ret 0x44
// 005c05af  57                   push edi
// 005c05b0  6a00                 push 0
// 005c05b2  53                   push ebx
// 005c05b3  83ec28               sub esp, 0x28
// 005c05b6  8d442464             lea eax, [esp + 0x64]
// 005c05ba  8bcc                 mov ecx, esp
// 005c05bc  50                   push eax
// 005c05bd  e82e9fffff           call 0x5ba4f0
// 005c05c2  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 005c05c6  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005c05ca  8b442458             mov eax, dword ptr [esp + 0x58]
// 005c05ce  51                   push ecx
// 005c05cf  52                   push edx
// 005c05d0  8b542458             mov edx, dword ptr [esp + 0x58]
// 005c05d4  50                   push eax
// 005c05d5  8d0ced00000000       lea ecx, [ebp*8]
// 005c05dc  51                   push ecx
// 005c05dd  52                   push edx
// 005c05de  8bce                 mov ecx, esi
// 005c05e0  e8fbf7ffff           call 0x5bfde0
// 005c05e5  8bc7                 mov eax, edi
// 005c05e7  5f                   pop edi
// 005c05e8  5e                   pop esi
// 005c05e9  5d                   pop ebp
// 005c05ea  5b                   pop ebx
// 005c05eb  83c408               add esp, 8
// 005c05ee  c24400               ret 0x44
// 005c05f1  5f                   pop edi
// 005c05f2  5e                   pop esi
// 005c05f3  5d                   pop ebp
// 005c05f4  33c0                 xor eax, eax
// 005c05f6  5b                   pop ebx
// 005c05f7  83c408               add esp, 8
// 005c05fa  c24400               ret 0x44
// copied from an identical function in another client (function ?Send@RakPeer@RakNet@@UAEIPBDHW4PacketPriority@@W4PacketReliability@@DUAddressOrGUID@2@_NI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp