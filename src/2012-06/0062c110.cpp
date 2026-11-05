// from server: 100% by auto
// roc 2012-06 0062c110  unit: G3D::Sphere  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c110
//
// 0062c110  f6056086e20001       test byte ptr [0xe28660], 1
// 0062c117  7514                 jne 0x62c12d
// 0062c119  a11825b200           mov eax, dword ptr [0xb22518]
// 0062c11e  dd00                 fld qword ptr [eax]
// 0062c120  830d6086e20001       or dword ptr [0xe28660], 1
// 0062c127  d91d5c86e200         fstp dword ptr [0xe2865c]
// 0062c12d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062c131  8b155c86e200         mov edx, dword ptr [0xe2865c]
// 0062c137  3bca                 cmp ecx, edx
// 0062c139  7436                 je 0x62c171
// 0062c13b  56                   push esi
// 0062c13c  0fb6f2               movzx esi, dl
// 0062c13f  0fb6c1               movzx eax, cl
// 0062c142  2bc6                 sub eax, esi
// 0062c144  5e                   pop esi
// 0062c145  7536                 jne 0x62c17d
// 0062c147  0fb6d6               movzx edx, dh
// 0062c14a  0fb6c5               movzx eax, ch
// 0062c14d  2bc2                 sub eax, edx
// 0062c14f  752c                 jne 0x62c17d
// 0062c151  0fb60d5e86e200       movzx ecx, byte ptr [0xe2865e]
// 0062c158  0fb6442406           movzx eax, byte ptr [esp + 6]
// 0062c15d  2bc1                 sub eax, ecx
// 0062c15f  751c                 jne 0x62c17d
// 0062c161  0fb6155f86e200       movzx edx, byte ptr [0xe2865f]
// 0062c168  0fb6442407           movzx eax, byte ptr [esp + 7]
// 0062c16d  2bc2                 sub eax, edx
// 0062c16f  750c                 jne 0x62c17d
// 0062c171  33c0                 xor eax, eax
// 0062c173  33c9                 xor ecx, ecx
// 0062c175  85c0                 test eax, eax
// 0062c177  0f94c1               sete cl
// 0062c17a  8ac1                 mov al, cl
// 0062c17c  c3                   ret 
// 0062c17d  c1f81f               sar eax, 0x1f
// 0062c180  83c801               or eax, 1
// 0062c183  33c9                 xor ecx, ecx
// 0062c185  85c0                 test eax, eax
// 0062c187  0f94c1               sete cl
// 0062c18a  8ac1                 mov al, cl
// 0062c18c  c3                   ret 
// library rbx2016-g3d/g3dmath.cpp (function ?isNaN@G3D@@YA_NM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dmath.cpp
