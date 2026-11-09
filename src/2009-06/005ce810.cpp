// from server: 100% by auto
// roc 2009-06 005ce810  unit: RBX::P8Instance::?$GetSetImpl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ce810
//
// 005ce810  83ec08               sub esp, 8
// 005ce813  55                   push ebp
// 005ce814  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 005ce81a  56                   push esi
// 005ce81b  8bf1                 mov esi, ecx
// 005ce81d  57                   push edi
// 005ce81e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005ce821  397e0c               cmp dword ptr [esi + 0xc], edi
// 005ce824  7602                 jbe 0x5ce828
// 005ce826  ffd5                 call ebp
// 005ce828  8b36                 mov esi, dword ptr [esi]
// 005ce82a  53                   push ebx
// 005ce82b  8bde                 mov ebx, esi
// 005ce82d  897c2414             mov dword ptr [esp + 0x14], edi
// 005ce831  85f6                 test esi, esi
// 005ce833  7514                 jne 0x5ce849
// 005ce835  ffd5                 call ebp
// 005ce837  33c0                 xor eax, eax
// 005ce839  8d4ff8               lea ecx, [edi - 8]
// 005ce83c  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 005ce83f  7713                 ja 0x5ce854
// 005ce841  85f6                 test esi, esi
// 005ce843  7408                 je 0x5ce84d
// 005ce845  8b36                 mov esi, dword ptr [esi]
// 005ce847  eb06                 jmp 0x5ce84f
// 005ce849  8b06                 mov eax, dword ptr [esi]
// 005ce84b  ebec                 jmp 0x5ce839
// 005ce84d  33f6                 xor esi, esi
// 005ce84f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 005ce852  7302                 jae 0x5ce856
// 005ce854  ffd5                 call ebp
// 005ce856  8d77f8               lea esi, [edi - 8]
// 005ce859  85db                 test ebx, ebx
// 005ce85b  7515                 jne 0x5ce872
// 005ce85d  ffd5                 call ebp
// 005ce85f  33c0                 xor eax, eax
// 005ce861  5b                   pop ebx
// 005ce862  3b7010               cmp esi, dword ptr [eax + 0x10]
// 005ce865  7202                 jb 0x5ce869
// 005ce867  ffd5                 call ebp
// 005ce869  5f                   pop edi
// 005ce86a  8bc6                 mov eax, esi
// 005ce86c  5e                   pop esi
// 005ce86d  5d                   pop ebp
// 005ce86e  83c408               add esp, 8
// 005ce871  c3                   ret 
// 005ce872  8b03                 mov eax, dword ptr [ebx]
// 005ce874  ebeb                 jmp 0x5ce861
// standard library vector<double> (function ?back@?$vector@NV?$allocator@N@std@@@std@@QAEAANXZ)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
