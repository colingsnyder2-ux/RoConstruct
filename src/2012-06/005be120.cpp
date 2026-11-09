// roc 2012-06 005be120  unit: RakNet::RakPeer  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005be120
//
// 005be120  6aff                 push -1
// 005be122  685b0aab00           push 0xab0a5b
// 005be127  64a100000000         mov eax, dword ptr fs:[0]
// 005be12d  50                   push eax
// 005be12e  64892500000000       mov dword ptr fs:[0], esp
// 005be135  81ec18010000         sub esp, 0x118
// 005be13b  53                   push ebx
// 005be13c  56                   push esi
// 005be13d  8bf1                 mov esi, ecx
// 005be13f  8d4c240c             lea ecx, [esp + 0xc]
// 005be143  e85894faff           call 0x5675a0
// 005be148  6a01                 push 1
// 005be14a  6a08                 push 8
// 005be14c  8d442413             lea eax, [esp + 0x13]
// 005be150  50                   push eax
// 005be151  8d4c2418             lea ecx, [esp + 0x18]
// 005be155  c784243401000000000000 mov dword ptr [esp + 0x134], 0
// 005be160  c64424171d           mov byte ptr [esp + 0x17], 0x1d
// 005be165  e8269cfaff           call 0x567d90
// 005be16a  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005be171  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 005be178  51                   push ecx
// 005be179  52                   push edx
// 005be17a  8d4c2414             lea ecx, [esp + 0x14]
// 005be17e  e81d9efaff           call 0x567fa0
// 005be183  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005be187  8b8c2440010000       mov ecx, dword ptr [esp + 0x140]
// 005be18e  8b16                 mov edx, dword ptr [esi]
// 005be190  8b9244010000         mov edx, dword ptr [edx + 0x144]
// 005be196  51                   push ecx
// 005be197  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 005be19e  83c007               add eax, 7
// 005be1a1  c1e803               shr eax, 3
// 005be1a4  50                   push eax
// 005be1a5  8b442420             mov eax, dword ptr [esp + 0x20]
// 005be1a9  50                   push eax
// 005be1aa  8b84243c010000       mov eax, dword ptr [esp + 0x13c]
// 005be1b1  51                   push ecx
// 005be1b2  50                   push eax
// 005be1b3  8bce                 mov ecx, esi
// 005be1b5  ffd2                 call edx
// 005be1b7  8d4c240c             lea ecx, [esp + 0xc]
// 005be1bb  8ad8                 mov bl, al
// 005be1bd  c7842428010000ffffffff mov dword ptr [esp + 0x128], 0xffffffff
// 005be1c8  e8e394faff           call 0x5676b0
// 005be1cd  8b8c2420010000       mov ecx, dword ptr [esp + 0x120]
// 005be1d4  5e                   pop esi
// 005be1d5  8ac3                 mov al, bl
// 005be1d7  5b                   pop ebx
// 005be1d8  64890d00000000       mov dword ptr fs:[0], ecx
// 005be1df  81c424010000         add esp, 0x124
// 005be1e5  c21400               ret 0x14
// copied from an identical function in another client (function ?AdvertiseSystem@RakPeer@RakNet@@UAE_NPBDG0HI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp