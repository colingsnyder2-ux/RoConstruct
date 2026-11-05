// from server: 100% by auto
// roc 2007-03 004036e0  unit: seg_00400000  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004036e0
//
// 004036e0  51                   push ecx
// 004036e1  8b01                 mov eax, dword ptr [ecx]
// 004036e3  85c0                 test eax, eax
// 004036e5  56                   push esi
// 004036e6  750d                 jne 0x4036f5
// 004036e8  3944240c             cmp dword ptr [esp + 0xc], eax
// 004036ec  7573                 jne 0x403761
// 004036ee  b001                 mov al, 1
// 004036f0  5e                   pop esi
// 004036f1  59                   pop ecx
// 004036f2  c20400               ret 4
// 004036f5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004036f9  85f6                 test esi, esi
// 004036fb  7464                 je 0x403761
// 004036fd  53                   push ebx
// 004036fe  8d542410             lea edx, [esp + 0x10]
// 00403702  52                   push edx
// 00403703  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040370b  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00403713  8b08                 mov ecx, dword ptr [eax]
// 00403715  68b43e7800           push 0x783eb4
// 0040371a  50                   push eax
// 0040371b  8b01                 mov eax, dword ptr [ecx]
// 0040371d  ffd0                 call eax
// 0040371f  8b0e                 mov ecx, dword ptr [esi]
// 00403721  8b01                 mov eax, dword ptr [ecx]
// 00403723  8d542408             lea edx, [esp + 8]
// 00403727  52                   push edx
// 00403728  68b43e7800           push 0x783eb4
// 0040372d  56                   push esi
// 0040372e  ffd0                 call eax
// 00403730  8b442408             mov eax, dword ptr [esp + 8]
// 00403734  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00403738  3bc8                 cmp ecx, eax
// 0040373a  0f94c3               sete bl
// 0040373d  85c0                 test eax, eax
// 0040373f  740c                 je 0x40374d
// 00403741  8b08                 mov ecx, dword ptr [eax]
// 00403743  8b5108               mov edx, dword ptr [ecx + 8]
// 00403746  50                   push eax
// 00403747  ffd2                 call edx
// 00403749  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040374d  85c9                 test ecx, ecx
// 0040374f  7408                 je 0x403759
// 00403751  8b01                 mov eax, dword ptr [ecx]
// 00403753  51                   push ecx
// 00403754  8b4808               mov ecx, dword ptr [eax + 8]
// 00403757  ffd1                 call ecx
// 00403759  8ac3                 mov al, bl
// 0040375b  5b                   pop ebx
// 0040375c  5e                   pop esi
// 0040375d  59                   pop ecx
// 0040375e  c20400               ret 4
// 00403761  32c0                 xor al, al
// 00403763  5e                   pop esi
// 00403764  59                   pop ecx
// 00403765  c20400               ret 4
// library atl-8.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
