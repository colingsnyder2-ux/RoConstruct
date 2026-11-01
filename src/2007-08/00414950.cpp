// from server: 100% by auto
// roc 2007-08 00414950  unit: DHTMLWindow  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00414950
//
// 00414950  57                   push edi
// 00414951  8b7c2408             mov edi, dword ptr [esp + 8]
// 00414955  85ff                 test edi, edi
// 00414957  7506                 jne 0x41495f
// 00414959  33c0                 xor eax, eax
// 0041495b  5f                   pop edi
// 0041495c  c20400               ret 4
// 0041495f  53                   push ebx
// 00414960  55                   push ebp
// 00414961  56                   push esi
// 00414962  8d6f04               lea ebp, [edi + 4]
// 00414965  55                   push ebp
// 00414966  33db                 xor ebx, ebx
// 00414968  ff15fcd27700         call dword ptr [0x77d2fc]
// 0041496e  8b771c               mov esi, dword ptr [edi + 0x1c]
// 00414971  85f6                 test esi, esi
// 00414973  744d                 je 0x4149c2
// 00414975  ff15c4d27700         call dword ptr [0x77d2c4]
// 0041497b  33c9                 xor ecx, ecx
// 0041497d  8d4900               lea ecx, [ecx]
// 00414980  394604               cmp dword ptr [esi + 4], eax
// 00414983  7419                 je 0x41499e
// 00414985  8bce                 mov ecx, esi
// 00414987  8b7608               mov esi, dword ptr [esi + 8]
// 0041498a  85f6                 test esi, esi
// 0041498c  75f2                 jne 0x414980
// 0041498e  55                   push ebp
// 0041498f  ff15f8d27700         call dword ptr [0x77d2f8]
// 00414995  5e                   pop esi
// 00414996  5d                   pop ebp
// 00414997  8bc3                 mov eax, ebx
// 00414999  5b                   pop ebx
// 0041499a  5f                   pop edi
// 0041499b  c20400               ret 4
// 0041499e  85c9                 test ecx, ecx
// 004149a0  7518                 jne 0x4149ba
// 004149a2  8b4608               mov eax, dword ptr [esi + 8]
// 004149a5  89471c               mov dword ptr [edi + 0x1c], eax
// 004149a8  8b1e                 mov ebx, dword ptr [esi]
// 004149aa  55                   push ebp
// 004149ab  ff15f8d27700         call dword ptr [0x77d2f8]
// 004149b1  5e                   pop esi
// 004149b2  5d                   pop ebp
// 004149b3  8bc3                 mov eax, ebx
// 004149b5  5b                   pop ebx
// 004149b6  5f                   pop edi
// 004149b7  c20400               ret 4
// 004149ba  8b5608               mov edx, dword ptr [esi + 8]
// 004149bd  895108               mov dword ptr [ecx + 8], edx
// 004149c0  8b1e                 mov ebx, dword ptr [esi]
// 004149c2  55                   push ebp
// 004149c3  ff15f8d27700         call dword ptr [0x77d2f8]
// 004149c9  5e                   pop esi
// 004149ca  5d                   pop ebp
// 004149cb  8bc3                 mov eax, ebx
// 004149cd  5b                   pop ebx
// 004149ce  5f                   pop edi
// 004149cf  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlWinModuleExtractCreateWndData@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
