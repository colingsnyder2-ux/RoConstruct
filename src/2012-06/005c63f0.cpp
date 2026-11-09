// roc 2012-06 005c63f0  unit: RakNet::RakPeer  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c63f0
//
// 005c63f0  53                   push ebx
// 005c63f1  56                   push esi
// 005c63f2  57                   push edi
// 005c63f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c63f7  837f0800             cmp dword ptr [edi + 8], 0
// 005c63fb  8bd9                 mov ebx, ecx
// 005c63fd  7623                 jbe 0x5c6422
// 005c63ff  8b07                 mov eax, dword ptr [edi]
// 005c6401  85c0                 test eax, eax
// 005c6403  741d                 je 0x5c6422
// 005c6405  8b48fc               mov ecx, dword ptr [eax - 4]
// 005c6408  8d70fc               lea esi, [eax - 4]
// 005c640b  68e0ed5b00           push 0x5bede0
// 005c6410  51                   push ecx
// 005c6411  6a08                 push 8
// 005c6413  50                   push eax
// 005c6414  e857ce3b00           call 0x983270
// 005c6419  56                   push esi
// 005c641a  e89bbf3b00           call 0x9823ba
// 005c641f  83c404               add esp, 4
// 005c6422  8d7314               lea esi, [ebx + 0x14]
// 005c6425  8bce                 mov ecx, esi
// 005c6427  e8342be5ff           call 0x418f60
// 005c642c  8b542418             mov edx, dword ptr [esp + 0x18]
// 005c6430  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c6434  52                   push edx
// 005c6435  50                   push eax
// 005c6436  57                   push edi
// 005c6437  8bcb                 mov ecx, ebx
// 005c6439  e8c269ffff           call 0x5bce00
// 005c643e  8bce                 mov ecx, esi
// 005c6440  e82b2be5ff           call 0x418f70
// 005c6445  5f                   pop edi
// 005c6446  5e                   pop esi
// 005c6447  5b                   pop ebx
// 005c6448  c20c00               ret 0xc
// copied from an identical function in another client (function ?Deallocate@?$ThreadsafeAllocatingQueue@USocketQueryOutput@RakPeer@RakNet@@@DataStructures@@QAEXPAUSocketQueryOutput@RakPeer@RakNet@@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp