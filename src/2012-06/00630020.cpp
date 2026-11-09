// from server: 100% by auto
// roc 2012-06 00630020  unit: G3D::BinaryInput  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00630020
//
// 00630020  56                   push esi
// 00630021  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00630025  57                   push edi
// 00630026  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0063002a  8bc6                 mov eax, esi
// 0063002c  8bcf                 mov ecx, edi
// 0063002e  85f6                 test esi, esi
// 00630030  7614                 jbe 0x630046
// 00630032  8b542414             mov edx, dword ptr [esp + 0x14]
// 00630036  53                   push ebx
// 00630037  668b1a               mov bx, word ptr [edx]
// 0063003a  668919               mov word ptr [ecx], bx
// 0063003d  48                   dec eax
// 0063003e  83c102               add ecx, 2
// 00630041  85c0                 test eax, eax
// 00630043  77f2                 ja 0x630037
// 00630045  5b                   pop ebx
// 00630046  8d0477               lea eax, [edi + esi*2]
// 00630049  5f                   pop edi
// 0063004a  5e                   pop esi
// 0063004b  c20c00               ret 0xc
// standard library vector<short> (function ?_Ufill@?$vector@FV?$allocator@F@std@@@std@@IAEPAFPAFIABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
