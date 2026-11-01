// from server: 100% by auto
// roc 2012-06 0046c6a0  unit: RBX::TeleportCallback  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046c6a0
//
// 0046c6a0  51                   push ecx
// 0046c6a1  56                   push esi
// 0046c6a2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046c6a6  8b4608               mov eax, dword ptr [esi + 8]
// 0046c6a9  c744240400000000     mov dword ptr [esp + 4], 0
// 0046c6b1  85c0                 test eax, eax
// 0046c6b3  7505                 jne 0x46c6ba
// 0046c6b5  5e                   pop esi
// 0046c6b6  59                   pop ecx
// 0046c6b7  c20c00               ret 0xc
// 0046c6ba  8b560c               mov edx, dword ptr [esi + 0xc]
// 0046c6bd  57                   push edi
// 0046c6be  8d4c2408             lea ecx, [esp + 8]
// 0046c6c2  51                   push ecx
// 0046c6c3  68503ab400           push 0xb43a50
// 0046c6c8  52                   push edx
// 0046c6c9  ffd0                 call eax
// 0046c6cb  8bf8                 mov edi, eax
// 0046c6cd  85ff                 test edi, edi
// 0046c6cf  7c1e                 jl 0x46c6ef
// 0046c6d1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0046c6d5  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046c6d9  8d4614               lea eax, [esi + 0x14]
// 0046c6dc  50                   push eax
// 0046c6dd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046c6e1  51                   push ecx
// 0046c6e2  8b0e                 mov ecx, dword ptr [esi]
// 0046c6e4  52                   push edx
// 0046c6e5  50                   push eax
// 0046c6e6  51                   push ecx
// 0046c6e7  ff154451b200         call dword ptr [0xb25144]
// 0046c6ed  8bf8                 mov edi, eax
// 0046c6ef  8b442408             mov eax, dword ptr [esp + 8]
// 0046c6f3  85c0                 test eax, eax
// 0046c6f5  7408                 je 0x46c6ff
// 0046c6f7  8b10                 mov edx, dword ptr [eax]
// 0046c6f9  50                   push eax
// 0046c6fa  8b4208               mov eax, dword ptr [edx + 8]
// 0046c6fd  ffd0                 call eax
// 0046c6ff  8bc7                 mov eax, edi
// 0046c701  5f                   pop edi
// 0046c702  5e                   pop esi
// 0046c703  59                   pop ecx
// 0046c704  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
