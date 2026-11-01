// from server: 100% by auto
// roc 2012-06 0046f230  unit: CRobloxModule  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046f230
//
// 0046f230  53                   push ebx
// 0046f231  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0046f235  85db                 test ebx, ebx
// 0046f237  7509                 jne 0x46f242
// 0046f239  b803400080           mov eax, 0x80004003
// 0046f23e  5b                   pop ebx
// 0046f23f  c20400               ret 4
// 0046f242  56                   push esi
// 0046f243  57                   push edi
// 0046f244  33ff                 xor edi, edi
// 0046f246  397928               cmp dword ptr [ecx + 0x28], edi
// 0046f249  8d7128               lea esi, [ecx + 0x28]
// 0046f24c  751a                 jne 0x46f268
// 0046f24e  56                   push esi
// 0046f24f  68f89eb500           push 0xb59ef8
// 0046f254  6a01                 push 1
// 0046f256  57                   push edi
// 0046f257  6878cdc000           push 0xc0cd78
// 0046f25c  ff151851b200         call dword ptr [0xb25118]
// 0046f262  8bf8                 mov edi, eax
// 0046f264  85ff                 test edi, edi
// 0046f266  7c0e                 jl 0x46f276
// 0046f268  8b06                 mov eax, dword ptr [esi]
// 0046f26a  8903                 mov dword ptr [ebx], eax
// 0046f26c  8b36                 mov esi, dword ptr [esi]
// 0046f26e  8b0e                 mov ecx, dword ptr [esi]
// 0046f270  8b5104               mov edx, dword ptr [ecx + 4]
// 0046f273  56                   push esi
// 0046f274  ffd2                 call edx
// 0046f276  8bc7                 mov eax, edi
// 0046f278  5f                   pop edi
// 0046f279  5e                   pop esi
// 0046f27a  5b                   pop ebx
// 0046f27b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
