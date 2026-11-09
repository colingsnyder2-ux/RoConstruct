// from server: 100% by auto
// roc 2009-12 004068c0  unit: VCApp::?$CComObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004068c0
//
// 004068c0  51                   push ecx
// 004068c1  8b01                 mov eax, dword ptr [ecx]
// 004068c3  56                   push esi
// 004068c4  85c0                 test eax, eax
// 004068c6  750d                 jne 0x4068d5
// 004068c8  3944240c             cmp dword ptr [esp + 0xc], eax
// 004068cc  7573                 jne 0x406941
// 004068ce  b001                 mov al, 1
// 004068d0  5e                   pop esi
// 004068d1  59                   pop ecx
// 004068d2  c20400               ret 4
// 004068d5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004068d9  85f6                 test esi, esi
// 004068db  7464                 je 0x406941
// 004068dd  53                   push ebx
// 004068de  8d542410             lea edx, [esp + 0x10]
// 004068e2  52                   push edx
// 004068e3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004068eb  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004068f3  8b08                 mov ecx, dword ptr [eax]
// 004068f5  689cfb9900           push 0x99fb9c
// 004068fa  50                   push eax
// 004068fb  8b01                 mov eax, dword ptr [ecx]
// 004068fd  ffd0                 call eax
// 004068ff  8b0e                 mov ecx, dword ptr [esi]
// 00406901  8b01                 mov eax, dword ptr [ecx]
// 00406903  8d542408             lea edx, [esp + 8]
// 00406907  52                   push edx
// 00406908  689cfb9900           push 0x99fb9c
// 0040690d  56                   push esi
// 0040690e  ffd0                 call eax
// 00406910  8b442408             mov eax, dword ptr [esp + 8]
// 00406914  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00406918  3bc8                 cmp ecx, eax
// 0040691a  0f94c3               sete bl
// 0040691d  85c0                 test eax, eax
// 0040691f  740c                 je 0x40692d
// 00406921  8b08                 mov ecx, dword ptr [eax]
// 00406923  8b5108               mov edx, dword ptr [ecx + 8]
// 00406926  50                   push eax
// 00406927  ffd2                 call edx
// 00406929  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040692d  85c9                 test ecx, ecx
// 0040692f  7408                 je 0x406939
// 00406931  8b01                 mov eax, dword ptr [ecx]
// 00406933  51                   push ecx
// 00406934  8b4808               mov ecx, dword ptr [eax + 8]
// 00406937  ffd1                 call ecx
// 00406939  8ac3                 mov al, bl
// 0040693b  5b                   pop ebx
// 0040693c  5e                   pop esi
// 0040693d  59                   pop ecx
// 0040693e  c20400               ret 4
// 00406941  32c0                 xor al, al
// 00406943  5e                   pop esi
// 00406944  59                   pop ecx
// 00406945  c20400               ret 4
// library atl-9.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
