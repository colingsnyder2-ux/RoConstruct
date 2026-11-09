// from server: 100% by auto
// roc 2009-06 00705e20  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00705e20
//
// 00705e20  83ec08               sub esp, 8
// 00705e23  55                   push ebp
// 00705e24  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00705e2a  56                   push esi
// 00705e2b  8bf1                 mov esi, ecx
// 00705e2d  57                   push edi
// 00705e2e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00705e31  397e0c               cmp dword ptr [esi + 0xc], edi
// 00705e34  7602                 jbe 0x705e38
// 00705e36  ffd5                 call ebp
// 00705e38  8b36                 mov esi, dword ptr [esi]
// 00705e3a  53                   push ebx
// 00705e3b  8bde                 mov ebx, esi
// 00705e3d  897c2414             mov dword ptr [esp + 0x14], edi
// 00705e41  85f6                 test esi, esi
// 00705e43  7514                 jne 0x705e59
// 00705e45  ffd5                 call ebp
// 00705e47  33c0                 xor eax, eax
// 00705e49  8d4ffc               lea ecx, [edi - 4]
// 00705e4c  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 00705e4f  7713                 ja 0x705e64
// 00705e51  85f6                 test esi, esi
// 00705e53  7408                 je 0x705e5d
// 00705e55  8b36                 mov esi, dword ptr [esi]
// 00705e57  eb06                 jmp 0x705e5f
// 00705e59  8b06                 mov eax, dword ptr [esi]
// 00705e5b  ebec                 jmp 0x705e49
// 00705e5d  33f6                 xor esi, esi
// 00705e5f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 00705e62  7302                 jae 0x705e66
// 00705e64  ffd5                 call ebp
// 00705e66  8d77fc               lea esi, [edi - 4]
// 00705e69  85db                 test ebx, ebx
// 00705e6b  7515                 jne 0x705e82
// 00705e6d  ffd5                 call ebp
// 00705e6f  33c0                 xor eax, eax
// 00705e71  5b                   pop ebx
// 00705e72  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00705e75  7202                 jb 0x705e79
// 00705e77  ffd5                 call ebp
// 00705e79  5f                   pop edi
// 00705e7a  8bc6                 mov eax, esi
// 00705e7c  5e                   pop esi
// 00705e7d  5d                   pop ebp
// 00705e7e  83c408               add esp, 8
// 00705e81  c3                   ret 
// 00705e82  8b03                 mov eax, dword ptr [ebx]
// 00705e84  ebeb                 jmp 0x705e71
// standard library vector<ptr> (function ?back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
