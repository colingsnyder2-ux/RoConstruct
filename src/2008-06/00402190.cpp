// from server: 100% by auto
// roc 2008-06 00402190  unit: VCWorkspace::?$CComObject  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402190
//
// 00402190  53                   push ebx
// 00402191  8b1db4218000         mov ebx, dword ptr [0x8021b4]
// 00402197  56                   push esi
// 00402198  57                   push edi
// 00402199  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040219d  bed8ad8000           mov esi, 0x80add8
// 004021a2  8b06                 mov eax, dword ptr [esi]
// 004021a4  50                   push eax
// 004021a5  57                   push edi
// 004021a6  ffd3                 call ebx
// 004021a8  85c0                 test eax, eax
// 004021aa  7416                 je 0x4021c2
// 004021ac  83c604               add esi, 4
// 004021af  81fe08ae8000         cmp esi, 0x80ae08
// 004021b5  7ceb                 jl 0x4021a2
// 004021b7  5f                   pop edi
// 004021b8  5e                   pop esi
// 004021b9  b801000000           mov eax, 1
// 004021be  5b                   pop ebx
// 004021bf  c20400               ret 4
// 004021c2  5f                   pop edi
// 004021c3  5e                   pop esi
// 004021c4  33c0                 xor eax, eax
// 004021c6  5b                   pop ebx
// 004021c7  c20400               ret 4
// library atl-8.0/atl.cpp (function ?CanForceRemoveKey@CRegParser@ATL@@IAEHPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
