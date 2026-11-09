// from server: 100% by auto
// roc 2008-06 004dca20  unit: RBX::ViewNew::ViewG3D  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dca20
//
// 004dca20  8b442404             mov eax, dword ptr [esp + 4]
// 004dca24  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004dca28  3bc1                 cmp eax, ecx
// 004dca2a  7413                 je 0x4dca3f
// 004dca2c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004dca30  56                   push esi
// 004dca31  668b32               mov si, word ptr [edx]
// 004dca34  668930               mov word ptr [eax], si
// 004dca37  83c002               add eax, 2
// 004dca3a  3bc1                 cmp eax, ecx
// 004dca3c  75f3                 jne 0x4dca31
// 004dca3e  5e                   pop esi
// 004dca3f  c3                   ret 
// standard library vector<short> (function ??$_Fill@PAFF@std@@YAXPAF0ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
