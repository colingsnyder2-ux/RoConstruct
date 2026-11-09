// from server: 100% by auto
// roc 2009-12 004038b0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004038b0
//
// 004038b0  53                   push ebx
// 004038b1  55                   push ebp
// 004038b2  56                   push esi
// 004038b3  57                   push edi
// 004038b4  8bf9                 mov edi, ecx
// 004038b6  33f6                 xor esi, esi
// 004038b8  397708               cmp dword ptr [edi + 8], esi
// 004038bb  7e1f                 jle 0x4038dc
// 004038bd  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004038c1  8b2d14b29800         mov ebp, dword ptr [0x98b214]
// 004038c7  8b03                 mov eax, dword ptr [ebx]
// 004038c9  8b0f                 mov ecx, dword ptr [edi]
// 004038cb  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 004038ce  50                   push eax
// 004038cf  51                   push ecx
// 004038d0  ffd5                 call ebp
// 004038d2  85c0                 test eax, eax
// 004038d4  7410                 je 0x4038e6
// 004038d6  46                   inc esi
// 004038d7  3b7708               cmp esi, dword ptr [edi + 8]
// 004038da  7ceb                 jl 0x4038c7
// 004038dc  5f                   pop edi
// 004038dd  5e                   pop esi
// 004038de  5d                   pop ebp
// 004038df  83c8ff               or eax, 0xffffffff
// 004038e2  5b                   pop ebx
// 004038e3  c20400               ret 4
// 004038e6  5f                   pop edi
// 004038e7  8bc6                 mov eax, esi
// 004038e9  5e                   pop esi
// 004038ea  5d                   pop ebp
// 004038eb  5b                   pop ebx
// 004038ec  c20400               ret 4
// library atl-9.0/atl.cpp (function ?FindKey@?$CSimpleMap@PADPA_WVCExpansionVectorEqualHelper@ATL@@@ATL@@QBEHABQAD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
