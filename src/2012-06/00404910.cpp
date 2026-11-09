// from server: 100% by auto
// roc 2012-06 00404910  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404910
//
// 00404910  53                   push ebx
// 00404911  8b1da421b200         mov ebx, dword ptr [0xb221a4]
// 00404917  56                   push esi
// 00404918  57                   push edi
// 00404919  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040491d  be2836b400           mov esi, 0xb43628
// 00404922  8b06                 mov eax, dword ptr [esi]
// 00404924  50                   push eax
// 00404925  57                   push edi
// 00404926  ffd3                 call ebx
// 00404928  85c0                 test eax, eax
// 0040492a  7416                 je 0x404942
// 0040492c  83c604               add esi, 4
// 0040492f  81fe5836b400         cmp esi, 0xb43658
// 00404935  7ceb                 jl 0x404922
// 00404937  5f                   pop edi
// 00404938  5e                   pop esi
// 00404939  b801000000           mov eax, 1
// 0040493e  5b                   pop ebx
// 0040493f  c20400               ret 4
// 00404942  5f                   pop edi
// 00404943  5e                   pop esi
// 00404944  33c0                 xor eax, eax
// 00404946  5b                   pop ebx
// 00404947  c20400               ret 4
// library atl-8.0/atl.cpp (function ?CanForceRemoveKey@CRegParser@ATL@@IAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
