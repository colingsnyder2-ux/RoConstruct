// from server: 100% by auto
// roc 2008-06 005587c0  unit: RBX::VInstance::?$AbstractFactoryProduct  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005587c0
//
// 005587c0  83ec08               sub esp, 8
// 005587c3  55                   push ebp
// 005587c4  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005587ca  56                   push esi
// 005587cb  8bf1                 mov esi, ecx
// 005587cd  57                   push edi
// 005587ce  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005587d1  397e0c               cmp dword ptr [esi + 0xc], edi
// 005587d4  7602                 jbe 0x5587d8
// 005587d6  ffd5                 call ebp
// 005587d8  8b36                 mov esi, dword ptr [esi]
// 005587da  53                   push ebx
// 005587db  8bde                 mov ebx, esi
// 005587dd  897c2414             mov dword ptr [esp + 0x14], edi
// 005587e1  85f6                 test esi, esi
// 005587e3  7514                 jne 0x5587f9
// 005587e5  ffd5                 call ebp
// 005587e7  33c0                 xor eax, eax
// 005587e9  8d4ff8               lea ecx, [edi - 8]
// 005587ec  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 005587ef  7713                 ja 0x558804
// 005587f1  85f6                 test esi, esi
// 005587f3  7408                 je 0x5587fd
// 005587f5  8b36                 mov esi, dword ptr [esi]
// 005587f7  eb06                 jmp 0x5587ff
// 005587f9  8b06                 mov eax, dword ptr [esi]
// 005587fb  ebec                 jmp 0x5587e9
// 005587fd  33f6                 xor esi, esi
// 005587ff  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 00558802  7302                 jae 0x558806
// 00558804  ffd5                 call ebp
// 00558806  8d77f8               lea esi, [edi - 8]
// 00558809  85db                 test ebx, ebx
// 0055880b  7515                 jne 0x558822
// 0055880d  ffd5                 call ebp
// 0055880f  33c0                 xor eax, eax
// 00558811  5b                   pop ebx
// 00558812  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00558815  7202                 jb 0x558819
// 00558817  ffd5                 call ebp
// 00558819  5f                   pop edi
// 0055881a  8bc6                 mov eax, esi
// 0055881c  5e                   pop esi
// 0055881d  5d                   pop ebp
// 0055881e  83c408               add esp, 8
// 00558821  c3                   ret 
// 00558822  8b03                 mov eax, dword ptr [ebx]
// 00558824  ebeb                 jmp 0x558811
// standard library vector<double> (function ?back@?$vector@NV?$allocator@N@std@@@std@@QAEAANXZ)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
