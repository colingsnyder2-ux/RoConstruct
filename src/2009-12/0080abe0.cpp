// from server: 100% by auto
// roc 2009-12 0080abe0  unit: CXTPImageManagerResource::CBitmapDC  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080abe0
//
// 0080abe0  8b442408             mov eax, dword ptr [esp + 8]
// 0080abe4  83ec2c               sub esp, 0x2c
// 0080abe7  56                   push esi
// 0080abe8  8b742434             mov esi, dword ptr [esp + 0x34]
// 0080abec  c70600000000         mov dword ptr [esi], 0
// 0080abf2  c7460400000000       mov dword ptr [esi + 4], 0
// 0080abf9  85c0                 test eax, eax
// 0080abfb  7468                 je 0x80ac65
// 0080abfd  8d4c2404             lea ecx, [esp + 4]
// 0080ac01  51                   push ecx
// 0080ac02  50                   push eax
// 0080ac03  ff15ecc99800         call dword ptr [0x98c9ec]
// 0080ac09  85c0                 test eax, eax
// 0080ac0b  7458                 je 0x80ac65
// 0080ac0d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0080ac11  8d542418             lea edx, [esp + 0x18]
// 0080ac15  52                   push edx
// 0080ac16  6a18                 push 0x18
// 0080ac18  50                   push eax
// 0080ac19  ff155cb19800         call dword ptr [0x98b15c]
// 0080ac1f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0080ac23  85c0                 test eax, eax
// 0080ac25  7419                 je 0x80ac40
// 0080ac27  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0080ac2b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0080ac2f  8916                 mov dword ptr [esi], edx
// 0080ac31  894604               mov dword ptr [esi + 4], eax
// 0080ac34  85c9                 test ecx, ecx
// 0080ac36  7508                 jne 0x80ac40
// 0080ac38  99                   cdq 
// 0080ac39  2bc2                 sub eax, edx
// 0080ac3b  d1f8                 sar eax, 1
// 0080ac3d  894604               mov dword ptr [esi + 4], eax
// 0080ac40  8b442410             mov eax, dword ptr [esp + 0x10]
// 0080ac44  57                   push edi
// 0080ac45  8b3d3cb19800         mov edi, dword ptr [0x98b13c]
// 0080ac4b  85c0                 test eax, eax
// 0080ac4d  7407                 je 0x80ac56
// 0080ac4f  50                   push eax
// 0080ac50  ffd7                 call edi
// 0080ac52  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0080ac56  85c9                 test ecx, ecx
// 0080ac58  7403                 je 0x80ac5d
// 0080ac5a  51                   push ecx
// 0080ac5b  ffd7                 call edi
// 0080ac5d  5f                   pop edi
// 0080ac5e  8bc6                 mov eax, esi
// 0080ac60  5e                   pop esi
// 0080ac61  83c42c               add esp, 0x2c
// 0080ac64  c3                   ret 
// 0080ac65  8bc6                 mov eax, esi
// 0080ac67  5e                   pop esi
// 0080ac68  83c42c               add esp, 0x2c
// 0080ac6b  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetExtent@CXTPImageManagerIcon@@SA?AVCSize@@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
