// from server: 100% by auto
// roc 2008-06 00403d10  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403d10
//
// 00403d10  56                   push esi
// 00403d11  8b742408             mov esi, dword ptr [esp + 8]
// 00403d15  57                   push edi
// 00403d16  8d4604               lea eax, [esi + 4]
// 00403d19  50                   push eax
// 00403d1a  ff15ac218000         call dword ptr [0x8021ac]
// 00403d20  8bf8                 mov edi, eax
// 00403d22  85ff                 test edi, edi
// 00403d24  7511                 jne 0x403d37
// 00403d26  85f6                 test esi, esi
// 00403d28  740d                 je 0x403d37
// 00403d2a  8b16                 mov edx, dword ptr [esi]
// 00403d2c  8b4214               mov eax, dword ptr [edx + 0x14]
// 00403d2f  6a01                 push 1
// 00403d31  8bce                 mov ecx, esi
// 00403d33  ffd0                 call eax
// 00403d35  8bc7                 mov eax, edi
// 00403d37  5f                   pop edi
// 00403d38  5e                   pop esi
// 00403d39  c20400               ret 4
// library atl-9.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
