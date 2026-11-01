// from server: 100% by auto
// roc 2009-12 005b0820  unit: seg_005b0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0820
//
// 005b0820  56                   push esi
// 005b0821  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b0825  57                   push edi
// 005b0826  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005b082a  8bc6                 mov eax, esi
// 005b082c  8bcf                 mov ecx, edi
// 005b082e  85f6                 test esi, esi
// 005b0830  7614                 jbe 0x5b0846
// 005b0832  8b542414             mov edx, dword ptr [esp + 0x14]
// 005b0836  53                   push ebx
// 005b0837  668b1a               mov bx, word ptr [edx]
// 005b083a  668919               mov word ptr [ecx], bx
// 005b083d  48                   dec eax
// 005b083e  83c102               add ecx, 2
// 005b0841  85c0                 test eax, eax
// 005b0843  77f2                 ja 0x5b0837
// 005b0845  5b                   pop ebx
// 005b0846  8d0477               lea eax, [edi + esi*2]
// 005b0849  5f                   pop edi
// 005b084a  5e                   pop esi
// 005b084b  c20c00               ret 0xc
// standard library vector<short> (function ?_Ufill@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAFIABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
