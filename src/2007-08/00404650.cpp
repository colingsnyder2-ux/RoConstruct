// from server: 100% by tester
// roc 2007-03 00404550  unit: seg_00400000  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00404550
//
// 00404550  56                   push esi
// 00404551  57                   push edi
// 00404552  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00404556  8b07                 mov eax, dword ptr [edi]
// 00404558  50                   push eax
// 00404559  8bf1                 mov esi, ecx
// 0040455b  e880f1ffff           call 0x4036e0
// 00404560  84c0                 test al, al
// 00404562  7532                 jne 0x404596
// 00404564  85f6                 test esi, esi
// 00404566  8b07                 mov eax, dword ptr [edi]
// 00404568  7507                 jne 0x404571
// 0040456a  5f                   pop edi
// 0040456b  33c0                 xor eax, eax
// 0040456d  5e                   pop esi
// 0040456e  c20400               ret 4
// 00404571  85c0                 test eax, eax
// 00404573  8b3e                 mov edi, dword ptr [esi]
// 00404575  c70600000000         mov dword ptr [esi], 0
// 0040457b  740d                 je 0x40458a
// 0040457d  8b08                 mov ecx, dword ptr [eax]
// 0040457f  8b11                 mov edx, dword ptr [ecx]
// 00404581  56                   push esi
// 00404582  68143f7800           push 0x783f14
// 00404587  50                   push eax
// 00404588  ffd2                 call edx
// 0040458a  85ff                 test edi, edi
// 0040458c  7408                 je 0x404596
// 0040458e  8b07                 mov eax, dword ptr [edi]
// 00404590  8b4808               mov ecx, dword ptr [eax + 8]
// 00404593  57                   push edi
// 00404594  ffd1                 call ecx
// 00404596  8b06                 mov eax, dword ptr [esi]
// 00404598  5f                   pop edi
// 00404599  5e                   pop esi
// 0040459a  c20400               ret 4
// library atl-8.0/atl.cpp (function ??$?4UITypeInfo2@@@?$CComPtr@UITypeInfo@@@ATL@@QAEPAUITypeInfo@@ABV?$CComPtr@UITypeInfo2@@@1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
