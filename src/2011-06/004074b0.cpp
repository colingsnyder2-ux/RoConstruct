// from server: 100% by auto
// roc 2011-06 004074b0  unit: VCApp::?$CComObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004074b0
//
// 004074b0  51                   push ecx
// 004074b1  8b01                 mov eax, dword ptr [ecx]
// 004074b3  56                   push esi
// 004074b4  85c0                 test eax, eax
// 004074b6  750d                 jne 0x4074c5
// 004074b8  3944240c             cmp dword ptr [esp + 0xc], eax
// 004074bc  7573                 jne 0x407531
// 004074be  b001                 mov al, 1
// 004074c0  5e                   pop esi
// 004074c1  59                   pop ecx
// 004074c2  c20400               ret 4
// 004074c5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004074c9  85f6                 test esi, esi
// 004074cb  7464                 je 0x407531
// 004074cd  53                   push ebx
// 004074ce  8d542410             lea edx, [esp + 0x10]
// 004074d2  52                   push edx
// 004074d3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004074db  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004074e3  8b08                 mov ecx, dword ptr [eax]
// 004074e5  68e0bca500           push 0xa5bce0
// 004074ea  50                   push eax
// 004074eb  8b01                 mov eax, dword ptr [ecx]
// 004074ed  ffd0                 call eax
// 004074ef  8b0e                 mov ecx, dword ptr [esi]
// 004074f1  8b01                 mov eax, dword ptr [ecx]
// 004074f3  8d542408             lea edx, [esp + 8]
// 004074f7  52                   push edx
// 004074f8  68e0bca500           push 0xa5bce0
// 004074fd  56                   push esi
// 004074fe  ffd0                 call eax
// 00407500  8b442408             mov eax, dword ptr [esp + 8]
// 00407504  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00407508  3bc8                 cmp ecx, eax
// 0040750a  0f94c3               sete bl
// 0040750d  85c0                 test eax, eax
// 0040750f  740c                 je 0x40751d
// 00407511  8b08                 mov ecx, dword ptr [eax]
// 00407513  8b5108               mov edx, dword ptr [ecx + 8]
// 00407516  50                   push eax
// 00407517  ffd2                 call edx
// 00407519  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040751d  85c9                 test ecx, ecx
// 0040751f  7408                 je 0x407529
// 00407521  8b01                 mov eax, dword ptr [ecx]
// 00407523  51                   push ecx
// 00407524  8b4808               mov ecx, dword ptr [eax + 8]
// 00407527  ffd1                 call ecx
// 00407529  8ac3                 mov al, bl
// 0040752b  5b                   pop ebx
// 0040752c  5e                   pop esi
// 0040752d  59                   pop ecx
// 0040752e  c20400               ret 4
// 00407531  32c0                 xor al, al
// 00407533  5e                   pop esi
// 00407534  59                   pop ecx
// 00407535  c20400               ret 4
// library atl-9.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
