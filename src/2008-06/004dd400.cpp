// from server: 100% by auto
// roc 2008-06 004dd400  unit: RBX::RenderBase::Mesh::Level  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd400
//
// 004dd400  56                   push esi
// 004dd401  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004dd405  57                   push edi
// 004dd406  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004dd40a  8bc6                 mov eax, esi
// 004dd40c  8bcf                 mov ecx, edi
// 004dd40e  85f6                 test esi, esi
// 004dd410  7614                 jbe 0x4dd426
// 004dd412  8b542414             mov edx, dword ptr [esp + 0x14]
// 004dd416  53                   push ebx
// 004dd417  668b1a               mov bx, word ptr [edx]
// 004dd41a  668919               mov word ptr [ecx], bx
// 004dd41d  48                   dec eax
// 004dd41e  83c102               add ecx, 2
// 004dd421  85c0                 test eax, eax
// 004dd423  77f2                 ja 0x4dd417
// 004dd425  5b                   pop ebx
// 004dd426  8d0477               lea eax, [edi + esi*2]
// 004dd429  5f                   pop edi
// 004dd42a  5e                   pop esi
// 004dd42b  c20c00               ret 0xc
// standard library vector<short> (function ?_Ufill@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAFIABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
