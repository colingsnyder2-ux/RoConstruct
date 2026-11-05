// from server: 100% by auto
// roc 2011-06 004068d0  unit: ATL::VCComClassFactory::?$CComObjectNoLock  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004068d0
//
// 004068d0  56                   push esi
// 004068d1  8b742408             mov esi, dword ptr [esp + 8]
// 004068d5  57                   push edi
// 004068d6  8d4604               lea eax, [esi + 4]
// 004068d9  50                   push eax
// 004068da  ff154803a400         call dword ptr [0xa40348]
// 004068e0  8bf8                 mov edi, eax
// 004068e2  85ff                 test edi, edi
// 004068e4  7511                 jne 0x4068f7
// 004068e6  85f6                 test esi, esi
// 004068e8  740d                 je 0x4068f7
// 004068ea  8b16                 mov edx, dword ptr [esi]
// 004068ec  8b4214               mov eax, dword ptr [edx + 0x14]
// 004068ef  6a01                 push 1
// 004068f1  8bce                 mov ecx, esi
// 004068f3  ffd0                 call eax
// 004068f5  8bc7                 mov eax, edi
// 004068f7  5f                   pop edi
// 004068f8  5e                   pop esi
// 004068f9  c20400               ret 4
// library atl-9.0/atl.cpp (function ?Release@?$CComObjectNoLock@VCComClassFactory@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
