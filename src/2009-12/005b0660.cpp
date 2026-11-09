// from server: 100% by auto
// roc 2009-12 005b0660  unit: seg_005b0000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0660
//
// 005b0660  8b442404             mov eax, dword ptr [esp + 4]
// 005b0664  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b0668  3bc1                 cmp eax, ecx
// 005b066a  7413                 je 0x5b067f
// 005b066c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005b0670  56                   push esi
// 005b0671  668b32               mov si, word ptr [edx]
// 005b0674  668930               mov word ptr [eax], si
// 005b0677  83c002               add eax, 2
// 005b067a  3bc1                 cmp eax, ecx
// 005b067c  75f3                 jne 0x5b0671
// 005b067e  5e                   pop esi
// 005b067f  c3                   ret 
// standard library vector<short> (function ??$_Fill@PAFF@std@@YAXPAF0ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
