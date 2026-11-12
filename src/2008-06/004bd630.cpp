// from server: 100% by auto
// roc 2008-06 004bd630  unit: ProfiledRakPeer  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd630
//
// 004bd630  53                   push ebx
// 004bd631  55                   push ebp
// 004bd632  56                   push esi
// 004bd633  57                   push edi
// 004bd634  8bf9                 mov edi, ecx
// 004bd636  8b87e8060000         mov eax, dword ptr [edi + 0x6e8]
// 004bd63c  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bd63f  3b8fec060000         cmp ecx, dword ptr [edi + 0x6ec]
// 004bd645  7411                 je 0x4bd658
// 004bd647  8b97e8060000         mov edx, dword ptr [edi + 0x6e8]
// 004bd64d  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bd650  8a4838               mov cl, byte ptr [eax + 0x38]
// 004bd653  80f901               cmp cl, 1
// 004bd656  7528                 jne 0x4bd680
// 004bd658  8b97e8060000         mov edx, dword ptr [edi + 0x6e8]
// 004bd65e  8b723c               mov esi, dword ptr [edx + 0x3c]
// 004bd661  6a40                 push 0x40
// 004bd663  e8b8321e00           call 0x6a0920
// 004bd668  8b8fe8060000         mov ecx, dword ptr [edi + 0x6e8]
// 004bd66e  89413c               mov dword ptr [ecx + 0x3c], eax
// 004bd671  8b97e8060000         mov edx, dword ptr [edi + 0x6e8]
// 004bd677  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bd67a  83c404               add esp, 4
// 004bd67d  89703c               mov dword ptr [eax + 0x3c], esi
// 004bd680  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004bd684  8bb7e8060000         mov esi, dword ptr [edi + 0x6e8]
// 004bd68a  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 004bd68d  8d6b07               lea ebp, [ebx + 7]
// 004bd690  c1fd03               sar ebp, 3
// 004bd693  55                   push ebp
// 004bd694  898fe8060000         mov dword ptr [edi + 0x6e8], ecx
// 004bd69a  e881321e00           call 0x6a0920
// 004bd69f  8b542418             mov edx, dword ptr [esp + 0x18]
// 004bd6a3  55                   push ebp
// 004bd6a4  52                   push edx
// 004bd6a5  50                   push eax
// 004bd6a6  894630               mov dword ptr [esi + 0x30], eax
// 004bd6a9  e832411e00           call 0x6a17e0
// 004bd6ae  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004bd6b2  8a542434             mov dl, byte ptr [esp + 0x34]
// 004bd6b6  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004bd6ba  891e                 mov dword ptr [esi], ebx
// 004bd6bc  894604               mov dword ptr [esi + 4], eax
// 004bd6bf  88560c               mov byte ptr [esi + 0xc], dl
// 004bd6c2  8a542440             mov dl, byte ptr [esp + 0x40]
// 004bd6c6  894e08               mov dword ptr [esi + 8], ecx
// 004bd6c9  8b442438             mov eax, dword ptr [esp + 0x38]
// 004bd6cd  894610               mov dword ptr [esi + 0x10], eax
// 004bd6d0  668b4c243c           mov cx, word ptr [esp + 0x3c]
// 004bd6d5  8b442444             mov eax, dword ptr [esp + 0x44]
// 004bd6d9  66894e14             mov word ptr [esi + 0x14], cx
// 004bd6dd  885618               mov byte ptr [esi + 0x18], dl
// 004bd6e0  89461c               mov dword ptr [esi + 0x1c], eax
// 004bd6e3  c7463400000000       mov dword ptr [esi + 0x34], 0
// 004bd6ea  8b8ff0060000         mov ecx, dword ptr [edi + 0x6f0]
// 004bd6f0  ff87f8060000         inc dword ptr [edi + 0x6f8]
// 004bd6f6  c6413801             mov byte ptr [ecx + 0x38], 1
// 004bd6fa  8b97f0060000         mov edx, dword ptr [edi + 0x6f0]
// 004bd700  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bd703  83c410               add esp, 0x10
// 004bd706  8987f0060000         mov dword ptr [edi + 0x6f0], eax
// 004bd70c  5f                   pop edi
// 004bd70d  5e                   pop esi
// 004bd70e  5d                   pop ebp
// 004bd70f  5b                   pop ebx
// 004bd710  c22400               ret 0x24
// library openrbx-raknet/RakPeer.cpp (function ?SendBuffered@RakPeer@@IAEXPBDHW4PacketPriority@@W4PacketReliability@@DUSystemAddress@@_NW4ConnectMode@RemoteSystemStruct@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
