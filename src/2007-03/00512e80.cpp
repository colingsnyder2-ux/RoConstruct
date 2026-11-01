// from server: 100% by auto
// roc 2007-03 00512e80  unit: seg_00510000  size: 286 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00512e80
//
// 00512e80  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00512e84  85c9                 test ecx, ecx
// 00512e86  53                   push ebx
// 00512e87  55                   push ebp
// 00512e88  56                   push esi
// 00512e89  57                   push edi
// 00512e8a  0f8407010000         je 0x512f97
// 00512e90  8b742418             mov esi, dword ptr [esp + 0x18]
// 00512e94  85f6                 test esi, esi
// 00512e96  0f84fb000000         je 0x512f97
// 00512e9c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00512ea0  85db                 test ebx, ebx
// 00512ea2  0f84ef000000         je 0x512f97
// 00512ea8  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00512eac  85ed                 test ebp, ebp
// 00512eae  0f84e3000000         je 0x512f97
// 00512eb4  8b442424             mov eax, dword ptr [esp + 0x24]
// 00512eb8  85c0                 test eax, eax
// 00512eba  0f84d7000000         je 0x512f97
// 00512ec0  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00512ec4  85ff                 test edi, edi
// 00512ec6  0f84cb000000         je 0x512f97
// 00512ecc  8b16                 mov edx, dword ptr [esi]
// 00512ece  8913                 mov dword ptr [ebx], edx
// 00512ed0  8b5604               mov edx, dword ptr [esi + 4]
// 00512ed3  895500               mov dword ptr [ebp], edx
// 00512ed6  0fb65618             movzx edx, byte ptr [esi + 0x18]
// 00512eda  8910                 mov dword ptr [eax], edx
// 00512edc  807e1801             cmp byte ptr [esi + 0x18], 1
// 00512ee0  7206                 jb 0x512ee8
// 00512ee2  807e1810             cmp byte ptr [esi + 0x18], 0x10
// 00512ee6  7612                 jbe 0x512efa
// 00512ee8  6890277a00           push 0x7a2790
// 00512eed  51                   push ecx
// 00512eee  e82d540000           call 0x518320
// 00512ef3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00512ef7  83c408               add esp, 8
// 00512efa  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 00512efe  8907                 mov dword ptr [edi], eax
// 00512f00  807e1906             cmp byte ptr [esi + 0x19], 6
// 00512f04  7612                 jbe 0x512f18
// 00512f06  687c277a00           push 0x7a277c
// 00512f0b  51                   push ecx
// 00512f0c  e80f540000           call 0x518320
// 00512f11  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00512f15  83c408               add esp, 8
// 00512f18  8b442430             mov eax, dword ptr [esp + 0x30]
// 00512f1c  85c0                 test eax, eax
// 00512f1e  7406                 je 0x512f26
// 00512f20  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00512f24  8910                 mov dword ptr [eax], edx
// 00512f26  8b442434             mov eax, dword ptr [esp + 0x34]
// 00512f2a  85c0                 test eax, eax
// 00512f2c  7406                 je 0x512f34
// 00512f2e  0fb6561b             movzx edx, byte ptr [esi + 0x1b]
// 00512f32  8910                 mov dword ptr [eax], edx
// 00512f34  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00512f38  85c0                 test eax, eax
// 00512f3a  7406                 je 0x512f42
// 00512f3c  0fb6561c             movzx edx, byte ptr [esi + 0x1c]
// 00512f40  8910                 mov dword ptr [eax], edx
// 00512f42  813bffffff7f         cmp dword ptr [ebx], 0x7fffffff
// 00512f48  7612                 jbe 0x512f5c
// 00512f4a  6868277a00           push 0x7a2768
// 00512f4f  51                   push ecx
// 00512f50  e8cb530000           call 0x518320
// 00512f55  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00512f59  83c408               add esp, 8
// 00512f5c  817d00ffffff7f       cmp dword ptr [ebp], 0x7fffffff
// 00512f63  7612                 jbe 0x512f77
// 00512f65  6850277a00           push 0x7a2750
// 00512f6a  51                   push ecx
// 00512f6b  e8b0530000           call 0x518320
// 00512f70  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00512f74  83c408               add esp, 8
// 00512f77  813e7effff1f         cmp dword ptr [esi], 0x1fffff7e
// 00512f7d  760e                 jbe 0x512f8d
// 00512f7f  681c277a00           push 0x7a271c
// 00512f84  51                   push ecx
// 00512f85  e846540000           call 0x5183d0
// 00512f8a  83c408               add esp, 8
// 00512f8d  5f                   pop edi
// 00512f8e  5e                   pop esi
// 00512f8f  5d                   pop ebp
// 00512f90  b801000000           mov eax, 1
// 00512f95  5b                   pop ebx
// 00512f96  c3                   ret 
// 00512f97  5f                   pop edi
// 00512f98  5e                   pop esi
// 00512f99  5d                   pop ebp
// 00512f9a  33c0                 xor eax, eax
// 00512f9c  5b                   pop ebx
// 00512f9d  c3                   ret 
// library libpng-1.2.7/pngget.c (function _png_get_IHDR)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngget.c
