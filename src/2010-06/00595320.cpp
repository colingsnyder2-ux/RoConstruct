// from server: 100% by auto
// roc 2010-06 00595320  unit: RBX::Object  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00595320
//
// 00595320  83ec08               sub esp, 8
// 00595323  55                   push ebp
// 00595324  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0059532a  56                   push esi
// 0059532b  8bf1                 mov esi, ecx
// 0059532d  57                   push edi
// 0059532e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00595331  397e0c               cmp dword ptr [esi + 0xc], edi
// 00595334  7602                 jbe 0x595338
// 00595336  ffd5                 call ebp
// 00595338  8b36                 mov esi, dword ptr [esi]
// 0059533a  53                   push ebx
// 0059533b  8bde                 mov ebx, esi
// 0059533d  897c2414             mov dword ptr [esp + 0x14], edi
// 00595341  85f6                 test esi, esi
// 00595343  7514                 jne 0x595359
// 00595345  ffd5                 call ebp
// 00595347  33c0                 xor eax, eax
// 00595349  8d4ff8               lea ecx, [edi - 8]
// 0059534c  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 0059534f  7713                 ja 0x595364
// 00595351  85f6                 test esi, esi
// 00595353  7408                 je 0x59535d
// 00595355  8b36                 mov esi, dword ptr [esi]
// 00595357  eb06                 jmp 0x59535f
// 00595359  8b06                 mov eax, dword ptr [esi]
// 0059535b  ebec                 jmp 0x595349
// 0059535d  33f6                 xor esi, esi
// 0059535f  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 00595362  7302                 jae 0x595366
// 00595364  ffd5                 call ebp
// 00595366  8d77f8               lea esi, [edi - 8]
// 00595369  85db                 test ebx, ebx
// 0059536b  7515                 jne 0x595382
// 0059536d  ffd5                 call ebp
// 0059536f  33c0                 xor eax, eax
// 00595371  5b                   pop ebx
// 00595372  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00595375  7202                 jb 0x595379
// 00595377  ffd5                 call ebp
// 00595379  5f                   pop edi
// 0059537a  8bc6                 mov eax, esi
// 0059537c  5e                   pop esi
// 0059537d  5d                   pop ebp
// 0059537e  83c408               add esp, 8
// 00595381  c3                   ret 
// 00595382  8b03                 mov eax, dword ptr [ebx]
// 00595384  ebeb                 jmp 0x595371
// standard library vector<double> (function ?back@?$vector@NV?$allocator@N@std@@@std@@QAEAANXZ)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
