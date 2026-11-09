// from server: 100% by auto
// roc 2010-06 00896180  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00896180
//
// 00896180  8b15ac66c200         mov edx, dword ptr [0xc266ac]
// 00896186  56                   push esi
// 00896187  33c0                 xor eax, eax
// 00896189  57                   push edi
// 0089618a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0089618e  85d2                 test edx, edx
// 00896190  7e18                 jle 0x8961aa
// 00896192  8b35a866c200         mov esi, dword ptr [0xc266a8]
// 00896198  85c0                 test eax, eax
// 0089619a  7c3c                 jl 0x8961d8
// 0089619c  3bc2                 cmp eax, edx
// 0089619e  7d38                 jge 0x8961d8
// 008961a0  3b3c86               cmp edi, dword ptr [esi + eax*4]
// 008961a3  7429                 je 0x8961ce
// 008961a5  40                   inc eax
// 008961a6  3bc2                 cmp eax, edx
// 008961a8  7cee                 jl 0x896198
// 008961aa  33c0                 xor eax, eax
// 008961ac  f681a400000002       test byte ptr [ecx + 0xa4], 2
// 008961b3  742b                 je 0x8961e0
// 008961b5  3bb810b5be00         cmp edi, dword ptr [eax + 0xbeb510]
// 008961bb  7411                 je 0x8961ce
// 008961bd  83c008               add eax, 8
// 008961c0  3d40010000           cmp eax, 0x140
// 008961c5  72ee                 jb 0x8961b5
// 008961c7  5f                   pop edi
// 008961c8  33c0                 xor eax, eax
// 008961ca  5e                   pop esi
// 008961cb  c20400               ret 4
// 008961ce  5f                   pop edi
// 008961cf  b801000000           mov eax, 1
// 008961d4  5e                   pop esi
// 008961d5  c20400               ret 4
// 008961d8  e86f1af1ff           call 0x7a7c4c
// 008961dd  8d4900               lea ecx, [ecx]
// 008961e0  3bb890b4be00         cmp edi, dword ptr [eax + 0xbeb490]
// 008961e6  74e6                 je 0x8961ce
// 008961e8  83c008               add eax, 8
// 008961eb  3d80000000           cmp eax, 0x80
// 008961f0  72ee                 jb 0x8961e0
// 008961f2  5f                   pop edi
// 008961f3  33c0                 xor eax, eax
// 008961f5  5e                   pop esi
// 008961f6  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?LookUpColor@CXTColorSelectorCtrl@@IAEHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
