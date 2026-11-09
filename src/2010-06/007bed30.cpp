// from server: 100% by auto
// roc 2010-06 007bed30  unit: CXTPImageManagerResource::CBitmapDC  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bed30
//
// 007bed30  8b442408             mov eax, dword ptr [esp + 8]
// 007bed34  83ec2c               sub esp, 0x2c
// 007bed37  56                   push esi
// 007bed38  8b742434             mov esi, dword ptr [esp + 0x34]
// 007bed3c  c70600000000         mov dword ptr [esi], 0
// 007bed42  c7460400000000       mov dword ptr [esi + 4], 0
// 007bed49  85c0                 test eax, eax
// 007bed4b  7468                 je 0x7bedb5
// 007bed4d  8d4c2404             lea ecx, [esp + 4]
// 007bed51  51                   push ecx
// 007bed52  50                   push eax
// 007bed53  ff1538bb9e00         call dword ptr [0x9ebb38]
// 007bed59  85c0                 test eax, eax
// 007bed5b  7458                 je 0x7bedb5
// 007bed5d  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bed61  8d542418             lea edx, [esp + 0x18]
// 007bed65  52                   push edx
// 007bed66  6a18                 push 0x18
// 007bed68  50                   push eax
// 007bed69  ff15bca09e00         call dword ptr [0x9ea0bc]
// 007bed6f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007bed73  85c0                 test eax, eax
// 007bed75  7419                 je 0x7bed90
// 007bed77  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007bed7b  8b442420             mov eax, dword ptr [esp + 0x20]
// 007bed7f  8916                 mov dword ptr [esi], edx
// 007bed81  894604               mov dword ptr [esi + 4], eax
// 007bed84  85c9                 test ecx, ecx
// 007bed86  7508                 jne 0x7bed90
// 007bed88  99                   cdq 
// 007bed89  2bc2                 sub eax, edx
// 007bed8b  d1f8                 sar eax, 1
// 007bed8d  894604               mov dword ptr [esi + 4], eax
// 007bed90  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bed94  57                   push edi
// 007bed95  8b3dd4a09e00         mov edi, dword ptr [0x9ea0d4]
// 007bed9b  85c0                 test eax, eax
// 007bed9d  7407                 je 0x7beda6
// 007bed9f  50                   push eax
// 007beda0  ffd7                 call edi
// 007beda2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007beda6  85c9                 test ecx, ecx
// 007beda8  7403                 je 0x7bedad
// 007bedaa  51                   push ecx
// 007bedab  ffd7                 call edi
// 007bedad  5f                   pop edi
// 007bedae  8bc6                 mov eax, esi
// 007bedb0  5e                   pop esi
// 007bedb1  83c42c               add esp, 0x2c
// 007bedb4  c3                   ret 
// 007bedb5  8bc6                 mov eax, esi
// 007bedb7  5e                   pop esi
// 007bedb8  83c42c               add esp, 0x2c
// 007bedbb  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?GetExtent@CXTPImageManagerIcon@@SA?AVCSize@@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
