// from server: 100% by auto
// roc 2009-06 004855b0  unit: RBX::MeshFileKey  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004855b0
//
// 004855b0  83ec08               sub esp, 8
// 004855b3  55                   push ebp
// 004855b4  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004855ba  56                   push esi
// 004855bb  8bf1                 mov esi, ecx
// 004855bd  57                   push edi
// 004855be  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004855c1  397e0c               cmp dword ptr [esi + 0xc], edi
// 004855c4  7602                 jbe 0x4855c8
// 004855c6  ffd5                 call ebp
// 004855c8  8b36                 mov esi, dword ptr [esi]
// 004855ca  53                   push ebx
// 004855cb  8bde                 mov ebx, esi
// 004855cd  897c2414             mov dword ptr [esp + 0x14], edi
// 004855d1  85f6                 test esi, esi
// 004855d3  7514                 jne 0x4855e9
// 004855d5  ffd5                 call ebp
// 004855d7  33c0                 xor eax, eax
// 004855d9  8d4ff0               lea ecx, [edi - 0x10]
// 004855dc  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 004855df  7713                 ja 0x4855f4
// 004855e1  85f6                 test esi, esi
// 004855e3  7408                 je 0x4855ed
// 004855e5  8b36                 mov esi, dword ptr [esi]
// 004855e7  eb06                 jmp 0x4855ef
// 004855e9  8b06                 mov eax, dword ptr [esi]
// 004855eb  ebec                 jmp 0x4855d9
// 004855ed  33f6                 xor esi, esi
// 004855ef  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 004855f2  7302                 jae 0x4855f6
// 004855f4  ffd5                 call ebp
// 004855f6  8d77f0               lea esi, [edi - 0x10]
// 004855f9  85db                 test ebx, ebx
// 004855fb  7515                 jne 0x485612
// 004855fd  ffd5                 call ebp
// 004855ff  33c0                 xor eax, eax
// 00485601  5b                   pop ebx
// 00485602  3b7010               cmp esi, dword ptr [eax + 0x10]
// 00485605  7202                 jb 0x485609
// 00485607  ffd5                 call ebp
// 00485609  5f                   pop edi
// 0048560a  8bc6                 mov eax, esi
// 0048560c  5e                   pop esi
// 0048560d  5d                   pop ebp
// 0048560e  83c408               add esp, 8
// 00485611  c3                   ret 
// 00485612  8b03                 mov eax, dword ptr [ebx]
// 00485614  ebeb                 jmp 0x485601
// standard library vector<pod16> (function ?back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEAAUE@@XZ)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
