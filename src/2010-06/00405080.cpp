// from server: 100% by auto
// roc 2010-06 00405080  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00405080
//
// 00405080  56                   push esi
// 00405081  8b742408             mov esi, dword ptr [esp + 8]
// 00405085  57                   push edi
// 00405086  8d4604               lea eax, [esi + 4]
// 00405089  50                   push eax
// 0040508a  ff157ca39e00         call dword ptr [0x9ea37c]
// 00405090  8bf8                 mov edi, eax
// 00405092  85ff                 test edi, edi
// 00405094  7511                 jne 0x4050a7
// 00405096  85f6                 test esi, esi
// 00405098  740d                 je 0x4050a7
// 0040509a  8b16                 mov edx, dword ptr [esi]
// 0040509c  8b4214               mov eax, dword ptr [edx + 0x14]
// 0040509f  6a01                 push 1
// 004050a1  8bce                 mov ecx, esi
// 004050a3  ffd0                 call eax
// 004050a5  8bc7                 mov eax, edi
// 004050a7  5f                   pop edi
// 004050a8  5e                   pop esi
// 004050a9  c20400               ret 4
// library atl-9.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
