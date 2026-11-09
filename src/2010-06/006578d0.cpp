// from server: 100% by auto
// roc 2010-06 006578d0  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006578d0
//
// 006578d0  83ec08               sub esp, 8
// 006578d3  55                   push ebp
// 006578d4  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006578da  56                   push esi
// 006578db  8bf1                 mov esi, ecx
// 006578dd  57                   push edi
// 006578de  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006578e1  397e0c               cmp dword ptr [esi + 0xc], edi
// 006578e4  7602                 jbe 0x6578e8
// 006578e6  ffd5                 call ebp
// 006578e8  8b36                 mov esi, dword ptr [esi]
// 006578ea  53                   push ebx
// 006578eb  8bde                 mov ebx, esi
// 006578ed  897c2414             mov dword ptr [esp + 0x14], edi
// 006578f1  85f6                 test esi, esi
// 006578f3  7514                 jne 0x657909
// 006578f5  ffd5                 call ebp
// 006578f7  33c0                 xor eax, eax
// 006578f9  8d4fe0               lea ecx, [edi - 0x20]
// 006578fc  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 006578ff  7713                 ja 0x657914
// 00657901  85f6                 test esi, esi
// 00657903  7408                 je 0x65790d
// 00657905  8b36                 mov esi, dword ptr [esi]
// 00657907  eb06                 jmp 0x65790f
// 00657909  8b06                 mov eax, dword ptr [esi]
// 0065790b  ebec                 jmp 0x6578f9
// 0065790d  33f6                 xor esi, esi
// 0065790f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 00657912  7302                 jae 0x657916
// 00657914  ffd5                 call ebp
// 00657916  8d77e0               lea esi, [edi - 0x20]
// 00657919  85db                 test ebx, ebx
// 0065791b  7515                 jne 0x657932
// 0065791d  ffd5                 call ebp
// 0065791f  33c0                 xor eax, eax
// 00657921  5b                   pop ebx
// 00657922  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00657925  7202                 jb 0x657929
// 00657927  ffd5                 call ebp
// 00657929  5f                   pop edi
// 0065792a  8bc6                 mov eax, esi
// 0065792c  5e                   pop esi
// 0065792d  5d                   pop ebp
// 0065792e  83c408               add esp, 8
// 00657931  c3                   ret 
// 00657932  8b03                 mov eax, dword ptr [ebx]
// 00657934  ebeb                 jmp 0x657921
// standard library vector<pod32> (function ?back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEAAUE@@XZ)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
