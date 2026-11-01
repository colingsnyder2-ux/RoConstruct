// from server: 100% by auto
// roc 2009-06 00406ba0  unit: VCApp::?$CComObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00406ba0
//
// 00406ba0  51                   push ecx
// 00406ba1  8b01                 mov eax, dword ptr [ecx]
// 00406ba3  56                   push esi
// 00406ba4  85c0                 test eax, eax
// 00406ba6  750d                 jne 0x406bb5
// 00406ba8  3944240c             cmp dword ptr [esp + 0xc], eax
// 00406bac  7573                 jne 0x406c21
// 00406bae  b001                 mov al, 1
// 00406bb0  5e                   pop esi
// 00406bb1  59                   pop ecx
// 00406bb2  c20400               ret 4
// 00406bb5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00406bb9  85f6                 test esi, esi
// 00406bbb  7464                 je 0x406c21
// 00406bbd  53                   push ebx
// 00406bbe  8d542410             lea edx, [esp + 0x10]
// 00406bc2  52                   push edx
// 00406bc3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00406bcb  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00406bd3  8b08                 mov ecx, dword ptr [eax]
// 00406bd5  685cd08a00           push 0x8ad05c
// 00406bda  50                   push eax
// 00406bdb  8b01                 mov eax, dword ptr [ecx]
// 00406bdd  ffd0                 call eax
// 00406bdf  8b0e                 mov ecx, dword ptr [esi]
// 00406be1  8b01                 mov eax, dword ptr [ecx]
// 00406be3  8d542408             lea edx, [esp + 8]
// 00406be7  52                   push edx
// 00406be8  685cd08a00           push 0x8ad05c
// 00406bed  56                   push esi
// 00406bee  ffd0                 call eax
// 00406bf0  8b442408             mov eax, dword ptr [esp + 8]
// 00406bf4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00406bf8  3bc8                 cmp ecx, eax
// 00406bfa  0f94c3               sete bl
// 00406bfd  85c0                 test eax, eax
// 00406bff  740c                 je 0x406c0d
// 00406c01  8b08                 mov ecx, dword ptr [eax]
// 00406c03  8b5108               mov edx, dword ptr [ecx + 8]
// 00406c06  50                   push eax
// 00406c07  ffd2                 call edx
// 00406c09  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00406c0d  85c9                 test ecx, ecx
// 00406c0f  7408                 je 0x406c19
// 00406c11  8b01                 mov eax, dword ptr [ecx]
// 00406c13  51                   push ecx
// 00406c14  8b4808               mov ecx, dword ptr [eax + 8]
// 00406c17  ffd1                 call ecx
// 00406c19  8ac3                 mov al, bl
// 00406c1b  5b                   pop ebx
// 00406c1c  5e                   pop esi
// 00406c1d  59                   pop ecx
// 00406c1e  c20400               ret 4
// 00406c21  32c0                 xor al, al
// 00406c23  5e                   pop esi
// 00406c24  59                   pop ecx
// 00406c25  c20400               ret 4
// library atl-9.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
