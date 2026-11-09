// from server: 100% by auto
// roc 2011-06 00544260  unit: G3D::BinaryInput  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00544260
//
// 00544260  56                   push esi
// 00544261  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00544265  57                   push edi
// 00544266  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0054426a  8bc6                 mov eax, esi
// 0054426c  8bcf                 mov ecx, edi
// 0054426e  85f6                 test esi, esi
// 00544270  7614                 jbe 0x544286
// 00544272  8b542414             mov edx, dword ptr [esp + 0x14]
// 00544276  53                   push ebx
// 00544277  668b1a               mov bx, word ptr [edx]
// 0054427a  668919               mov word ptr [ecx], bx
// 0054427d  48                   dec eax
// 0054427e  83c102               add ecx, 2
// 00544281  85c0                 test eax, eax
// 00544283  77f2                 ja 0x544277
// 00544285  5b                   pop ebx
// 00544286  8d0477               lea eax, [edi + esi*2]
// 00544289  5f                   pop edi
// 0054428a  5e                   pop esi
// 0054428b  c20c00               ret 0xc
// standard library vector<short> (function ?_Ufill@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAFIABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
