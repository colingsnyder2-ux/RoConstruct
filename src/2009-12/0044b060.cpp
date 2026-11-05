// from server: 100% by auto
// roc 2009-12 0044b060  unit: CRobloxControlColorSelector  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044b060
//
// 0044b060  51                   push ecx
// 0044b061  56                   push esi
// 0044b062  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0044b066  8b4608               mov eax, dword ptr [esi + 8]
// 0044b069  c744240400000000     mov dword ptr [esp + 4], 0
// 0044b071  85c0                 test eax, eax
// 0044b073  7505                 jne 0x44b07a
// 0044b075  5e                   pop esi
// 0044b076  59                   pop ecx
// 0044b077  c20c00               ret 0xc
// 0044b07a  8b560c               mov edx, dword ptr [esi + 0xc]
// 0044b07d  57                   push edi
// 0044b07e  8d4c2408             lea ecx, [esp + 8]
// 0044b082  51                   push ecx
// 0044b083  689cfb9900           push 0x99fb9c
// 0044b088  52                   push edx
// 0044b089  ffd0                 call eax
// 0044b08b  8bf8                 mov edi, eax
// 0044b08d  85ff                 test edi, edi
// 0044b08f  7c1e                 jl 0x44b0af
// 0044b091  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044b095  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044b099  8d4614               lea eax, [esi + 0x14]
// 0044b09c  50                   push eax
// 0044b09d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0044b0a1  51                   push ecx
// 0044b0a2  8b0e                 mov ecx, dword ptr [esi]
// 0044b0a4  52                   push edx
// 0044b0a5  50                   push eax
// 0044b0a6  51                   push ecx
// 0044b0a7  ff15b0e09800         call dword ptr [0x98e0b0]
// 0044b0ad  8bf8                 mov edi, eax
// 0044b0af  8b442408             mov eax, dword ptr [esp + 8]
// 0044b0b3  85c0                 test eax, eax
// 0044b0b5  7408                 je 0x44b0bf
// 0044b0b7  8b10                 mov edx, dword ptr [eax]
// 0044b0b9  50                   push eax
// 0044b0ba  8b4208               mov eax, dword ptr [edx + 8]
// 0044b0bd  ffd0                 call eax
// 0044b0bf  8bc7                 mov eax, edi
// 0044b0c1  5f                   pop edi
// 0044b0c2  5e                   pop esi
// 0044b0c3  59                   pop ecx
// 0044b0c4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
