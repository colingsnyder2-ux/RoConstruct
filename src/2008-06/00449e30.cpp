// from server: 100% by auto
// roc 2008-06 00449e30  unit: CIDEDocManager  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449e30
//
// 00449e30  51                   push ecx
// 00449e31  56                   push esi
// 00449e32  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00449e36  8b4608               mov eax, dword ptr [esi + 8]
// 00449e39  c744240400000000     mov dword ptr [esp + 4], 0
// 00449e41  85c0                 test eax, eax
// 00449e43  7505                 jne 0x449e4a
// 00449e45  5e                   pop esi
// 00449e46  59                   pop ecx
// 00449e47  c20c00               ret 0xc
// 00449e4a  8b560c               mov edx, dword ptr [esi + 0xc]
// 00449e4d  57                   push edi
// 00449e4e  8d4c2408             lea ecx, [esp + 8]
// 00449e52  51                   push ecx
// 00449e53  6854b18000           push 0x80b154
// 00449e58  52                   push edx
// 00449e59  ffd0                 call eax
// 00449e5b  8bf8                 mov edi, eax
// 00449e5d  85ff                 test edi, edi
// 00449e5f  7c1e                 jl 0x449e7f
// 00449e61  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00449e65  8b542414             mov edx, dword ptr [esp + 0x14]
// 00449e69  8d4614               lea eax, [esi + 0x14]
// 00449e6c  50                   push eax
// 00449e6d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00449e71  51                   push ecx
// 00449e72  8b0e                 mov ecx, dword ptr [esi]
// 00449e74  52                   push edx
// 00449e75  50                   push eax
// 00449e76  51                   push ecx
// 00449e77  ff1524418000         call dword ptr [0x804124]
// 00449e7d  8bf8                 mov edi, eax
// 00449e7f  8b442408             mov eax, dword ptr [esp + 8]
// 00449e83  85c0                 test eax, eax
// 00449e85  7408                 je 0x449e8f
// 00449e87  8b10                 mov edx, dword ptr [eax]
// 00449e89  50                   push eax
// 00449e8a  8b4208               mov eax, dword ptr [edx + 8]
// 00449e8d  ffd0                 call eax
// 00449e8f  8bc7                 mov eax, edi
// 00449e91  5f                   pop edi
// 00449e92  5e                   pop esi
// 00449e93  59                   pop ecx
// 00449e94  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
