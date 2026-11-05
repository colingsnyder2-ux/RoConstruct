// from server: 100% by auto
// roc 2008-06 006900d0  unit: Ogre::RbxSceneManagerFactory  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006900d0
//
// 006900d0  53                   push ebx
// 006900d1  8b1d90288000         mov ebx, dword ptr [0x802890]
// 006900d7  56                   push esi
// 006900d8  8b31                 mov esi, dword ptr [ecx]
// 006900da  57                   push edi
// 006900db  8b7904               mov edi, dword ptr [ecx + 4]
// 006900de  85f6                 test esi, esi
// 006900e0  751b                 jne 0x6900fd
// 006900e2  ffd3                 call ebx
// 006900e4  33c9                 xor ecx, ecx
// 006900e6  8b442414             mov eax, dword ptr [esp + 0x14]
// 006900ea  8d0440               lea eax, [eax + eax*2]
// 006900ed  8d3c87               lea edi, [edi + eax*4]
// 006900f0  3b7910               cmp edi, dword ptr [ecx + 0x10]
// 006900f3  7713                 ja 0x690108
// 006900f5  85f6                 test esi, esi
// 006900f7  7408                 je 0x690101
// 006900f9  8b06                 mov eax, dword ptr [esi]
// 006900fb  eb06                 jmp 0x690103
// 006900fd  8b0e                 mov ecx, dword ptr [esi]
// 006900ff  ebe5                 jmp 0x6900e6
// 00690101  33c0                 xor eax, eax
// 00690103  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00690106  7302                 jae 0x69010a
// 00690108  ffd3                 call ebx
// 0069010a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0069010e  897804               mov dword ptr [eax + 4], edi
// 00690111  5f                   pop edi
// 00690112  8930                 mov dword ptr [eax], esi
// 00690114  5e                   pop esi
// 00690115  5b                   pop ebx
// 00690116  c20800               ret 8
// standard library vector<pod12> (function ??H?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
