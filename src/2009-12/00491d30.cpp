// from server: 100% by auto
// roc 2009-12 00491d30  unit: Ogre::RbxEntity  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491d30
//
// 00491d30  53                   push ebx
// 00491d31  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00491d37  56                   push esi
// 00491d38  8b31                 mov esi, dword ptr [ecx]
// 00491d3a  57                   push edi
// 00491d3b  8b7904               mov edi, dword ptr [ecx + 4]
// 00491d3e  85f6                 test esi, esi
// 00491d40  751b                 jne 0x491d5d
// 00491d42  ffd3                 call ebx
// 00491d44  33c9                 xor ecx, ecx
// 00491d46  8b442414             mov eax, dword ptr [esp + 0x14]
// 00491d4a  8d0440               lea eax, [eax + eax*2]
// 00491d4d  8d3c87               lea edi, [edi + eax*4]
// 00491d50  3b7910               cmp edi, dword ptr [ecx + 0x10]
// 00491d53  7713                 ja 0x491d68
// 00491d55  85f6                 test esi, esi
// 00491d57  7408                 je 0x491d61
// 00491d59  8b06                 mov eax, dword ptr [esi]
// 00491d5b  eb06                 jmp 0x491d63
// 00491d5d  8b0e                 mov ecx, dword ptr [esi]
// 00491d5f  ebe5                 jmp 0x491d46
// 00491d61  33c0                 xor eax, eax
// 00491d63  3b780c               cmp edi, dword ptr [eax + 0xc]
// 00491d66  7302                 jae 0x491d6a
// 00491d68  ffd3                 call ebx
// 00491d6a  8b442410             mov eax, dword ptr [esp + 0x10]
// 00491d6e  897804               mov dword ptr [eax + 4], edi
// 00491d71  5f                   pop edi
// 00491d72  8930                 mov dword ptr [eax], esi
// 00491d74  5e                   pop esi
// 00491d75  5b                   pop ebx
// 00491d76  c20800               ret 8
// standard library vector<pod12> (function ??H?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
