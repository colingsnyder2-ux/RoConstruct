// from server: 100% by auto
// roc 2009-06 00733b40  unit: CXTPImageManagerResource::CBitmapDC  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00733b40
//
// 00733b40  8b442408             mov eax, dword ptr [esp + 8]
// 00733b44  83ec2c               sub esp, 0x2c
// 00733b47  56                   push esi
// 00733b48  8b742434             mov esi, dword ptr [esp + 0x34]
// 00733b4c  c70600000000         mov dword ptr [esi], 0
// 00733b52  c7460400000000       mov dword ptr [esi + 4], 0
// 00733b59  85c0                 test eax, eax
// 00733b5b  7468                 je 0x733bc5
// 00733b5d  8d4c2404             lea ecx, [esp + 4]
// 00733b61  51                   push ecx
// 00733b62  50                   push eax
// 00733b63  ff15e4ec8900         call dword ptr [0x89ece4]
// 00733b69  85c0                 test eax, eax
// 00733b6b  7458                 je 0x733bc5
// 00733b6d  8b442410             mov eax, dword ptr [esp + 0x10]
// 00733b71  8d542418             lea edx, [esp + 0x18]
// 00733b75  52                   push edx
// 00733b76  6a18                 push 0x18
// 00733b78  50                   push eax
// 00733b79  ff1564e18900         call dword ptr [0x89e164]
// 00733b7f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00733b83  85c0                 test eax, eax
// 00733b85  7419                 je 0x733ba0
// 00733b87  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00733b8b  8b442420             mov eax, dword ptr [esp + 0x20]
// 00733b8f  8916                 mov dword ptr [esi], edx
// 00733b91  894604               mov dword ptr [esi + 4], eax
// 00733b94  85c9                 test ecx, ecx
// 00733b96  7508                 jne 0x733ba0
// 00733b98  99                   cdq 
// 00733b99  2bc2                 sub eax, edx
// 00733b9b  d1f8                 sar eax, 1
// 00733b9d  894604               mov dword ptr [esi + 4], eax
// 00733ba0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00733ba4  57                   push edi
// 00733ba5  8b3d60e18900         mov edi, dword ptr [0x89e160]
// 00733bab  85c0                 test eax, eax
// 00733bad  7407                 je 0x733bb6
// 00733baf  50                   push eax
// 00733bb0  ffd7                 call edi
// 00733bb2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00733bb6  85c9                 test ecx, ecx
// 00733bb8  7403                 je 0x733bbd
// 00733bba  51                   push ecx
// 00733bbb  ffd7                 call edi
// 00733bbd  5f                   pop edi
// 00733bbe  8bc6                 mov eax, esi
// 00733bc0  5e                   pop esi
// 00733bc1  83c42c               add esp, 0x2c
// 00733bc4  c3                   ret 
// 00733bc5  8bc6                 mov eax, esi
// 00733bc7  5e                   pop esi
// 00733bc8  83c42c               add esp, 0x2c
// 00733bcb  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetExtent@CXTPImageManagerIcon@@SA?AVCSize@@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
