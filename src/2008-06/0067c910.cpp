// from server: 100% by auto
// roc 2008-06 0067c910  unit: Ogre::RbxEntity  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067c910
//
// 0067c910  53                   push ebx
// 0067c911  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0067c917  56                   push esi
// 0067c918  8b31                 mov esi, dword ptr [ecx]
// 0067c91a  57                   push edi
// 0067c91b  8b7904               mov edi, dword ptr [ecx + 4]
// 0067c91e  85f6                 test esi, esi
// 0067c920  7518                 jne 0x67c93a
// 0067c922  ffd3                 call ebx
// 0067c924  33c0                 xor eax, eax
// 0067c926  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0067c92a  8d3ccf               lea edi, [edi + ecx*8]
// 0067c92d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0067c930  7713                 ja 0x67c945
// 0067c932  85f6                 test esi, esi
// 0067c934  7408                 je 0x67c93e
// 0067c936  8b06                 mov eax, dword ptr [esi]
// 0067c938  eb06                 jmp 0x67c940
// 0067c93a  8b06                 mov eax, dword ptr [esi]
// 0067c93c  ebe8                 jmp 0x67c926
// 0067c93e  33c0                 xor eax, eax
// 0067c940  3b780c               cmp edi, dword ptr [eax + 0xc]
// 0067c943  7302                 jae 0x67c947
// 0067c945  ffd3                 call ebx
// 0067c947  8b442410             mov eax, dword ptr [esp + 0x10]
// 0067c94b  897804               mov dword ptr [eax + 4], edi
// 0067c94e  5f                   pop edi
// 0067c94f  8930                 mov dword ptr [eax], esi
// 0067c951  5e                   pop esi
// 0067c952  5b                   pop ebx
// 0067c953  c20800               ret 8
// standard library vector<double> (function ??H?$_Vector_const_iterator@NV?$allocator@N@std@@@std@@QBE?AV01@H@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
