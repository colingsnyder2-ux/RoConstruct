// from server: 100% by auto
// roc 2009-12 007e2860  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e2860
//
// 007e2860  83ec08               sub esp, 8
// 007e2863  55                   push ebp
// 007e2864  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007e286a  56                   push esi
// 007e286b  8bf1                 mov esi, ecx
// 007e286d  57                   push edi
// 007e286e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007e2871  397e0c               cmp dword ptr [esi + 0xc], edi
// 007e2874  7602                 jbe 0x7e2878
// 007e2876  ffd5                 call ebp
// 007e2878  8b36                 mov esi, dword ptr [esi]
// 007e287a  53                   push ebx
// 007e287b  8bde                 mov ebx, esi
// 007e287d  897c2414             mov dword ptr [esp + 0x14], edi
// 007e2881  85f6                 test esi, esi
// 007e2883  7514                 jne 0x7e2899
// 007e2885  ffd5                 call ebp
// 007e2887  33c0                 xor eax, eax
// 007e2889  8d4ffc               lea ecx, [edi - 4]
// 007e288c  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 007e288f  7713                 ja 0x7e28a4
// 007e2891  85f6                 test esi, esi
// 007e2893  7408                 je 0x7e289d
// 007e2895  8b36                 mov esi, dword ptr [esi]
// 007e2897  eb06                 jmp 0x7e289f
// 007e2899  8b06                 mov eax, dword ptr [esi]
// 007e289b  ebec                 jmp 0x7e2889
// 007e289d  33f6                 xor esi, esi
// 007e289f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 007e28a2  7302                 jae 0x7e28a6
// 007e28a4  ffd5                 call ebp
// 007e28a6  8d77fc               lea esi, [edi - 4]
// 007e28a9  85db                 test ebx, ebx
// 007e28ab  7515                 jne 0x7e28c2
// 007e28ad  ffd5                 call ebp
// 007e28af  33c0                 xor eax, eax
// 007e28b1  5b                   pop ebx
// 007e28b2  3b7010               cmp esi, dword ptr [eax + 0x10]
// 007e28b5  7202                 jb 0x7e28b9
// 007e28b7  ffd5                 call ebp
// 007e28b9  5f                   pop edi
// 007e28ba  8bc6                 mov eax, esi
// 007e28bc  5e                   pop esi
// 007e28bd  5d                   pop ebp
// 007e28be  83c408               add esp, 8
// 007e28c1  c3                   ret 
// 007e28c2  8b03                 mov eax, dword ptr [ebx]
// 007e28c4  ebeb                 jmp 0x7e28b1
// standard library vector<ptr> (function ?back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
