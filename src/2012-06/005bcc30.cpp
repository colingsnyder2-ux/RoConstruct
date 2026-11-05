// roc 2012-06 005bcc30  unit: RakNet::RakPeer  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bcc30
//
// 005bcc30  8b542404             mov edx, dword ptr [esp + 4]
// 005bcc34  56                   push esi
// 005bcc35  8bb208060000         mov esi, dword ptr [edx + 0x608]
// 005bcc3b  8b4604               mov eax, dword ptr [esi + 4]
// 005bcc3e  85c0                 test eax, eax
// 005bcc40  7566                 jne 0x5bcca8
// 005bcc42  8b06                 mov eax, dword ptr [esi]
// 005bcc44  8910                 mov dword ptr [eax], edx
// 005bcc46  ff4604               inc dword ptr [esi + 4]
// 005bcc49  ff490c               dec dword ptr [ecx + 0xc]
// 005bcc4c  8b560c               mov edx, dword ptr [esi + 0xc]
// 005bcc4f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bcc52  894210               mov dword ptr [edx + 0x10], eax
// 005bcc55  8b5610               mov edx, dword ptr [esi + 0x10]
// 005bcc58  8b460c               mov eax, dword ptr [esi + 0xc]
// 005bcc5b  89420c               mov dword ptr [edx + 0xc], eax
// 005bcc5e  83790c00             cmp dword ptr [ecx + 0xc], 0
// 005bcc62  7e0d                 jle 0x5bcc71
// 005bcc64  8b4104               mov eax, dword ptr [ecx + 4]
// 005bcc67  3bf0                 cmp esi, eax
// 005bcc69  7506                 jne 0x5bcc71
// 005bcc6b  8b500c               mov edx, dword ptr [eax + 0xc]
// 005bcc6e  895104               mov dword ptr [ecx + 4], edx
// 005bcc71  8b4108               mov eax, dword ptr [ecx + 8]
// 005bcc74  8d5001               lea edx, [eax + 1]
// 005bcc77  895108               mov dword ptr [ecx + 8], edx
// 005bcc7a  85c0                 test eax, eax
// 005bcc7c  750c                 jne 0x5bcc8a
// 005bcc7e  8931                 mov dword ptr [ecx], esi
// 005bcc80  89760c               mov dword ptr [esi + 0xc], esi
// 005bcc83  897610               mov dword ptr [esi + 0x10], esi
// 005bcc86  5e                   pop esi
// 005bcc87  c20c00               ret 0xc
// 005bcc8a  8b01                 mov eax, dword ptr [ecx]
// 005bcc8c  89460c               mov dword ptr [esi + 0xc], eax
// 005bcc8f  8b11                 mov edx, dword ptr [ecx]
// 005bcc91  8b4210               mov eax, dword ptr [edx + 0x10]
// 005bcc94  894610               mov dword ptr [esi + 0x10], eax
// 005bcc97  8b11                 mov edx, dword ptr [ecx]
// 005bcc99  8b4210               mov eax, dword ptr [edx + 0x10]
// 005bcc9c  89700c               mov dword ptr [eax + 0xc], esi
// 005bcc9f  8b09                 mov ecx, dword ptr [ecx]
// 005bcca1  897110               mov dword ptr [ecx + 0x10], esi
// 005bcca4  5e                   pop esi
// 005bcca5  c20c00               ret 0xc
// 005bcca8  53                   push ebx
// 005bcca9  57                   push edi
// 005bccaa  8b3e                 mov edi, dword ptr [esi]
// 005bccac  891487               mov dword ptr [edi + eax*4], edx
// 005bccaf  ff4604               inc dword ptr [esi + 4]
// 005bccb2  8b7910               mov edi, dword ptr [ecx + 0x10]
// 005bccb5  8b5e04               mov ebx, dword ptr [esi + 4]
// 005bccb8  b8af7ed051           mov eax, 0x51d07eaf
// 005bccbd  f7e7                 mul edi
// 005bccbf  2bfa                 sub edi, edx
// 005bccc1  d1ef                 shr edi, 1
// 005bccc3  03fa                 add edi, edx
// 005bccc5  c1ef0a               shr edi, 0xa
// 005bccc8  3bdf                 cmp ebx, edi
// 005bccca  754f                 jne 0x5bcd1b
// 005bcccc  83790804             cmp dword ptr [ecx + 8], 4
// 005bccd0  7c49                 jl 0x5bcd1b
// 005bccd2  3b31                 cmp esi, dword ptr [ecx]
// 005bccd4  7505                 jne 0x5bccdb
// 005bccd6  8b560c               mov edx, dword ptr [esi + 0xc]
// 005bccd9  8911                 mov dword ptr [ecx], edx
// 005bccdb  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bccde  8b560c               mov edx, dword ptr [esi + 0xc]
// 005bcce1  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005bcce5  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005bcce9  89500c               mov dword ptr [eax + 0xc], edx
// 005bccec  8b460c               mov eax, dword ptr [esi + 0xc]
// 005bccef  8b5610               mov edx, dword ptr [esi + 0x10]
// 005bccf2  895010               mov dword ptr [eax + 0x10], edx
// 005bccf5  ff4908               dec dword ptr [ecx + 8]
// 005bccf8  8b06                 mov eax, dword ptr [esi]
// 005bccfa  57                   push edi
// 005bccfb  53                   push ebx
// 005bccfc  50                   push eax
// 005bccfd  ff159c04d900         call dword ptr [0xd9049c]
// 005bcd03  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bcd06  57                   push edi
// 005bcd07  53                   push ebx
// 005bcd08  51                   push ecx
// 005bcd09  ff159c04d900         call dword ptr [0xd9049c]
// 005bcd0f  57                   push edi
// 005bcd10  53                   push ebx
// 005bcd11  56                   push esi
// 005bcd12  ff159c04d900         call dword ptr [0xd9049c]
// 005bcd18  83c424               add esp, 0x24
// 005bcd1b  5f                   pop edi
// 005bcd1c  5b                   pop ebx
// 005bcd1d  5e                   pop esi
// 005bcd1e  c20c00               ret 0xc
// copied from an identical function in another client (function ?Release@?$MemoryPool@URecvFromStruct@RakPeer@RakNet@@@DataStructures@@QAEXPAURecvFromStruct@RakPeer@RakNet@@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp