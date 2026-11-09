// from server: 100% by auto
// roc 2009-12 006334f0  unit: RBX::Object  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006334f0
//
// 006334f0  83ec08               sub esp, 8
// 006334f3  55                   push ebp
// 006334f4  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006334fa  56                   push esi
// 006334fb  8bf1                 mov esi, ecx
// 006334fd  57                   push edi
// 006334fe  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00633501  397e0c               cmp dword ptr [esi + 0xc], edi
// 00633504  7602                 jbe 0x633508
// 00633506  ffd5                 call ebp
// 00633508  8b36                 mov esi, dword ptr [esi]
// 0063350a  53                   push ebx
// 0063350b  8bde                 mov ebx, esi
// 0063350d  897c2414             mov dword ptr [esp + 0x14], edi
// 00633511  85f6                 test esi, esi
// 00633513  7514                 jne 0x633529
// 00633515  ffd5                 call ebp
// 00633517  33c0                 xor eax, eax
// 00633519  8d4ff8               lea ecx, [edi - 8]
// 0063351c  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0063351f  7713                 ja 0x633534
// 00633521  85f6                 test esi, esi
// 00633523  7408                 je 0x63352d
// 00633525  8b36                 mov esi, dword ptr [esi]
// 00633527  eb06                 jmp 0x63352f
// 00633529  8b06                 mov eax, dword ptr [esi]
// 0063352b  ebec                 jmp 0x633519
// 0063352d  33f6                 xor esi, esi
// 0063352f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 00633532  7302                 jae 0x633536
// 00633534  ffd5                 call ebp
// 00633536  8d77f8               lea esi, [edi - 8]
// 00633539  85db                 test ebx, ebx
// 0063353b  7515                 jne 0x633552
// 0063353d  ffd5                 call ebp
// 0063353f  33c0                 xor eax, eax
// 00633541  5b                   pop ebx
// 00633542  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00633545  7202                 jb 0x633549
// 00633547  ffd5                 call ebp
// 00633549  5f                   pop edi
// 0063354a  8bc6                 mov eax, esi
// 0063354c  5e                   pop esi
// 0063354d  5d                   pop ebp
// 0063354e  83c408               add esp, 8
// 00633551  c3                   ret 
// 00633552  8b03                 mov eax, dword ptr [ebx]
// 00633554  ebeb                 jmp 0x633541
// standard library vector<double> (function ?back@?$vector@NV?$allocator@N@std@@@std@@QAEAANXZ)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
