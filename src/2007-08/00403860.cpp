// from server: 100% by auto
// roc 2007-08 00403860  unit: VCWorkspace::?$CComObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00403860
//
// 00403860  51                   push ecx
// 00403861  8b01                 mov eax, dword ptr [ecx]
// 00403863  85c0                 test eax, eax
// 00403865  56                   push esi
// 00403866  750d                 jne 0x403875
// 00403868  3944240c             cmp dword ptr [esp + 0xc], eax
// 0040386c  7573                 jne 0x4038e1
// 0040386e  b001                 mov al, 1
// 00403870  5e                   pop esi
// 00403871  59                   pop ecx
// 00403872  c20400               ret 4
// 00403875  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00403879  85f6                 test esi, esi
// 0040387b  7464                 je 0x4038e1
// 0040387d  53                   push ebx
// 0040387e  8d542410             lea edx, [esp + 0x10]
// 00403882  52                   push edx
// 00403883  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040388b  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00403893  8b08                 mov ecx, dword ptr [eax]
// 00403895  68b44e7800           push 0x784eb4
// 0040389a  50                   push eax
// 0040389b  8b01                 mov eax, dword ptr [ecx]
// 0040389d  ffd0                 call eax
// 0040389f  8b0e                 mov ecx, dword ptr [esi]
// 004038a1  8b01                 mov eax, dword ptr [ecx]
// 004038a3  8d542408             lea edx, [esp + 8]
// 004038a7  52                   push edx
// 004038a8  68b44e7800           push 0x784eb4
// 004038ad  56                   push esi
// 004038ae  ffd0                 call eax
// 004038b0  8b442408             mov eax, dword ptr [esp + 8]
// 004038b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004038b8  3bc8                 cmp ecx, eax
// 004038ba  0f94c3               sete bl
// 004038bd  85c0                 test eax, eax
// 004038bf  740c                 je 0x4038cd
// 004038c1  8b08                 mov ecx, dword ptr [eax]
// 004038c3  8b5108               mov edx, dword ptr [ecx + 8]
// 004038c6  50                   push eax
// 004038c7  ffd2                 call edx
// 004038c9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004038cd  85c9                 test ecx, ecx
// 004038cf  7408                 je 0x4038d9
// 004038d1  8b01                 mov eax, dword ptr [ecx]
// 004038d3  51                   push ecx
// 004038d4  8b4808               mov ecx, dword ptr [eax + 8]
// 004038d7  ffd1                 call ecx
// 004038d9  8ac3                 mov al, bl
// 004038db  5b                   pop ebx
// 004038dc  5e                   pop esi
// 004038dd  59                   pop ecx
// 004038de  c20400               ret 4
// 004038e1  32c0                 xor al, al
// 004038e3  5e                   pop esi
// 004038e4  59                   pop ecx
// 004038e5  c20400               ret 4
// library atl-8.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
