// from server: 100% by auto
// roc 2010-06 004067c0  unit: VCApp::?$CComObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004067c0
//
// 004067c0  51                   push ecx
// 004067c1  8b01                 mov eax, dword ptr [ecx]
// 004067c3  56                   push esi
// 004067c4  85c0                 test eax, eax
// 004067c6  750d                 jne 0x4067d5
// 004067c8  3944240c             cmp dword ptr [esp + 0xc], eax
// 004067cc  7573                 jne 0x406841
// 004067ce  b001                 mov al, 1
// 004067d0  5e                   pop esi
// 004067d1  59                   pop ecx
// 004067d2  c20400               ret 4
// 004067d5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004067d9  85f6                 test esi, esi
// 004067db  7464                 je 0x406841
// 004067dd  53                   push ebx
// 004067de  8d542410             lea edx, [esp + 0x10]
// 004067e2  52                   push edx
// 004067e3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004067eb  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004067f3  8b08                 mov ecx, dword ptr [eax]
// 004067f5  684007a000           push 0xa00740
// 004067fa  50                   push eax
// 004067fb  8b01                 mov eax, dword ptr [ecx]
// 004067fd  ffd0                 call eax
// 004067ff  8b0e                 mov ecx, dword ptr [esi]
// 00406801  8b01                 mov eax, dword ptr [ecx]
// 00406803  8d542408             lea edx, [esp + 8]
// 00406807  52                   push edx
// 00406808  684007a000           push 0xa00740
// 0040680d  56                   push esi
// 0040680e  ffd0                 call eax
// 00406810  8b442408             mov eax, dword ptr [esp + 8]
// 00406814  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00406818  3bc8                 cmp ecx, eax
// 0040681a  0f94c3               sete bl
// 0040681d  85c0                 test eax, eax
// 0040681f  740c                 je 0x40682d
// 00406821  8b08                 mov ecx, dword ptr [eax]
// 00406823  8b5108               mov edx, dword ptr [ecx + 8]
// 00406826  50                   push eax
// 00406827  ffd2                 call edx
// 00406829  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040682d  85c9                 test ecx, ecx
// 0040682f  7408                 je 0x406839
// 00406831  8b01                 mov eax, dword ptr [ecx]
// 00406833  51                   push ecx
// 00406834  8b4808               mov ecx, dword ptr [eax + 8]
// 00406837  ffd1                 call ecx
// 00406839  8ac3                 mov al, bl
// 0040683b  5b                   pop ebx
// 0040683c  5e                   pop esi
// 0040683d  59                   pop ecx
// 0040683e  c20400               ret 4
// 00406841  32c0                 xor al, al
// 00406843  5e                   pop esi
// 00406844  59                   pop ecx
// 00406845  c20400               ret 4
// library atl-9.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
