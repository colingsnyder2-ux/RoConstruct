// from server: 100% by auto
// roc 2010-06 00559270  unit: G3D::BinaryInput  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559270
//
// 00559270  56                   push esi
// 00559271  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00559275  57                   push edi
// 00559276  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0055927a  8bc6                 mov eax, esi
// 0055927c  8bcf                 mov ecx, edi
// 0055927e  85f6                 test esi, esi
// 00559280  7614                 jbe 0x559296
// 00559282  8b542414             mov edx, dword ptr [esp + 0x14]
// 00559286  53                   push ebx
// 00559287  668b1a               mov bx, word ptr [edx]
// 0055928a  668919               mov word ptr [ecx], bx
// 0055928d  48                   dec eax
// 0055928e  83c102               add ecx, 2
// 00559291  85c0                 test eax, eax
// 00559293  77f2                 ja 0x559287
// 00559295  5b                   pop ebx
// 00559296  8d0477               lea eax, [edi + esi*2]
// 00559299  5f                   pop edi
// 0055929a  5e                   pop esi
// 0055929b  c20c00               ret 0xc
// standard library vector<short> (function ?_Ufill@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAFIABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
