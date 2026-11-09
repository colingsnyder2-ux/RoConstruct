// from server: 100% by auto
// roc 2011-06 008eed30  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008eed30
//
// 008eed30  8b159492d100         mov edx, dword ptr [0xd19294]
// 008eed36  56                   push esi
// 008eed37  33c0                 xor eax, eax
// 008eed39  57                   push edi
// 008eed3a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008eed3e  85d2                 test edx, edx
// 008eed40  7e18                 jle 0x8eed5a
// 008eed42  8b359092d100         mov esi, dword ptr [0xd19290]
// 008eed48  85c0                 test eax, eax
// 008eed4a  7c3c                 jl 0x8eed88
// 008eed4c  3bc2                 cmp eax, edx
// 008eed4e  7d38                 jge 0x8eed88
// 008eed50  3b3c86               cmp edi, dword ptr [esi + eax*4]
// 008eed53  7429                 je 0x8eed7e
// 008eed55  40                   inc eax
// 008eed56  3bc2                 cmp eax, edx
// 008eed58  7cee                 jl 0x8eed48
// 008eed5a  33c0                 xor eax, eax
// 008eed5c  f681a400000002       test byte ptr [ecx + 0xa4], 2
// 008eed63  742b                 je 0x8eed90
// 008eed65  3bb830aac900         cmp edi, dword ptr [eax + 0xc9aa30]
// 008eed6b  7411                 je 0x8eed7e
// 008eed6d  83c008               add eax, 8
// 008eed70  3d40010000           cmp eax, 0x140
// 008eed75  72ee                 jb 0x8eed65
// 008eed77  5f                   pop edi
// 008eed78  33c0                 xor eax, eax
// 008eed7a  5e                   pop esi
// 008eed7b  c20400               ret 4
// 008eed7e  5f                   pop edi
// 008eed7f  b801000000           mov eax, 1
// 008eed84  5e                   pop esi
// 008eed85  c20400               ret 4
// 008eed88  e87db5f1ff           call 0x80a30a
// 008eed8d  8d4900               lea ecx, [ecx]
// 008eed90  3bb8b0a9c900         cmp edi, dword ptr [eax + 0xc9a9b0]
// 008eed96  74e6                 je 0x8eed7e
// 008eed98  83c008               add eax, 8
// 008eed9b  3d80000000           cmp eax, 0x80
// 008eeda0  72ee                 jb 0x8eed90
// 008eeda2  5f                   pop edi
// 008eeda3  33c0                 xor eax, eax
// 008eeda5  5e                   pop esi
// 008eeda6  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?LookUpColor@CXTColorSelectorCtrl@@IAEHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
