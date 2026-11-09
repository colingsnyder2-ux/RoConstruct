// from server: 100% by auto
// roc 2012-06 0062f360  unit: G3D::BinaryInput  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062f360
//
// 0062f360  8b442404             mov eax, dword ptr [esp + 4]
// 0062f364  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062f368  3bc1                 cmp eax, ecx
// 0062f36a  7413                 je 0x62f37f
// 0062f36c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0062f370  56                   push esi
// 0062f371  668b32               mov si, word ptr [edx]
// 0062f374  668930               mov word ptr [eax], si
// 0062f377  83c002               add eax, 2
// 0062f37a  3bc1                 cmp eax, ecx
// 0062f37c  75f3                 jne 0x62f371
// 0062f37e  5e                   pop esi
// 0062f37f  c3                   ret 
// standard library vector<short> (function ??$_Fill@PAFF@std@@YAXPAF0ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
