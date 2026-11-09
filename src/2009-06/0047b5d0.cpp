// from server: 100% by auto
// roc 2009-06 0047b5d0  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047b5d0
//
// 0047b5d0  53                   push ebx
// 0047b5d1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 0047b5d7  56                   push esi
// 0047b5d8  8b31                 mov esi, dword ptr [ecx]
// 0047b5da  57                   push edi
// 0047b5db  8b7904               mov edi, dword ptr [ecx + 4]
// 0047b5de  85f6                 test esi, esi
// 0047b5e0  751b                 jne 0x47b5fd
// 0047b5e2  ffd3                 call ebx
// 0047b5e4  33c9                 xor ecx, ecx
// 0047b5e6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0047b5ea  8d0440               lea eax, [eax + eax*2]
// 0047b5ed  8d3c87               lea edi, [edi + eax*4]
// 0047b5f0  3b7910               cmp edi, dword ptr [ecx + 0x10]
// 0047b5f3  7713                 ja 0x47b608
// 0047b5f5  85f6                 test esi, esi
// 0047b5f7  7408                 je 0x47b601
// 0047b5f9  8b06                 mov eax, dword ptr [esi]
// 0047b5fb  eb06                 jmp 0x47b603
// 0047b5fd  8b0e                 mov ecx, dword ptr [esi]
// 0047b5ff  ebe5                 jmp 0x47b5e6
// 0047b601  33c0                 xor eax, eax
// 0047b603  3b780c               cmp edi, dword ptr [eax + 0xc]
// 0047b606  7302                 jae 0x47b60a
// 0047b608  ffd3                 call ebx
// 0047b60a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0047b60e  897804               mov dword ptr [eax + 4], edi
// 0047b611  5f                   pop edi
// 0047b612  8930                 mov dword ptr [eax], esi
// 0047b614  5e                   pop esi
// 0047b615  5b                   pop ebx
// 0047b616  c20800               ret 8
// standard library vector<pod12> (function ??H?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QBE?AV01@H@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
