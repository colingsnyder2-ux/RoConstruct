// from server: 100% by auto
// roc 2009-06 0053ad50  unit: RBX::VerticalCylinderBuilder  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053ad50
//
// 0053ad50  8b442404             mov eax, dword ptr [esp + 4]
// 0053ad54  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0053ad58  3bc1                 cmp eax, ecx
// 0053ad5a  7413                 je 0x53ad6f
// 0053ad5c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0053ad60  56                   push esi
// 0053ad61  668b32               mov si, word ptr [edx]
// 0053ad64  668930               mov word ptr [eax], si
// 0053ad67  83c002               add eax, 2
// 0053ad6a  3bc1                 cmp eax, ecx
// 0053ad6c  75f3                 jne 0x53ad61
// 0053ad6e  5e                   pop esi
// 0053ad6f  c3                   ret 
// standard library vector<short> (function ??$_Fill@PAFF@std@@YAXPAF0ABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
