// from server: 100% by auto
// roc 2009-12 008e1ef0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e1ef0
//
// 008e1ef0  8b157cbfb900         mov edx, dword ptr [0xb9bf7c]
// 008e1ef6  56                   push esi
// 008e1ef7  33c0                 xor eax, eax
// 008e1ef9  57                   push edi
// 008e1efa  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008e1efe  85d2                 test edx, edx
// 008e1f00  7e18                 jle 0x8e1f1a
// 008e1f02  8b3578bfb900         mov esi, dword ptr [0xb9bf78]
// 008e1f08  85c0                 test eax, eax
// 008e1f0a  7c3c                 jl 0x8e1f48
// 008e1f0c  3bc2                 cmp eax, edx
// 008e1f0e  7d38                 jge 0x8e1f48
// 008e1f10  3b3c86               cmp edi, dword ptr [esi + eax*4]
// 008e1f13  7429                 je 0x8e1f3e
// 008e1f15  40                   inc eax
// 008e1f16  3bc2                 cmp eax, edx
// 008e1f18  7cee                 jl 0x8e1f08
// 008e1f1a  33c0                 xor eax, eax
// 008e1f1c  f681a400000002       test byte ptr [ecx + 0xa4], 2
// 008e1f23  742b                 je 0x8e1f50
// 008e1f25  3bb858a7b600         cmp edi, dword ptr [eax + 0xb6a758]
// 008e1f2b  7411                 je 0x8e1f3e
// 008e1f2d  83c008               add eax, 8
// 008e1f30  3d40010000           cmp eax, 0x140
// 008e1f35  72ee                 jb 0x8e1f25
// 008e1f37  5f                   pop edi
// 008e1f38  33c0                 xor eax, eax
// 008e1f3a  5e                   pop esi
// 008e1f3b  c20400               ret 4
// 008e1f3e  5f                   pop edi
// 008e1f3f  b801000000           mov eax, 1
// 008e1f44  5e                   pop esi
// 008e1f45  c20400               ret 4
// 008e1f48  e8bf1bf1ff           call 0x7f3b0c
// 008e1f4d  8d4900               lea ecx, [ecx]
// 008e1f50  3bb8d8a6b600         cmp edi, dword ptr [eax + 0xb6a6d8]
// 008e1f56  74e6                 je 0x8e1f3e
// 008e1f58  83c008               add eax, 8
// 008e1f5b  3d80000000           cmp eax, 0x80
// 008e1f60  72ee                 jb 0x8e1f50
// 008e1f62  5f                   pop edi
// 008e1f63  33c0                 xor eax, eax
// 008e1f65  5e                   pop esi
// 008e1f66  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorSelectorCtrl.cpp (function ?LookUpColor@CXTColorSelectorCtrl@@IAEHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorSelectorCtrl.cpp
