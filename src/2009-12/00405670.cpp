// from server: 100% by auto
// roc 2009-12 00405670  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00405670
//
// 00405670  56                   push esi
// 00405671  8b742408             mov esi, dword ptr [esp + 8]
// 00405675  57                   push edi
// 00405676  8d4604               lea eax, [esi + 4]
// 00405679  50                   push eax
// 0040567a  ff1508b29800         call dword ptr [0x98b208]
// 00405680  8bf8                 mov edi, eax
// 00405682  85ff                 test edi, edi
// 00405684  7511                 jne 0x405697
// 00405686  85f6                 test esi, esi
// 00405688  740d                 je 0x405697
// 0040568a  8b16                 mov edx, dword ptr [esi]
// 0040568c  8b4214               mov eax, dword ptr [edx + 0x14]
// 0040568f  6a01                 push 1
// 00405691  8bce                 mov ecx, esi
// 00405693  ffd0                 call eax
// 00405695  8bc7                 mov eax, edi
// 00405697  5f                   pop edi
// 00405698  5e                   pop esi
// 00405699  c20400               ret 4
// library atl-9.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
