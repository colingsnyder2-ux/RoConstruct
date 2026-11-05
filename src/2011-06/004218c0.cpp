// from server: 100% by auto
// roc 2011-06 004218c0  unit: RBX::FunctionMarshaller  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004218c0
//
// 004218c0  57                   push edi
// 004218c1  8b7c2408             mov edi, dword ptr [esp + 8]
// 004218c5  85ff                 test edi, edi
// 004218c7  7506                 jne 0x4218cf
// 004218c9  33c0                 xor eax, eax
// 004218cb  5f                   pop edi
// 004218cc  c20400               ret 4
// 004218cf  53                   push ebx
// 004218d0  55                   push ebp
// 004218d1  56                   push esi
// 004218d2  8d6f04               lea ebp, [edi + 4]
// 004218d5  55                   push ebp
// 004218d6  33db                 xor ebx, ebx
// 004218d8  ff158403a400         call dword ptr [0xa40384]
// 004218de  8b771c               mov esi, dword ptr [edi + 0x1c]
// 004218e1  85f6                 test esi, esi
// 004218e3  744d                 je 0x421932
// 004218e5  ff157003a400         call dword ptr [0xa40370]
// 004218eb  33c9                 xor ecx, ecx
// 004218ed  8d4900               lea ecx, [ecx]
// 004218f0  394604               cmp dword ptr [esi + 4], eax
// 004218f3  7419                 je 0x42190e
// 004218f5  8bce                 mov ecx, esi
// 004218f7  8b7608               mov esi, dword ptr [esi + 8]
// 004218fa  85f6                 test esi, esi
// 004218fc  75f2                 jne 0x4218f0
// 004218fe  55                   push ebp
// 004218ff  ff158003a400         call dword ptr [0xa40380]
// 00421905  5e                   pop esi
// 00421906  5d                   pop ebp
// 00421907  8bc3                 mov eax, ebx
// 00421909  5b                   pop ebx
// 0042190a  5f                   pop edi
// 0042190b  c20400               ret 4
// 0042190e  85c9                 test ecx, ecx
// 00421910  7518                 jne 0x42192a
// 00421912  8b4608               mov eax, dword ptr [esi + 8]
// 00421915  89471c               mov dword ptr [edi + 0x1c], eax
// 00421918  8b1e                 mov ebx, dword ptr [esi]
// 0042191a  55                   push ebp
// 0042191b  ff158003a400         call dword ptr [0xa40380]
// 00421921  5e                   pop esi
// 00421922  5d                   pop ebp
// 00421923  8bc3                 mov eax, ebx
// 00421925  5b                   pop ebx
// 00421926  5f                   pop edi
// 00421927  c20400               ret 4
// 0042192a  8b5608               mov edx, dword ptr [esi + 8]
// 0042192d  895108               mov dword ptr [ecx + 8], edx
// 00421930  8b1e                 mov ebx, dword ptr [esi]
// 00421932  55                   push ebp
// 00421933  ff158003a400         call dword ptr [0xa40380]
// 00421939  5e                   pop esi
// 0042193a  5d                   pop ebp
// 0042193b  8bc3                 mov eax, ebx
// 0042193d  5b                   pop ebx
// 0042193e  5f                   pop edi
// 0042193f  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlWinModuleExtractCreateWndData@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
