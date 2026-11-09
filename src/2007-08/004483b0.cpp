// from server: 100% by tester
// roc 2007-03 00447a30  unit: seg_00440000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00447a30
//
// 00447a30  51                   push ecx
// 00447a31  56                   push esi
// 00447a32  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00447a36  8b4608               mov eax, dword ptr [esi + 8]
// 00447a39  85c0                 test eax, eax
// 00447a3b  c744240400000000     mov dword ptr [esp + 4], 0
// 00447a43  7505                 jne 0x447a4a
// 00447a45  5e                   pop esi
// 00447a46  59                   pop ecx
// 00447a47  c20c00               ret 0xc
// 00447a4a  8b560c               mov edx, dword ptr [esi + 0xc]
// 00447a4d  57                   push edi
// 00447a4e  8d4c2408             lea ecx, [esp + 8]
// 00447a52  51                   push ecx
// 00447a53  68b43e7800           push 0x783eb4
// 00447a58  52                   push edx
// 00447a59  ffd0                 call eax
// 00447a5b  8bf8                 mov edi, eax
// 00447a5d  85ff                 test edi, edi
// 00447a5f  7c1e                 jl 0x447a7f
// 00447a61  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00447a65  8b542414             mov edx, dword ptr [esp + 0x14]
// 00447a69  8d4614               lea eax, [esi + 0x14]
// 00447a6c  50                   push eax
// 00447a6d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00447a71  51                   push ecx
// 00447a72  8b0e                 mov ecx, dword ptr [esi]
// 00447a74  52                   push edx
// 00447a75  50                   push eax
// 00447a76  51                   push ecx
// 00447a77  ff1510f17700         call dword ptr [0x77f110]
// 00447a7d  8bf8                 mov edi, eax
// 00447a7f  8b442408             mov eax, dword ptr [esp + 8]
// 00447a83  85c0                 test eax, eax
// 00447a85  7408                 je 0x447a8f
// 00447a87  8b10                 mov edx, dword ptr [eax]
// 00447a89  50                   push eax
// 00447a8a  8b4208               mov eax, dword ptr [edx + 8]
// 00447a8d  ffd0                 call eax
// 00447a8f  8bc7                 mov eax, edi
// 00447a91  5f                   pop edi
// 00447a92  5e                   pop esi
// 00447a93  59                   pop ecx
// 00447a94  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
