// from server: 100% by auto
// roc 2009-06 00406030  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00406030
//
// 00406030  56                   push esi
// 00406031  8b742408             mov esi, dword ptr [esp + 8]
// 00406035  57                   push edi
// 00406036  8d4604               lea eax, [esi + 4]
// 00406039  50                   push eax
// 0040603a  ff15a4e18900         call dword ptr [0x89e1a4]
// 00406040  8bf8                 mov edi, eax
// 00406042  85ff                 test edi, edi
// 00406044  7511                 jne 0x406057
// 00406046  85f6                 test esi, esi
// 00406048  740d                 je 0x406057
// 0040604a  8b16                 mov edx, dword ptr [esi]
// 0040604c  8b4214               mov eax, dword ptr [edx + 0x14]
// 0040604f  6a01                 push 1
// 00406051  8bce                 mov ecx, esi
// 00406053  ffd0                 call eax
// 00406055  8bc7                 mov eax, edi
// 00406057  5f                   pop edi
// 00406058  5e                   pop esi
// 00406059  c20400               ret 4
// library atl-9.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
