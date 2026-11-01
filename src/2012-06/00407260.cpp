// from server: 100% by auto
// roc 2012-06 00407260  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00407260
//
// 00407260  56                   push esi
// 00407261  8b742408             mov esi, dword ptr [esp + 8]
// 00407265  57                   push edi
// 00407266  8d4604               lea eax, [esi + 4]
// 00407269  50                   push eax
// 0040726a  ff159421b200         call dword ptr [0xb22194]
// 00407270  8bf8                 mov edi, eax
// 00407272  85ff                 test edi, edi
// 00407274  7511                 jne 0x407287
// 00407276  85f6                 test esi, esi
// 00407278  740d                 je 0x407287
// 0040727a  8b16                 mov edx, dword ptr [esi]
// 0040727c  8b4214               mov eax, dword ptr [edx + 0x14]
// 0040727f  6a01                 push 1
// 00407281  8bce                 mov ecx, esi
// 00407283  ffd0                 call eax
// 00407285  8bc7                 mov eax, edi
// 00407287  5f                   pop edi
// 00407288  5e                   pop esi
// 00407289  c20400               ret 4
// library atl-9.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
