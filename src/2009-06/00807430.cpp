// from server: 100% by auto
// roc 2009-06 00807430  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00807430
//
// 00807430  8b15242ba500         mov edx, dword ptr [0xa52b24]
// 00807436  56                   push esi
// 00807437  33c0                 xor eax, eax
// 00807439  57                   push edi
// 0080743a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0080743e  85d2                 test edx, edx
// 00807440  7e18                 jle 0x80745a
// 00807442  8b35202ba500         mov esi, dword ptr [0xa52b20]
// 00807448  85c0                 test eax, eax
// 0080744a  7c3c                 jl 0x807488
// 0080744c  3bc2                 cmp eax, edx
// 0080744e  7d38                 jge 0x807488
// 00807450  3b3c86               cmp edi, dword ptr [esi + eax*4]
// 00807453  7429                 je 0x80747e
// 00807455  40                   inc eax
// 00807456  3bc2                 cmp eax, edx
// 00807458  7cee                 jl 0x807448
// 0080745a  33c0                 xor eax, eax
// 0080745c  f681a400000002       test byte ptr [ecx + 0xa4], 2
// 00807463  742b                 je 0x807490
// 00807465  3bb888a4a200         cmp edi, dword ptr [eax + 0xa2a488]
// 0080746b  7411                 je 0x80747e
// 0080746d  83c008               add eax, 8
// 00807470  3d40010000           cmp eax, 0x140
// 00807475  72ee                 jb 0x807465
// 00807477  5f                   pop edi
// 00807478  33c0                 xor eax, eax
// 0080747a  5e                   pop esi
// 0080747b  c20400               ret 4
// 0080747e  5f                   pop edi
// 0080747f  b801000000           mov eax, 1
// 00807484  5e                   pop esi
// 00807485  c20400               ret 4
// 00807488  e85718f1ff           call 0x718ce4
// 0080748d  8d4900               lea ecx, [ecx]
// 00807490  3bb808a4a200         cmp edi, dword ptr [eax + 0xa2a408]
// 00807496  74e6                 je 0x80747e
// 00807498  83c008               add eax, 8
// 0080749b  3d80000000           cmp eax, 0x80
// 008074a0  72ee                 jb 0x807490
// 008074a2  5f                   pop edi
// 008074a3  33c0                 xor eax, eax
// 008074a5  5e                   pop esi
// 008074a6  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?LookUpColor@CXTColorSelectorCtrl@@IAEHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
