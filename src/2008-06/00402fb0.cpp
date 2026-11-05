// from server: 100% by auto
// roc 2008-06 00402fb0  unit: ATL::CRegObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402fb0
//
// 00402fb0  51                   push ecx
// 00402fb1  8b01                 mov eax, dword ptr [ecx]
// 00402fb3  56                   push esi
// 00402fb4  85c0                 test eax, eax
// 00402fb6  750d                 jne 0x402fc5
// 00402fb8  3944240c             cmp dword ptr [esp + 0xc], eax
// 00402fbc  7573                 jne 0x403031
// 00402fbe  b001                 mov al, 1
// 00402fc0  5e                   pop esi
// 00402fc1  59                   pop ecx
// 00402fc2  c20400               ret 4
// 00402fc5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00402fc9  85f6                 test esi, esi
// 00402fcb  7464                 je 0x403031
// 00402fcd  53                   push ebx
// 00402fce  8d542410             lea edx, [esp + 0x10]
// 00402fd2  52                   push edx
// 00402fd3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00402fdb  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00402fe3  8b08                 mov ecx, dword ptr [eax]
// 00402fe5  6854b18000           push 0x80b154
// 00402fea  50                   push eax
// 00402feb  8b01                 mov eax, dword ptr [ecx]
// 00402fed  ffd0                 call eax
// 00402fef  8b0e                 mov ecx, dword ptr [esi]
// 00402ff1  8b01                 mov eax, dword ptr [ecx]
// 00402ff3  8d542408             lea edx, [esp + 8]
// 00402ff7  52                   push edx
// 00402ff8  6854b18000           push 0x80b154
// 00402ffd  56                   push esi
// 00402ffe  ffd0                 call eax
// 00403000  8b442408             mov eax, dword ptr [esp + 8]
// 00403004  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403008  3bc8                 cmp ecx, eax
// 0040300a  0f94c3               sete bl
// 0040300d  85c0                 test eax, eax
// 0040300f  740c                 je 0x40301d
// 00403011  8b08                 mov ecx, dword ptr [eax]
// 00403013  8b5108               mov edx, dword ptr [ecx + 8]
// 00403016  50                   push eax
// 00403017  ffd2                 call edx
// 00403019  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040301d  85c9                 test ecx, ecx
// 0040301f  7408                 je 0x403029
// 00403021  8b01                 mov eax, dword ptr [ecx]
// 00403023  51                   push ecx
// 00403024  8b4808               mov ecx, dword ptr [eax + 8]
// 00403027  ffd1                 call ecx
// 00403029  8ac3                 mov al, bl
// 0040302b  5b                   pop ebx
// 0040302c  5e                   pop esi
// 0040302d  59                   pop ecx
// 0040302e  c20400               ret 4
// 00403031  32c0                 xor al, al
// 00403033  5e                   pop esi
// 00403034  59                   pop ecx
// 00403035  c20400               ret 4
// library atl-9.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
