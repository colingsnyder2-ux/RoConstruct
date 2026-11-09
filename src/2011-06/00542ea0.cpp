// from server: 100% by auto
// roc 2011-06 00542ea0  unit: G3D::Sphere  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542ea0
//
// 00542ea0  f60580a3cb0001       test byte ptr [0xcba380], 1
// 00542ea7  7514                 jne 0x542ebd
// 00542ea9  a17005a400           mov eax, dword ptr [0xa40570]
// 00542eae  dd00                 fld qword ptr [eax]
// 00542eb0  830d80a3cb0001       or dword ptr [0xcba380], 1
// 00542eb7  d91d7ca3cb00         fstp dword ptr [0xcba37c]
// 00542ebd  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00542ec1  8b157ca3cb00         mov edx, dword ptr [0xcba37c]
// 00542ec7  3bca                 cmp ecx, edx
// 00542ec9  7436                 je 0x542f01
// 00542ecb  56                   push esi
// 00542ecc  0fb6f2               movzx esi, dl
// 00542ecf  0fb6c1               movzx eax, cl
// 00542ed2  2bc6                 sub eax, esi
// 00542ed4  5e                   pop esi
// 00542ed5  7536                 jne 0x542f0d
// 00542ed7  0fb6d6               movzx edx, dh
// 00542eda  0fb6c5               movzx eax, ch
// 00542edd  2bc2                 sub eax, edx
// 00542edf  752c                 jne 0x542f0d
// 00542ee1  0fb60d7ea3cb00       movzx ecx, byte ptr [0xcba37e]
// 00542ee8  0fb6442406           movzx eax, byte ptr [esp + 6]
// 00542eed  2bc1                 sub eax, ecx
// 00542eef  751c                 jne 0x542f0d
// 00542ef1  0fb6157fa3cb00       movzx edx, byte ptr [0xcba37f]
// 00542ef8  0fb6442407           movzx eax, byte ptr [esp + 7]
// 00542efd  2bc2                 sub eax, edx
// 00542eff  750c                 jne 0x542f0d
// 00542f01  33c0                 xor eax, eax
// 00542f03  33c9                 xor ecx, ecx
// 00542f05  85c0                 test eax, eax
// 00542f07  0f94c1               sete cl
// 00542f0a  8ac1                 mov al, cl
// 00542f0c  c3                   ret 
// 00542f0d  c1f81f               sar eax, 0x1f
// 00542f10  83c801               or eax, 1
// 00542f13  33c9                 xor ecx, ecx
// 00542f15  85c0                 test eax, eax
// 00542f17  0f94c1               sete cl
// 00542f1a  8ac1                 mov al, cl
// 00542f1c  c3                   ret 
// library rbx2016-g3d/g3dmath.cpp (function ?isNaN@G3D@@YA_NM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dmath.cpp
