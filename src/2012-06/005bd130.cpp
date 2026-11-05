// roc 2012-06 005bd130  unit: RakNet::RakPeer  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bd130
//
// 005bd130  64a100000000         mov eax, dword ptr fs:[0]
// 005bd136  6aff                 push -1
// 005bd138  68312aab00           push 0xab2a31
// 005bd13d  50                   push eax
// 005bd13e  64892500000000       mov dword ptr fs:[0], esp
// 005bd145  53                   push ebx
// 005bd146  55                   push ebp
// 005bd147  56                   push esi
// 005bd148  8bf1                 mov esi, ecx
// 005bd14a  57                   push edi
// 005bd14b  8dbe74050000         lea edi, [esi + 0x574]
// 005bd151  8bcf                 mov ecx, edi
// 005bd153  e808bee5ff           call 0x418f60
// 005bd158  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005bd15c  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005bd160  55                   push ebp
// 005bd161  53                   push ebx
// 005bd162  8d8e8c050000         lea ecx, [esi + 0x58c]
// 005bd168  e8a3f5ffff           call 0x5bc710
// 005bd16d  8bf0                 mov esi, eax
// 005bd16f  8bcf                 mov ecx, edi
// 005bd171  89742428             mov dword ptr [esp + 0x28], esi
// 005bd175  e8f6bde5ff           call 0x418f70
// 005bd17a  89742424             mov dword ptr [esp + 0x24], esi
// 005bd17e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005bd186  85f6                 test esi, esi
// 005bd188  7411                 je 0x5bd19b
// 005bd18a  8bce                 mov ecx, esi
// 005bd18c  e89f48faff           call 0x561a30
// 005bd191  8d4e18               lea ecx, [esi + 0x18]
// 005bd194  e8474bfaff           call 0x561ce0
// 005bd199  eb02                 jmp 0x5bd19d
// 005bd19b  33f6                 xor esi, esi
// 005bd19d  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005bd1a1  55                   push ebp
// 005bd1a2  53                   push ebx
// 005bd1a3  57                   push edi
// 005bd1a4  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005bd1ac  ff159404d900         call dword ptr [0xd90494]
// 005bd1b2  894630               mov dword ptr [esi + 0x30], eax
// 005bd1b5  897e28               mov dword ptr [esi + 0x28], edi
// 005bd1b8  c6463401             mov byte ptr [esi + 0x34], 1
// 005bd1bc  8d04fd00000000       lea eax, [edi*8]
// 005bd1c3  89462c               mov dword ptr [esi + 0x2c], eax
// 005bd1c6  8b0df815d900         mov ecx, dword ptr [0xd915f8]
// 005bd1cc  894e18               mov dword ptr [esi + 0x18], ecx
// 005bd1cf  8b15fc15d900         mov edx, dword ptr [0xd915fc]
// 005bd1d5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005bd1d9  89561c               mov dword ptr [esi + 0x1c], edx
// 005bd1dc  66a10016d900         mov ax, word ptr [0xd91600]
// 005bd1e2  83c40c               add esp, 0xc
// 005bd1e5  66894620             mov word ptr [esi + 0x20], ax
// 005bd1e9  5f                   pop edi
// 005bd1ea  c6463500             mov byte ptr [esi + 0x35], 0
// 005bd1ee  8bc6                 mov eax, esi
// 005bd1f0  5e                   pop esi
// 005bd1f1  5d                   pop ebp
// 005bd1f2  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd1f9  5b                   pop ebx
// 005bd1fa  83c40c               add esp, 0xc
// 005bd1fd  c20c00               ret 0xc
// copied from an identical function in another client (function ?AllocPacket@RakPeer@RakNet@@IAEPAUPacket@2@IPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp